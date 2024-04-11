#include <bits/stdc++.h>

using namespace std;

int main() {
#ifdef wxh010910
  freopen("input.txt", "r", stdin);
#endif
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int n, m, q;
  cin >> n >> m >> q;
  vector<int> p(n);
  for (int i = 0; i < n; ++i) {
    cin >> p[i];
    --p[i];
  }
  vector<int> nxt(n);
  for (int i = 0; i < n; ++i) {
    nxt[p[i]] = p[(i + 1) % n];
  }
  vector<int> a(m);
  for (int i = 0; i < m; ++i) {
    cin >> a[i];
    --a[i];
  }
  vector<int> pos(n, m);
  vector<int> to(m);
  for (int i = m - 1; ~i; --i) {
    to[i] = pos[nxt[a[i]]];
    pos[a[i]] = i;
  }
  vector<vector<int>> adj(m + 1);
  for (int i = 0; i < m; ++i) {
    adj[to[i]].push_back(i);
  }
  vector<int> ans(m, m);
  vector<int> st;
  function<void(int)> dfs = [&](int x) {
    st.push_back(x);
    if ((int) st.size() >= n) {
      ans[x] = st[st.size() - n];
    }
    for (auto y : adj[x]) {
      dfs(y);
    }
    st.pop_back();
  };
  dfs(m);
  for (int i = m - 2; ~i; --i) {
    ans[i] = min(ans[i], ans[i + 1]);
  }
  while (q--) {
    int l, r;
    cin >> l >> r;
    --l;
    --r;
    cout << (ans[l] <= r ? 1 : 0);
  }
  cout << "\n";
  return 0;
}