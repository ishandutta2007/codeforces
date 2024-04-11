#include <bits/stdc++.h>
using namespace std;
const int MAXN = 200100;
int D[MAXN];
int Q[MAXN];
int ways[MAXN];
vector<int> ed[MAXN], red[MAXN];
int ql = 0, qr = 0;

void push(int n, int d) {
  if (D[n]) return;
  D[n] = d;
  Q[qr++] = n;
}

void bfs(int src) {
  push(src, 1);
  while (ql < qr) {
    int cur = Q[ql++];
    int d = D[cur];
    for (int nxt: ed[cur]) {
      push(nxt, d + 1);
    }
  }
}

int path[MAXN];
int main() {
  int n, m, k;
  cin >> n >> m;
  for (int i = 0; i < m; ++i) {
    int a, b;
    cin >> a >> b;
    ed[b].push_back(a);
    red[a].push_back(b);
  }

  cin >> k;
  for(int i = 0; i < k; ++i) {
    cin >> path[i];
  }
  bfs(path[k - 1]);
  int ans1 = 0, ans2 = 0;
  for (int i = 0; i < k - 1; ++i) {
    int cur = path[i];
    int cnt = 0;
    for (int nxt: red[cur]) {
      if (D[nxt] == D[cur] - 1) ++cnt;
    }
    if (D[path[i + 1]] > D[cur] - 1) {
      ++ans1;
      ++ans2;
    } else {
      if (cnt > 1) ++ans2;
    }
  }

  cout << ans1 << " " << ans2 << "\n";
}