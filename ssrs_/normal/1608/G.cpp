#include <bits/stdc++.h>
using namespace std;
const int LOG = 18;
const long long M30 = ((long long) 1 << 30) - 1;
const long long M31 = ((long long) 1 << 31) - 1;
const long long MOD = ((long long) 1 << 61) - 1;
const long long BASE = 10000000;
unsigned long long modulo(unsigned long long x){
  unsigned long long xu = x >> 61;
  unsigned long long xd = x & MOD;
  unsigned long long res = xu + xd;
  if (res >= MOD){
    res -= MOD;
  }
  return res;
}
unsigned long long mul(unsigned long long a, unsigned long long b){
  unsigned long long au = a >> 31;
  unsigned long long ad = a & M31;
  unsigned long long bu = b >> 31;
  unsigned long long bd = b & M31;
  unsigned long long mid = au * bd + ad * bu;
  unsigned long long midu = mid >> 30;
  unsigned long long midd = mid & M30;
  return modulo(au * bu * 2 + midu + (midd << 31) + ad * bd);
}
struct monoid{
  unsigned long long hash, mul;
  monoid(){
    hash = 0;
    mul = 1;
  }
  monoid(char c){
    hash = c;
    mul = BASE;
  }
};
monoid f(monoid L, monoid R){
  monoid ans;
  ans.hash = modulo(L.hash + mul(R.hash, L.mul));
  ans.mul = mul(L.mul, R.mul);
  return ans;
}

