#include <bits/stdc++.h>
using namespace std;
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
    long long ans = 0;
    for (int j = 0; j < (n + 1) / 2; j++){
      for (int k = 0; k < (m + 1) / 2; k++){
        vector<int> x;
        x.push_back(a[j][k]);
        if (j != n - 1 - j){
          x.push_back(a[n - 1 - j][k]);
        }
        if (k != m - 1 - k){
          x.push_back(a[j][m - 1 - k]);
        }
        if (j != n - 1 - j && k != m - 1 - k){
          x.push_back(a[n - 1 - j][m - 1 - k]);
        }
        int cnt = x.size();
        sort(x.begin(), x.end());
        int m = x[(cnt - 1) / 2];
        for (int l = 0; l < cnt; l++){
          ans += abs(m - x[l]);
        }
      }
    }
    cout << ans << endl;
  }
}