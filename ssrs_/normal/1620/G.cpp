#include <bits/stdc++.h>
using namespace std;
const int INF = 100000;
const long long MOD = 998244353;
int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n;
  cin >> n;
  vector<string> s(n);
  for (int i = 0; i < n; i++){
    cin >> s[i];
  }
  vector<vector<int>> cnt(n, vector<int>(26, 0));
  for (int i = 0; i < n; i++){
    int L = s[i].size();
    for (int j = 0; j < L; j++){
      cnt[i][s[i][j] - 'a']++;
    }
  }
  vector<long long> ans(1 << n, 1);
  for (int i = 0; i < 26; i++){
    vector<pair<int, int>> P(n);
    for (int j = 0; j < n; j++){
      P[j] = make_pair(cnt[j][i], j);
    }
    sort(P.begin(), P.end());
    int S = (1 << n) - 1;
    vector<long long> mn(1 << n, INF);
    for (int j = 0; j < n; j++){
      S -= 1 << P[j].second;
      for (int k = S; k >= 0; k = (k - 1) & S){
        mn[k | (1 << P[j].second)] = P[j].first;
        if (k == 0){
          break;
        }
      }
    }
    for (int j = 0; j < (1 << n); j++){
      ans[j] *= mn[j] + 1;
      ans[j] %= MOD;
    }
  }
  ans[0] = 0;
  for (int i = 1; i < (1 << n); i++){
    if (__builtin_parity(i) == 0){
      ans[i] = MOD - ans[i];
    }
  }
  for (int i = 0; i < n; i++){
    for (int j = 0; j < (1 << n); j++){
      if ((j >> i & 1) == 1){
        ans[j] += ans[j ^ (1 << i)];
        if (ans[j] >= MOD){
          ans[j] -= MOD;
        }
      }
    }
  }
  long long ans2 = 0;
  for (int i = 0; i < (1 << n); i++){
    int s = 0;
    for (int j = 0; j < n; j++){
      if ((i >> j & 1) == 1){
        s += j + 1;
      }
    }
    ans2 ^= (ans[i] * s * __builtin_popcount(i));
  }
  cout << ans2 << endl;
}