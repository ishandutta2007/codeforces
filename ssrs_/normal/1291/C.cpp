#include <bits/stdc++.h>
using namespace std;
const int INF = 1000000001;
int main(){
  int t;
  cin >> t;
  for (int i = 0; i < t; i++){
    int n, m, k;
    cin >> n >> m >> k;
    vector<int> a(n);
    for (int j = 0; j < n; j++){
      cin >> a[j];
    }
    k = min(k, m - 1);
    int tv = 0, fv = INF;
    while (fv - tv > 1){
      int mid = (tv + fv) / 2;
      vector<int> p(m);
      for (int j = 0; j < m; j++){
        if (a[j] >= mid || a[j + n - m] >= mid){
          p[j] = 1;
        } else {
          p[j] = 0;
        }
      }
      vector<int> S(m + 1);
      S[0] = 0;
      for (int j = 0; j < m; j++){
        S[j + 1] = S[j] + (1 - p[j]);
      }
      bool ok = false;
      for (int j = 0; j <= k; j++){
        if (S[j + m - k] - S[j] == 0){
          ok = true;
        }
      }
      if (ok){
        tv = mid;
      } else {
        fv = mid;
      }
    }
    cout << tv << endl;
  }
}