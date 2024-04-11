#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

const int N = 200005;
int n, m;
vector<int> e[N], r[N];
int deg[N];
char res[N];
bool vis1[N], vis2[N];

void dfs1(int x) {
  if (vis1[x]) return;
  vis1[x] = 1;
  for (auto &y : e[x]) dfs1(y);
}

void dfs2(int x) {
  if (vis2[x]) return;
  vis2[x] = 1;
  for (auto &y : r[x]) dfs2(y);
}

int main() {
  scanf("%d%d", &n, &m);
  for (int i = 0; i < m; ++i) {
    int x, y;
    scanf("%d%d", &x, &y);
    e[x].emplace_back(y);
    r[y].emplace_back(x);
    ++deg[y];
  }

  queue<int> Q;
  for (int i = 1; i <= n; ++i) {
    if (!deg[i]) {
      Q.push(i);
    }
  }
  int cnt = 0, num = 0;
  while (!Q.empty()) {
    int x = Q.front();
    Q.pop();
    ++cnt;
    for (auto &y : e[x]) {
      if (!--deg[y]) {
        Q.push(y);
      }
    }
  }
  if (cnt < n) {
    puts("-1");
    return 0;
  }

  for (int x = 1; x <= n; ++x) {
    if (vis1[x] || vis2[x]) {
      res[x] = 'E';
    } else {
      ++num;
      res[x] = 'A';
    }
    dfs1(x);
    dfs2(x);
  }
  printf("%d\n", num);
  puts(res + 1);
}