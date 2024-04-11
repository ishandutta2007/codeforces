#include <bits/stdc++.h>
using namespace std;
const long long MOD = 1000000007;
long long solve1(vector<int> &A, int N, int M){
  vector<vector<long long>> dp(N + 1, vector<long long>(M / 2 + 1, 0));
  dp[0][0] = 1;
  for (int i = 0; i < N; i++){
    dp[i + 1] = dp[i];
    for (int j = 0; j <= M / 2 - A[i]; j++){
      dp[i + 1][j + A[i]] += dp[i][j];
      dp[i + 1][j + A[i]] %= MOD;
    }
  }
  return dp[N][M / 2];
}
long long solve2(vector<int> &A, int N, int M){
  vector<vector<long long>> dp1(N + 1, vector<long long>(M * 2 + 1, 0));
  dp1[0][M] = 1;
  for (int i = 0; i < N; i++){
    for (int j = 0; j <= M * 2; j++){
      dp1[i + 1][j] += dp1[i][j];
      dp1[i + 1][j] %= MOD;
      if (j + A[i] <= M * 2){
        dp1[i + 1][j + A[i]] += dp1[i][j];
        dp1[i + 1][j + A[i]] %= MOD;
      }
      if (j - A[i] >= 0){
        dp1[i + 1][j - A[i]] += dp1[i][j];
        dp1[i + 1][j - A[i]] %= MOD;
      }
    }
  }
  vector<vector<long long>> dp2(N + 1, vector<long long>(M * 2 + 1, 0));
  dp2[N][M] = 1;
  for (int i = N - 1; i >= 0; i--){
    for (int j = 0; j <= M * 2; j++){
      dp2[i][j] += dp2[i + 1][j];
      dp2[i][j] %= MOD;
      if (j + A[i] <= M * 2){
        dp2[i][j + A[i]] += dp2[i + 1][j];
        dp2[i][j + A[i]] %= MOD;
      }
      if (j - A[i] >= 0){
        dp2[i][j - A[i]] += dp2[i + 1][j];
        dp2[i][j - A[i]] %= MOD;
      }
    }
  }
  long long ans = 0;
  for (int i = 0; i < N; i++){
    vector<long long> S(M * 2 + 2);
    S[0] = 0;
    for (int j = 0; j < M * 2 + 1; j++){
      S[j + 1] = (S[j] + dp2[i + 1][j]) % MOD;
    }
    for (int j = 0; j < M * 2 + 1; j++){
      int l = (2 * M - j) - (A[i] - 2);
      int r = (2 * M - j) + (A[i] - 2) + 1;
      l = max(l, 0);
      r = min(r, M * 2 + 1);
      long long tmp = (S[r] - S[l] + MOD) * dp1[i][j] % MOD;
      ans += tmp;
    }
  }
  ans *= 2;
  ans %= MOD;
  return ans;
}
long long solve3(vector<int> &A, int N, int M){
  vector<vector<long long>> dp1(N + 1, vector<long long>(M * 2 + 1, 0));
  dp1[0][M] = 1;
  for (int i = 0; i < N; i++){
    for (int j = 0; j <= M * 2; j++){
      if (j + A[i] <= M * 2){
        dp1[i + 1][j + A[i]] += dp1[i][j];
        dp1[i + 1][j + A[i]] %= MOD;
      }
      if (j - A[i] >= 0){
        dp1[i + 1][j - A[i]] += dp1[i][j];
        dp1[i + 1][j - A[i]] %= MOD;
      }
    }
  }
  vector<vector<long long>> dp2(N + 1, vector<long long>(M * 2 + 1, 0));
  dp2[N][M] = 1;
  for (int i = N - 1; i >= 0; i--){
    for (int j = 0; j <= M * 2; j++){
      if (j + A[i] <= M * 2){
        dp2[i][j + A[i]] += dp2[i + 1][j];
        dp2[i][j + A[i]] %= MOD;
      }
      if (j - A[i] >= 0){
        dp2[i][j - A[i]] += dp2[i + 1][j];
        dp2[i][j - A[i]] %= MOD;
      }
    }
  }
  long long ans = 0;
  for (int i = 0; i < N; i++){
    for (int j = 0; j <= M * 2; j++){
      int x = (2 * M - j) + (A[i] - 1);
      if (0 <= x && x <= M * 2){
        ans += dp1[i][j] * dp2[i + 1][x] % MOD;
      }
    }
  }
  ans *= 4;
  ans %= MOD;
  return ans;
}
int main(){
  int N, M;
  cin >> N >> M;
  vector<vector<int>> E(N);
  for (int i = 0; i < M; i++){
    int U, V;
    cin >> U >> V;
    U--;
    V--;
    E[U].push_back(V);
    E[V].push_back(U);
  }
  vector<bool> used(N, false);
  used[0] = true;
  vector<int> A;
  for (int i = 1; i < N; i++){
    if (!used[i]){
      used[i] = true;
      int cnt = 2;
      queue<int> Q;
      Q.push(i);
      while (!Q.empty()){
        int v = Q.front();
        Q.pop();
        for (int w : E[v]){
          if (!used[w]){
            used[w] = true;
            Q.push(w);
            cnt++;
          }
        }
      }
      A.push_back(cnt);
    }
  }
  int L = A.size();
  /*
  cout << "L = " << L << endl;
  for (int i = 0; i < L; i++){
    cout << A[i] << ' ';
  }
  cout << endl;
  */
  long long ans = 0;
  if (M % 2 == 0){
    long long ans1 = solve1(A, L, M);
    ans += ans1;
    //cout << "ans1 = " << ans1 << endl;
  }
  long long ans2 = solve2(A, L, M);
  ans += ans2;
  //cout << "ans2 = " << ans2 << endl;
  if (M % 2 == 1){
    long long ans3 = solve3(A, L, M);
    ans += ans3;
    //cout << "ans3 = " << ans3 << endl;
  }
  ans %= MOD;
  cout << ans << endl;
}