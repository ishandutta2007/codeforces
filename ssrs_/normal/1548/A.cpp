#include <bits/stdc++.h>
using namespace std;
int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n, m;
  cin >> n >> m;
  vector<set<int>> st(n);
  for (int i = 0; i < n; i++){
    st[i].insert(-1);
  }
  for (int i = 0; i < m; i++){
    int u, v;
    cin >> u >> v;
    u--;
    v--;
    st[u].insert(v);
    st[v].insert(u);
  }
  int cnt = 0;
  for (int i = 0; i < n; i++){
    if (*prev(st[i].end()) < i){
      cnt++;
    }
  }
  int q;
  cin >> q;
  for (int i = 0; i < q; i++){
    int t;
    cin >> t;
    if (t == 1 || t == 2){
      int u, v;
      cin >> u >> v;
      u--;
      v--;
      if (*prev(st[u].end()) < u){
        cnt--;
      }
      if (*prev(st[v].end()) < v){
        cnt--;
      }
      if (t == 1){
        st[u].insert(v);
        st[v].insert(u);
      }
      if (t == 2){
        st[u].erase(v);
        st[v].erase(u);
      }
      if (*prev(st[u].end()) < u){
        cnt++;
      }
      if (*prev(st[v].end()) < v){
        cnt++;
      }
    }
    if (t == 3){
      cout << cnt << "\n";
    }
  }
}