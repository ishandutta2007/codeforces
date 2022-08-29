#include <bits/stdc++.h>
using namespace std;
int main(){
  int n;
  cin >> n;
  vector<vector<int>> E(n);
  for (int i = 0; i < n - 1; i++){
    int a, b;
    cin >> a >> b;
    a--;
    b--;
    E[a].push_back(b);
    E[b].push_back(a);
  }
  vector<int> leaf;
  for (int i = 0; i < n; i++){
    if (E[i].size() == 1){
      leaf.push_back(i);
    }
  }
  map<int, int> leaf2;
  for (int i : leaf){
    leaf2[E[i][0]]++;
  }
  vector<int> c(n, -1);
  c[0] = 0;
  queue<int> Q;
  Q.push(0);
  while (!Q.empty()){
    int v = Q.front();
    Q.pop();
    for (int w : E[v]){
      if (c[w] == -1){
        c[w] = 1 - c[v];
        Q.push(w);
      }
    }
  }
  bool one = true;
  for (int i = 1; i < leaf.size(); i++){
    if (c[leaf[i]] != c[leaf[0]]){
      one = false;
    }
  }
  if (one){
    cout << 1;
  } else {
    cout << 3;
  }
  cout << ' ';
  int ans = n - 1;
  for (auto P : leaf2){
    ans -= P.second - 1;
  }
  cout << ans << endl;
}