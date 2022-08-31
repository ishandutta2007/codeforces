#include <bits/stdc++.h>
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()

using namespace std;

vector<vector<int>> e;
vector<int> p2;
vector<char> vis;

bool dfs(int v) {
  if (vis[v]) return false;
  vis[v] = 1;
  for (int nv : e[v]) {
    if (p2[nv] == -1 || dfs(p2[nv])) {
      p2[nv] = v;
      return true;
    }
  }
  return false;
}

int main() {
  ios::sync_with_stdio(false);
  int d, n;
  cin >> d >> n;
  e.resize(n);
  p2.resize(n, -1);
  vector<int> mask(n, 0);
  for (int i = 0; i < n; ++i) {
    string s;
    cin >> s;
    for (int j = 0; j < d; ++j)
      if (s[j] == '1')
        mask[i] |= (1 << j);
  }

  for (int i = 0; i < n; ++i)
    for (int j = 0; j < n; ++j)
      if (i != j && (mask[i] & mask[j]) == mask[i])
        e[i].push_back(j);

  vector<int> order(n);
  iota(all(order), 0);
  sort(all(order), [&](int x, int y) { 
    return __builtin_popcount(mask[x]) > __builtin_popcount(mask[y]);
  });

  vis.resize(n);
  for (int i : order) {
    fill(all(vis), 0);
    dfs(i);
  }

  fill(all(vis), 0);
  vector<int> p1(n, -1);
  for (int i = 0; i < n; ++i)
    if (p2[i] != -1)
      p1[p2[i]] = i;

  string ans;
  for (int i = 0; i < n; ++i) {
    if (vis[i] || p2[i] != -1) continue;
    int j = i;
    for (int k = 0; k < d; ++k)
      if (mask[j] & (1 << k))
        ans += char('0' + k);
    while (p1[j] != -1) {
      vis[j] = 1;
      int m = mask[j] ^ mask[p1[j]];
      for (int k = 0; k < d; ++k)
        if (m & (1 << k))
          ans += char('0' + k);
      j = p1[j];
    }
    ans += 'R';
  }
  ans.pop_back();

  cout << sz(ans) << "\n";
  for (char c : ans)
    cout << c << " ";
  cout << "\n";
}