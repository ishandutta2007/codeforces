#include <bits/stdc++.h>
using namespace std;
int INF = 100000000;
int main(){
  int n, m, k;
  cin >> n >> m >> k;
  vector<vector<int>> E(n);
  for (int i = 0; i < m; i++){
    int u, v;
    cin >> u >> v;
    u--;
    v--;
    E[u].push_back(v);
    E[v].push_back(u);
  }
  for (int i = 0; i < n; i++){
    sort(E[i].begin(), E[i].end());
  }
  if (m == n - 1){
    //Tree
    vector<int> c(n, -1);
    c[0] = 0;
    queue<int> Q;
    Q.push(0);
    while (!Q.empty()){
      int v = Q.front();
      Q.pop();
      for (auto w : E[v]){
        if (c[w] == -1){
          c[w] = 1 - c[v];
          Q.push(w);
        }
      }
    }
    vector<int> a(2, 0);
    for (int i = 0; i < n; i++){
      a[c[i]]++;
    }
    int color;
    if (a[0] >= a[1]){
      color = 0;
    } else {
      color = 1;
    }
    vector<int> ans;
    for (int i = 0; i < n; i++){
      if (c[i] == color){
        ans.push_back(i + 1);
      }
    }
    cout << 1 << endl;
    int s = (k + 1) / 2;
    for (int i = 0; i < s; i++){
      cout << ans[i];
      if (i < s - 1){
        cout << ' ';
      }
    }
    cout << endl;
  } else {
    //find a cycle
    vector<int> d(n, INF);
    d[0] = 0;
    vector<int> prev(n, -1);
    queue<int> Q;
    Q.push(0);
    int c1 = -1, c2 = -1;
    while (!Q.empty()){
      int v = Q.front();
      Q.pop();
      for (int w : E[v]){
        if (d[w] == INF){
          prev[w] = v;
          d[w] = d[v] + 1;
          Q.push(w);
        } else {
          if (prev[v] != w){
            c1 = w;
            c2 = v;
            break;
          }
        }
      }
      if (c1 != -1){
        break;
      }
    }
    /*
    for (int i = 0; i < n; i++){
        cout << d[i] << ' ';
    }
    cout << endl;
    for (int i = 0; i < n; i++){
        cout << prev[i] << ' ';
    }
    cout << endl;
    cout << "c1 = " << c1 << ", c2 = " << c2 << endl;
    */
    vector<int> cycle;
    cycle.push_back(c1);
    while (cycle.back() != 0){
      int v = prev[cycle.back()];
      cycle.push_back(v);
    }
    set<int> st_c1;
    for (int i : cycle){
      st_c1.insert(i);
    }
    vector<int> cycle2;
    cycle2.push_back(c2);
    while (!st_c1.count(cycle2.back())){
      int v = prev[cycle2.back()];
      cycle2.push_back(v);
    }
    int L = cycle2.back();
    cycle2.pop_back();
    while (cycle.back() != L){
      cycle.pop_back();
    }
    while (!cycle2.empty()){
      cycle.push_back(cycle2.back());
      cycle2.pop_back();
    }
    int sz = cycle.size();
    if (sz <= k){
      cout << 2 << endl;
      cout << sz << endl;
      for (int i = 0; i < sz; i++){
        cout << cycle[i] + 1;
        if (i < sz - 1){
          cout << ' ';
        }
      }
      cout << endl;
    } else {
      int s = (k + 1) / 2;
      vector<int> ans;
      for (int i = 0; i < sz; i += 2){
        ans.push_back(cycle[i] + 1);
      }
      cout << 1 << endl;
      for (int i = 0; i < s; i++){
        cout << ans[i];
        if (i < s - 1){
          cout << ' ';
        }
      }
      cout << endl;
    }
  }
}