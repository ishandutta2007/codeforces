#include <cstdio>
#include <vector>
#include <cstring>
#include <algorithm>

using namespace std;

const int MAXN = 111;

#define source 0
#define sink (N + 1)

int N, M;

vector<int> guys[MAXN]; // guys[x]: y s.t. ar[y] are factors of a[x]

int a[MAXN];
bool adj[MAXN][MAXN];

int cap[MAXN][MAXN]; // cap[x][y]: capacity x->y

bool vis[MAXN];

bool dfs(int cur) {
//  printf("dfs at %d\n", cur);
  if (cur == sink) return true;

  if (vis[cur]) return false;
  vis[cur] = true;

  for(int i = 1; i <= N + 1; ++i) {
    if (cap[cur][i]) {
      --cap[cur][i];
      if (dfs(i)) {
        ++cap[i][cur];
        return true;
      } else {
        ++cap[cur][i];
      }
    }
  }

  return false;
}

bool push() {
  memset(vis, 0, sizeof(vis));
  return dfs(source);
}

int go(int x) {
  if (x == 1) return 0;
//  printf("go %d\n", x);
  int ans = 0;
  memset(cap, 0, sizeof(cap));
  for(int i = 1; i <= N; ++i) {
    while (a[i] % x == 0) {
      a[i] /= x;
      if (i % 2 == 0) {
        ++cap[source][i];
      } else {
        ++cap[i][sink];
      }
    }
  }

  for(int i = 1; i <= N; ++i) {
    for(int j = 1; j <= N; ++j) {
      if (adj[i][j]) {
        cap[i][j] = cap[source][i] + cap[j][sink];
      }
    }
  }


  while (push()) {
//      printf("success at x = %d\n", x);
    ++ans;
  }
  return ans;
}

int main() {
  scanf("%d %d", &N, &M);
//  source = 0, sink = 0

  for(int i = 1; i <= N; ++i) {
    scanf("%d", a + i);
  }

  for(int i = 0; i < M; ++i) {
    int x, y;
    scanf("%d %d", &x, &y);
    if (x % 2 == 1) {
      swap(x, y);
    }

    adj[x][y] = true;
  }

//  printf("starting.\n");
  int ans = 0;
  for(int x = 2; x < 100000; ++x) {
    ans += go(x);
  }

  for(int i = 1; i <= N; ++i) {
    ans += go(a[i]);
  }

  printf("%d\n", ans);
}