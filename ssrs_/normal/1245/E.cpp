#include <bits/stdc++.h>
using namespace std;
int main(){
  cout << fixed << setprecision(20);
  vector<vector<int>> h(10, vector<int>(10));
  for (int i = 0; i < 10; i++){
    for (int j = 0; j < 10; j++){
      cin >> h[i][j];
    }
  }
  vector<vector<int>> id(10, vector<int>(10));
  int cnt = 0;
  for (int i = 9; i >= 0; i--){
    if (i % 2 == 1){
      for (int j = 0; j < 10; j++){
        id[i][j] = cnt;
        cnt++;
      }
    }
    if (i % 2 == 0){
      for (int j = 9; j >= 0; j--){
        id[i][j] = cnt;
        cnt++;
      }
    }
  }
  vector<int> l(100, -1);
  for (int i = 0; i < 10; i++){
    for (int j = 0; j < 10; j++){
      if (h[i][j] != 0){
        l[id[i][j]] = id[i - h[i][j]][j];
      }
    }
  }
  vector<double> dp(100, 0);
  for (int i = 98; i >= 0; i--){
    int next = 0;
    for (int j = 1; j <= 6; j++){
      if (i + j <= 99){
        next++;
        if (l[i + j] == -1){
          dp[i] += dp[i + j];
        } else {
          dp[i] += min(dp[i + j], dp[l[i + j]]);
        }
      }
    }
    dp[i] /= next;
    dp[i] += (double) 6 / next;
  }
  cout << dp[0] << endl;
}