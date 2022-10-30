#include <bits/stdc++.h>
using namespace std;
#define M 50010

__int64 ans, cnt[M][600];
vector <int> con[M];
int n, m;

void dfs(int x, int pa) {
  for (int i = 0; i < con[x].size(); i++) {
    int u = con[x][i];
    if (u == pa) continue;
    dfs(u, x);
    for (int j = 0; j < m; j++) {
      cnt[x][j + 1] += cnt[u][j];
    }
  }
  cnt[x][0] = 1;
  for (int i = 0; i <= m; i++) {
    ans += cnt[x][i] * cnt[x][m - i];
  }
  for (int i = 0; i < con[x].size(); i++) {
    int u = con[x][i];
    if (u == pa) continue;
    for (int j = 1; j <= m; j++) {
      ans -= cnt[u][j - 1] * cnt[u][m - j - 1];
    }
  }
}

int main() {
  //freopen("in.txt", "r", stdin);
  scanf("%d %d", &n, &m);
  for (int i = 0; i < n - 1; i++) {
    int x, y;
    scanf("%d %d", &x, &y); con[x].push_back(y); con[y].push_back(x);
  }
  dfs(1, 0);
  cout << ans / 2 << endl;
}