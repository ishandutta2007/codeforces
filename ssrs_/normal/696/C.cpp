#include <bits/stdc++.h>
using namespace std;
const long long MOD = 1000000007;
long long modpow(long long a, long long b){
  long long ans = 1;
  while (b > 0){
    if (b % 2 == 1){
      ans *= a;
      ans %= MOD;
    }
    a *= a;
    a %= MOD;
    b /= 2;
  }
  return ans;
}
long long modinv(long long a){
  return modpow(a, MOD - 2);
}
int main(){
  int k;
  cin >> k;
  vector<long long> a(k);
  for (int i = 0; i < k; i++){
    cin >> a[i];
  }
  long long num1 = 2;
  for (int i = 0; i < k; i++){
    num1 = modpow(num1, a[i]);
  }
  num1 *= modinv(2);
  num1 %= MOD;
  long long num2 = MOD - 1;
  for (int i = 0; i < k; i++){
    num2 = modpow(num2, a[i]);
  }
  long long num = num1 + num2;
  num %= MOD;
  num *= modinv(3);
  num %= MOD;
  long long denom = num1;
  cout << num << '/' << denom << endl;
}