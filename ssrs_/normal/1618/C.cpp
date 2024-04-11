#include <bits/stdc++.h>
using namespace std;
int main(){
  int t;
  cin >> t;
  for (int i = 0; i < t; i++){
    int n;
    cin >> n;
    vector<long long> a(n);
    for (int j = 0; j < n; j++){
      cin >> a[j];
    }
    long long ans = 0;
    for (int j = 0; j < 2; j++){
      long long d = 0;
      for (int k = j; k < n; k += 2){
        d = __gcd(d, a[k]);
      }
      bool ok = true;
      for (int k = 1 - j; k < n; k += 2){
        if (a[k] % d == 0){
          ok = false;
        }
      }
      if (ok){
        ans = d;
      }
    }
    cout << ans << endl;
  }
}