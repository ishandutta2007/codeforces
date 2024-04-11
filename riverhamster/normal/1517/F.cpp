#include <cstdio>
#include <cctype>
#include <cstring>
#include <algorithm>
#include <numeric>
#include <vector>
#include <cassert>
#include <vector>
using namespace std;

#define LOG(f...) fprintf(stderr, f)

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

const int N = 305;
const int M = 998244353;

int power(int x, int y) {
  int p = 1;
  for (; y; y >>= 1, x = (ll)x * x % M) if (y & 1) p = (ll)p * x % M;
  return p;
}

int f[N][N * 2], sum[N];
int len[N];
vector<int> G[N];
int s[N], R;

int add(int x, int y) { return x + y >= M ? x + y - M : x + y; }
int sub(int x, int y) { return x < y ? x - y + M : x - y; }

void inc(int &x, ll y) { x = (x + y) % M; }

void DFS(int x, int fa = 0) {
  len[x] = 1;
  if (fa && G[x].size() == 1) {
    for (int i = -R; i <= R; ++i) f[x][i] = 0;
    (&f[x][0])[-1] = f[x][R] = 1;
    sum[x] = 2;
    return;
  }
  bool first = true;
  static int _t[N * 2], *t = _t + N;
  for (int v : G[x]) {
    if (v == fa) continue;
    DFS(v, x);
    if (len[v] >= len[x]) len[x] = len[v] + 1;
    len[x] = min(len[x], R);
    if (first) {
      for (int i = -R; i < R; ++i)
        f[x][i] = f[v][i + 1];
      first = false;
      continue;
    }
    memset(_t, 0, sizeof(_t));
    for (int j = -R + 1; j <= R; ++j) {
      if (!f[v][j]) continue;
      ll V = f[v][j];
      for (int i = R - len[x]; i <= R; ++i) {
        int T = i + j >= 0 ? max(i, j - 1) : min(i, j - 1);
        inc(t[T], (ll)f[x][i] * V);
      }
      for (int i = -len[x], li = (len[x] == R ? -1 : 0); i <= li; ++i) {
        int T = i + j >= 0 ? max(i, j - 1) : min(i, j - 1);
        inc(t[T], (ll)f[x][i] * V);
      }
    }
    for (int i = -R; i <= R; ++i) f[x][i] = t[i];
  }
  ll Sum = 0;
  for (int i = -R; i < R; ++i) Sum += f[x][i];
  ll prod = 1;
  for (int v : G[x])
    if (v != fa) prod = prod * sum[v] % M;
  f[x][R] = prod;
  Sum += prod;
  sum[x] = Sum % M;
}

int main() {
#ifndef ONLINE_JUDGE
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
#endif
  int n;
  read(n);
  for (int i = 1; i < n; ++i) {
    int u, v;
    read(u, v);
    G[u].emplace_back(v); G[v].emplace_back(u);
  }
  s[0] = 1;
  for (int i = 1; i <= n; ++i) {
    R = i;
    DFS(1);
    s[i] = accumulate(f[1], f[1] + R + 1, 0LL) % M;
  }
  int sum = M - 1;
  s[n + 1] = power(2, n);
  for (int i = 1; i <= n + 1; ++i)
    sum = (sum + ll(i - 1) * sub(s[i], s[i - 1])) % M;
  printf("%lld\n", (ll)sum * power(2, M - 1 - n) % M);
  return 0;
}