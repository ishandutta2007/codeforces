#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <cstring>
#include <algorithm>
#include <cctype>
#include <ctime>
#include <cmath>
#include <complex>
#include <cassert>
#include <iomanip>

using namespace std;

typedef long long ll;
typedef long double ld;

long long rdtsc() {
  long long tmp;
  asm("rdtsc" : "=A"(tmp));
  return tmp;
}

inline int myrand() {
  return abs((rand() << 15) ^ rand());
}

inline int rnd(int x) {
  return myrand() % x;
}

#define pb push_back
#define mp make_pair
#define eprintf(...) fprintf(stderr, __VA_ARGS__), fflush(stdout)
#define sz(x) ((int)(x).size())
#define TASKNAME ""

void precalc() {
}

const ll inf = 1.01e18;
const int maxn = 2e5 + 10;

int n, k, b, c;
int t[maxn];

bool read() {
  if (scanf("%d%d%d%d", &n, &k, &b, &c) < 4) {
    return false;
  }
  for (int i = 0; i < n; ++i) {
    scanf("%d", &t[i]);
  }
  return true;
}

void solve() {
  sort(t, t + n);
  b = min(b, 5 * c);
  ll ans = inf;

  for (int rem = 0; rem < 5; ++rem) {
    multiset<ll> q;
    ll csum = 0;
    for (int i = 0; i < n; ++i) {
      ll cost = 0;
      int ct = t[i];
      for (; (ct % 5 + 5) % 5 != rem; cost += c, ++ct);
      cost -= (ll) ((ct - rem) / 5) * b;

      q.insert(cost);
      csum += cost;
      if (sz(q) > k) {
        auto it = q.end();
        it--;
        csum -= (*it);
        q.erase(it);
      }
      if (sz(q) == k) {
        ans = min(ans, csum + (ll) k * ((ct - rem) / 5) * b);
      }
    }
  }

  assert(ans >= 0);

  printf("%I64d\n", ans);
}

int main() {
  srand(rdtsc());
#ifdef LOCAL 
  freopen("input.txt", "r", stdin);
#else
//  freopen(TASKNAME".in", "r", stdin);
//  freopen(TASKNAME".out", "w", stdout);
#endif

  precalc();
  while (true) {
    if (!read()) {
      break;
    }
    solve();
#ifdef LOCAL
    eprintf("%.18f\n", (double)clock() / CLOCKS_PER_SEC);
#endif
  }
  return 0;
}