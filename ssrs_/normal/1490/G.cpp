#include <bits/stdc++.h>
using namespace std;
int main(){
  int t;
  cin >> t;
  for (int i = 0; i < t; i++){
    int n, m;
    cin >> n >> m;
    vector<int> a(n);
    for (int j = 0; j < n; j++){
      cin >> a[j];
    }
    vector<long long> x(m);
    for (int j = 0; j < m; j++){
      cin >> x[j];
    }
    vector<long long> S(n + 1, 0);
    for (int j = 0; j < n; j++){
      S[j + 1] = S[j] + a[j];
    }
    if (S[n] <= 0){
      long long mx = a[0];
      map<long long, int> mp;
      mp[mx] = 0;
      for (int j = 1; j <= n; j++){
        if (mx < S[j]){
          mx = S[j];
          mp[S[j]] = j - 1;
        }
      }
      for (int j = 0; j < m; j++){
        auto itr = mp.lower_bound(x[j]);
        if (itr == mp.end()){
          cout << -1;
        } else {
          cout << (*itr).second;
        }
        if (j < m - 1){
          cout << ' ';
        }
      }
    } else {
      long long smax = *max_element(S.begin(), S.end());
      long long mx = a[0];
      map<long long, int> mp;
      mp[mx] = 0;
      for (int j = 1; j <= n; j++){
        if (mx < S[j]){
          mx = S[j];
          mp[S[j]] = j - 1;
        }
      }
      for (int j = 0; j < m; j++){
        long long q = 0;
        if (x[j] > smax){
          q = (x[j] - smax - 1) / S[n] + 1;
          x[j] -= q * S[n];
        }
        auto itr = mp.lower_bound(x[j]);
        if (itr == mp.end()){
          cout << -1;
        } else {
          if (q >= 1 && x[j] == 0){
            cout << q * n - 1;
          } else {
            cout << (*itr).second + q * n;
          }
        }
        if (j < m - 1){
          cout << ' ';
        }
      }
    }
    cout << endl;
  }
}