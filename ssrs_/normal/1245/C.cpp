#include <bits/stdc++.h>
using namespace std;
const long long MOD = 1000000007;
int main(){
  string s;
  cin >> s;
  int n = s.size();
  vector<long long> fib(n + 1, 1);
  for (int i = 2; i <= n; i++){
    fib[i] = (fib[i - 2] + fib[i - 1]) % MOD;
  }
  long long ans = 1;
  int con = 0;
  for (int i = 0; i < n; i++){
    if (s[i] == 'w'){
      ans = 0;
    } else if (s[i] == 'm'){
      ans = 0;
    } else if (s[i] == 'u' || s[i] == 'n'){
      if (i > 0){
        if (s[i - 1] != s[i]){
          ans *= fib[con];
          ans %= MOD;
          con = 0;
        }
      }
      con++;
    } else {
      ans *= fib[con];
      ans %= MOD;
      con = 0;
    }
  }
  ans *= fib[con];
  ans %= MOD;
  cout << ans << endl;
}