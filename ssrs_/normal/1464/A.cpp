#include <bits/stdc++.h>
using namespace std;
int main(){
  int t;
  cin >> t;
  for (int i = 0; i < t; i++){
    int n, m;
    cin >> n >> m;
    vector<int> x(m), y(m);
    for (int j = 0; j < m; j++){
      cin >> x[j] >> y[j];
      x[j]--;
      y[j]--;
    }
    vector<vector<int>> E(n);
    for (int j = 0; j < m; j++){
      E[x[j]].push_back(y[j]);
      E[y[j]].push_back(x[j]);
    }
    vector<int> c(n, -1);
    int cnt = 0;
    for (int j = 0; j < n; j++){
      if (c[j] == -1){
        c[j] = cnt;
        queue<int> Q;
        Q.push(j);
        while (!Q.empty()){
          int v = Q.front();
          Q.pop();
          for (int w : E[v]){
            if (c[w] == -1){
              c[w] = cnt;
              Q.push(w);
            }
          }
        }
        cnt++;
      }
    }
    vector<int> c1(cnt, 0);
    for (int j = 0; j < n; j++){
      c1[c[j]]++;
    }
    vector<int> c2(cnt, 0);
    for (int j = 0; j < m; j++){
      c2[c[x[j]]]++;
    }
    int ans = 0;
    for (int j = 0; j < cnt; j++){
      if (c1[j] >= 2){
        if (c2[j] == c1[j]){
          ans += c1[j] + 1;
        } else {
          ans += c1[j] - 1;
        }
      }
    }
    cout << ans << endl;
  }
}