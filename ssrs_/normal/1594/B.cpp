#include <bits/stdc++.h>
using namespace std;
const long long MOD = 1000000007;
int main(){
  int t;
  cin >> t;
  for (int i = 0; i < t; i++){
    int n, k;
    cin >> n >> k;
    long long m = 1;
    long long ans = 0;
    for (int j = 0; j < 30; j++){
      if ((k >> j & 1) == 1){
        ans += m;
      }
      m *= n;
      m %= MOD;
    }
    ans %= MOD;
    cout << ans << endl;
  }
}