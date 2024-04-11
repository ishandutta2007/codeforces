#include <bits/stdc++.h>
using namespace std;
int main(){
  int n, m;
  cin >> n >> m;
  vector<vector<int>> a(n, vector<int>(m));
  for (int i = 0; i < n; i++){
    for (int j = 0; j < m; j++){
      cin >> a[i][j];
      a[i][j]--;
    }
  }
  int ans = 0;
  for (int i = 0; i < m; i++){
    vector<int> b(n);
    for (int j = 0; j < n; j++){
      b[j] = a[j][i];
    }
    vector<int> cnt(n);
    for (int j = 0; j < n; j++){
      cnt[j] = n + j;
    }
    for (int j = 0; j < n; j++){
      if (b[j] % m == i){
        int q = b[j] / m;
        if (q < n){
          int p = (j - q + n) % n;
          cnt[p]--;
        }
      }
    }
    int mn = n;
    for (int j = 0; j < n; j++){
      mn = min(mn, cnt[j]);
    }
    ans += mn;
  }
  cout << ans << endl;
}