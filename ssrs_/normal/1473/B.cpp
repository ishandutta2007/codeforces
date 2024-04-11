#include <bits/stdc++.h>
using namespace std;
int main(){
  int q;
  cin >> q;
  for (int i = 0; i < q; i++){
    string s, t;
    cin >> s >> t;
    int n = s.size();
    int m = t.size();
    int g = -1;
    for (int j = 1; j <= n; j++){
      if (n % j == 0 && m % j == 0){
        string tmp = s.substr(0, j);
        bool ok = true;
        for (int k = 0; k < n; k += j){
          if (s.substr(k, j) != tmp){
            ok = false;
          }
        }
        for (int k = 0; k < m; k += j){
          if (t.substr(k, j) != tmp){
            ok = false;
          }
        }
        if (ok){
          g = j;
        }
      }
    }
    if (g == -1){
      cout << -1 << endl;
    } else {
      int r = lcm(n / g, m / g);
      string ans;
      for (int j = 0; j < r; j++){
        ans += s.substr(0, g);
      }
      cout << ans << endl;
    }
  }
}