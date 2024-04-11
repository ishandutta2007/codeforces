#include <bits/stdc++.h>
using namespace std;
pair<long long, long long> ext_gcd(long long a, long long b){
  //ax+by=1 gcd(a,b)=1
  if (a > b){
    pair<long long, long long> S = ext_gcd(b, a);
    return make_pair(S.second, S.first);
  }
  if (a == 1){
    return make_pair(1, 0);
  } else {
    pair<long long, long long> S = ext_gcd(b % a, a);
    return make_pair(S.second - b / a * S.first, S.first);
  }
}
long long composite_modinv(long long a, long long MOD){
  long long tmp = ext_gcd(a, MOD).first;
  return (tmp % MOD + MOD) % MOD;
}
int find_centroid(vector<vector<pair<int, int>>> &E){
  int N = E.size();
  vector<int> p(N, -1);
  vector<vector<int>> c(N);
  queue<int> Q;
  Q.push(0);
  vector<int> bfs;
  while (!Q.empty()){
    int v = Q.front();
    Q.pop();
    bfs.push_back(v);
    for (auto P : E[v]){
      int w = P.second;
      if (w != p[v]){
        p[w] = v;
        c[v].push_back(w);
        Q.push(w);
      }
    }
  }
  reverse(bfs.begin(), bfs.end());
  vector<int> dp(N, 1);
  for (int v : bfs){
    for (int w : c[v]){
      dp[v] += dp[w];
    }
  }
  for (int v : bfs){
    bool ok = true;
    for (int w : c[v]){
      if (dp[w] > N / 2 + 1){
        ok = false;
      }
    }
    if (N - dp[v] > N / 2 + 1){
      ok = false;
    }
    if (ok){
      return v;
    }
  }
}
long long dfs(vector<vector<pair<int, int>>> &E, int M){
  int N = E.size();
  int r = find_centroid(E);
  vector<int> p(N, -1);
  vector<vector<int>> c(N);
  vector<long long> mul(N, 1);
  vector<long long> up(N, 0), down(N, 0);
  vector<int> group(N, -1);
  int cnt = 0;
  queue<int> Q;
  Q.push(r);
  while (!Q.empty()){
    int v = Q.front();
    Q.pop();
    for (auto P : E[v]){
      int w = P.second;
      if (w != p[v]){
        p[w] = v;
        c[v].push_back(w);
        mul[w] = mul[v] * 10 % M;
        up[w] = (up[v] + mul[v] * P.first) % M;
        down[w] = (down[v] * 10 + P.first) % M;
        if (v == r){
          group[w] = cnt;
          cnt++;
        } else {
          group[w] = group[v];
        }
        Q.push(w);
      }
    }
  }
  vector<vector<int>> id(cnt);
  for (int i = 0; i < N; i++){
    if (i != r){
      id[group[i]].push_back(i);
    }
  }
  long long ans = 0;
  for (int i = 0; i < N; i++){
    if (i != r){
      if (up[i] == 0){
        ans++;
      }
      if (down[i] == 0){
        ans++;
      }
    }
  }
  for (int i = 0; i < 2; i++){
    map<int, int> mp;
    for (int j = 0; j < cnt; j++){
      for (int v : id[j]){
        long long X = M - down[v] * composite_modinv(mul[v], M) % M;
        if (X == M){
          X = 0;
        }
        ans += mp[X];
      }
      for (int v : id[j]){
        mp[up[v]]++;
      }
    }
    reverse(id.begin(), id.end());
  }
  vector<vector<int>> id2 = id;
  for (int i = 0; i < cnt; i++){
    sort(id2[i].begin(), id2[i].end());
  }
  vector<int> pos(N);
  for (int i = 0; i < cnt; i++){
    int sz = id[i].size();
    for (int j = 0; j < sz; j++){
      pos[id2[i][j]] = j;
    }
  }
  vector<vector<vector<pair<int, int>>>> E2(cnt);
  for (int i = 0; i < cnt; i++){
    E2[i].resize(id[i].size());
  }
  for (int i = 0; i < N; i++){
    for (auto P : E[i]){
      int j = P.second;
      if (i != r && j != r){
        assert(group[i] == group[j]);
        E2[group[i]][pos[i]].push_back(make_pair(P.first, pos[j]));
      }
    }
  }
  for (int i = 0; i < cnt; i++){
    ans += dfs(E2[i], M);
  }
  return ans;
}
int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n, M;
  cin >> n >> M;
  if (M == 1){
    cout << (long long) n * (n - 1) << endl;
  } else {
    vector<vector<pair<int, int>>> E(n);
    for (int i = 0; i < n - 1; i++){
      int u, v, w;
      cin >> u >> v >> w;
      E[u].push_back(make_pair(w, v));
      E[v].push_back(make_pair(w, u));
    }
    long long ans = dfs(E, M);
    cout << ans << endl;
  }
}