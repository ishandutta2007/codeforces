#include <bits/stdc++.h>
using namespace std;
const long long INF = 1000000000000000;
int main(){
  int n, m;
  cin >> n >> m;
  vector<int> x(n);
  for (int i = 0; i < n; i++){
    cin >> x[i];
  }
  vector<int> p(m), c(m);
  for (int i = 0; i < m; i++){
    cin >> p[i] >> c[i];
  }
  sort(x.begin(), x.end());
  vector<pair<int, int>> P(m);
  for (int i = 0; i < m; i++){
    P[i] = make_pair(p[i], c[i]);
  }
  sort(P.begin(), P.end());
  for (int i = 0; i < m; i++){
    p[i] = P[i].first;
    c[i] = P[i].second;
  }
  int sum = 0;
  for (int i = 0; i < m; i++){
    sum += c[i];
  }
  if (sum < n){
    cout << -1 << endl;
  } else {
    vector<long long> dp(n + 1, INF);
    dp[0] = 0;
    for (int i = 0; i < m; i++){
      vector<long long> d(n);
      for (int j = 0; j < n; j++){
        d[j] = abs(x[j] - p[i]);
      }
      vector<long long> S(n + 1);
      S[0] = 0;
      for (int j = 0; j < n; j++){
        S[j + 1] = S[j] + d[j];
      }
      vector<long long> a(n + 1);
      for (int j = 0; j <= n; j++){
        a[j] = dp[j] - S[j];
      }
      deque<int> dq;
      for (int j = 0; j <= n; j++){
        while (!dq.empty()){
          if (a[dq.back()] >= a[j]){
            dq.pop_back();
          } else {
            break;
          }
        }
        dq.push_back(j);
        dp[j] = a[dq.front()] + S[j];
        if (dq.front() == j - c[i]){
          dq.pop_front();
        }
      }
    }
    cout << dp[n] << endl;
  }
}