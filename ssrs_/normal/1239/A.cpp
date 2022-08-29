#include <bits/stdc++.h>
using namespace std;
const long long MOD = 1000000007;
int main(){
  vector<long long> F(100001);
  F[0] = 1;
  F[1] = 1;
  for (int i = 2; i <= 100000; i++){
    F[i] = (F[i - 2] + F[i - 1]) % MOD;
  }
  int n, m;
  cin >> n >> m;
  cout << (F[n] + F[m] + MOD - 1) * 2 % MOD << endl;
}