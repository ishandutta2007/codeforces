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

const ld eps = 1e-9;
const int maxn = 1e5 + 10;

int n;
ld c[maxn];
ld d[maxn];

bool read() {
  if (scanf("%d", &n) < 1) {
    return false;
  }
  for (int i = 1; i <= n; ++i) {
    double tmp;
    scanf("%lf", &tmp);
    c[i] = tmp;
  }
  for (int i = 1; i <= n; ++i) {
    double tmp;
    scanf("%lf", &tmp);
    d[i] = tmp;
  }
  return true;
}

ld p[maxn][2];

bool dp[maxn][2];
int fr[maxn][2];

ld ans[maxn][2];

void solve() {
  for (int i = 2; i <= n; ++i) {
    c[i] += c[i - 1];
  }
  for (int i = n - 1; i >= 1; --i) {
    d[i] += d[i + 1];
  }
  d[n + 1] = 0.0L;
  for (int i = 1; i <= n; ++i) {
    ld B = 1 + c[i] - d[i + 1];
    ld C = c[i];

    ld D = B * B - 4.0L * C;
    assert(D > -eps);
    p[i][0] = (B + sqrt(max(0.0L, D))) / 2.0L;
    p[i][1] = (B - sqrt(max(0.0L, D))) / 2.0L;
//    eprintf("%.3f %.3f\n", (double) p[i], (double) q[i]);
    assert(-eps <= p[i][0] && p[i][0] <= 1.0L + eps);
    assert(-eps <= p[i][1] && p[i][1] <= 1.0L + eps);
  }
  p[0][0] = p[0][1] = 0.0L;

  memset(dp, 0, sizeof(dp));
  dp[1][0] = dp[1][1] = true;
  fr[1][0] = fr[1][1] = 0;
  for (int i = 1; i < n; ++i) {
    for (int it = 0; it < 2; ++it) {
      if (!dp[i][it]) {
        continue;
      }
      for (int it2 = 0; it2 < 2; ++it2) {
        if (p[i][it] <= p[i + 1][it2] + eps && p[i][!it] <= p[i + 1][!it2] + eps) {
          dp[i + 1][it2] = true;
          fr[i + 1][it2] = it;
        }
      }
    }
  }

  int k = n, it;
  if (dp[n][0]) {
    it = 0;
  } else {
    assert(dp[n][1]);
    it = 1;
  }

  for (; k > 0; it = fr[k][it], --k) {
    int nit = fr[k][it];
    ans[k][0] = p[k][it] - p[k - 1][nit];
    ans[k][1] = p[k][!it] - p[k - 1][!nit];
  }

  for (int it = 0; it < 2; ++it) {
    for (int i = 1; i <= n; ++i) {
      printf("%.10f%c", (double) ans[i][it], " \n"[i == n]);
    }
  }
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