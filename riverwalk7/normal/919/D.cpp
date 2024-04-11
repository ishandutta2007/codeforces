
 #include <cstdio>
#include <cstdlib>
#include <vector>
#include <algorithm>

using std::vector;

const int MAXN = 300004;

int N, M;
char str[MAXN];
vector<int> E[MAXN];
int dp[MAXN][26];
int visited[MAXN];

void rage() {
  puts("-1");
  exit(0);
}

void dfs(int p) {
  if (visited[p] == 1) rage();
  else if (visited[p] == 2) return;
  visited[p] = 1;
  for (const auto& x : E[p]) {
    dfs(x);
    for (int i = 0; i < 26; ++i) {
      dp[p][i] = std::max(dp[p][i], dp[x][i]);
    }
  }
  ++dp[p][str[p]];
  visited[p] = 2;
}

int main() {
  scanf("%d%d%s", &N, &M, str + 1);
  for (int i = 1; i <= N; ++i) {
    str[i] -= 'a';
  }
  for (int i = M; i--;) {
    int x, y;
    scanf("%d%d", &x, &y);
    if (x == y) rage();
    E[x].push_back(y);
  }
  for (int i = 1; i <= N; ++i) {
    std::sort(E[i].begin(), E[i].end());
    E[i].resize(std::unique(E[i].begin(), E[i].end()) - E[i].begin());
  }
  for (int i = 1; i <= N; ++i) {
    if (!visited[i]) dfs(i);
  }

  int ans = 1;
  for (int i = 1; i <= N; ++i) {
    for (int j = 26; j--;) {
      ans = std::max(ans, dp[i][j]);
    }
  }

  printf("%d\n", ans);
  return 0;
}