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

#define mx(a, b) a = max(a, b)
#define sub_to_errichto main
const int inf = 1000 << 20;

// ============= Solution ============= //
int sub_to_errichto() {
   int n, m, q;
   cin >> n >> m >> q;
   vector<int> val(n);
   for (int &i: val) {
      cin >> i;
   }
   vector<int> A(m), B(m);
   for (int i = 0; i < m; ++i) {
      cin >> A[i] >> B[i];
      --A[i], --B[i];
   }
   vector<int> qtype(q);
   vector<int> qval(q);
   vector<int> ans(q);

   vector<bool> isdel(m);
   for (int i = 0; i < q; ++i) {
      cin >> qtype[i] >> qval[i];
      --qval[i];
      if (qtype[i] == 2) {
         isdel[qval[i]] = 1;
      }
   }
   pp(qtype);

   vector<int> id(n);
   vector<vector<int>> comps(n);
   for (int i = 0; i < n; ++i) {
     id[i] = i;
     comps[i].push_back(i);
   }
   for (int i = 0; i < m; ++i) {
      if (!isdel[i]) {
         int a = A[i], b = B[i];
         a = id[a];
         b = id[b];
         if (a == b) continue;
         if (sz(comps[a]) < sz(comps[b])) swap(a, b);
         comps[a].insert(comps[a].end(), comps[b].begin(), comps[b].end());
         for (int i: comps[b]) {
            id[i] = a;
         }
      }
   }

   vector<int> deleted(q, -1); // for qtype = 2 that splits, store the id of the smaller comp
   for (int i = q - 1; i >= 0; --i) {
      if (qtype[i] != 2) continue;
      int a = A[qval[i]], b = B[qval[i]];
      a = id[a];
      b = id[b];
      if (a == b) continue;
      if (sz(comps[a]) < sz(comps[b])) swap(a, b);
      deleted[i] = b;
      comps[a].insert(comps[a].end(), comps[b].begin(), comps[b].end());
      for (int i: comps[b]) {
         id[i] = a;
      }
   }

   vector<vector<pii>> PQs(n);
   for (int i = 0; i < n; ++i) {
      PQs[i] = vector<pii>(sz(comps[i]));
      for (int j = 0; j < sz(comps[i]); ++j) {
         PQs[i][j] = pii(val[comps[i][j]], comps[i][j]);
      }
      sort(PQs[i].begin(), PQs[i].end());
   }
   pp(deleted);
   pp(comps);
   pp(PQs);
   vector<bool> del(n);
   for (int i = 0; i < q; ++i) {
      if (qtype[i] == 1) {
         int x = id[qval[i]];
         vector<pii> &v = PQs[x];
         pp("QUERY", i, x, v);
         pp(id);
         while (sz(v)) {
            int b = v.back().se;
            v.pop_back();
            pp(b, del[b], id[b], val[b]);
            if (!del[b] && id[b] == x) {
               ans[i] = val[b];
               del[b] = true;
               break;
            }
         }
      } else if (deleted[i] != -1) {
         int b = deleted[i];
         for (int i: comps[b]) {
            id[i] = b;
         }
      }
   }

   for (int i = 0; i < q; ++i) {
      if (qtype[i] == 2) continue;
      cout << ans[i] << "\n";
   }
}

// ============== Notes =============== //
// common bugs
// - fastio
// - int overflow (especially intermediate expressionns)
// - array bounds (indices bigger than MAXN?)
// - special cases (n=1? graph not connected?)
// - re-initialize efficiently between test cases