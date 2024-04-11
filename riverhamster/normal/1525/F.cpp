#include <cstdio>
#include <cctype>
#include <cstring>
#include <algorithm>
#include <numeric>
#include <vector>
#include <cassert>
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

const int N = 55;

int mx[N], my[N], dfny[N];
bool sx[N], sy[N];
int cover[N], cc = 0;
vector<int> G[N];
int dfsid = 0;
ll dp[N][N];
int pre[N][N];
int x[N], y[N];

bool upmax(ll &x, ll y) {
  bool f = x < y;
  x = f ? y : x;
  return f;
}

bool DFS(int x) {
  for (int v : G[x]) {
    if (dfny[v] == dfsid) continue;
    dfny[v] = dfsid;
    if (!my[v] || DFS(my[v])) {
      mx[x] = v;
      my[v] = x;
      return true;
    }
  }
  return false;
}

void konig(int x) {
  sx[x] = true;
  for (int v : G[x])
    if (!sy[v]) {
      sy[v] = true;
      konig(my[v]);
    }
}

int main() {
#ifndef ONLINE_JUDGE
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
#endif
  int n, m, k;
  read(n, m, k);
  for (int i = 1; i <= m; ++i) {
    int u, v;
    read(u, v);
    G[u].push_back(v);
  }

  for (int i = 1; i <= n; ++i)
    if (!mx[i])
      ++dfsid, DFS(i);
  int max_match = count_if(mx + 1, mx + 1 + n, [](int x) { return bool(x); });
  for (int i = 1; i <= n; ++i)
    if (!mx[i])
      konig(i);
  for (int i = 1; i <= n; ++i)
    if (!sx[i])
      cover[++cc] = i;
  for (int i = 1; i <= n; ++i)
    if (sy[i])
      cover[++cc] = -i;

  for (int i = 1; i <= k; ++i)
    read(x[i], y[i]);

  memset(dp, 0xAF, sizeof(dp));
  dp[0][max_match] = 0;
  for (int i = 0; i < k; ++i) {
    int li = min(max_match, n - i - 1);
    for (int j = 0; j <= li; ++j)
      if (dp[i][j] >= 0)
        for (int k = 0; k <= j; ++k)
          if (upmax(dp[i + 1][j - k], dp[i][j] + max(0LL, x[i + 1] - (ll)k * y[i + 1])))
            pre[i + 1][j - k] = j;
  }

  int li = min(max_match, n - k - 1);
  int pos = max_element(dp[k], dp[k] + li + 1) - dp[k];
  vector<int> res;
  for (int i = k; i >= 1; --i) {
    res.push_back(0);
    for (int _ = 0, li = pre[i][pos] - pos; _ != li; ++_)
      res.push_back(cover[cc--]);
    pos = pre[i][pos];
  }
  printf("%llu\n", (unsigned long long)res.size());
  for (auto i = res.rbegin(); i != res.rend(); ++i)
    printf("%d ", *i);
  putchar('\n');
  return 0;
}