#include <bits/stdc++.h>
using namespace std;
const long long MOD = 1000000007;
long long dfs(vector<long long> &dp, vector<int> &a, vector<vector<int>> &c, int v = 0){
  dp[v] = a[v];
  for (int w : c[v]){
    dp[v] += dfs(dp, a, c, w);
  }
  return dp[v];
}
vector<long long> list_factors(long long N){
  vector<long long> ans;
  for (long long i = 1; i * i <= N; i++){
    if (N % i == 0){
      ans.push_back(i);
      if (i * i < N){
        ans.push_back(N / i);
      }
    }
  }
  sort(ans.rbegin(), ans.rend());
  return ans;
}
int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; i++){
    cin >> a[i];
  }
  vector<int> p(n);
  p[0] = -1;
  for (int i = 1; i < n; i++){
    cin >> p[i];
    p[i]--;
  }
  vector<vector<int>> c(n);
  for (int i = 1; i < n; i++){
    c[p[i]].push_back(i);
  }
  long long sum = 0;
  for (int i = 0; i < n; i++){
    sum += a[i];
  }
  vector<long long> dp(n);
  dfs(dp, a, c);
  //list factors of sum
  vector<long long> fact = list_factors(sum);
  int cnt = fact.size();
  map<long long, int> mp;
  for (int i = 0; i < n; i++){
    mp[__gcd(dp[i], sum)]++;
  }
  vector<bool> ok(cnt, false);
  for (int i = 0; i < cnt; i++){
    int tmp = 0;
    for (auto P : mp){
      if (P.first % fact[i] == 0){
        tmp += P.second;
      }
    }
    if (tmp == sum / fact[i]){
      ok[i] = true;
    }
  }
  vector<long long> dp2(cnt, 0);
  dp2[0] = 1;
  for (int i = 1; i < cnt; i++){
    if (ok[i]){
      for (int j = 0; j < i; j++){
        if (fact[j] % fact[i] == 0 && ok[j]){
          dp2[i] += dp2[j];
          dp2[i] %= MOD;
        }
      }
    }
  }
  long long ans = 0;
  for (int i = 0; i < cnt; i++){
    ans += dp2[i];
  }
  ans %= MOD;
  cout << ans << endl;
}