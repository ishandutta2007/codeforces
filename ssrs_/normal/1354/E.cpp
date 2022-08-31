#include <bits/stdc++.h>
using namespace std;
int main(){
  int n, m;
  cin >> n >> m;
  int n1, n2, n3;
  cin >> n1 >> n2 >> n3;
  vector<vector<int>> E(n);
  for (int i = 0; i < m; i++){
    int u, v;
    cin >> u >> v;
    u--;
    v--;
    E[u].push_back(v);
    E[v].push_back(u);
  }
  vector<int> color1(n, -1);
  vector<pair<vector<int>, vector<int>>> C;
  bool flg = false;
  for (int i = 0; i < n; i++){
    if (color1[i] == -1){
      queue<int> Q;
      Q.push(i);
      color1[i] = 0;
      vector<int> A, B;
      A.push_back(i);
      while (!Q.empty()){
        int v = Q.front();
        Q.pop();
        if (color1[v] == 0){
          for (int w : E[v]){
            if (color1[w] == 0){
              flg = true;
              break;
            }
            if (color1[w] == -1){
              color1[w] = 1;
              B.push_back(w);
              Q.push(w);
            }
          }
        } else {
          for (int w : E[v]){
            if (color1[w] == 1){
              flg = true;
              break;
            }
            if (color1[w] == -1){
              color1[w] = 0;
              A.push_back(w);
              Q.push(w);
            }
          }
        }
      }
      C.push_back(make_pair(A, B));
    }
  }
  if (flg){
    cout << "NO" << endl;
  } else {
    int cc = C.size();
    vector<vector<bool>> dp(cc + 1, vector<bool>(n2 + 1, false));
     dp[0][0] = true;
    for (int i = 0; i < cc; i++){
      int A = C[i].first.size();
      int B = C[i].second.size();
      for (int j = 0; j <= n2; j++){
        if (dp[i][j]){
          if ((j + A) <= n2){
            dp[i + 1][j + A] = true;
          }
          if ((j + B) <= n2){
            dp[i + 1][j + B] = true;
          }
        }
      }
    }
    if (!dp[cc][n2]){
      cout << "NO" << endl;
    } else {
      int curr = n2;
      vector<int> ans(n, -1);
      for (int i = cc - 1; i >= 0; i--){
        int A = C[i].first.size();
        int B = C[i].second.size();
        bool A_ok = false;
        if (curr - A >= 0){
          if (dp[i][curr - A]){
            A_ok = true;
          }
        }
        if (A_ok){
          curr -= A;
          for (int j : C[i].first){
            ans[j] = 2;
          }
        } else {
          curr -= B;
          for (int j : C[i].second){
            ans[j] = 2;
          }
        }
      }
      int cnt = 0;
      for (int i = 0; i < n; i++){
        if (ans[i] == -1 && cnt < n1){
          ans[i] = 1;
          cnt++;
        } else if (ans[i] == -1){
          ans[i] = 3;
        }
      }
      cout << "YES" << endl;
      for (int i = 0; i < n; i++){
        cout << ans[i];
      }
      cout << endl;
    }
  }
}