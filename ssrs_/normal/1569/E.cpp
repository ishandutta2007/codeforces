#include <bits/stdc++.h>
using namespace std;
const long long MOD = 998244353;
void dfs(vector<vector<pair<long long, vector<short>>>> &M, vector<long long> &P, int cnt, int k, vector<short> &c, int s, long long h, int p){
  if (p == cnt){
    M[s].push_back(make_pair(h, c));
  } else {
    for (int i = 1; i <= s; i++){
      c[p] = i;
      dfs(M, P, cnt, k, c, s - i, (h + P[p] * i) % MOD, p + 1);
      if (p == 0 && i == (1 << k) + 1){
        break;
      }
    }
  }
}
void dfs2(vector<int> &ans, bool &ok, int k, vector<int> &r, vector<int> &S, int p){
  if (p == k){
    if (S[0] == r[0]){
      ans[r[0] - 1] = 1;
      ok = true;
    }
  } else {
    int game = r.size() / 2;
    for (int i = 0; i < (1 << game); i++){
      int s = 0;
      bool used1 = false, used2 = false;
      for (int j = 0; j < game; j++){
        int id = j * 2 + (i >> j & 1);
        s += r[id];
        ans[r[id] - 1] = game + 1;
        if (r[id] == S[0]){
          used1 = true;
        }
        if (r[id] == S[1]){
          used2 = true;
        }
      }
      if (!used1 && (!used2 || game == 1)){
        if (s == S[k - p]){
          vector<int> r2;
          for (int j = 0; j < game; j++){
            if ((i >> j & 1) == 0){
              r2.push_back(r[j * 2 + 1]);
            } else {
              r2.push_back(r[j * 2]);
            }
          }
          dfs2(ans, ok, k, r2, S, p + 1);
          if (ok){
            break;
          }
        }
      }
    }
  }
}
int main(){
  int k, A;
  long long h;
  cin >> k >> A >> h;
  vector<int> p;
  p.push_back(1);
  for (int i = 0; i < k; i++){
    p.push_back(1 + (1 << i));
  }
  vector<long long> P(k + 1, 1);
  for (int i = 0; i <= k; i++){
    for (int j = 0; j < p[i]; j++){
      P[i] *= A;
      P[i] %= MOD;
    }
  }
  int s = 0;
  for (int i = 1; i <= (1 << k); i++){
    s += i;
  }
  int X = (k + 2) / 2, Y = k + 1 - X;
  vector<long long> P1, P2;
  for (int i = 0; i <= k; i++){
    if (i % 2 == 0){
      P1.push_back(P[i]);
    } else {
      P2.push_back(P[i]);
    }
  }
  vector<vector<pair<long long, vector<short>>>> M1(s + 1), M2(s + 1);
  vector<short> c1(X);
  dfs(M1, P1, X, k, c1, s, 0, 0);
  vector<short> c2(Y);
  dfs(M2, P2, Y, k, c2, s, 0, 0);
  for (int i = 0; i <= s; i++){
    sort(M1[i].begin(), M1[i].end());
    sort(M2[i].begin(), M2[i].end());
  }
  vector<int> ans;
  bool ok = false;
  for (int i = 0; i <= s; i++){
    int cnt = M1[i].size();
    for (int j = 0; j < cnt; j++){
      long long h1 = M1[i][j].first;
      long long h2 = (h - h1 + MOD) % MOD;
      int L = lower_bound(M2[s - i].begin(), M2[s - i].end(), make_pair(h2, vector<short>(Y, 0))) - M2[s - i].begin();
      int R = lower_bound(M2[s - i].begin(), M2[s - i].end(), make_pair(h2, vector<short>(Y, s))) - M2[s - i].begin();
      for (int l = L; l < R; l++){
        vector<int> S;
        for (int m = 0; m <= k; m++){
          if (m % 2 == 0){
            S.push_back(M1[i][j].second[m / 2]);
          } else {
            S.push_back(M2[s - i][l].second[m / 2]);
          }
        }
        vector<int> r;
        for (int j = 1; j <= (1 << k); j++){
          r.push_back(j);
        }
        ans = vector<int>(1 << k, -1);
        dfs2(ans, ok, k, r, S, 0);
        if(ok){
          break;
        }
      }
      if (ok){
        break;
      }
    }
    if (ok){
      break;
    }
  }
  if (!ok){
    cout << -1 << endl;
  } else {
    for (int i = 0; i < (1 << k); i++){
      cout << ans[i];
      if (i < (1 << k) - 1){
        cout << ' ';
      }
    }
    cout << endl;
  }
}