#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> pii;
const int MAXN = 100100;
const int MAXK = 110;
int ans[MAXK][MAXN];
vector<int> ed[MAXN];
int type[MAXN];

pii Q[MAXN];
bool vis[MAXN];
int ql, qr;

void psh(int x, int d) {
  if (vis[x]) return;
  vis[x] = true;
  Q[qr++] = pii(x, d);
}

int n, m;
void solve(int color) {
  for(int i = 1; i <= n; ++i) {
    vis[i] = false;
  }
  ql = qr = 0;
  for(int i = 1; i <= n; ++i) {
    if (type[i] == color) {
      psh(i, 0);
    }
  }

  while (ql < qr) {
    pii p = Q[ql++];
    ans[color][p.first] = p.second;
    for(auto nxt: ed[p.first]) {
      psh(nxt, p.second + 1);
    }
  }
}

int main() {
  int k, s;
  cin >> n >> m >> k >> s;

  for(int i = 1; i <= n; ++i) {
    cin >> type[i];
  }
  for(int i = 0; i < m; ++i) {
    int a, b;
    cin >> a >> b;
    ed[a].push_back(b);
    ed[b].push_back(a);
  }

  for(int i = 1; i <= k; ++i) {
    solve(i);
  }

  for(int i = 1; i <= n; ++i) {
    vector<int> v;
    for(int j = 1; j <= k; ++j) {
      v.push_back(ans[j][i]);
    }
    sort(v.begin(), v.end());
    int sum = 0;
    for(int i = 0; i < s; ++i) {
      sum += v[i];
    }
    cout << sum << "\n";
  }
}