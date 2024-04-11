#include <bits/stdc++.h>
using namespace std;
const long long INF = 1100000000000000000;
bool comp(string &s, vector<vector<int>> &lcp, pair<int, int> p1, pair<int, int> p2){
  int l = lcp[p1.first][p2.first];
  if (p1.second - p1.first <= l || p2.second - p2.first <= l){
    return p1.second - p1.first < p2.second - p2.first;
  } else {
    return s[p1.first + l] < s[p2.first + l];
  }
}
void mergesort(string &s, vector<vector<int>> &lcp, vector<pair<int, int>> &P, int L, int R){
  if (R - L >= 2){
    int m = (L + R) / 2;
    mergesort(s, lcp, P, L, m);
    mergesort(s, lcp, P, m, R);
    vector<pair<int, int>> ans;
    int p1 = L, p2 = m;
    while (p1 < m || p2 < R){
      if (p1 == m){
        ans.push_back(P[p2]);
        p2++;
      } else if (p2 == R){
        ans.push_back(P[p1]);
        p1++;
      } else if (comp(s, lcp, P[p1], P[p2])){
        ans.push_back(P[p1]);
        p1++;
      } else {
        ans.push_back(P[p2]);
        p2++;
      }
    }
    for (int i = 0; i < R - L; i++){
      P[L + i] = ans[i];
    }
  }
}
int main(){
  int n, m;
  long long k;
  cin >> n >> m >> k;
  string s;
  cin >> s;
  s += '`';
  vector<vector<int>> lcp(n + 1, vector<int>(n + 1, 0));
  for (int i = n - 1; i >= 0; i--){
    for (int j = n - 1; j >= 0; j--){
      if (s[i] == s[j]){
        lcp[i][j] = lcp[i + 1][j + 1] + 1;
      }
    }
  }
  vector<pair<int, int>> P;
  for (int i = 0; i < n; i++){
    for (int j = i + 1; j <= n; j++){
      P.push_back(make_pair(i, j));
    }
  }
  int cnt = P.size();
  mergesort(s, lcp, P, 0, cnt);
  int tv = 0, fv = cnt;
  while (fv - tv > 1){
    int mid = (tv + fv) / 2;
    vector<int> mn(n, n + 1);
    for (int i = cnt - 1; i >= mid; i--){
      mn[P[i].first] = P[i].second;
    }
    vector<long long> dp(n + 1, 0);
    dp[0] = 1;
    for (int i = 0; i < m; i++){
      vector<long long> imos(n + 2, 0);
      for (int j = 0; j < n; j++){
        imos[mn[j]] = min(imos[mn[j]] + dp[j], INF);
      }
      for (int j = 0; j <= n; j++){
        imos[j + 1] = min(imos[j + 1] + imos[j], INF);
        dp[j] = imos[j];
      }
    }
    if (dp[n] >= k){
      tv = mid;
    } else {
      fv = mid;
    }
  }
  cout << s.substr(P[tv].first, P[tv].second - P[tv].first) << endl;
}