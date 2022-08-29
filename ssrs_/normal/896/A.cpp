#include <bits/stdc++.h>
using namespace std;
string f0 = "What are you doing at the end of the world? Are you busy? Will you save us?";
string fa = "What are you doing while sending \"";
string fb = "\"? Are you busy? Will you send \"";
string fc = "\"?";
char dfs(vector<long long> &dp, int n, long long k){
  if (n == 0){
    return f0[k];
  }
  if (k < fa.size()){
    return fa[k];
  }
  k -= fa.size();
  if (k < dp[n - 1]){
    return dfs(dp, n - 1, k);
  }
  k -= dp[n - 1];
  if (k < fb.size()){
    return fb[k];
  }
  k -= fb.size();
  if (k < dp[n - 1]){
    return dfs(dp, n - 1, k);
  }
  k -= dp[n - 1];
  return fc[k];
}
int main(){
  int q;
  cin >> q;
  for (int i = 0; i < q; i++){
    int n;
    long long k;
    cin >> n >> k;
    vector<long long> dp(n + 1);
    dp[0] = f0.size();
    for (int j = 0; j < n; j++){
      dp[j + 1] = fa.size() + dp[j] + fb.size() + dp[j] + fc.size();
      dp[j + 1] = min(dp[j + 1], k + 1);
    }
    if (dp[n] < k){
      cout << '.';
    } else {
      k--;
      cout << dfs(dp, n, k);
    }
  }
  cout << endl;
}