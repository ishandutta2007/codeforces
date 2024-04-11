#include <bits/stdc++.h>
using namespace std;
int main(){
  int n, m, q;
  cin >> n >> m >> q;
  string s;
  cin >> s;
  string t;
  cin >> t;
  if (n < m){
    for (int i = 0; i < q; i++){
      cout << 0 << endl;
    }
  } else {
    vector<int> occ(n - m + 1, 0);
    for (int i = 0; i <= n - m; i++){
      bool flg = true;
      for (int j = 0; j < m; j++){
        if (s[i + j] != t[j]){
          flg = false;
        }
      }
      if (flg){
        occ[i] = 1;
      }
    }
    vector<int> sum(n - m + 2, 0);
    for (int i = 0; i <= n - m; i++){
      sum[i + 1] = sum[i] + occ[i];
    }
    for (int i = 0; i < q; i++){
      int l, r;
      cin >> l >> r;
      if (r - l + 1 < m){
        cout << 0 << endl;
      } else {
        r -= m;
        r++;
        l--;
        cout << sum[r] - sum[l] << endl;
      }
    }
  }
}