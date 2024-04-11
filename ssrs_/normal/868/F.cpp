#include <bits/stdc++.h>
using namespace std;
const long long INF = 1000000000000;
struct S{
  vector<int> A;
  vector<int> cnt;
  int L, R;
  long long cost;
  S(vector<int> a): A(a){
    int N = A.size();
    cnt = vector<int>(N, 0);
    L = 0, R = 0, cost = 0;
  }
  long long f(int l, int r){
    while (l < L){
      L--;
      cost += cnt[A[L]];
      cnt[A[L]]++;
    }
    while (R < r){
      cost += cnt[A[R]];
      cnt[A[R]]++;
      R++;
    }
    while (L < l){
      cnt[A[L]]--;
      cost -= cnt[A[L]];
      L++;
    }
    while (r < R){
      R--;
      cnt[A[R]]--;
      cost -= cnt[A[R]];
    }
    return cost;
  }
};
void dfs(vector<vector<long long>> &dp, S &s, int l, int r, int l2, int r2, int p){
  if (l >= r){
    return;
  }
  int mid = (l + r) / 2;
  int m2 = -1;
  for (int i = l2; i < min(mid + 1, r2); i++){
    long long S = dp[p][i] + s.f(i, mid);
    if (dp[p + 1][mid] > S){
      dp[p + 1][mid] = S;
      m2 = i;
    }
  }
  dfs(dp, s, l, mid, l2, m2 + 1, p);
  dfs(dp, s, mid + 1, r, m2, r2, p);
}
int main(){
  int n, k;
  cin >> n >> k;
  vector<int> a(n);
  for (int i = 0; i < n; i++){
    cin >> a[i];
    a[i]--;
  }
  S s(a);
  vector<vector<long long>> dp(k + 1, vector<long long>(n + 1, INF));
  dp[0][0] = 0;
  for (int i = 0; i < k; i++){
    dfs(dp, s, 0, n + 1, 0, n + 1, i);
  }
  cout << dp[k][n] << endl;
}