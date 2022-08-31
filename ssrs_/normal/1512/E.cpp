#include <bits/stdc++.h>
using namespace std;
int main(){
  int t;
  cin >> t;
  for (int i = 0; i < t; i++){
    int n, l, r, s;
    cin >> n >> l >> r >> s;
    l--;
    int cnt = r - l;
    int mn = cnt * (cnt + 1) / 2;
    int mx = cnt * (n + 1) - mn;
    if (s < mn || mx < s){
      cout << -1 << endl;
    } else {
      vector<int> a(cnt);
      for (int j = 0; j < cnt; j++){
        a[j] = j + 1;
        s -= a[j];
      }
      for (int j = cnt - 1; j >= 0; j--){
        while (s > 0 && a[j] < n - (cnt - 1 - j)){
          s--;
          a[j]++;
        }
      }
      vector<bool> used(n + 1, false);
      for (int j = 0; j < cnt; j++){
        used[a[j]] = true;
      }
      vector<int> p(n);
      for (int j = 0; j < n; j++){
        if (j < l || r <= j){
          for (int k = 1; k <= n; k++){
            if (!used[k]){
              used[k] = true;
              p[j] = k;
              break;
            }
          }
        } else {
          p[j] = a[j - l];
        }
      }
      for (int j = 0; j < n; j++){
        cout << p[j];
        if (j < n - 1){
          cout << ' ';
        }
      }
      cout << endl;
    }
  }
}