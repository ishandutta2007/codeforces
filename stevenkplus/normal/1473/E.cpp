// =========== Template ========== //
#include <bits/stdc++.h>
using namespace std;
int fastio() { ios_base::sync_with_stdio(false); cout << fixed << setprecision(10); cin.tie(nullptr); return 0; }
int __fastio = fastio();
template<typename A, typename B> ostream& operator<<(ostream &os, const pair<A, B> &p);
template<typename A> ostream& operator<<(ostream &os, const set<A> &m) { os << "{"; string sep = ""; for (auto e: m) os << sep << e, sep = ", "; return os << "}"; }
template<typename A> ostream& operator<<(ostream &os, const multiset<A> &m) { os << "{"; string sep = ""; for (auto e: m) os << sep << e, sep = ", "; return os << "}"; }
template<typename A, typename B> ostream& operator<<(ostream &os, const map<A, B> &m) { os << "{"; string sep = ""; for (auto e: m) os << sep << e.first << ": " << e.second, sep = ", "; return os << "}"; }
template<typename T>ostream& operator<<(ostream& os, const vector<T>& v) { os << "["; string sep = ""; for (auto e: v) os << sep << e, sep = ", "; return os << "]"; }
template<typename T, size_t L>ostream& operator<<(ostream& os, const array<T, L>& v) { os << "["; string sep = ""; for (int i = 0; i < L; ++i) os << sep << v[i], sep = ", "; return os << "]"; }
template<typename A, typename B> ostream& operator<<(ostream &os, const pair<A, B> &p) { os << '(' << p.first << ", " << p.second << ')'; return os; }
void dbg_out() { cerr << endl; }
template<typename Head, typename... Tail> void dbg_out(Head H, Tail... T) { cerr << ' ' << H; dbg_out(T...); }
#ifdef STEVEN
#define pp(...) cerr << "\t[" << #__VA_ARGS__ << "]:\t", dbg_out(__VA_ARGS__)
#define ppp(x) cerr << x << "\n"
#else
#define pp(...)
#define ppp(...)
#endif
template<class Fun> class y_combinator_result { Fun fun_; public: template<class T> explicit y_combinator_result(T &&fun): fun_(std::forward<T>(fun)) {} template<class ...Args> decltype(auto) operator()(Args &&...args) { return fun_(std::ref(*this), std::forward<Args>(args)...); } };
template<class Fun> decltype(auto) y_combinator(Fun &&fun) { return y_combinator_result<std::decay_t<Fun>>(std::forward<Fun>(fun)); }
#define yc y_combinator
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef long double ld;
#define fi first
#define se second
#define sz(x) (int((x).size()))
#define data _data
// =========== Book ============ //

typedef priority_queue<pll, vector<pll>, greater<pll> > PQ;

const ll infl = 1LL << 60;

// ============= Solution ============= //
int main() {
   int n, m;
   cin >> n >> m;
   vector<vector<pii>> ed(n);
   for (int i = 0; i < m; ++i) {
      int a, b, c;
      cin >> a >> b >> c;
      --a, --b;
      ed[a].push_back(pii(b, c));
      ed[b].push_back(pii(a, c));
   }

   PQ pq; // PQ of pll: pair(dist, id  = i * 4 + state) [we are doing a graph transformation from n to 4n nodes]
   // id -> (i, state) = (i, a * 2 + b) -> original node i, skipped an edge a times, doubled an edge b times
   vector<ll> dist(4 * n, infl);
   auto push = [&](int cur, int state, ll d) {
      pp(cur, state, d);
      int id = cur * 4 + state;
      pp(id, dist[id], d);
      if (d >= dist[id]) return;
      dist[id] = d;
      pq.push(pll(d, id));
   };
   push(0, 0, 0);
   while (!pq.empty()) {
      pll p = pq.top(); pq.pop();
      int id = p.se;
      if (p.fi != dist[id]) continue;

      int cur = id / 4, a = (id % 4) / 2, b = id % 2;
      for (pii e: ed[cur]) {
         int nxt = e.fi;
         for(int na = 0; na < 2; ++na) {
            if (na < a) continue;
            for (int nb = 0; nb < 2; ++nb) {
               if (nb < b) continue;
               ll ndist = dist[id] + e.se;
               if (na > a) ndist -= e.se;
               if (nb > b) ndist += e.se;
               push(nxt, na * 2 + nb, ndist);
            }
         }
      }
   }

   pp(dist);
   vector<ll> ans(n);
   for (int i = 1; i < n; ++i) {
      ans[i] = dist[i * 4 + 3];
   }
   for (int i = 1; i < n; ++i) cout << ans[i] << " ";
   cout << "\n";

}

// ============== Notes =============== //
// common bugs
// - fastio
// - int overflow (especially intermediate expressionns)
// - array bounds (indices bigger than MAXN?)
// - special cases (n=1? graph not connected?)
// - re-initialize efficiently between test cases