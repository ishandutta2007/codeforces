#include <cstdio>
#include <cctype>
#include <cstring>
#include <algorithm>
#include <numeric>
#include <vector>
#include <cassert>
using namespace std;

#define LOG(f...) fprintf(stderr, f)
#define DBG(f...) printf("%3d: ", __LINE__), printf(f)
// #define DBG(f...) void()
#define all(cont) begin(cont), end(cont)
#ifdef __linux__
#define getchar getchar_unlocked
#define putchar putchar_unlocked
#endif

using ll = long long;

template <class T> void read(T &x) {
  char ch; x = 0;
  int f = 1;
  while (isspace(ch = getchar()));
  if (ch == '-') ch = getchar(), f = -1;
  do x = x * 10 + (ch - '0'); while(isdigit(ch = getchar()));
  x *= f;
}
template <class T, class ...A> void read(T &x, A&... args) { read(x); read(args...); }

char Get() {
  char ch;
  while (isspace(ch = getchar()));
  return ch;
}

int s[1000005];

int main() {
#ifndef ONLINE_JUDGE
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
#endif
  int n, m;
  read(n, m);
  vector<vector<char>> a(n, vector<char>(m));
  for (int i = 0; i < n; ++i)
    for (int j = 0; j < m; ++j)
      a[i][j] = Get();
  for (int i = 1; i < n; ++i)
    for (int j = 1; j < m; ++j)
      s[j] += (a[i - 1][j] == 'X' && a[i][j - 1] == 'X');
  partial_sum(s, s + m, s);
  int qc;
  read(qc);
  while (qc--) {
    int l, r;
    read(l, r);
    --l; --r;
    if (s[r] != s[l])
      puts("NO");
    else
      puts("YES");
  }
  return 0;
}