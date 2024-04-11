#include <cstdio>
#include <algorithm>
#include <set>
#include <iostream>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
const pii inf(-(1 << 30), 0);

const int MAXN = 100100;
set<pii> myset;

pii ps[MAXN];
int S[MAXN];

int N;
int main() {
  scanf("%d", &N);
  ll ans = 1E9;
  myset.insert(inf);
  int j = 0;
  scanf("%d", &j);
  j = 0;
  for(int i = 1; i <= N; ++i) {
    if (i < N) {
      int x;
      scanf("%d", &x);
      S[i + 1] = S[i] + x;
    }

    ps[i] = pii(S[i], i);
    pii p = ps[i];
    if (i > 1) {
      set<pii>::iterator it = myset.lower_bound(p);
      for(set<pii>::iterator up = it; up != myset.end(); ++up) {
        ll cur = up->first - S[i];
        cur *= cur;
        if (cur >= ans) break;
        ll part = (up->second - i);
        part *= part;
        cur += part;
        if (cur < ans) ans = cur;
      }

      --it;
      for(set<pii>::iterator down = it; *down != inf; --down) {
        ll cur = down->first - S[i];
        cur *= cur;
        if (cur >= ans) break;
        ll part = (down->second - i);
        part *= part;
        cur += part;
        if (cur < ans) ans = cur;
      }
    }
    myset.insert(p);


    while (ll(i - j) * (i - j) >= ans) {
      myset.erase(ps[j]);
      ++j;
    }
  }

  cout << ans << "\n";
  return 0;
}