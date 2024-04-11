#include <bits/stdc++.h>
using namespace std;
int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int t;
  cin >> t;
  for (int k = 0; k < t; k++){
    int n, m;
    cin >> n >> m;
    vector<vector<pair<int, int>>> E(n);
    for (int l = 0; l < m; l++){
      int i, j;
      string c;
      cin >> i >> j >> c;
      i--;
      j--;
      if (c == "crewmate"){
        E[i].push_back(make_pair(0, j));
        E[j].push_back(make_pair(0, i));
      }
      if (c == "imposter"){
        E[i].push_back(make_pair(1, j));
        E[j].push_back(make_pair(1, i));
      }
    }
    bool ok = true;
    int ans = 0;
    vector<int> p(n, -1);
    for (int l = 0; l < n; l++){
      if (p[l] == -1){
        p[l] = 0;
        vector<int> cnt(2, 0);
        queue<int> Q;
        Q.push(l);
        while (!Q.empty()){
          int v = Q.front();
          Q.pop();
          cnt[p[v]]++;
          for (auto P : E[v]){
            int c = P.first;
            int w = P.second;
            if (p[w] == -1){
              p[w] = p[v] ^ c;
              Q.push(w);
            } else if (p[w] != (p[v] ^ c)){
              ok = false;
            }
          }
        }
        ans += max(cnt[0], cnt[1]);
      }
    }
    if (!ok){
      cout << -1 << endl;
    } else {
      cout << ans << endl;
    }
  }
}