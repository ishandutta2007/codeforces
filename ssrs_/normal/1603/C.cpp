#include <bits/stdc++.h>
using namespace std;
const long long MOD = 998244353;
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
    long long ans = 0;
    vector<pair<int, int>> P;
    for (int j = n - 1; j >= 0; j--){
      P.push_back(make_pair(a[j], 1));
      if (a[j] == 1){
        P = vector<pair<int, int>>(1, make_pair(1, n - j));
      } else {
        int cnt = P.size();
        vector<pair<int, int>> Q;
        for (int k = 0; k < cnt; k++){
          int x = (a[j] - 1) / P[k].first;
          ans += (long long) x * (j + 1) % MOD * P[k].second % MOD;
          int p2 = a[j] / (x + 1);
          if (Q.empty()){
            Q.push_back(make_pair(p2, P[k].second));
          } else if (Q.back().first != p2){
            Q.push_back(make_pair(p2, P[k].second));
          } else {
            Q.back().second += P[k].second;
          }
        }
        swap(P, Q);
      }
    }
    ans %= MOD;
    cout << ans << endl;
  }
}