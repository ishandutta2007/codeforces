#include <bits/stdc++.h>
using namespace std;
const long long INF = 1000000000000000;
//https://ei1333.github.io/library/structure/convex-hull-trick/convex-hull-trick-add-monotone.hpp
/**
 * @brief Convex Hull Trick Add Monotone
 * @docs docs/convex-hull-trick-add-monotone.md
*/
template< typename T, bool isMin >
struct ConvexHullTrickAddMonotone {
#define F first
#define S second
  using P = pair< T, T >;
  deque< P > H;

  ConvexHullTrickAddMonotone() = default;

  bool empty() const { return H.empty(); }

  void clear() { H.clear(); }

  inline int sgn(T x) { return x == 0 ? 0 : (x < 0 ? -1 : 1); }

  inline bool check(const P &a, const P &b, const P &c) {
    if(b.S == a.S || c.S == b.S)
      return sgn(b.F - a.F) * sgn(c.S - b.S) >= sgn(c.F - b.F) * sgn(b.S - a.S);
    //return (b.F-a.F)*(c.S-b.S) >= (b.S-a.S)*(c.F-b.F);
    if(is_integral< T >::value) {
      return (b.S - a.S) / (a.F - b.F) >= (c.S - b.S) / (b.F - c.F);
    } else {
      return
          (b.F - a.F) * sgn(c.S - b.S) / abs(b.S - a.S) >=
          (c.F - b.F) * sgn(b.S - a.S) / abs(c.S - b.S);
    }
  }

  void add(T a, T b) {
    if(!isMin) a *= -1, b *= -1;
    P line(a, b);
    if(empty()) {
      H.emplace_front(line);
      return;
    }
    if(H.front().F <= a) {
      if(H.front().F == a) {
        if(H.front().S <= b) return;
        H.pop_front();
      }
      while(H.size() >= 2 && check(line, H.front(), H[1])) H.pop_front();
      H.emplace_front(line);
    } else {
      assert(a <= H.back().F);
      if(H.back().F == a) {
        if(H.back().S <= b) return;
        H.pop_back();
      }
      while(H.size() >= 2 && check(H[H.size() - 2], H.back(), line)) H.pop_back();
      H.emplace_back(line);
    }
  }

  inline T get_y(const P &a, const T &x) {
    return a.F * x + a.S;
  }

  T query(T x) {
    assert(!empty());
    int l = -1, r = H.size() - 1;
    while(l + 1 < r) {
      int m = (l + r) >> 1;
      if(get_y(H[m], x) >= get_y(H[m + 1], x)) l = m;
      else r = m;
    }
    if(isMin) return get_y(H[r], x);
    return -get_y(H[r], x);
  }

  T query_monotone_inc(T x) {
    assert(!empty());
    while(H.size() >= 2 && get_y(H.front(), x) >= get_y(H[1], x)) H.pop_front();
    if(isMin) return get_y(H.front(), x);
    return -get_y(H.front(), x);
  }

  T query_monotone_dec(T x) {
    assert(!empty());
    while(H.size() >= 2 && get_y(H.back(), x) >= get_y(H[H.size() - 2], x)) H.pop_back();
    if(isMin) return get_y(H.back(), x);
    return -get_y(H.back(), x);
  }

#undef F
#undef S
};
int main(){
  int n, m, k;
  cin >> n >> m >> k;
  vector<vector<pair<int, int>>> E(n);
  for (int i = 0; i < m; i++){
    int u, v, w;
    cin >> u >> v >> w;
    u--;
    v--;
    E[u].push_back(make_pair(w, v));
    E[v].push_back(make_pair(w, u));
  }
  vector<long long> dp(n, INF);
  dp[0] = 0;
  vector<int> upd = {0};
  for (int i = 0; i <= k; i++){
    vector<long long> dp2(n, INF);
    priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> pq;
    for (int j : upd){
      pq.push(make_pair(dp[j], j));
    }
    while (!pq.empty()){
      long long d = pq.top().first;
      int v = pq.top().second;
      pq.pop();
      if (dp2[v] == INF){
        dp2[v] = d;
        for (auto P : E[v]){
          int w = P.second;
          if (dp2[w] == INF){
            pq.push(make_pair(d + P.first, w));
          }
        }
      }
    }
    for (int j = 0; j < n; j++){
      dp[j] = min(dp[j], dp2[j]);
    }
    upd.clear();
    if (i < k){
      ConvexHullTrickAddMonotone<long long, true> CHT;
      for (int j = 0; j < n; j++){
        CHT.add(1 - 2 * j, dp[j] + (long long) j * j);
      }
      vector<long long> dp3(n);
      for (int j = 0; j < n; j++){
        long long tmp = CHT.query_monotone_inc(j) + (long long) j * (j - 1);
        if (tmp < dp[j]){
          dp[j] = tmp;
          upd.push_back(j);
        }
      }
    }
  }
  for (int i = 0; i < n; i++){
    cout << dp[i];
    if (i < n - 1){
      cout << ' ';
    }
  }
  cout << endl;
}