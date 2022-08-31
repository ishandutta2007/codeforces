//WA
#include <bits/stdc++.h>
using namespace std;
const int SQRT = 450;
int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n, m;
  cin >> n >> m;
  vector<int> x(n), y(n);
  for (int i = 0; i < n; i++){
    cin >> x[i] >> y[i];
  }
  vector<int> op(m), k(m);
  for (int i = 0; i < m; i++){
    cin >> op[i] >> k[i];
    k[i]--;
  }
  vector<vector<int>> id(n);
  for (int i = 0; i < m; i++){
    id[k[i]].push_back(i);
  }
  vector<int> imos(m + 1, 0);
  vector<vector<int>> imos2(SQRT, vector<int>(m + 1, 0));
  for (int i = 0; i < n; i++){
    if (id[i].size() % 2 == 1){
      id[i].push_back(m);
    }
    int cnt = id[i].size();
    for (int j = 0; j < cnt; j += 2){
      int L = id[i][j];
      int R = id[i][j + 1];
      if (x[i] + y[i] >= SQRT){
        while (true){
          if (L + x[i] > R){
            break;
          } else if (L + x[i] + y[i] > R){
            imos[L + x[i]]++;
            imos[R]--;
            break;
          } else {
            imos[L + x[i]]++;
            imos[L + x[i] + y[i]]--;
            L += x[i] + y[i];
          }
        }
      } else {
        int c = x[i] + y[i];
        if (L + x[i] <= m){
          imos2[c][L + x[i]]++;
        }
        if (L + x[i] + y[i] <= m){
          imos2[c][L + x[i] + y[i]]--;
        }
        int r = (R - L) % c;
        int R2 = R - r;
        if (r <= x[i]){
          if (R2 + x[i] <= m){
            imos2[c][R2 + x[i]]--;
          }
          if (R2 + c <= m){
            imos2[c][R2 + c]++;
          }
        } else {
          imos2[c][R]--;
          if (R2 + c <= m){
            imos2[c][R2 + c]++;
          }
          if (R2 + c + x[i] <= m){
            imos2[c][R2 + c + x[i]]--;
          }
          if (R + c <= m){
            imos2[c][R + c]++;
          }
        }
      }
    }
  }
  for (int i = 0; i < m; i++){
    imos[i + 1] += imos[i];
  }
  for (int i = 2; i < SQRT; i++){
    for (int j = 0; j < m; j++){
      imos2[i][j + 1] += imos2[i][j];
    }
    for (int j = 0; j <= m - i; j++){
      imos2[i][j + i] += imos2[i][j];
    }
  }
  for (int i = 0; i < m; i++){
    int ans = imos[i];
    for (int j = 2; j < SQRT; j++){
      ans += imos2[j][i];
    }
    cout << ans << "\n";
  }
}