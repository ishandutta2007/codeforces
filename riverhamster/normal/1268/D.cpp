#include <cstdio>
#include <cctype>
#include <cstring>
#include <algorithm>
#include <numeric>
#include <vector>
#include <cassert>
using namespace std;

#define LOG(f...) fprintf(stderr, f)
#define all(cont) begin(cont), end(cont)
#ifdef __linux__
#define getchar getchar_unlocked
#define putchar putchar_unlocked
#endif

using ll = long long;

template<class T> void read(T &x) {
  char ch; x = 0;
  int f = 1;
  while (isspace(ch = getchar()));
  if (ch == '-') ch = getchar(), f = -1;
  do x = x * 10 + (ch - '0'); while(isdigit(ch = getchar()));
  x *= f;
}
template<class T, class ...A> void read(T &x, A&... args) { read(x); read(args...); }

const int N = 2005;
const int fact[] = {1, 1, 2, 6, 24, 120, 720};

char g[N][N];
int d[N], tmp[N];
int n;

void invert(int u) {
  d[u] = n - 2 - d[u];
  for (int i = 0; i < n; ++i)
    d[i] += g[u][i] == '1' ? -1 : 1;
  for (int i = 0; i < n; ++i)
    g[u][i] ^= 1;
  for (int i = 0; i < n; ++i)
    g[i][u] ^= 1;
}

bool strong() {
  memcpy(tmp, d, sizeof(d));
  sort(tmp, tmp + n);
  int sum = 0;
  for (int i = 0; i < n - 1; ++i) {
    sum += tmp[i];
    if (sum == i * (i + 1) / 2)
      return false;
  }
  return true;
}

int main() {
#ifndef ONLINE_JUDGE
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
#endif
  read(n);
  for (int i = 0; i < n; ++i)
    scanf("%s", g[i]);
  for (int i = 0; i < n; ++i)
    for (int j = 0; j < n; ++j)
      d[j] += g[i][j] - '0';
  if (n <= 6) {
    int cnt = 0, mn = numeric_limits<int>::max();
    for (int s = 0; s < (1 << n); ++s) {
      for (int i = 0; i < n; ++i)
        if ((s >> i) & 1) invert(i);
      if (strong()) {
        int pc = __builtin_popcount(s);
        if (pc < mn) mn = pc, cnt = 1;
        else if (pc == mn) ++cnt;
      }
      for (int i = 0; i < n; ++i)
        if ((s >> i) & 1) invert(i);
    }
    if (!cnt) puts("-1");
    else printf("%d %d\n", mn, cnt * fact[mn]);
  }
  else {
    if (strong()) {
      puts("0 1");
      return 0;
    }
    int cnt = 0;
    for (int i = 0; i < n; ++i) {
      invert(i);
      if (strong()) ++cnt;
      invert(i);
    }
    printf("1 %d\n", cnt);
  }
  return 0;
}