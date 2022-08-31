#include <bits/stdc++.h>
using namespace std;
const long long MOD = 1000000007;
int main(){
  vector<vector<long long>> binom(1001, vector<long long>(1001, 1));
  for (int i = 2; i <= 1000; i++){
    for (int j = 1; j < i; j++){
      binom[i][j] = (binom[i - 1][j - 1] + binom[i - 1][j]) % MOD;
    }
  }
  int t;
  cin >> t;
  for (int i = 0; i < t; i++){
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (int j = 0; j < n; j++){
      cin >> a[j];
    }
    vector<int> cnt(n + 1, 0);
    for (int j = 0; j < n; j++){
      cnt[a[j]]++;
    }
    for (int j = n; j >= 0; j--){
      if (k - cnt[j] > 0){
        k -= cnt[j];
      } else {
        cout << binom[cnt[j]][k] << endl;
        break;
      }
    }
  }
}