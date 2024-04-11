#include <bits/stdc++.h>
using namespace std;
int main(){
  int t;
  cin >> t;
  for (int i = 0; i < t; i++){
    int n, q;
    cin >> n >> q;
    vector<int> a(n);
    for (int j = 0; j < n; j++){
      cin >> a[j];
    }
    int tv = n, fv = -1;
    string ans;
    while (tv - fv > 1){
      int mid = (tv + fv) / 2;
      string s(n, '1');
      int cnt = 0;
      int tmp = q;
      bool ok = true;
      for (int j = 0; j < n; j++){
        if (a[j] > tmp){
          if (cnt < mid){
            s[j] = '0';
          } else {
            if (tmp == 0){
              ok = false;
            }
            tmp--;
          }
          cnt++;
        } else {
          if (tmp == 0){
            ok = false;
          }
        }
      }
      if (ok){
        tv = mid;
        ans = s;
      } else {
        fv = mid;
      }
    }
    cout << ans << endl;
  }
}