#include <bits/stdc++.h>
using namespace std;
int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  mt19937 mt(chrono::steady_clock::now().time_since_epoch().count());
  int n, m, p;
  cin >> n >> m >> p;
  vector<string> s(n);
  for (int i = 0; i < n; i++){
    cin >> s[i];
  }
  int mx = -1;
  string ans;
  for (int i = 0; i < 100; i++){
    int id = mt() % n;
    vector<int> pos;
    for (int j = 0; j < m; j++){
      if (s[id][j] == '1'){
        pos.push_back(j);
      }
    }
    int cnt = pos.size();
    vector<int> b(n, 0);
    for (int j = 0; j < n; j++){
      for (int k = 0; k < cnt; k++){
        if (s[j][pos[k]] == '1'){
          b[j] += 1 << k;
        }
      }
    }
    vector<int> zeta(1 << cnt, 0);
    for (int j = 0; j < n; j++){
      zeta[b[j]]++;
    }
    for (int j = 0; j < cnt; j++){
      for (int k = 0; k < (1 << cnt); k++){
        if ((k >> j & 1) == 1){
          zeta[k - (1 << j)] += zeta[k];
        }
      }
    }
    for (int j = 0; j < (1 << cnt); j++){
      if (zeta[j] >= (n + 1) / 2){
        if (__builtin_popcount(j) > mx){
          string t(m, '0');
          for (int k = 0; k < cnt; k++){
            if ((j >> k & 1) == 1){
              t[pos[k]] = '1';
            }
          }
          mx = __builtin_popcount(j);
          ans = t;
        }
      }
    }
  }
  cout << ans << endl;
}