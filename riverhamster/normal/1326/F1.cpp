#include <cstdio>
#include <cctype>
#include <cstring>
#include <algorithm>
#include <numeric>
#include <vector>
#include <cassert>
#include <random>
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
using ull = unsigned long long;

template <class T> void read(T &x) {
  char ch; x = 0;
  int f = 1;
  while (isspace(ch = getchar()));
  if (ch == '-') ch = getchar(), f = -1;
  do x = x * 10 + (ch - '0'); while(isdigit(ch = getchar()));
  x *= f;
}
template <class T, class ...A> void read(T &x, A&... args) { read(x); read(args...); }

const int N = 18;

mt19937_64 rng;

bool G[N][N];
ull sub[N + 1][1 << N];
ull key[N + 1];
ull cur[1 << N];
int n;
vector<pair<ull, ull>> ans;
ull s[1 << N];

void FWTor(ull *a, int n) {
  ull *t = a + n;
  for (int l = 2, k = 1; k < n; l <<= 1, k <<= 1)
    for (ull *i = a; i != t; i += l)
      for (int j = 0; j < k; ++j)
        i[j + k] += i[j];
}
void IFWTand(ull *a, int n) {
  ull *t = a + n;
  for (int l = 2, k = 1; k < n; l <<= 1, k <<= 1) {
    for (ull *i = a; i != t; i += l)
      for (int j = 0; j < k; ++j)
        i[j] -= i[j + k];
  }
}

void DP() {
  static ull dp[1 << N][N];
  for (int i = 0; i < n; ++i)
    dp[1 << i][i] = 1;
  for (int s = 1; s < (1 << n); ++s) {
    int pc = __builtin_popcount(s);
    for (int u = 0; u < n; ++u)
      sub[pc][s] += dp[s][u];
    for (int u = 0; u < n; ++u)
      if ((s >> u) & 1)
        for (int v = 0; v < n; ++v)
          if (G[u][v] && ((~s >> v) & 1))
            dp[s | (1 << v)][v] += dp[s][u];
  }

  for (int i = 1; i <= n; ++i)
    FWTor(sub[i], 1 << n);
}

void DFS(int sum, int lim, ull hsh) {
  if (sum == n) {
    ull s = 0;
    for (int i = 0; i < (1 << n); ++i) {
      if (__builtin_parity(i) == (n & 1)) s += cur[i];
      else s -= cur[i];
    }
    ans.emplace_back(hsh, s);
    return;
  }

  ull *t = new ull[1 << N];
  memcpy(t, cur, sizeof(cur));

  auto trans = [&](int v) {
    for (int i = 0; i < (1 << n); ++i)
      cur[i] = t[i] * sub[v][i];
    DFS(sum + v, v, hsh + key[v]);
  };

  trans(n - sum);
  for (int i = lim; sum + i * 2 <= n; ++i)
    trans(i);
}

int main() {
#ifdef LOCAL
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
#endif
  for (int i = 0; i <= 18; ++i)
    key[i] = rng();
  read(n);
  for (int i = 0; i < n; ++i)
    for (int j = 0; j < n; ++j) {
      int x;
      scanf("%1d", &x);
      G[i][j] = x;
    }
  DP();
  fill(cur, cur + (1 << n), 1);
  DFS(0, 1, 0);

  sort(all(ans));

  for (int i = 0; i < (1 << (n - 1)); ++i) {
    int cnt = 1;
    ull hsh = 0;
    for (int j = 0; j < n; ++j) {
      if ((i >> j) & 1) ++cnt;
      else hsh += key[cnt], cnt = 1;
    }
    auto it = lower_bound(all(ans), make_pair(hsh, 0ULL));
    assert(it != ans.end());
    assert(it->first == hsh);
    s[i] = lower_bound(all(ans), make_pair(hsh, 0ULL))->second;
  }
  IFWTand(s, 1 << (n - 1));
  for (int i = 0; i < (1 << (n - 1)); ++i)
    printf("%lld ", s[i]);
  putchar('\n');
  return 0;
}