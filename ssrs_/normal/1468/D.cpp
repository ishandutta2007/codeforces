#include <bits/stdc++.h>
using namespace std;
int main(){
  int t;
  cin >> t;
  for (int i = 0; i < t; i++){
    int n, m, a, b;
    cin >> n >> m >> a >> b;
    a--;
    b--;
    vector<int> s(m);
    for (int j = 0; j < m; j++){
      cin >> s[j];
    }
    int d = abs(a - b);
    sort(s.begin(), s.end());
    int tv = 0;
    int fv = m + 1;
    while (fv - tv > 1){
      int mid = (tv + fv) / 2;
      bool ok = true;
      if (mid > d){
        ok = false;
      } else if (mid == d){
        for (int j = mid - 1; j >= 0; j--){
          if (s[j] > j){
            ok = false;
          }
        }
      } else {
        int c;
        if (a < b){
          c = b;
        } else {
          c = n - 1 - b;
        }
        for (int j = mid - 1; j >= 0; j--){
          if (s[j] > c - (mid - j)){
            ok = false;
          }
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