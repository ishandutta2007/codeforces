#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int N = (int)3e5 + 34;

vector<int> es[N];
map<int, ll> ds;
ll val[N];
vector<pair<int, int>> d[N];
int depth[N];

void dfs(int v, int pr, ll sum) {
  for (auto &[dep, val] : d[v]) {
    ds[depth[v]] += val;
    ds[depth[v] + dep + 1] -= val;
  }

  sum += ds[depth[v]];
  val[v] = sum;

  for (int w : es[v]) {
    if (w == pr) continue;
    depth[w] = depth[v] + 1;
    dfs(w, v, sum);
  }  

  for (auto &[dep, val] : d[v]) {
    ds[depth[v]] -= val;
    ds[depth[v] + dep + 1] += val; 
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int n;
  cin >> n;
  for (int i = 0; i < n - 1; i++) {
    int v1, v2;
    cin >> v1 >> v2;
    v1--;
    v2--;
    es[v1].push_back(v2);
    es[v2].push_back(v1);
  }

  int q;
  cin >> q;
  depth[0] = 0;
  while (q--) {
    int v, a, b;
    cin >> v >> a >> b;
    d[v - 1].emplace_back(a, b);
  }

  dfs(0, -1, 0ll);

  for (int i = 0; i < n; i++) {
    cout << val[i] << " ";
  }
  cout << "\n";

  return 0;
}