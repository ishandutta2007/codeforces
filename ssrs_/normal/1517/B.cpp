#include <bits/stdc++.h>
using namespace std;
int main(){
  int t;
  cin >> t;
  for (int i = 0; i < t; i++){
    int n, m;
    cin >> n >> m;
    vector<vector<int>> b(n, vector<int>(m));
    for (int j = 0; j < n; j++){
      for (int k = 0; k < m; k++){
        cin >> b[j][k];
      }
    }
    vector<tuple<int, int, int>> c;
    for (int j = 0; j < n; j++){
      for (int k = 0; k < m; k++){
        c.push_back(make_tuple(b[j][k], j, k));
      }
    }
    sort(c.begin(), c.end());
    vector<vector<bool>> mn(n, vector<bool>(m, false));
    for (int j = 0; j < m; j++){
      mn[get<1>(c[j])][get<2>(c[j])] = true;
    }
    int cnt = 0;
    for (int i = 0; i < n; i++){
      vector<int> ans(m);
      vector<bool> used(m, false);
      for (int j = 0; j < m; j++){
        if (mn[i][j]){
          used[cnt] = true;
          ans[cnt] = b[i][j];
          cnt++;
        }
      }
      int p = 0;
      for (int j = 0; j < m; j++){
        if (!used[j]){
          while (mn[i][p]){
            p++;
          }
          ans[j] = b[i][p];
          p++;
        }
      }
      for (int j = 0; j < m; j++){
        cout << ans[j];
        if (j < m - 1){
          cout << ' ';
        }
      }
      cout << endl;
    }
  }
}