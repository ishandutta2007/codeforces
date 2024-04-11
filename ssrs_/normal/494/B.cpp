#include <bits/stdc++.h>
using namespace std;
const long long MOD = 1000000007;
vector<int> z_algorithm(string S){
  int N = S.size();
  vector<int> ans(N);
  for (int i = 1, j = 0; i < N; i++){
    if (i + ans[i - j] < j + ans[j]){
      ans[i] = ans[i - j];
    } else {
      int k = max(0, j + ans[j] - i);
      while (i + k < N && S[k] == S[i + k]){
        k++;
      }
      ans[i] = k;
      j = i;
    }
  }
  ans[0] = N;
  return ans;
}
int main(){
  string s;
  cin >> s;
  string t;
  cin >> t;
  int N = s.size();
  int M = t.size();
  string ts = t + "#" + s;
  vector<int> a = z_algorithm(ts);
  vector<int> r;
  for (int i = 0; i < N; i++){
    if (a[M + 1 + i] == M){
      r.push_back(i + M);
    }
  }
  if (r.empty()){
    cout << 0 << endl;
  } else {
    vector<long long> dpS1(N + 2, 0);
    vector<long long> dpS2(N + 2, 0);
    dpS1[1] = 1;
    for (int i = 1; i <= N; i++){
      long long dp = 0;
      if (i >= r[0]){
        int R = *(upper_bound(r.begin(), r.end(), i) - 1);
        int L = R - M;
        dp = (L + 1) * dpS1[L + 1] - dpS2[L + 1] + MOD;
        dp %= MOD;
      }
      dpS1[i + 1] = dpS1[i] + dp;
      dpS1[i + 1] %= MOD;
      dpS2[i + 1] = dpS2[i] + dp * i;
      dpS2[i + 1] %= MOD;
    }
    cout << (dpS1[N + 1] + MOD - 1) % MOD << endl;
  }
}