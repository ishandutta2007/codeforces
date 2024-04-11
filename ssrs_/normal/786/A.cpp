#include <bits/stdc++.h>
using namespace std;
int main(){
  int n;
  cin >> n;
  int k1;
  cin >> k1;
  vector<int> s1(k1);
  for (int i = 0; i < k1; i++){
    cin >> s1[i];
  }
  int k2;
  cin >> k2;
  vector<int> s2(k2);
  for (int i = 0; i < k2; i++){
    cin >> s2[i];
  }
  vector<vector<int>> deg(n, vector<int>(2));
  deg[0][0] = 0;
  deg[0][1] = 0;
  for (int i = 1; i < n; i++){
    deg[i][0] = k1;
    deg[i][1] = k2;
  }
  vector<vector<int>> dp(n, vector<int>(2, 0));
  dp[0][0] = -1;
  dp[0][1] = -1;
  vector<vector<bool>> used(n, vector<bool>(2, false));
  used[0][0] = true;
  used[0][1] = true;
  queue<pair<int, int>> Q;
  Q.push(make_pair(0, 0));
  Q.push(make_pair(0, 1));
  while (!Q.empty()){
    int pos = Q.front().first;
    int t = Q.front().second;
    Q.pop();
    if (t == 0){
      for (int i = 0; i < k2; i++){
        int pos0 = (pos - s2[i] + n) % n;
        if (!used[pos0][1]){
          deg[pos0][1]--;
          if (dp[pos][0] == -1){
            dp[pos0][1] = 1;
            used[pos0][1] = true;
            Q.push(make_pair(pos0, 1));
          } else if (dp[pos][0] == 1){
            if (deg[pos0][1] == 0){
              dp[pos0][1] = -1;
              used[pos0][1] = true;
              Q.push(make_pair(pos0, 1));
            }
          }
        }
      }
    } else {
      for (int i = 0; i < k1; i++){
        int pos0 = (pos - s1[i] + n) % n;
        if (!used[pos0][0]){
          deg[pos0][0]--;
          if (dp[pos][1] == -1){
            dp[pos0][0] = 1;
            used[pos0][0] = true;
            Q.push(make_pair(pos0, 0));
          } else if (dp[pos][1] == 1){
            if (deg[pos0][0] == 0){
              dp[pos0][0] = -1;
              used[pos0][0] = true;
              Q.push(make_pair(pos0, 0));
            }
          }
        }
      }
    }
  }
  for (int i = 0; i < 2; i++){
    for (int j = 1; j < n; j++){
      if (dp[j][i] == 1){
        cout << "Win";
      }
      if (dp[j][i] == 0){
        cout << "Loop";
      }
      if (dp[j][i] == -1){
        cout << "Lose";
      }
      if (j < n - 1){
        cout << ' ';
      }
    }
    cout << endl;
  }
}