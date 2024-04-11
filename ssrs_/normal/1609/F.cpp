#pragma GCC target("popcnt")
#include <bits/stdc++.h>
using namespace std;
const int LOG = 60;
const long long BASE = 123456789;
const long long MOD = 998244353;
long long f(long long a, long long b){
  a %= MOD;
  return (a * BASE + b) % MOD;
}
long long dfs(vector<long long> &a, int L, int R){
  if (R - L <= 30){
    long long ans = 0;
    for (int i = L; i < R; i++){
      long long mn = a[i], mx = a[i];
      for (int j = i; j < R; j++){
        mn = min(mn, a[j]);
        mx = max(mx, a[j]);
        if (__builtin_popcountll(mn) == __builtin_popcountll(mx)){
          ans++;
        }
      }
    }
    return ans;
  }
  int m = (L + R) / 2;
  int cnt1 = m - L, cnt2 = R - m - 1;
  vector<long long> mnL(cnt1 + 1, a[m]), mxL(cnt1 + 1, a[m]);
  for (int i = 0; i < cnt1; i++){
    long long x = a[m - 1 - i];
    mnL[i + 1] = min(mnL[i], x);
    mxL[i + 1] = max(mxL[i], x);
  }
  vector<long long> mnR(cnt2 + 1, a[m]), mxR(cnt2 + 1, a[m]);
  for (int i = 0; i < cnt2; i++){
    long long x = a[m + 1 + i];
    mnR[i + 1] = min(mnR[i], x);
    mxR[i + 1] = max(mxR[i], x);
  }
  long long ans = 0;
  map<long long, int> mp;
  for (int i = 0; i < 2; i++){
    for (int j = cnt1; j >= 0; j--){
      if (__builtin_popcountll(mnL[j]) == __builtin_popcountll(mxL[j])){
        if (i == 0){
          mp[f(mnL[j], mxL[j])] = j;
        }
        int tv = 0, fv = cnt2 + 1;
        if (j == 0){
          fv = 1;
        }
        if (i == 1){
          long long h = f(mnL[j], mxL[j]);
          if (mp.count(h) == 1){
            fv = min(fv, max(mp[h], 1));
          }
        }
        while (fv - tv > 1){
          int mid = (tv + fv) / 2;
          if (mnR[mid] >= mnL[j] && mxR[mid] <= mxL[j]){
            tv = mid;
          } else {
            fv = mid;
          }
        }
        ans += tv + 1;
      }
    }
    vector<vector<long long>> pos(LOG);
    for (int j = 0; j <= cnt2; j++){
      pos[__builtin_popcountll(mxR[j])].push_back(j);
    }
    for (int j = 0; j <= cnt1; j++){
      int tv1 = cnt2 + 1, fv1 = 0;
      while (tv1 - fv1 > 1){
        int mid = (tv1 + fv1) / 2;
        if (mxR[mid] > mxL[j]){
          tv1 = mid;
        } else {
          fv1 = mid;
        }
      }
      if (tv1 < cnt2 + 1){
        if (mnR[tv1] > mnL[j]){
          int tv2 = tv1, fv2 = cnt2 + 1;
          while (fv2 - tv2 > 1){
            int mid = (tv2 + fv2) / 2;
            if (mnR[mid] > mnL[j]){
              tv2 = mid;
            } else {
              fv2 = mid;
            }
          }
          int p = __builtin_popcountll(mnL[j]);
          ans += upper_bound(pos[p].begin(), pos[p].end(), tv2) - lower_bound(pos[p].begin(), pos[p].end(), tv1);
        }
      }
    }
    swap(cnt1, cnt2);
    swap(mnL, mnR);
    swap(mxL, mxR);
  }
  ans--;
  ans += dfs(a, L, m);
  ans += dfs(a, m + 1, R);
  return ans;
}
int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n;
  cin >> n;
  vector<long long> a(n);
  for (int i = 0; i < n; i++){
    cin >> a[i];
  }
  cout << dfs(a, 0, n) << "\n";
}