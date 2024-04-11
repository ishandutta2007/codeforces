#include <bits/stdc++.h>
using namespace std;
int main(){
  int n;
  cin >> n;
  map<pair<int, int>, int> M;
  vector<int> value(n - 1, -1);
  vector<set<int>> E(n);
  for (int i = 0; i < n - 1; i++){
    int u, v;
    cin >> u >> v;
    u--;
    v--;
    M[make_pair(u, v)] = i;
    M[make_pair(v, u)] = i;
    E[u].insert(v);
    E[v].insert(u);
  }
  int cnt = 0;
  for (int i = 0; i < n; i++){
    for (int j : E[i]){
      if (E[i].size() == 1 && value[M[make_pair(i, j)]] == -1){
        value[M[make_pair(i, j)]] = cnt;
        cnt++;
      }
    }
  }
  for (int i = 0; i < n - 1; i++){
    if (value[i] == -1){
      value[i] = cnt;
      cnt++;
    }
    cout << value[i] << endl;
  }
}