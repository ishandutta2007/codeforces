#undef NDEBUG
#ifdef ssu1
#endif

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

string s, t;
int pfx, sfx, pfx1, sfx1, n;

int Get(int pos, char c) {
  if (pfx >= pos) {
    if (sfx >= n - pos)
      return 1;
    if (t[pos] == c && pos + sfx1 >= n)
      return 1;
  } else {
    if (sfx >= n - pos && pfx1 + (n - pos) >= n && t[pos - 1] == c)
      return 1;
  }
  return 0;
}

int main() {
#ifdef ssu1
  assert(freopen("input.txt", "rt", stdin));
#endif

  cin >> n;
  cin >> s >> t;

  while (pfx < n && s[pfx] == t[pfx])
    pfx++;
  while (sfx < n && s[n - sfx - 1] == t[n - sfx - 1])
    sfx++;

  pfx1 = pfx + 1, sfx1 = sfx + 1;
  while (pfx1 < n && s[pfx1] == t[pfx1 - 1])
    pfx1++;
  while (sfx1 < n && s[n - 1 - sfx1] == t[n - sfx1])
    sfx1++;

  int ans = 0;

  for (int pos = 0; pos <= n; ++pos) {
    if (pos == 0) {
      for (char c = 'a'; c <= 'z'; ++c) {
        ans += Get(pos, c);
      }
    } else {
      for (char c = 'a'; c <= 'z'; ++c) {
        if (c == s[pos - 1])
          continue;
        ans += Get(pos, c);
      }
    }
  }

  cout << ans << endl;

#ifdef ssu1
  cerr << "\nTime = " << static_cast<double>(clock()) / CLOCKS_PER_SEC << endl;
#endif
  return 0;
}