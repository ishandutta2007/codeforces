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
#define yc y_combinator;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef long double ld;
#define fi first
#define se second
#define sz(x) (int((x).size()))
#define data _data
// =========== Book ============ //

int gcd(int a, int b) {
   if (a == 0) return b;
   return gcd(b % a, a);
}

class LazySeg {
   int size;
   vector<ll> data;
   vector<ll> lazy;
   public:
   LazySeg(int _size) {
      size = 1;
      while (size < _size) size *= 2;
      data = vector<ll>(size * 2);
      lazy = vector<ll>(size * 2);
   }
   void down(int cur, int l, int r) {
      int cl = cur * 2, cr = cur * 2 + 1;
      ll diff = lazy[cur];
      data[cl] += diff;
      data[cr] += diff;
      lazy[cl] += lazy[cur];
      lazy[cr] += lazy[cur];
      lazy[cur] = 0;
   }
   // ASK
   ll ask(int left, int right, int cur, int l, int r) {
      if (left <= l && r <= right) {
         return data[cur];
      } else if (left >= r || l >= right) {
         return 0;
      } else {
         down(cur, l, r);
         int mid = (l + r) / 2;
         int cl = cur * 2, cr = cur * 2 + 1;
         ll ql = ask(left, right, cl, l, mid);
         ll qr = ask(left, right, cr, mid, r);
         return max(ql, qr);
      }
   }
   ll ask(int left, int right) {
      return ask(left, right, 1, 0, size);
   }
   // ADD
   void add(int left, int right, ll val, int cur, int l, int r) {
      if (left <= l && r <= right) {
         lazy[cur] += val;
         data[cur] += val;
      } else if (left >= r || l >= right) {
      } else {
         down(cur, l, r);
         int mid = (l + r) / 2;
         int cl = cur * 2, cr = cur * 2 + 1;
         add(left, right, val, cl, l, mid);
         add(left, right, val, cr, mid, r);
         data[cur] = max(data[cl], data[cr]);
      }
   }
   void add(int left, int right, ll val) {
      add(left, right, val, 1, 0, size);
   }
};


const ll infl = 1LL << 60;
// ============= Solution ============= //
// Start Read: 1:13:30
// Give up: 1:04:20
// Continue: 0:57:20
// Start Coding: 0:46:31
int main() {
   int n;
   cin >> n;
   vector<int> l(n), r(n), t(n);
   for (int i = 0; i < n; ++i) {
      cin >> l[i] >> r[i] >> t[i];
   }

   map<int, int> mp;
   for (int i: l) mp[i] = -1;
   for (int i: r) mp[i] = -1;
   
   int M = 1;
   for (auto &p: mp) {
      p.se = M++;
   }
   for (int &i: l) i = mp[i];
   for (int &i: r) i = mp[i];
   // */
   // int M = 0;
   for (int i: r) M = max(M, i + 1);

   pp(l, r, t);
   vector<int> ans(M);
   int size = 1;
   while (size < M) size *= 2;
   LazySeg A(size), B(size);

   vector<pii> white, black;
   for (int i = 0; i < n; ++i) {
      if (t[i] == 1) {
         white.push_back(pii(r[i], i));
      } else {
         black.push_back(pii(r[i], i));
      }
   }
   sort(white.begin(), white.end());
   sort(black.begin(), black.end());

   // vector<ll> Aar(M), Bar(M);
   int widx = 0, bidx = 0;
   for (int i = 0; i < M; ++i) {
      while (widx < sz(white) && r[white[widx].se] <= i) {
         int idx = white[widx++].se;
         pp("Processing White", l[idx], r[idx]);
         A.add(0, l[idx], 1);
         // for (int j = 0; j <= l[idx]; ++j) {
            // Aar[j] += 1;
         // }
      }
      while (bidx < sz(black) && r[black[bidx].se] <= i) {
         int idx = black[bidx++].se;
         pp("Processing Black", l[idx], r[idx]);
         B.add(0, l[idx], 1);
         // for (int j = 0; j <= l[idx]; ++j) {
            // Bar[j] += 1;
         // }
      }

      ans[i] = max(A.ask(0, M), B.ask(0, M));
      A.add(i, i + 1, ans[i]);
      // Aar[i] += ans[i];
      // Bar[i] += ans[i];
      B.add(i, i + 1, ans[i]);
      pp(i, ans[i]);
      pp(A.ask(0, M));
      pp(B.ask(0, M));
      // pp(Aar);
      // pp(Bar);
   }
   pp(ans);
   cout << ans[M - 1] << "\n";
}

// ============== Notes =============== //
// common bugs
// - fastio
// - int overflow (especially intermediate expressionns)
// - array bounds (indices bigger than MAXN?)
// - special cases (n=1? graph not connected?)
// - re-initialize efficiently between test cases