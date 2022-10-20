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

template <class T> void read(T &x) {
  char ch; x = 0;
  int f = 1;
  while (isspace(ch = getchar()));
  if (ch == '-') ch = getchar(), f = -1;
  do x = x * 10 + (ch - '0'); while(isdigit(ch = getchar()));
  x *= f;
}
template <class T, class ...A> void read(T &x, A&... args) { read(x); read(args...); }

const int N = 205;

int c[N][N];
ll s[N][N];
int x[N], y[N];
int n, K;

ll area(int i, int j, int k) {
  ll a = x[j] - x[i], c = x[k] - x[i];
  ll b = y[j] - y[i], d = y[k] - y[i];
  return a * d - b * c;
}

bool check(ll lim) {
  for (int l = n - 2; l >= 1; --l) {
    c[l][l + 2] = 0;
    s[l][l + 2] = area(l, l + 1, l + 2);
    for (int r = l + 3; r <= n; ++r) {
      c[l][r] = s[l][r] = 0;
      for (int p = l + 1; p < r; ++p) {
        ll s0 = area(l, p, r);
        int c0 = 0;
        if (s[l][p] >= lim) c0 += c[l][p] + 1;
        else s0 += s[l][p], c0 += c[l][p];
        if (s[p][r] >= lim) c0 += c[p][r] + 1;
        else s0 += s[p][r], c0 += c[p][r];
        if (c0 > c[l][r]) c[l][r] = c0, s[l][r] = s0;
        else if (c0 == c[l][r]) s[l][r] = max(s[l][r], s0);
      }
    }
  }
  return (c[1][n] + (s[1][n] >= lim)) >= K + 1;
}

int main() {
#ifndef ONLINE_JUDGE
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
#endif
  read(n, K);
  for (int i = 1; i <= n; ++i)
    read(x[i], y[i]);
  ll ans = 0;
  for (int i = 56; i >= 0; --i)
    if (check(ans | (1LL << i))) ans |= (1LL << i);
  printf("%lld\n", ans);
  return 0;
}