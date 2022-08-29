#include <bits/stdc++.h>
using namespace std;
const int INF = 100000000;
vector<int> dx = {1, 0, -1, 0};
vector<int> dy = {0, 1, 0, -1};
int main(){
  int n, m, k;
  cin >> n >> m >> k;
  if (k % 2 == 1){
    for (int i = 0; i < n; i++){
      for (int j = 0; j < m; j++){
        cout << -1;
        if (j < m - 1){
          cout << ' ';
        }
      }
      cout << endl;
    }
  } else {
    vector<vector<vector<int>>> e(n + 2, vector<vector<int>>(m + 2, vector<int>(4, INF)));
    for (int i = 1; i <= n; i++){
      for (int j = 1; j < m; j++){
        int x;
        cin >> x;
        e[i][j][1] = x;
        e[i][j + 1][3] = x;
      }
    }
    for (int i = 1; i < n; i++){
      for (int j = 1; j <= m; j++){
        int x;
        cin >> x;
        e[i][j][0] = x;
        e[i + 1][j][2] = x;
      }
    }
    vector<vector<int>> dp(n + 2, vector<int>(m + 2, 0));
    for (int i = 0; i < k / 2; i++){
      vector<vector<int>> dp2(n + 2, vector<int>(m + 2, INF));
      for (int x = 1; x <= n; x++){
        for (int y = 1; y <= m; y++){
          for (int j = 0; j < 4; j++){
            int x2 = x + dx[j];
            int y2 = y + dy[j];
            dp2[x][y] = min(dp2[x][y], dp[x2][y2] + e[x][y][j] * 2);
          }
        }
      }
      swap(dp, dp2);
    }
    for (int i = 1; i <= n; i++){
      for (int j = 1; j <= m; j++){
        cout << dp[i][j];
        if (j < m){
          cout << ' ';
        }
      }
      cout << endl;
    }
  }
}