#include <bits/stdc++.h>
using namespace std;
const int INF = 10000000;
struct segment_tree{
  int N;
  vector<int> mn, mx;
  segment_tree(vector<int> A){
    int N2 = A.size();
    N = 1;
    while (N < N2){
      N *= 2;
    }
    mn = vector<int>(N * 2 - 1, INF);
    mx = vector<int>(N * 2 - 1, -INF);
    for (int i = 0; i < N2; i++){
      mn[N - 1 + i] = A[i];
      mx[N - 1 + i] = A[i];
    }
    for (int i = N - 2; i >= 0; i--){
      mn[i] = min(mn[i * 2 + 1], mn[i * 2 + 2]);
      mx[i] = max(mx[i * 2 + 1], mx[i * 2 + 2]);
    }
  }
  void update(int p, int x){
    p += N - 1;
    mn[p] = x;
    mx[p] = x;
    while (p > 0){
      p = (p - 1) / 2;
      mn[p] = min(mn[p * 2 + 1], mn[p * 2 + 2]);
      mx[p] = max(mx[p * 2 + 1], mx[p * 2 + 2]);
    }
  }
  pair<int, int> range_minmax(int L, int R, int i, int l, int r){
    if (r <= L || R <= l){
      return make_pair(INF, -INF);
    } else if (L <= l && r <= R){
      return make_pair(mn[i], mx[i]);
    } else {
      int m = (l + r) / 2;
      pair<int, int> A = range_minmax(L, R, i * 2 + 1, l, m);
      pair<int, int> B = range_minmax(L, R, i * 2 + 2, m, r);
      return make_pair(min(A.first, B.first), max(A.second, B.second));
    }
  }
  bool range_same(int L, int R, int x){
    if (L == R){
      return true;
    } else {
      pair<int, int> P = range_minmax(L, R, 0, 0, N);
      return P.first == x && P.second == x;
    }
  }
  int max_right(int L, int R, int x, int i, int l, int r){
    if (r <= L || R <= l){
      return -1;
    } else if (mn[i] == x && mx[i] == x){
      return -1;
    } else if (r - l == 1){
      return i - (N - 1);
    } else {
      int m = (l + r) / 2;
      int tmp = max_right(L, R, x, i * 2 + 1, l, m);
      if (tmp != -1){
        return tmp;
      } else {
        return max_right(L, R, x, i * 2 + 2, m, r);
      }
    }
  }
  int max_right(int L, int R, int x){
    return max_right(L, R, x, 0, 0, N);
  }
  int min_left(int L, int R, int x, int i, int l, int r){
    if (r <= L || R <= l){
      return -1;
    } else if (mn[i] == x && mx[i] == x){
      return -1;
    } else if (r - l == 1){
      return i - (N - 1);
    } else {
      int m = (l + r) / 2;
      int tmp = min_left(L, R, x, i * 2 + 2, m, r);
      if (tmp != -1){
        return tmp;
      } else {
        return min_left(L, R, x, i * 2 + 1, l, m);
      }
    }
  }
  int min_left(int L, int R, int x){
    return min_left(L, R, x, 0, 0, N);
  }
};
int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n, q, s, d;
  cin >> n >> q >> s >> d;
  s--;
  vector<int> a(n);
  for (int i = 0; i < n; i++){
    cin >> a[i];
  }
  vector<vector<pair<int, int>>> E(n);
  vector<int> b(n);
  for (int i = 0; i < n; i++){
    b[i] = i;
  }
  vector<int> sz(n, 1);
  segment_tree ST(b);
  vector<vector<int>> T(n);
  for (int i = 0; i < n; i++){
    T[i].push_back(i);
  }
  while (true){
    vector<tuple<int, int, int>> tmp(n);
    for (int i = 0; i < n; i++){
      get<0>(tmp[i]) = INF;
    }
    bool ok = false;
    for (int i = 0; i < n; i++){
      int L = upper_bound(a.begin(), a.end(), a[i] - d) - a.begin();
      pair<int, int> P1 = make_pair(INF, -1);
      if (!ST.range_same(0, L, b[i])){
        int p = ST.min_left(0, L, b[i]);
        P1 = make_pair((a[i] - a[p]) - d, p);
      }
      pair<int, int> P2 = make_pair(INF, -1);
      if (!ST.range_same(L, i, b[i])){
        int p = ST.max_right(L, i, b[i]);
        P2 = make_pair(d - (a[i] - a[p]), p);
      }
      int R = lower_bound(a.begin(), a.end(), a[i] + d) - a.begin();
      pair<int, int> P3 = make_pair(INF, -1);
      if (!ST.range_same(i + 1, R, b[i])){
        int p = ST.min_left(i + 1, R, b[i]);
        P3 = make_pair(d - (a[p] - a[i]), p);
      }
      pair<int, int> P4 = make_pair(INF, -1);
      if (!ST.range_same(R, n, b[i])){
        int p = ST.max_right(R, n, b[i]);
        P4 = make_pair((a[p] - a[i]) - d, p);
      }
      pair<int, int> P = min({P1, P2, P3, P4});
      if (P.first < get<0>(tmp[b[i]])){
        tmp[b[i]] = make_tuple(P.first, i, P.second);
        ok = true;
      }
    }
    if (!ok){
      break;
    }
    for (int i = 0; i < n; i++){
      int c = get<0>(tmp[i]);
      if (c != INF){
        int v = get<1>(tmp[i]);
        int w = get<2>(tmp[i]);
        if (b[v] != b[w]){
          E[v].push_back(make_pair(c, w));
          E[w].push_back(make_pair(c, v));
          v = b[v];
          w = b[w];
          if (sz[v] > sz[w]){
            swap(v, w);
          }
          for (int x : T[v]){
            b[x] = w;
            ST.update(x, w);
            T[w].push_back(x);
          }
          T[v].clear();
          sz[w] += sz[v];
        }
      }
    }
  }
  vector<int> mx(n, INF);
  mx[s] = 0;
  queue<int> Q;
  Q.push(s);
  while (!Q.empty()){
    int v = Q.front();
    Q.pop();
    for (auto P : E[v]){
      int w = P.second;
      if (mx[w] == INF){
        mx[w] = max(mx[v], P.first);
        Q.push(w);
      }
    }
  }
  for (int i = 0; i < q; i++){
    int p, k;
    cin >> p >> k;
    p--;
    if (k >= mx[p]){
      cout << "Yes" << "\n";
    } else {
      cout << "No" << "\n";
    }
  }
}