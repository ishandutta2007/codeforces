#include <cstdio>
#include <algorithm>
#include <vector>
#include <tuple>
using namespace std;

const int M = 998244353;

inline int power(int x, int y) {
  int p = 1;
  for (; y; y >>= 1, x = 1LL * x * x % M)
    if (y & 1) p = 1LL * p * x % M;
  return p;
}

template<bool inv>
void FWT(int *a, int n) {
  for (int w = 2, k = 1; k < n; k <<= 1, w <<= 1)
    for (int i = 0; i < n; i += w)
      for (int j = i, lj = i + k; j < lj; ++j)
        tie(a[j], a[j | k]) = make_pair((a[j] + a[j | k]) % M, (a[j] - a[j | k]) % M);
  if (inv) {
    int in = power(n, M - 2);
    for (int i = 0; i < n; ++i) a[i] = 1LL * a[i] * in % M;
  }
}

const int N = 1 << 17;
vector<int> G[N];
int sg[N], sgc[N], state[N];

int getsg(int x) {
  if (sg[x] != -1) return sg[x];
  for (int &v : G[x]) v = getsg(v);
  sort(G[x].begin(), G[x].end());
  G[x].erase(unique(G[x].begin(), G[x].end()), G[x].end());
  for (int i = 0; i < (int)G[x].size(); ++i)
    if (G[x][i] != i) return sg[x] = i;
  return sg[x] = G[x].size();
}

int main() {
#ifndef ONLINE_JUDGE
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
#endif
  int n, m;
  scanf("%d%d", &n, &m);
  for (int i = 0; i < m; ++i) {
    int u, v;
    scanf("%d%d", &u, &v);
    G[u].push_back(v);
  }
  fill(sg + 1, sg + 1 + n, -1);
  for (int i = 1; i <= n; ++i) --sgc[getsg(i)];
  int maxsg = *max_element(sg + 1, sg + 1 + n);
  int len = 1;
  while (len < maxsg + 1) len <<= 1;
  for (int i = 1; i < len; ++i) state[i] = 1;
  sgc[0] += n + 1;
  FWT<false>(state, len); FWT<false>(sgc, len);
  for (int i = 0; i < len; ++i) state[i] = 1LL * state[i] * power(sgc[i], M - 2) % M;
  FWT<true>(state, len);
  printf("%d\n", (state[0] + M) % M);
  return 0;
}