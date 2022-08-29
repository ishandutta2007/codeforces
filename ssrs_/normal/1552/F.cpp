#include <bits/stdc++.h>
using namespace std;
const long long MOD = 998244353;
int main(){
  int n;
  cin >> n;
  vector<int> x(n), y(n), s(n);
  for (int i = 0; i < n; i++){
    cin >> x[i] >> y[i] >> s[i];
  }
  vector<long long> P(n);
  P[0] = 1;
  for (int i = 0; i < n - 1; i++){
    P[i + 1] = P[i] * 2 % MOD;
  }
  vector<tuple<int, int, int>> X;
  for (int i = 0; i < n; i++){
    X.push_back(make_tuple(x[i], i, 0));
    X.push_back(make_tuple(y[i], i, 1));
  }
  sort(X.begin(), X.end());
  vector<long long> A(n, 0);
  long long S = 0;
  for (int i = n * 2 - 1; i >= 0; i--){
    int id = get<1>(X[i]);
    int t = get<2>(X[i]);
    if (t == 0){
      A[id] = S;
      S *= 2;
      if (s[id] == 1){
        S++;
        A[id]++;
      }
      S %= MOD;
    }
    if (t == 1){
      S += MOD - A[id];
      S %= MOD;
    }
  }
  long long ans = x[n - 1] + 1;
  for (int i = 0; i < n; i++){
    ans += A[i] * (x[i] - y[i]);
    ans %= MOD;
  }
  cout << ans << endl;
}