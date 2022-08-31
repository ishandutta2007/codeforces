#include <bits/stdc++.h>
using namespace std;
const long long MOD = 1000000007;
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
    int s = a[0];
    for (int j = 1; j < n; j++){
      s &= a[j];
    }
    int cnt = 0;
    for (int j = 0; j < n; j++){
      if (s == a[j]){
        cnt++;
      }
    }
    long long ans = (long long) cnt * (cnt - 1);
    ans %= MOD;
    for (int j = 1; j <= n - 2; j++){
      ans *= j;
      ans %= MOD;
    }
    cout << ans << endl;
  }
}