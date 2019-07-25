#include <algorithm>
#include <cmath>
#include <cstring>
#include <climits>
#include <functional>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <utility>
#include <vector>
#include <sstream>
#include <unordered_map>
#include <unordered_set>

// https://leetcode.com/problems/powerful-integers/

#include "../utils/VectorUtils.hpp"
#include "../utils/PrintUtils.hpp"
// #include "../utils/HeapUtils.hpp"
// #include "../utils/BinarySearch.hpp"
// #include "../utils/TreeUtils.hpp"

using namespace std;

#pragma GCC diagnostic ignored "-Wunknown-pragmas"

// Live coding problems, watch at
// https://www.twitch.tv/yipcubed
// https://www.youtube.com/channel/UCTV_UOPu7EWXvYWsBFxMsSA/videos
//

// makes code faster, but larger. Just for LeetCode fun!
#pragma GCC optimise ("Ofast")

// makes stdin not synced so it is faster. Just for LeetCode fun!
static auto __ __attribute__((unused)) = []() {              // NOLINT
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  return nullptr;
}();

typedef std::pair<std::string,std::string> mpair;

class Solution {
public:

  vector<int> powerfulIntegers(int x, int y, int bound) {
    unordered_set<int> seen;
    for (int i = 0; i <= 19 && pow(x, i) <= bound; ++i) {
      for (int j = 0; j <= 19 && pow(y, j) <= bound; ++j) {
        unsigned long can = pow(x, i) + pow(y, j);
        if (can <= bound)
          seen.insert(can);
      }
    }
    vector<int> r(seen.begin(), seen.end());
    //sort(r.begin(), r.end());
    return r;
  }
};

void test1() {

  cout << "[2,3,4,5,7,9,10] ? " << Solution().powerfulIntegers(2, 3, 10) << endl;

  cout << "?? ? " << Solution().powerfulIntegers(2, 1, 10) << endl;
  // missing 262145 and 524289
  cout << "[33,2,3,1025,5,65,129,9,257,131073,524289,17,65537,513,32769,2049,4097,16385,262145,8193]\n"
       << Solution().powerfulIntegers(1, 2, 1000000) << endl;

}

void test2() {

}

void test3() {

}