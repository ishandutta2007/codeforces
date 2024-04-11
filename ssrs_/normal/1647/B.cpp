#include <bits/stdc++.h>
using namespace std;
vector<int> dx = {1, 0, -1, 0};
vector<int> dy = {0, 1, 0, -1};
int main(){
  int t;
  cin >> t;
  for (int i = 0; i < t; i++){
    int n, m;
    cin >> n >> m;
    vector<string> S(n);
    for (int j = 0; j < n; j++){
      cin >> S[j];
    }
    vector<vector<bool>> used(n, vector<bool>(m, false));
    bool ok = true;
    for (int j = 0; j < n; j++){
      for (int k = 0; k < m; k++){
        if (S[j][k] == '1' && !used[j][k]){
          used[j][k] = true;
          int U = j, D = j, L = k, R = k;
          int cnt = 0;
          queue<pair<int, int>> Q;
          Q.push(make_pair(j, k));
          while (!Q.empty()){
            int x = Q.front().first;
            int y = Q.front().second;
            Q.pop();
            U = min(U, x);
            D = max(D, x);
            L = min(L, y);
            R = max(R, y);
            cnt++;
            for (int l = 0; l < 4; l++){
              int x2 = x + dx[l];
              int y2 = y + dy[l];
              if (0 <= x2 && x2 < n && 0 <= y2 && y2 < m){
                if (S[x2][y2] == '1' && !used[x2][y2]){
                  used[x2][y2] = true;
                  Q.push(make_pair(x2, y2));
                }
              }
            }
          }
          if ((D - U + 1) * (R - L + 1) != cnt){
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