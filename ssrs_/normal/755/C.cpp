#include <bits/stdc++.h>
using namespace std;
int main(){
  int n;
  cin >> n;
  vector<int> p(n);
  for (int i = 0; i < n; i++){
    cin >> p[i];
    p[i]--;
  }
  vector<vector<int>> E(n);
  for (int i = 0; i < n; i++){
    E[i].push_back(p[i]);
    E[p[i]].push_back(i);
  }
  vector<bool> used(n, false);
  int ans = 0;
  for (int i = 0; i < n; i++){
    if (!used[i]){
      used[i] = true;
      ans++;
      queue<int> Q;
      Q.push(i);
      while (!Q.empty()){
        int v = Q.front();
        Q.pop();
        for (int w : E[v]){
          if (!used[w]){
            used[w] = true;
            Q.push(w);
          }
        }
      }
    }
  }
  cout << ans << endl;
}