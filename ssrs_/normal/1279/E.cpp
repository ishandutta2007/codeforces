#include <bits/stdc++.h>
using namespace std;
int main(){
  vector<long long> cnt(23), dp(23, 0);
  cnt[0] = 1;
  dp[0] = 1;
  cnt[1] = 1;
  dp[1] = 1;
  cnt[2] = 1;
  dp[2] = 2;
  for (int i = 3; i < 23; i++){
    cnt[i] = cnt[i - 1] * (i - 2);
    for (int j = 0; j < i; j++){
      dp[i] += dp[j] * cnt[i - j];
    }
  }
  int t;
  cin >> t;
  for (int i = 0; i < t; i++){
    int n;
    long long k;
    cin >> n >> k;
    k--;
    vector<int> ans;
    int next = 1;
    while (n >= 23){
      ans.push_back(next);
      n--;
      next++;
    }
    if (k >= dp[n]){
      cout << -1 << endl;
    } else {
      while (n > 0){
        vector<long long> lcnt(n);
        for (int j = 0; j < n; j++){
          lcnt[j] = cnt[j + 1] * dp[n - 1 - j];
        }
        vector<long long> lsum(n + 1);
        lsum[0] = 0;
        for (int j = 0; j < n; j++){
          lsum[j + 1] = lsum[j] + lcnt[j];
        }
        int L = upper_bound(lsum.begin(), lsum.end(), k) - lsum.begin();
        k -= lsum[L - 1];
        long long k2 = k / dp[n - L];
        vector<int> p(L, -1);
        p[0] = L - 1;
        for (int j = 1; j < L - 2; j++){
          vector<bool> ok(L, true);
          for (int l = 0; l < j; l++){
            ok[p[l]] = false;
          }
          vector<int> q(L, -1);
          for (int l = 0; l < j; l++){
            q[p[l]] = l;
          }
          int c = j;
          while (q[c] != -1){
            c = q[c];
          }
          ok[c] = false;
          vector<int> r;
          for (int l = 0; l < L; l++){
            if (ok[l]){
              r.push_back(l);
            }
          }
          p[j] = r[k2 / cnt[L - j]];
          k2 %= cnt[L - j];
        }
        if (L == 2){
          p[L - 1] = 0;
        } else if (L >= 3){
          vector<int> q(L, -1);
          for (int j = 0; j < L - 2; j++){
            q[p[j]] = j;
          }
          int c = L - 1;
          while (q[c] != -1){
            c = q[c];
          }
          p[L - 2] = c;
          vector<bool> used(L, false);
          for (int j = 0; j < L - 1; j++){
            used[p[j]] = true;
          }
          for (int j = 0; j < L; j++){
            if (!used[j]){
              p[L - 1] = j;
            }
          }
        }
        for (int j = 0; j < L; j++){
          ans.push_back(next + p[j]);
        }
        k %= dp[n - L];
        n -= L;
        next += L;
      }
      n = ans.size();
      for (int j = 0; j < n; j++){
        cout << ans[j];
        if (j < n - 1){
          cout << ' ';
        }
      }
      cout << endl;
    }
  }
}