#include <bits/stdc++.h>
using namespace std;
const int B = 78;
const int LOG = 17;
int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; i++){
    cin >> a[i];
  }
  int q;
  cin >> q;
  vector<vector<pair<int, int>>> query(n + 1);
  for (int i = 0; i < q; i++){
    int p, k;
    cin >> p >> k;
    p--;
    query[k].push_back(make_pair(p, i));
  }
  vector<int> ans(q, 0);
  for (int i = 1; i <= n; i++){
    if (i < B){
      vector<vector<int>> b(LOG, vector<int>(n));
      for (int j = 0; j < n; j++){
        b[0][j] = j + a[j] + i;
      }
      for (int j = 0; j < LOG - 1; j++){
        for (int k = 0; k < n; k++){
          if (b[j][k] >= n){
            b[j + 1][k] = n;
          } else {
            b[j + 1][k] = b[j][b[j][k]];
          }
        }
      }
      int cnt = query[i].size();
      for (int j = 0; j < cnt; j++){
        int p = query[i][j].first;
        int id = query[i][j].second;
        for (int j = LOG - 1; j >= 0; j--){
          if (b[j][p] < n){
            ans[id] += 1 << j;
            p = b[j][p];
          }
        }
        ans[id]++;
      }
    } else {
      int cnt = query[i].size();
      for (int j = 0; j < cnt; j++){
        int p = query[i][j].first;
        int id = query[i][j].second;
        while (p < n){
          p = p + a[p] + i;
          ans[id]++;
        }
      }
    }
  }
  for (int i = 0; i < q; i++){
    cout << ans[i] << "\n";
  }
}