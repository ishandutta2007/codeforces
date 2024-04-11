#include <bits/stdc++.h>
using namespace std;
int main(){
  random_device rnd;
  mt19937 mt(rnd());
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n, m;
  cin >> n >> m;
  vector<int> u(m), v(m);
  for (int i = 0; i < m; i++){
    cin >> u[i] >> v[i];
    u[i]--;
    v[i]--;
  }
  vector<int> d(n, 0);
  for (int i = 0; i < m; i++){
    d[u[i]]++;
    d[v[i]]++;
  }
  vector<int> p(m);
  for (int i = 0; i < m; i++){
    p[i] = i;
  }
  shuffle(p.begin(), p.end(), mt);
  vector<int> u2(m), v2(m);
  for (int i = 0; i < m; i++){
    u2[i] = u[p[i]];
    v2[i] = v[p[i]];
  }
  swap(u, u2);
  swap(v, v2);
  vector<int> f = d;
  vector<pair<int, int>> ans;
  for (int i = 0; i < m; i++){
    if (f[u[i]] - 1 >= (d[u[i]] + 1) / 2 && f[v[i]] - 1 >= (d[v[i]] + 1) / 2){
      f[u[i]]--;
      f[v[i]]--;
    } else {
      ans.push_back(make_pair(u[i], v[i]));
    }
  }
  int k = ans.size();
  cout << k << endl;
  for (int i = 0; i < k; i++){
    cout << ans[i].first + 1 << ' ' << ans[i].second + 1 << "\n";
  }
}