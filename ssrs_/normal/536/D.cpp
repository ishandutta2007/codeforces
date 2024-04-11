#include <bits/stdc++.h>
using namespace std;
int main(){
  int n, m;
  cin >> n >> m;
  int s, t;
  cin >> s >> t;
  s--;
  t--;
  vector<int> p(n);
  for (int i = 0; i < n; i++){
    cin >> p[i];
  }
  vector<vector<pair<int, int>>> E(n);
  for (int i = 0; i < m; i++){
    int u, v, w;
    cin >> u >> v >> w;
    u--;
    v--;
    E[u].push_back(make_pair(w, v));
    E[v].push_back(make_pair(w, u));
  }
  vector<long long> d1(n, -1);
  priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> pq1;
  pq1.push(make_pair(0, s));
  while (!pq1.empty()){
    long long d = pq1.top().first;
    int v = pq1.top().second;
    pq1.pop();
    if (d1[v] == -1){
      d1[v] = d;
      for (auto P : E[v]){
        int w = P.second;
        if (d1[w] == -1){
          pq1.push(make_pair(d + P.first, w));
        }
      }
    }
  }
  vector<long long> d2(n, -1);
  priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> pq2;
  pq2.push(make_pair(0, t));
  while (!pq2.empty()){
    long long d = pq2.top().first;
    int v = pq2.top().second;
    pq2.pop();
    if (d2[v] == -1){
      d2[v] = d;
      for (auto P : E[v]){
        int w = P.second;
        if (d2[w] == -1){
          pq2.push(make_pair(d + P.first, w));
        }
      }
    }
  }
  vector<long long> ds1 = d1;
  sort(ds1.begin(), ds1.end());
  ds1.erase(unique(ds1.begin(), ds1.end()), ds1.end());
  vector<long long> ds2 = d2;
  sort(ds2.begin(), ds2.end());
  ds2.erase(unique(ds2.begin(), ds2.end()), ds2.end());
  int cnt1 = ds1.size();
  int cnt2 = ds2.size();
  vector<int> x(n), y(n);
  for (int i = 0; i < n; i++){
    x[i] = lower_bound(ds1.begin(), ds1.end(), d1[i]) - ds1.begin();
    y[i] = lower_bound(ds2.begin(), ds2.end(), d2[i]) - ds2.begin();
  }
  vector<vector<long long>> S(cnt1 + 1, vector<long long>(cnt2 + 1, 0));
  vector<vector<int>> mnx(cnt1 + 1, vector<int>(cnt2 + 1, cnt1));
  vector<vector<int>> mny(cnt1 + 1, vector<int>(cnt2 + 1, cnt2));
  for (int i = 0; i < n; i++){
    S[x[i]][y[i]] += p[i];
    mnx[x[i]][y[i]] = x[i];
    mny[x[i]][y[i]] = y[i];
  }
  for (int i = 0; i < cnt1; i++){
    for (int j = cnt2 - 1; j >= 0; j--){
      S[i][j] += S[i][j + 1];
      mnx[i][j] = min(mnx[i][j], mnx[i][j + 1]);
      mny[i][j] = min(mny[i][j], mny[i][j + 1]);
    }
  }
  for (int i = 0; i < cnt2; i++){
    for (int j = cnt1 - 1; j >= 0; j--){
      S[j][i] += S[j + 1][i];
      mnx[j][i] = min(mnx[j][i], mnx[j + 1][i]);
      mny[j][i] = min(mny[j][i], mny[j + 1][i]);
    }
  }
  vector<vector<vector<long long>>> dp(2, vector<vector<long long>>(cnt1 + 1, vector<long long>(cnt2 + 1, 0)));
  vector<vector<long long>> mn1(cnt1 + 1, vector<long long>(cnt2 + 1, 0));
  vector<vector<long long>> mn2(cnt1 + 1, vector<long long>(cnt2 + 1, 0));
  for (int i = cnt1 - 1; i >= 0; i--){
    for (int j = cnt2 - 1; j >= 0; j--){
      mn1[i][j] = mn1[i + 1][j];
      mn2[i][j] = mn2[i][j + 1];
      if (mnx[i][j] == i || mny[i][j] == j){
        dp[0][i][j] = S[i][j] - mn1[mnx[i + 1][j]][j];
        dp[1][i][j] = S[i][j] - mn2[i][mny[i][j + 1]];
        mn1[i][j] = min(mn1[i][j], S[i][j] + dp[1][i][j]);
        mn2[i][j] = min(mn2[i][j], S[i][j] + dp[0][i][j]);
      }
    }
  }
  if (dp[0][0][0] > 0){
    cout << "Break a heart" << endl;
  } else if (dp[0][0][0] < 0){
    cout << "Cry" << endl;
  } else {
    cout << "Flowers" << endl;
  }
}