int la(vector<vector<int>> &pp, int v, int x){
  for (int i = 0; i < LOG; i++){
    if ((x >> i & 1) == 1){
      v = pp[i][v];
    }
  }
  return v;
}
int find_lca(vector<int> &d, vector<vector<int>> &pp, int u, int v){
  if (d[u] > d[v]){
    swap(u, v);
  }
  v = la(pp, v, d[v] - d[u]);
  if (u == v){
    return u;
  }
  for (int i = LOG - 1; i >= 0; i--){
    if (pp[i][u] != pp[i][v]){
      u = pp[i][u];
      v = pp[i][v];
    }
  }
  return pp[0][u];
}
vector<int> suffix_array(string S){
  S.push_back(0);
  int N = S.size();
  vector<int> cnt(128, 0);
  for (int i = 0; i < N; i++){
    cnt[S[i]]++;
  }
  for (int i = 0; i < 127; i++){
    cnt[i + 1] += cnt[i];
  }
  vector<int> SA(N), rank(N);
  for (int i = 0; i < N; i++){
    cnt[S[i]]--;
    SA[cnt[S[i]]] = i;
  }
  rank[SA[0]] = 0;
  for (int i = 0; i < N - 1; i++){
    rank[SA[i + 1]] = rank[SA[i]];
    if (S[SA[i]] != S[SA[i + 1]]){
      rank[SA[i + 1]]++;
    }
  }
  int L = 1;
  while (L < N){
    vector<int> SA2(N), rank2(N);
    for (int i = 0; i < N; i++){
      SA2[i] = SA[i] - L;
      if (SA2[i] < 0){
        SA2[i] += N;
      }
    }
    cnt = vector<int>(N, 0);
    for (int i = 0; i < N; i++){
      cnt[rank[SA2[i]]]++;
    }
    for (int i = 0; i < N - 1; i++){
      cnt[i + 1] += cnt[i];
    }
    for (int i = N - 1; i >= 0; i--){
      cnt[rank[SA2[i]]]--;
      SA[cnt[rank[SA2[i]]]] = SA2[i];
    }
    rank2[SA[0]] = 0;
    for (int i = 0; i < N - 1; i++){
      rank2[SA[i + 1]] = rank2[SA[i]];
      if (rank[SA[i]] != rank[SA[i + 1]] || rank[(SA[i] + L) % N] != rank[(SA[i + 1] + L) % N]){
        rank2[SA[i + 1]]++;
      }
    }
    rank = rank2;
    L *= 2;
  }
  SA.erase(SA.begin());
  return SA;
}
struct rolling_hash{
  vector<long long> POW, S;
  rolling_hash(string s){
    int N = s.size();
    POW.resize(N + 1);
    POW[0] = 1;
    for (int i = 0; i < N; i++){
      POW[i + 1] = mul(POW[i], BASE);
    }
    S.resize(N + 1);
    S[N] = 0;
    for (int i = N - 1; i >= 0; i--){
      S[i] = modulo(mul(S[i + 1], BASE) + s[i]);
    }
  }
  long long get(int L, int R){
    return modulo(S[L] + MOD - mul(S[R], POW[R - L]));
  }
};
long long get_hash(vector<int> &d, vector<vector<int>> &pp, vector<vector<monoid>> &up_hash, vector<vector<monoid>> &down_hash, int u, int v, int w){
  monoid L;
  for (int i = LOG - 1; i >= 0; i--){
    if (((d[u] - d[w]) >> i & 1) == 1){
      L = f(L, up_hash[i][u]);
      u = pp[i][u];
    }
  }
  monoid R;
  for (int i = LOG - 1; i >= 0; i--){
    if (((d[v] - d[w]) >> i & 1) == 1){
      R = f(down_hash[i][v], R);
      v = pp[i][v];
    }
  }
  return f(L, R).hash;
}
int compare(int SL, rolling_hash &RH, vector<int> &d, vector<vector<int>> &pp, vector<vector<monoid>> &up_hash, vector<vector<monoid>> &down_hash, int p, int u, int v, int w){
  bool same = true;
  for (int i = LOG - 1; i >= 0; i--){
    if (d[u] - d[w] >= (1 << i) && p + (1 << i) <= SL){
      long long hash1 = up_hash[i][u].hash;
      long long hash2 = RH.get(p, p + (1 << i));
      if (hash1 == hash2){
        u = pp[i][u];
        p += 1 << i;
      }
    }
  }
  if (p == SL){
    return 1;
  }
  if (u != w){
    long long hash1 = up_hash[0][u].hash;
    long long hash2 = RH.get(p, p + 1);
    if (hash1 < hash2){
      return -1;
    }
    if (hash1 > hash2){
      return 1;
    }
  }
  for (int i = LOG - 1; i >= 0; i--){
    if (d[v] - d[w] >= (1 << i) && p + (1 << i) <= SL){
      int t = la(pp, v, d[v] - d[w] - (1 << i));
      long long hash1 = down_hash[i][t].hash;
      long long hash2 = RH.get(p, p + (1 << i));
      if (hash1 == hash2){
        w = t;
        p += 1 << i;
      }
    }
  }
  if (w == v && p == SL){
    return 0;
  }
  if (p == SL){
    return 1;
  }
  if (w == v){
    return -1;
  }
  int t = la(pp, v, d[v] - d[w] - 1);
  long long hash1 = down_hash[0][t].hash;
  long long hash2 = RH.get(p, p + 1);
  if (hash1 < hash2){
    return -1;
  } else {
    return 1;
  }
}
template <typename T>
struct binary_indexed_tree{
  int N;
  vector<int> BIT;
  binary_indexed_tree(int N): N(N), BIT(N + 1, 0){
  }
  void add(int i){
    i++;
    while (i <= N){
      BIT[i]++;
      i += i & -i;
    }
  }
  int sum(int i){
    int ans = 0;
    while (i > 0){
      ans += BIT[i];
      i -= i & -i;
    }
    return ans;
  }
  int sum(int L, int R){
    return sum(R) - sum(L);
  }
};
int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n, m, q;
  cin >> n >> m >> q;
  vector<vector<pair<char, int>>> E(n);
  for (int i = 0; i < n - 1; i++){
    int u, v;
    char c;
    cin >> u >> v >> c;
    u--;
    v--;
    E[u].push_back(make_pair(c, v));
    E[v].push_back(make_pair(c, u));
  }
  vector<int> pr(n, -1);
  vector<char> pc(n);
  vector<vector<int>> c(n);
  vector<int> d(n, 0);
  queue<int> Q;
  Q.push(0);
  while (!Q.empty()){
    int v = Q.front();
    Q.pop();
    for (auto P : E[v]){
      int w = P.second;
      if (w != pr[v]){
        pr[w] = v;
        pc[w] = P.first;
        c[v].push_back(w);
        d[w] = d[v] + 1;
        Q.push(w);
      }
    }
  }
  vector<vector<int>> pp(LOG, vector<int>(n, -1));
  vector<vector<monoid>> up_hash(LOG, vector<monoid>(n));
  vector<vector<monoid>> down_hash(LOG, vector<monoid>(n));
  for (int i = 1; i < n; i++){
    pp[0][i] = pr[i];
    up_hash[0][i] = monoid(pc[i]);
    down_hash[0][i] = monoid(pc[i]);
  }
  for (int i = 0; i < LOG - 1; i++){
    for (int j = 0; j < n; j++){
      if (pp[i][j] != -1){
        pp[i + 1][j] = pp[i][pp[i][j]];
        if (pp[i + 1][j] != -1){
          up_hash[i + 1][j] = f(up_hash[i][j], up_hash[i][pp[i][j]]);
          down_hash[i + 1][j] = f(down_hash[i][pp[i][j]], down_hash[i][j]);
        }
      }
    }
  }
  vector<string> S(m);
  for (int i = 0; i < m; i++){
    cin >> S[i];
  }
  vector<int> S_id;
  string T;
  for (int i = 0; i < m; i++){
    T += S[i];
    int l = S[i].size();
    for (int j = 0; j < l; j++){
      S_id.push_back(i);
    }
    T += '$';
    S_id.push_back(m);
  }
  int SL = T.size();
  vector<int> SA = suffix_array(T);
  rolling_hash RH(T);
  vector<int> l(q), r(q), L(q), R(q);
  for (int i = 0; i < q; i++){
    int u, v;
    cin >> u >> v >> l[i] >> r[i];
    u--;
    v--;
    l[i]--;
    int w = find_lca(d, pp, u, v);
    int len = d[u] + d[v] - 2 * d[w];
    long long H = get_hash(d, pp, up_hash, down_hash, u, v, w);
    int tv1 = 0, fv1 = SL + 1;
    while (fv1 - tv1 > 1){
      int mid = (tv1 + fv1) / 2;
      int res = compare(SL, RH, d, pp, up_hash, down_hash, SA[mid - 1], u, v, w);
      if (res == 1){
        tv1 = mid;
      } else {
        fv1 = mid;
      }
    }
    L[i] = tv1;
    if (SA[tv1] + len > SL){
      R[i] = tv1;
    } else if (RH.get(SA[tv1], SA[tv1] + len) != H){
      R[i] = tv1;
    } else {
      int tv2 = tv1, fv2 = SL + 1;
      while (fv2 - tv2 > 1){
        int mid = (tv2 + fv2) / 2;
        if (SA[mid - 1] + len > SL){
          fv2 = mid;
        } else {
          long long hash = RH.get(SA[mid - 1], SA[mid - 1] + len);
          if (hash == H){
            tv2 = mid;
          } else {
            fv2 = mid;
          }
        }
      }
      R[i] = tv2;
    }
  }
  vector<vector<tuple<int, int, int>>> add_query(m + 1);
  vector<vector<tuple<int, int, int>>> sub_query(m + 1);
  for (int i = 0; i < q; i++){
    add_query[r[i]].push_back(make_tuple(L[i], R[i], i));
    sub_query[l[i]].push_back(make_tuple(L[i], R[i], i));
  }
  vector<vector<int>> id(m + 1);
  for (int i = 0; i < SL; i++){
    id[S_id[SA[i]]].push_back(i);
  }
  binary_indexed_tree<long long> BIT(SL);
  vector<long long> ans(q, 0);
  for (int i = 0; i <= m; i++){
    for (auto e : add_query[i]){
      ans[get<2>(e)] += BIT.sum(get<0>(e), get<1>(e));
    }
    for (auto e : sub_query[i]){
      ans[get<2>(e)] -= BIT.sum(get<0>(e), get<1>(e));
    }
    for (int x : id[i]){
      BIT.add(x);
    }
  }
  for (int i = 0; i < q; i++){
    cout << ans[i] << "\n";
  }
}