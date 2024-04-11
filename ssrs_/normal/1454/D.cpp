#include <bits/stdc++.h>
using namespace std;
int main(){
  int t;
  cin >> t;
  for (int i = 0; i < t; i++){
    long long n;
    cin >> n;
    long long n2 = n;
    map<long long, int> mp;
    for (long long j = 2; j * j <= n; j++){
      while (n % j == 0){
        mp[j]++;
        n /= j;
      }
    }
    if (n > 1){
      mp[n] = true;
    }
    long long f = 0;
    int mx = 0;
    for (auto P : mp){
      if (P.second > mx){
        f = P.first;
        mx = P.second;
      }
    }
    vector<long long> ans(mx, f);
    for (int j = 0; j < mx; j++){
      n2 /= f;
    }
    ans[mx - 1] *= n2;
    cout << mx << endl;
    for (int j = 0; j < mx; j++){
      cout << ans[j];
      if (j < mx - 1){
        cout << ' ';
      }
    }
    cout << endl;
  }
}