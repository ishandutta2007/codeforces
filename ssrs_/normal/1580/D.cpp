#include <bits/stdc++.h>
using namespace std;
const long long INF = 1000000000000000000;
int main(){
  int n, m;
  cin >> n >> m;
  vector<long long> a(n);
  for (int i = 0; i < n; i++){
    cin >> a[i];
  }
  vector<pair<long long, int>> P(n);
  for (int i = 0; i < n; i++){
    P[i] = make_pair(a[i], i);
  }
  sort(P.begin(), P.end());
  vector<int> p(n, -1);
  set<int> st;
  st.insert(P[0].second);
  for (int i = 1; i < n; i++){
    int id = P[i].second;
    auto itr = st.lower_bound(id);
    if (itr == st.begin()){
      p[id] = *itr;
    } else if (itr == st.end()){
      p[id] = *prev(itr);
    } else {
      int x = *itr;
      int y = *prev(itr);
      if (a[x] > a[y]){
        p[id] = x;
      } else {
        p[id] = y;
      }
    }
    st.insert(id);
  }
  int r = P[0].second;
  vector<vector<int>> c(n);
  for (int i = 0; i < n; i++){
    if (i != r){
      c[p[i]].push_back(i);
    }
  }
  vector<vector<long long>> dp(n + 1);
  dp[n] = {0};
  for (int i = n - 1; i >= 0; i--){
    int v = P[i].second;
    int L = n, R = n;
    for (int w : c[v]){
      if (w < v){
        L = w;
      }
      if (w > v){
        R = w;
      }
    }
    int cnt1 = dp[L].size();
    int cnt2 = dp[R].size();
    dp[v] = vector<long long>(cnt1 + cnt2, -INF);
    for (int j = 0; j < cnt1; j++){
      for (int k = 0; k < cnt2; k++){
        dp[v][j + k] = max(dp[v][j + k], dp[L][j] + dp[R][k] - a[v] * j * k * 2);
        dp[v][j + k + 1] = max(dp[v][j + k + 1], dp[L][j] + dp[R][k] + m * a[v] - a[v] * (j * k * 2 + j * 2 + k * 2 + 1));
      }
    }
  }
  cout << dp[r][m] << endl;
}