#include <bits/stdc++.h>
using namespace std;
vector<int> dx = {1, 1, -1, -1};
vector<int> dy = {1, -1, 1, -1};
int main(){
  int t;
  cin >> t;
  for (int i = 0; i < t; i++){
    int n, m;
    cin >> n >> m;
    vector<vector<int>> a(n, vector<int>(m));
    for (int j = 0; j < n; j++){
      for (int k = 0; k < m; k++){
        cin >> a[j][k];
      }
    }
    int ans = 0;
    for (int j = 0; j < n; j++){
      for (int k = 0; k < m; k++){
        int sum = a[j][k];
        for (int l = 0; l < 4; l++){
          int x = j + dx[l];
          int y = k + dy[l];
          while (0 <= x && x < n && 0 <= y && y < m){
            sum += a[x][y];
            x += dx[l];
            y += dy[l];
          }
        }
        ans = max(ans, sum);
      }
    }
    cout << ans << endl;
  }
}