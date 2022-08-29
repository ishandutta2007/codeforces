#include <bits/stdc++.h>
using namespace std;
const int INF = 1000000;
void add_edge(int &M, vector<vector<int>> &from, vector<vector<int>> &to, vector<int> &id1, vector<int> &id2){
  if (id1.empty() || id2.empty()){
    return;
  }
  int cnt1 = id1.size();
  int cnt2 = id2.size();
  for (int i = 0; i < cnt1; i++){
    from[id1[i]].push_back(M);
  }
  for (int i = 0; i < cnt2; i++){
    to[id2[i]].push_back(M);
  }
  M++;
}
void dfs(int &M, vector<vector<int>> &from, vector<vector<int>> &to, vector<int> &c2, vector<int> &id, int L1, int R1, int L2, int R2, int p){
  if (p == -1){
    sort(id.begin() + L1, id.begin() + R1);
    return;
  }
  int M2 = L2 + (1 << p);
  int M1 = lower_bound(c2.begin(), c2.end(), M2) - c2.begin();
  if (L1 < M1){
    dfs(M, from, to, c2, id, L1, M1, L2, M2, p - 1);
  }
  if (M1 < R1){
    dfs(M, from, to, c2, id, M1, R1, M2, R2, p - 1);
  }
  int p1 = L1, p2 = M1;
  while (p1 < M1 && p2 < R1){
    if ((c2[p1] >> (p + 1)) < (c2[p2] >> (p + 1))){
      p1++;
    } else if ((c2[p1] >> (p + 1)) > (c2[p2] >> (p + 1))){
      p2++;
    } else {
      int s = c2[p1] >> (p + 1);
      vector<int> l0, r0, l1, r1;
      while (p1 < M1){
        if ((c2[p1] >> (p + 1)) > s){
          break;
        }
        if ((id[p1] >> p & 1) == 0){
          l0.push_back(id[p1]);
        } else {
          l1.push_back(id[p1]);
        }
        p1++;
      }
      while (p2 < R1){
        if ((c2[p2] >> (p + 1)) > s){
          break;
        }
        if ((id[p2] >> p & 1) == 0){
          r0.push_back(id[p2]);
        } else {
          r1.push_back(id[p2]);
        }
        p2++;
      }
      add_edge(M, from, to, l0, r0);
      add_edge(M, from, to, l1, r1);
      add_edge(M, from, to, r0, l1);
      add_edge(M, from, to, r1, l0);
    }
  }
  vector<int> tmp;
  merge(id.begin() + L1, id.begin() + M1, id.begin() + M1, id.begin() + R1, back_inserter(tmp));
  copy(tmp.begin(), tmp.end(), id.begin() + L1);
}
int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int t;
  cin >> t;
  for (int i = 0; i < t; i++){
    int n;
    cin >> n;
    vector<int> a(n);
    for (int j = 0; j < n; j++){
      cin >> a[j];
    }
    vector<int> c(n);
    for (int j = 0; j < n; j++){
      c[j] = a[j] ^ j;
    }
    vector<pair<int, int>> P(n);
    for (int j = 0; j < n; j++){
      P[j] = make_pair(c[j], j);
    }
    sort(P.begin(), P.end());
    vector<int> c2(n), id(n);
    for (int j = 0; j < n; j++){
      c2[j] = P[j].first;
      id[j] = P[j].second;
    }
    int M = 0;
    vector<vector<int>> to(n), from(n);
    dfs(M, to, from, c2, id, 0, n, 0, 1 << 30, 29);
    vector<int> dp(n, 1);
    vector<int> dp2(M, -INF);
    for (int j = 0; j < n; j++){
      for (int k : from[j]){
        dp[j] = max(dp[j], dp2[k] + 1);
      }
      for (int k : to[j]){
        dp2[k] = max(dp2[k], dp[j]);
      }
    }
    int ans = 0;
    for (int j = 0; j < n; j++){
      ans = max(ans, dp[j]);
    }
    cout << ans << "\n";
  }
}