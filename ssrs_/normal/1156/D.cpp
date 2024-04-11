#include <bits/stdc++.h>
using namespace std;
int main(){
  int n;
  cin >> n;
  vector<vector<vector<int>>> E(2, vector<vector<int>>(n));
  for (int i = 0; i < n - 1; i++){
    int x, y, c;
    cin >> x >> y >> c;
    x--;
    y--;
    E[c][x].push_back(y);
    E[c][y].push_back(x);
  }
  vector<vector<int>> s(2, vector<int>(n));
  for (int i = 0; i < 2; i++){
    vector<bool> used(n, false);
    for (int j = 0; j < n; j++){
      if (!used[j]){
        used[j] = true;
        vector<int> b;
        queue<int> Q;
        Q.push(j);
        while (!Q.empty()){
          int v = Q.front();
          Q.pop();
          b.push_back(v);
          for (int w : E[i][v]){
            if (!used[w]){
              used[w] = true;
              Q.push(w);
            }
          }
        }
        for (int v : b){
          s[i][v] = b.size();
        }
      }
    }
  }
  long long ans = 0;
  for (int i = 0; i < n; i++){
    ans += (long long) s[0][i] * s[1][i];
  }
  ans -= n;
  cout << ans << endl;
}