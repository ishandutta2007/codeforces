#include <bits/stdc++.h>
using namespace std;
int main(){
  int n, m, c, q;
  cin >> n >> m >> c >> q;
  vector<tuple<char, int, int, int>> query(m + q);
  for (int i = 0; i < m; i++){
    int x, y, z;
    cin >> x >> y >> z;
    x--;
    y--;
    query[i] = make_tuple('+', x, y, z);
  }
  for (int i = m; i < m + q; i++){
    char c;
    cin >> c;
    if (c == '+'){
      int x, y, z;
      cin >> x >> y >> z;
      x--;
      y--;
      query[i] = make_tuple('+', x, y, z);
    }
    if (c == '?'){
      int x, y;
      cin >> x >> y;
      x--;
      y--;
      query[i] = make_tuple('?', x, y, -1);
    }
  }
  vector<set<int>> co(n);
  for (int i = 0; i < n; i++){
    co[i].insert(0);
  }
  for (int i = 0; i < m + q; i++){
    if (get<0>(query[i]) == '+'){
      int x = get<1>(query[i]);
      int y = get<2>(query[i]);
      int z = get<3>(query[i]);
      co[x].insert(z);
      co[y].insert(z);
    }
  }
  vector<pair<int, int>> t;
  for (int i = 0; i < n; i++){
    for (int j : co[i]){
      t.push_back(make_pair(i, j));
    }
  }
  int V = t.size();
  vector<map<int, int>> id(n);
  for (int i = 0; i < V; i++){
    id[t[i].first][t[i].second] = i;
  }
  vector<int> p(V);
  vector<vector<int>> g(V);
  vector<set<int>> st(V);
  for (int i = 0; i < V; i++){
    p[i] = i;
    g[i].push_back(i);
    st[i].insert(t[i].first);
  }
  for (int i = 0; i < m + q; i++){
    char c = get<0>(query[i]);
    if (c == '+'){
      int x = get<1>(query[i]);
      int y = get<2>(query[i]);
      int z = get<3>(query[i]);
      vector<int> u = {id[x][0], id[y][0]};
      vector<int> v = {id[y][z], id[x][z]};
      for (int j = 0; j < 2; j++){
        u[j] = p[u[j]];
        v[j] = p[v[j]];
        if (u[j] != v[j]){
          if (g[u[j]].size() > g[v[j]].size()){
            swap(u[j], v[j]);
          }
          for (int k : g[u[j]]){
            g[v[j]].push_back(k);
            p[k] = v[j];
          }
          for (int k : st[u[j]]){
            st[v[j]].insert(k);
          }
        }
      }
    }
    if (c == '?'){
      int x = get<1>(query[i]);
      int y = get<2>(query[i]);
      int v = id[x][0];
      v = p[v];
      if (st[v].count(y)){
        cout << "Yes" << endl;
      } else {
        cout << "No" << endl;
      }
    }
  }
}