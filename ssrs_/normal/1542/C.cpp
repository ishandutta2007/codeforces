#include <bits/stdc++.h>
using namespace std;
const long long MOD = 1000000007;
long long lcm(long long a, long long b){
  return a / __gcd(a, b) * b;
}
int main(){
  int t;
  cin >> t;
  for (int i = 0; i < t; i++){
    long long n;
    cin >> n;
    vector<long long> M(2, 1);
    while (M.back() <= n){
      long long nxt = lcm(M.back(), M.size());
      M.push_back(nxt);
    }
    int cnt = M.size();
    long long ans = 0;
    for (int j = 0; j < cnt; j++){
      ans += n / M[j];
      ans %= MOD;
    }
    cout << ans << endl;
  }
}