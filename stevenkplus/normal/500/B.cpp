#include <cstdio>
#include <algorithm>

using namespace std;

const int MAXN = 310;

char adj[MAXN][MAXN];
bool vis[MAXN];
int ar[MAXN];

int len = 0;
int guys[MAXN];
int vals[MAXN];

int N;

void dfs(int cur) {
  if (vis[cur]) return;
  vis[cur] = true;
  guys[len] = cur;
  ++len;

  for(int i = 0; i < N; ++i) {
    if (adj[cur][i] == '1') dfs(i);
  }
}

void sortguys() {
  for(int i = 0; i < len; ++i) {
    vals[i] = ar[guys[i]];
  }
  sort(vals, vals + len);
  sort(guys, guys + len);
  for(int i = 0; i < len; ++i) {
    ar[guys[i]] = vals[i];
  }
}


int main() {
  scanf("%d", &N);
  for(int i = 0; i < N; ++i) {
    scanf("%d", ar + i);
  }

  for(int i = 0; i < N; ++i) {
    scanf("%s", adj[i]);
  }

  for(int i = 0; i < N; ++i) {
    if (!vis[i]) {
      len = 0;
      dfs(i);
      sortguys();
    }
  }

  for(int i = 0; i < N; ++i) {
    printf("%d ", ar[i]);
  }
  printf("\n");
  return 0;
}