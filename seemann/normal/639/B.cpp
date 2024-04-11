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

int n, d, h;

bool read() {
  if (scanf("%d%d%d", &n, &d, &h) < 3) {
    return false;
  }
  return true;
}

void solve() {
  if (2 * h < d || (n > 2 && d == 1)) {
    printf("-1\n");
    return;
  }
  for (int i = 1; i <= h; ++i) {
    printf("%d %d\n", i, i + 1);
  }
  if (h < d) {
    printf("%d %d\n", 1, h + 2);
    for (int i = h + 2; i <= d; ++i) {
      printf("%d %d\n", i, i + 1);
    }

    for (int i = d + 2; i <= n; ++i) {
      printf("%d %d\n", 1, i);
    }
  } else {
    assert(h == d);
    for (int i = h + 2; i <= n; ++i) {
      printf("%d %d\n", h, i);
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