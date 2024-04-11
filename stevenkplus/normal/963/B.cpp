#include <bits/stdc++.h>
using namespace std;

const int MAXN = 200100;
vector<int> ed[MAXN];

int sz[MAXN];

void dfs1(int cur, int par=-1) {
  vector<int> &v = ed[cur];
  sz[cur] = 1;
  for(int i = 0; i < v.size(); ++i) {
    int nxt = v[i];
    if (nxt == par) continue;
    dfs1(nxt, cur);
    sz[cur] += sz[nxt];
  }
}

vector<int> ans;

void dfs2(int cur, int par=-1) {
  // cerr << "dfs2 " << cur << "(" << par << ")" << "\n";
  vector<int> &v = ed[cur];
  for(int i = 0; i < v.size(); ++i) {
    int nxt = v[i];
    if (nxt == par) continue;
    if (sz[nxt] % 2 == 0) {
      dfs2(nxt, cur);
    }
  }

  ans.push_back(cur);

  for(int i = 0; i < v.size(); ++i) {
    int nxt = v[i];
    if (nxt == par) continue;
    if (sz[nxt] % 2 == 1) {
      dfs2(nxt, cur);
    }
  }
}

int n;
int main() {
  cin >> n;
  if (n % 2 == 0) {
    cout << "NO" << "\n";
    return 0;
  }
  for(int i = 1; i <= n; ++i) {
    int p;
    cin >> p;
    if (p) {
      ed[i].push_back(p);
      ed[p].push_back(i);
    }
  }

  dfs1(1);
  dfs2(1);

  cout << "YES\n";
  for(int i = 0; i < n; ++i) {
    cout << ans[i] << "\n";
  }
}