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

const int maxn = 1e5 + 10;

int n;
char s[maxn];
int d[maxn];

bool read() {
  if (scanf("%d%s", &n, s) < 2) {
    return false;
  }
  assert((int) strlen(s) == n);
  for (int i = 0; i < n; ++i) {
    scanf("%d", &d[i]);
  }
  return true;
}

bool used[maxn];

void solve() {
  memset(used, 0, sizeof(used));
  int v;
  for (v = 0; v >= 0 && v < n && !used[v];) {
    used[v] = true;
    if (s[v] == '<') {
      v -= d[v];
    } else {
      assert(s[v] == '>');
      v += d[v];
    }
  }

  if (0 <= v && v < n) {
    printf("INFINITE\n");
  } else {
    printf("FINITE\n");
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