#include <bits/stdc++.h>
using namespace std;
const long long MOD = 1000000007;
int main(){
  int n;
  cin >> n;
  vector<int> p(n);
  for (int i = 0; i < n; i++){
    cin >> p[i];
  }
  sort(p.begin(), p.end(), greater<int>());
  vector<int> F(2000001, -1);
  for (int i = 2; i <= 2000000; i++){
    if (F[i] == -1){
      for (int j = i * 2; j <= 2000000; j += i){
        F[j] = i;
      }
    }
  }
  set<int> st;
  for (int i = 0; i < n; i++){
    if (st.count(p[i])){
      p[i]--;
      if (p[i] > 1){
        int q = p[i];
        while (F[q] != -1){
          st.insert(F[q]);
          q /= F[q];
        }
        st.insert(q);
      }
    } else {
      st.insert(p[i]);
    }
  }
  vector<vector<pair<int, int>>> pf(2000001);
  for (int i = 0; i < n; i++){
    if (p[i] > 1){
      map<int, int> f;
      while (F[p[i]] != -1){
        f[F[p[i]]]++;
        p[i] /= F[p[i]];
      }
      f[p[i]]++;
      for (auto P : f){
        pf[P.first].push_back(make_pair(P.second, i));
      }
    }
  }
  vector<bool> ok(n, true);
  long long ans = 1;
  for (int i = 0; i <= 2000000; i++){
    if (!pf[i].empty()){
      int cnt = pf[i].size();
      int mx = 0;
      vector<int> id;
      for (int j = 0; j < cnt; j++){
        if (pf[i][j].first == mx){
          id.push_back(pf[i][j].second);
        } else if (pf[i][j].first > mx){
          mx = pf[i][j].first;
          id = {pf[i][j].second};
        }
      }
      if (id.size() == 1){
        ok[id[0]] = false;
      }
      for (int j = 0; j < mx; j++){
        ans *= i;
        ans %= MOD;
      }
    }
  }
  bool add = false;
  for (int i = 0; i < n; i++){
    if (ok[i]){
      add = true;
    }
  }
  if (add){
    ans++;
    ans %= MOD;
  }
  cout << ans << endl;
}