#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;
const int MAXN = 200100;
int q[MAXN];
int ql, qr;
vector<int> D(MAXN);
int vis[MAXN];
vector<int> ed[MAXN];
void push(int cur, int d) {
  if (vis[cur]) return;
  vis[cur] = true;
  q[qr] = cur;
  D[cur] = d;
  ++qr;
}

void bfs(int start) {
  memset(vis, 0, sizeof(vis));
  ql = qr = 0;
  push(start, 0);
  while (ql < qr) {
    int cur = q[ql];
    ++ql;
    for (int i: ed[cur]) {
      push(i, D[cur] + 1);
    }
  }
}

int main() {
  int n, m, k;
  cin >> n >> m >> k;
  vector<int> special;
  for (int i = 0; i < k; ++i) {
    int x;
    cin >> x;
    special.push_back(x);
  }
  for (int i = 0; i < m; ++i) {
    int a, b;
    cin >> a >> b;
    ed[a].push_back(b);
    ed[b].push_back(a);
  }

  bfs(1);
  vector<int> d1 = D;
  bfs(n);
  vector<int> d2 = D;
  vector<pii> v;
  for (int i: special) {
    v.push_back(pii(d1[i], i));
  }
  sort(v.begin(), v.end());
  int ans = 0;
  for (int i = 0; i + 1 < v.size(); i += 1) {
    int val = d1[v[i].second] + 1 + d2[v[i + 1].second];
    ans = max(ans, val);
  }
  ans = min(ans, d1[n]);
  cout << ans << "\n";
}