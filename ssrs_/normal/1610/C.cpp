#include <bits/stdc++.h>
using namespace std;
int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int t;
  cin >> t;
  for (int i = 0; i < t; i++){
    int n;
    cin >> n;
    vector<int> a(n), b(n);
    for (int j = 0; j < n; j++){
      cin >> a[j] >> b[j];
    }
    int tv = 0, fv = n + 1;
    while (fv - tv > 1){
      int mid = (tv + fv) / 2;
      vector<int> c, d;
      int m = 0;
      for (int j = 0; j < n; j++){
        if (a[j] + b[j] + 1 >= mid){
          c.push_back(mid - 1 - a[j]);
          d.push_back(b[j]);
          m++;
        }
      }
      int cnt = 0;
      for (int j = 0; j < m; j++){
        if (c[j] <= cnt && cnt <= d[j]){
          cnt++;
        }
      }
      if (cnt >= mid){
        tv = mid;
      } else {
        fv = mid;
      }
    }
    cout << tv << endl;
  }
}