#include <bits/stdc++.h>
using namespace std;
const int INF = 1000000000;
const long long MOD = 998244353;
int main(){
  int t;
  cin >> t;
  for (int i = 0; i < t; i++){
    int n;
    cin >> n;
    vector<int> a(n);
    for (int j = 0; j < n; j++){
      cin >> a[j];
    }
    int p = 0;
    for (int j = 0; j < n; j++){
      if (a[j] > a[p]){
        p = j;
      }
    }
    int mn = INF;
    for (int j = 0; j < n; j++){
      if (j != p){
        mn = min(mn, a[p] - a[j]);
      }
    }
    if (mn >= 2){
      cout << 0 << endl;
    } else if (mn == 0){
      long long ans = 1;
      for (int j = 1; j <= n; j++){
        ans *= j;
        ans %= MOD;
      }
      cout << ans << endl;
    } else {
      int cnt = 0;
      for (int j = 0; j < n; j++){
        if (a[j] == a[p] - 1){
          cnt++;
        }
      }
      long long ans = 1;
      for (int j = 1; j <= n; j++){
        if (j == cnt + 1){
          ans *= cnt;
        } else {
          ans *= j;
        }
        ans %= MOD;
      }
      cout << ans << endl;
    }
  }
}