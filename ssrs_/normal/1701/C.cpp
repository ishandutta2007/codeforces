#include <bits/stdc++.h>
using namespace std;
int main(){
  int t;
  cin >> t;
  for (int i = 0; i < t; i++){
    int n, m;
    cin >> n >> m;
    vector<int> a(m);
    for (int j = 0; j < m; j++){
      cin >> a[j];
      a[j]--;
    }
    vector<int> cnt(n, 0);
    for (int j = 0; j < m; j++){
      cnt[a[j]]++;
    }
    int tv = m * 2, fv = 0;
    while (tv - fv > 1){
      int mid = (tv + fv) / 2;
      long long x = 0, y = 0;
      for (int j = 0; j < n; j++){
        if (cnt[j] < mid){
          y += (mid - cnt[j]) / 2;
        } else {
          x += cnt[j] - mid;
        }
      }
      if (y >= x){
        tv = mid;
      } else {
        fv = mid;
      }
    }
    cout << tv << endl;
  }
}