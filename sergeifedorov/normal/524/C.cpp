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

const int kInf = 1e9;

int main() {
#ifdef ssu1
  assert(freopen("input.txt", "rt", stdin));
#endif
  int n, k;
  cin >> n >> k;
  vector<int> a(n);
  for (int& ai : a)
    cin >> ai;
  sort(a.begin(), a.end());
  int q;
  cin >> q;
  for (int qi = 0; qi < q; ++qi) {
    int x;
    cin >> x;
    int answer = kInf;
    for (int cnt = 1; cnt <= k; ++cnt) {
      for (int cnt1 = 1; cnt1 <= cnt; cnt1++) {
        int cnt2 = cnt - cnt1;
        vector<int> b = a;
        for (int& bi : b)
          bi *= cnt2;
        int it = b.size() - 1;
        for (const int& ai : a) {
          int rem = x - ai * cnt1;
          if (rem == 0)
            answer = min(answer, cnt1);
          if (rem < 0)
            break;
          while (it >= 0 && b[it] > rem)
            it--;
          if (it >= 0 && b[it] == rem)
            answer = min(answer, cnt);
        }
      }
    }
    if (answer == kInf)
      answer = -1;
    cout << answer << endl;
  }

#ifdef ssu1
  cerr << "\nTime = " << ((double)clock()) / CLOCKS_PER_SEC << endl;
#endif    
  return 0;
}