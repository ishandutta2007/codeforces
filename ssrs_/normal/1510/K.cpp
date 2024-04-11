#include <bits/stdc++.h>
using namespace std;
const int INF = 1000000;
int main(){
  int n;
  cin >> n;
  vector<int> p(n * 2);
  for (int i = 0; i < n * 2; i++){
    cin >> p[i];
    p[i]--;
  }
  vector<vector<int>> P(n * 2, vector<int>(n * 2));
  for (int i = 0; i < n * 2; i++){
    P[0][i] = i;
  }
  for (int i = 0; i < n * 2 - 1; i++){
    P[i + 1] = P[i];
    for (int j = 0; j < n; j++){
      if (i % 2 == 0){
        swap(P[i + 1][j * 2], P[i + 1][j * 2 + 1]);
      } else {
        swap(P[i + 1][j], P[i + 1][n + j]);
      }
    }
  }
  int ans = INF;
  for (int i = 0; i < n * 2; i++){
    if (P[i] == p){
      ans = min(ans, min(i, n * 2 - i));
    }
  }
  if (ans == INF){
    cout << -1 << endl;
  } else {
    cout << ans << endl;
  }
}