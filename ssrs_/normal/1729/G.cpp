#include <bits/stdc++.h>
using namespace std;
const int INF = 10000;
const long long MOD = 1000000007;
int main(){
  int q;
  cin >> q;
  for (int i = 0; i < q; i++){
    string s;
    cin >> s;
    string t;
    cin >> t;
    int N = s.size();
    int M = t.size();
    vector<int> p;
    for (int j = 0; j <= N - M; j++){
      if (s.substr(j, M) == t){
        p.push_back(j);
      }
    }
    int cnt = p.size();
    if (cnt == 0){
      cout << 0 << ' ' << 1 << endl;
    } else {
      vector<int> dp1(cnt, INF);
      vector<long long> dp2(cnt, 0);
      for (int j = 0; j < cnt; j++){
        if (p[j] - p[0] < M){
          dp1[j] = 1;
          dp2[j] = 1;
        }
      }
      for (int j = 0; j < cnt; j++){
        int x = -1;
        for (int k = j + 1; k < cnt; k++){
          if (p[k] - p[j] >= M){
            if (x == -1){
              x = p[k];
            }
            if (p[k] - x >= M){
              break;
            }
            if (dp1[k] > dp1[j] + 1){
              dp1[k] = dp1[j] + 1;
              dp2[k] = 0;
            }
            if (dp1[k] == dp1[j] + 1){
              dp2[k] += dp2[j];
              dp2[k] %= MOD;
            }
          }
        }
      }
      int mn = INF;
      long long ans = 0;
      for (int j = cnt - 1; j >= 0; j--){
        if (p[cnt - 1] - p[j] < M){
          if (mn > dp1[j]){
            mn = dp1[j];
            ans = 0;
          }
          if (mn == dp1[j]){
            ans += dp2[j];
            ans %= MOD;
          }
        }
      }
      cout << mn << ' ' << ans << endl;
    }
  }
}