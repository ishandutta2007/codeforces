#undef NDEBUG

#include <algorithm>
#include <functional>
#include <numeric>
#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <cstring>
#include <cassert>
#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <queue>
#include <bitset>
#include <sstream>
#include <typeinfo>
#include <limits>

using namespace std;

const int kMaxH = 1111;

int main() {
#ifdef ssu1
  assert(freopen("input.txt", "rt", stdin));
#endif
  int n;
  cin >> n;
  vector<int> w(n), h(n);
  for (int i = 0; i < n; ++i)
    cin >> w[i] >> h[i];

  long long minans = 1e18;
  for (int mx = 1; mx <= kMaxH; mx++) {
    int minsum = 0;
    for (int i = 0; i < n; ++i) {
      int minh = kMaxH;

      if (w[i] <= mx)
        minh = min(minh, h[i]);
      if (h[i] <= mx)
        minh = min(minh, w[i]);

      if (minh == kMaxH) {
        minsum = -1;
        break;
      } else
        minsum += minh;
    }
    if (minsum != -1)
      minans = min(minans, minsum * 1LL * mx);
  }

  cout << minans << endl;
#ifdef ssu1
  cerr << "\nTime = " << ((double)clock()) / CLOCKS_PER_SEC << endl;
#endif    
  return 0;
}