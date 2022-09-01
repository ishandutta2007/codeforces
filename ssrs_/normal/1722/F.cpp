#include <bits/stdc++.h>
using namespace std;
const int INF = 1000000;
vector<int> dx = {1, 0, -1, 0, 1, 1, -1, -1};
vector<int> dy = {0, 1, 0, -1, 1, -1,  1,-1};
int main(){
  int t;
  cin >> t;
  for (int i = 0; i < t; i++){
    int n, m;
    cin >> n >> m;
    vector<vector<char>> c(n, vector<char>(m));
    for (int j = 0; j < n; j++){
      for (int k = 0; k < m; k++){
        cin >> c[j][k];
      }
    }
    bool ok = true;
    vector<vector<bool>> used(n, vector<bool>(m, false));
    for (int j = 0; j < n; j++){
      for (int k = 0; k < m; k++){
        if (!used[j][k] && c[j][k] == '*'){
          used[j][k] = true;
          int cnt = 0;
          int xmn = j, xmx = j, ymn = k, ymx = k;
          queue<pair<int, int>> Q;
          Q.push(make_pair(j, k));
          while (!Q.empty()){
            int x = Q.front().first;
            int y = Q.front().second;
            Q.pop();
            cnt++;
            xmn = min(xmn, x);
            xmx = max(xmx, x);
            ymn = min(ymn, y);
            ymx = max(ymx, y);
            for (int l = 0; l < 8; l++){
              int x2 = x + dx[l];
              int y2 = y + dy[l];
              if (0 <= x2 && x2 < n && 0 <= y2 && y2 < m){
                if (c[x2][y2] == '*' && !used[x2][y2]){
                  used[x2][y2] = true;
                  Q.push(make_pair(x2, y2));
                }
              }
            }
          }
          if (cnt != 3 || xmx - xmn != 1 || ymx - ymn != 1){
            ok = false;
          }
        }
      }
    }
    if (ok){
      cout << "YES" << endl;
    } else {
      cout << "NO" << endl;
    }
  }
}