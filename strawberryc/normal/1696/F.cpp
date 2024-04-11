#include <bits/stdc++.h>

template <class T>
inline void read(T &res) {
  res = 0; bool bo = 0; char c;
  while (((c = getchar()) < '0' || c > '9') && c != '-');
  if (c == '-') bo = 1; else res = c - 48;
  while ((c = getchar()) >= '0' && c <= '9')
    res = (res << 3) + (res << 1) + (c - 48);
  if (bo) res = ~res + 1;
}

const int N = 105, wd = 998244353, jyh = 1e9 + 7;

int n, hW[N][N], hJ[N][N], pW[N], pJ[N], iW[N][N], iJ[N][N], d[N][N];
bool is[N][N][N], G[N][N], I[N][N][N], leaf[N];
char s[N];

bool solve(std::vector<int> S) {
  if (S.size() == 1) return 1;
  if (S.size() == 2) {
  	G[S[0]][S[1]] = G[S[1]][S[0]] = 1;
  	return 1;
  }
  int m = S.size();
  for (int i = 0; i < m; i++)
    for (int j = 0; j < m; j++)
      for (int k = 0; k < m; k++)
        I[i][j][k] = is[S[i]][S[j]][S[k]];
  for (int k = 0; k < m; k++) {
  	for (int i = 0; i < m; i++) {
  	  int hw = 0, hj = 0;
  	  for (int j = 0; j < m; j++)
  	    hw = (2ll * hw + I[i][j][k]) % wd,
  	    hj = (3ll * hj + I[i][j][k]) % jyh;
  	  for (int j = 0; j < m; j++) {
  	    iW[i][j] = hw; iJ[i][j] = hj;
  	    if (I[i][j][k]) iW[i][j] = (iW[i][j] - pW[m - 1 - j] + wd) % wd,
  	      iJ[i][j] = (iJ[i][j] - pJ[m - 1 - j] + jyh) % jyh;
	  }
    }
    for (int i = 0; i < m; i++) {
      hW[k][i] = hJ[k][i] = 0;
      for (int j = 0; j < m; j++) {
      	hW[k][i] = 1ll * hW[k][i] * pW[m] % wd;
      	hJ[k][i] = 1ll * hJ[k][i] * pJ[m] % jyh;
	    if (j != i) hW[k][i] = (hW[k][i] + iW[j][i]) % wd,
	      hJ[k][i] = (hJ[k][i] + iJ[j][i]) % jyh;
	  }
	}
  }
  for (int u = 0; u < m; u++) {
  	leaf[u] = 0;
    for (int v = 0; v < m; v++) if (u != v && hW[u][u] == hW[v][u]
	  && hJ[u][u] == hJ[v][u]) leaf[u] = 1;
  }
  for (int u = 0; u < m; u++)
	if (leaf[u]) {
	  int flag = 0;
	  for (int v = 0; v < m; v++) if (u != v && hW[u][u] == hW[v][u]
	    && hJ[u][u] == hJ[v][u] && !leaf[v])
	      G[S[u]][S[v]] = G[S[v]][S[u]] = 1, flag++;
	  if (flag != 1) return 0;
	}
  std::vector<int> nS;
  for (int i = 0; i < m; i++) if (!leaf[i]) nS.push_back(S[i]);
  if (nS.size() == S.size()) return 0;
  return solve(nS);
}

void dfs(int rt, int u, int fu) {
  for (int v = 1; v <= n; v++)
    if (G[u][v] && v != fu)
      d[rt][v] = d[rt][u] + 1, dfs(rt, v, u);
}

void yhjssa() {
  read(n);
  pW[0] = pJ[0] = 1;
  for (int i = 1; i <= n; i++)
    pW[i] = 2ll * pW[i - 1] % wd, pJ[i] = 3ll * pJ[i - 1] % jyh;
  for (int i = 1; i <= n; i++) for (int j = 1; j <= n; j++)
    is[i][i][j] = 1;
  for (int i = 1; i <= n; i++)
    for (int j = i + 1; j <= n; j++) {
      scanf("%s", s + 1);
      for (int k = 1; k <= n; k++)
        is[i][j][k] = is[j][i][k] = s[k] == '1';
	}
  memset(G, 0, sizeof(G));
  std::vector<int> S;
  for (int i = 1; i <= n; i++) S.push_back(i);
  if (!solve(S)) return (void) puts("No");
  for (int u = 1; u <= n; u++) d[u][u] = 0, dfs(u, u, 0);
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= n; j++)
      for (int k = 1; k <= n; k++)
        if ((d[i][k] == d[j][k]) ^ is[i][j][k])
          return (void) puts("No");
  puts("Yes");
  for (int u = 1; u <= n; u++)
    for (int v = u + 1; v <= n; v++)
      if (G[u][v]) printf("%d %d\n", u, v);
}

int main() {
  int T; read(T);
  while (T--) yhjssa();
  return 0;
}