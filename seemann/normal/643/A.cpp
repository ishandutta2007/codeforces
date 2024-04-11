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

const int maxn = 5e3 + 10;

int n;
int t[maxn];

bool read() {
  if (scanf("%d", &n) < 1) {
    return false;
  }
  for (int i = 0; i < n; ++i) {
    scanf("%d", &t[i]);
  }
  return true;
}

int ans[maxn];
int cnt[maxn];

void solve() {
  memset(ans, 0, sizeof(ans));
  for (int i = 0; i < n; ++i) {
    memset(cnt, 0, sizeof(cnt));
    int mx = 0;
    for (int j = i; j < n; ++j) {
      ++cnt[t[j]];
      if (cnt[t[j]] > cnt[mx] || (cnt[t[j]] == cnt[mx] && t[j] < mx)) {
        mx = t[j];
      }
      ++ans[mx];
    }
  }

  for (int i = 1; i <= n; ++i) {
    printf("%d%c", ans[i], " \n"[i == n]);
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