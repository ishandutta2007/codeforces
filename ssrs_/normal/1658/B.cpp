#include <bits/stdc++.h>
using namespace std;
const long long MOD = 998244353;
int main(){
  int t;
  cin >> t;
  for (int i = 0; i < t; i++){
    int n;
    cin >> n;
    if (n % 2 == 0){
      long long F = 1;
      for (int j = 1; j <= n / 2; j++){
        F *= j;
        F %= MOD;
      }
      cout << F * F % MOD << endl;
    } else {
      cout << 0 << endl;
    }
  }
}