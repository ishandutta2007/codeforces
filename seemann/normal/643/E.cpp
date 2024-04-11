#include <bits/stdc++.h>

using namespace std;

typedef long double ld;
typedef long long ll;

long long rdtsc() {
  long long tmp;
  asm("rdtsc" : "=A"(tmp));
  return tmp;
}

inline int myrand() {
#ifdef _WIN32
  return abs((rand() << 15) ^ rand());
#else
  return rand();
#endif
}

inline int rnd(int x) {
  return myrand() % x;
}

#ifdef DEBUG
#define eprintf(...) fprintf(stderr, __VA_ARGS__), fflush(stdout)
#else
#define eprintf(...) ;
#endif

#define pb push_back
#define mp make_pair
#define sz(x) ((int)(x).size())
#define TASK "text"

void precalc() {
}

const int maxn = 5e5 + 10;
const int K = 50;

int q;
bool read() {
  if (scanf("%d", &q) < 1) {
    return false;
  }
  return true;
}

int n;
int pr[maxn];
ld dp[maxn][K];

int getv(int _pr = -1) {
  pr[n] = _pr;
  for (int i = 0; i < K; ++i) {
    dp[n][i] = 1.0L;
  }
  return n++;
}

ld tmp[K];

void solve() {
  n = 0;
  getv();
  for (int it = 0; it < q; ++it) {
    int tp, v;
    scanf("%d%d", &tp, &v);
    --v;
    assert(v < n);
    if (tp == 1) {
      int nv = getv(v);
      for (int k = 0; k < K; ++k) {
        tmp[k] = dp[v][k];
        if (k > 0) {
          dp[v][k] /= 0.5L * (1.0L + tmp[k - 1]);
        }
        dp[v][k] *= 0.5L * (1.0L + (k == 0 ? 0.0L : dp[nv][k - 1]));
        if (pr[v] == -1) {
          break;
        }
        nv = v;
        v = pr[v];
      }
    } else {
      assert(tp == 2);
      ld res = 0.0L;
      for (int i = 1; i < K; ++i) {
        res += (dp[v][i] - dp[v][i - 1]) * i;
      }
      printf("%.18f\n", (double) res);
    }
  }
}

int main() {
  srand(rdtsc());
  precalc();
#ifdef LOCAL 
  assert(freopen(TASK".out", "w", stdout));
  assert(freopen(TASK".in", "r", stdin));
#endif

  while (true) {
    if (!read()) {
      break;
    }
    solve();
#ifdef DEBUG
    eprintf("Time %.2f\n", (double) clock() / CLOCKS_PER_SEC);
#endif
  }
  return 0;
}