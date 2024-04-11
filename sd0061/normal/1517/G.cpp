#include <bits/stdc++.h>

using namespace std;
using int64 = long long;

const int N = 2005;

int pre[N], mcnt, s, t;
struct arc {
  int x;
  int64 f;
  int next;
} e[N * N];
void addarc(int x, int y, int64 z) {
  e[mcnt] = (arc){y, z, pre[x]}, pre[x] = mcnt++;
  e[mcnt] = (arc){x, 0, pre[y]}, pre[y] = mcnt++;
}
int d[N], cur[N], q[N];
bool bfs() {
  memset(d, -1, sizeof(d));
  int top = 0, bot = -1;
  q[++bot] = t, d[t] = 1;
  while (top != bot + 1) {
    int x = q[top++];
    for (int i = pre[x]; ~i; i = e[i].next) {
      int y = e[i].x;
      if (!~d[y] && e[i ^ 1].f) {
        d[y] = d[x] + 1, q[++bot] = y;
        if (y == s) return 1;
      }
    }
  }
  return 0;
}
int64 dfs(int x, int64 flow = 1LL << 60) {
  if (x == t || !flow) return flow;
  int64 sum = 0;
  for (int& i = cur[x]; ~i; i = e[i].next) {
    int y = e[i].x;
    int64 u;
    if (d[x] == d[y] + 1 && (u = dfs(y, min(flow, e[i].f)))) {
      e[i].f -= u, e[i ^ 1].f += u;
      sum += u, flow -= u;
      if (!flow) break;
    }
  }
  if (!sum) d[x] = -1;
  return sum;
}
int64 dinic() {
  int64 ans = 0;
  while (bfs()) {
    memcpy(cur, pre, sizeof(cur));
    ans += dfs(s);
  }
  return ans;
}

int n;
int X[N], Y[N];

int main() {
  scanf("%d", &n);
  mcnt = 0;
  memset(pre, -1, sizeof(pre));
  int64 sum = 0;
  s = n + n, t = s + 1;
  auto GetType = [&](int i) -> int {
    if (Y[i] % 2) {
      return 2 | (X[i] & 1);
    } else {
      return (~X[i] & 1);
    }
  };
  for (int i = 0; i < n; ++i) {
    int w;
    scanf("%d%d%d", &X[i], &Y[i], &w);
    addarc(i << 1, i << 1 | 1, w);
    sum += w;
    int type = GetType(i);
    if (type == 0) {
      addarc(s, i << 1, 1LL << 60);
    }
    if (type == 3) {
      addarc(i << 1 | 1, t, 1LL << 60);
    }
  }
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      if (abs(X[i] - X[j]) + abs(Y[i] - Y[j]) <= 1) {
        int type_i = GetType(i);
        int type_j = GetType(j);
        if (type_j == type_i + 1) {
          addarc(i << 1 | 1, j << 1, 1LL << 60);
        }
      }
    }
  }
  cout << sum - dinic() << endl;
}