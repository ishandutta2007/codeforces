#include <bits/stdc++.h>
using namespace std;
const long long MOD = 998244353;
int main(){
  mt19937 mt(chrono::steady_clock::now().time_since_epoch().count());
  long long BASE = mt() % 1000000 + 1000000;
  int n, k;
  cin >> n >> k;
  string s;
  cin >> s;
  vector<long long> POW(n);
  POW[0] = 1;
  for (int i = 0; i < n - 1; i++){
    POW[i + 1] = POW[i] * BASE % MOD;
  }
  vector<long long> S(n + 1);
  S[0] = 0;
  for (int i = 0; i < n; i++){
    S[i + 1] = (S[i] + s[i] * POW[i]) % MOD;
  }
  int l = 1;
  for (int i = 2; i <= n; i++){
    int sum = i + l;
    int tv = 0, fv = sum + 1;
    while (fv - tv > 1){
      int mid = (tv + fv) / 2;
      long long hash1 = 0;
      if (mid <= i){
        hash1 = S[mid];
      } else {
        hash1 = (S[i] + S[mid - i] * POW[i]) % MOD;
      }
      long long hash2 = 0;
      if (mid <= l){
        hash2 = S[mid];
      } else {
        hash2 = (S[l] + S[mid - l] * POW[l]) % MOD;
      }
      if (hash1 == hash2){
        tv = mid;
      } else {
        fv = mid;
      }
    }
    if (tv < sum){
      char c1;
      if (tv < i){
        c1 = s[tv];
      } else {
        c1 = s[tv - i];
      }
      char c2;
      if (tv < l){
        c2 = s[tv];
      } else {
        c2 = s[tv - l];
      }
      if (c1 < c2){
        l = i;
      }
    }
  }
  for (int i = 0; i < k; i++){
    cout << s[i % l];
  }
  cout << endl;
}