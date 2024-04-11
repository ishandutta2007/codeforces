#include <bits/stdc++.h>
using namespace std;
int main(){
  int t;
  cin >> t;
  for (int i = 0; i < t; i++){
    int n, m;
    cin >> n >> m;
    vector<int> a(n);
    for (int j = 0; j < n; j++){
      cin >> a[j];
    }
    vector<int> b(m);
    for (int j = 0; j < m; j++){
      cin >> b[j];
    }
    vector<vector<int>> a2(2);
    for (int j = 0; j < n; j++){
      if (a[j] < 0){
        a2[0].push_back(-a[j]);
      }
      if (a[j] > 0){
        a2[1].push_back(a[j]);
      }
    }
    vector<vector<int>> b2(2);
    for (int j = 0; j < m; j++){
      if (b[j] < 0){
        b2[0].push_back(-b[j]);
      }
      if (b[j] > 0){
        b2[1].push_back(b[j]);
      }
    }
    int ans = 0;
    for (int j = 0; j < 2; j++){
      sort(a2[j].begin(), a2[j].end());
      sort(b2[j].begin(), b2[j].end());
      int m2 = b2[j].size();
      int mx = 0;
      int add = 0;
      for (int k = m2 - 1; k >= 0; k--){
        int cnt = upper_bound(a2[j].begin(), a2[j].end(), b2[j][k]) - a2[j].begin();
        int d = upper_bound(b2[j].begin(), b2[j].end(), b2[j][k]) - upper_bound(b2[j].begin(), b2[j].end(), b2[j][k] - cnt);
        mx = max(mx, d + add);
        auto itr = lower_bound(a2[j].begin(), a2[j].end(), b2[j][k]);
        if (itr != a2[j].end()){
          if ((*itr) == b2[j][k]){
            add++;
          }
        }
      }
      ans += mx;
    }
    cout << ans << endl;
  }
}