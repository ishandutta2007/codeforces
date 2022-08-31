#include <bits/stdc++.h>
using namespace std;
const long long MOD = 1000000007;
int main(){
  int n, m;
  cin >> n >> m;
  vector<vector<pair<long long, int>>> E(n);
  for (int i = 0; i < m; i++){
    int u, v;
    long long t;
    cin >> u >> v >> t;
    u--;
    v--;
    E[u].push_back(make_pair(t, v));
    E[v].push_back(make_pair(t, u));
  }
  long long ans = 0;
  vector<long long> d(n, -1);
  for (int i = 0; i < n; i++){
    if (d[i] == -1){
      d[i] = 1;
      vector<long long> a;
      queue<int> Q;
      Q.push(i);
      vector<int> id;
      while (!Q.empty()){
        int v = Q.front();
        Q.pop();
        id.push_back(v);
        for (auto P : E[v]){
          int w = P.second;
          if (d[w] == -1){
            d[w] = d[v] ^ P.first;
            Q.push(w);
          } else {
            a.push_back(d[v] ^ d[w] ^ P.first);
          }
        }
      }
      vector<long long> b;
      int cnt = a.size();
      long long C = 1;
      for (int j = 0; j < cnt; j++){
        long long e = a[j];
        int cnt2 = b.size();
        for (int k = 0; k < cnt2; k++){
          e = min(e, e ^ b[k]);
        }
        if (e > 0){
          b.push_back(e);
          C *= 2;
          C %= MOD;
        }
      }
      int cnt2 = b.size();
      long long used = 0;
      for (int j = 0; j < cnt2; j++){
        used |= b[j];
      }
      long long t = (long long) id.size() * (id.size() - 1) / 2 % MOD;
      if (cnt2 > 0){
        ans += (((long long) 1) << (cnt2 - 1)) % MOD * (used % MOD) % MOD * t % MOD;
      }
      for (int j = 0; j < 60; j++){
        if ((used >> j & 1) == 0){
          int cnt0 = 0, cnt1 = 0;
          for (int v : id){
            if ((d[v] >> j & 1) == 0){
              cnt0++;
            } else {
              cnt1++;
            }
          }
          ans += C * cnt0 % MOD * cnt1 % MOD;
        }
        C *= 2;
        C %= MOD;
      }
    }
  }
  ans %= MOD;
  cout << ans << endl;
}