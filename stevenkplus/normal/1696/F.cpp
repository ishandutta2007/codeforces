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
struct node;
ostream& operator<<(ostream &os, const node &node);
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

template <int MOD_> struct modnum {
   static constexpr int MOD = MOD_;
   static_assert(MOD_ > 0, "MOD must be positive");
   private:
   using ll = long long;
   int v;
   static int minv(int a, int m) {
      a %= m;
      assert(a);
      return a == 1 ? 1 : int(m - ll(minv(m, a)) * ll(m) / a);
   }
   public:
   modnum() : v(0) {}
   modnum(ll v_) : v(int(v_ % MOD)) { if (v < 0) v += MOD; }
   explicit operator int() const { return v; }
   friend std::ostream& operator << (std::ostream& out, const modnum& n) { return out << int(n); }
   friend std::istream& operator >> (std::istream& in, modnum& n) { ll v_; in >> v_; n = modnum(v_); return in; }
   friend bool operator == (const modnum& a, const modnum& b) { return a.v == b.v; }
   friend bool operator != (const modnum& a, const modnum& b) { return a.v != b.v; }
   modnum inv() const {
      modnum res;
      res.v = minv(v, MOD);
      return res;
   }
   friend modnum inv(const modnum& m) { return m.inv(); }
   modnum neg() const {
      modnum res;
      res.v = v ? MOD-v : 0;
      return res;
   }
   friend modnum neg(const modnum& m) { return m.neg(); }
   modnum operator- () const {
      return neg();
   }
   modnum operator+ () const {
      return modnum(*this);
   }
   modnum& operator ++ () {
      v ++;
      if (v == MOD) v = 0;
      return *this;
   }
   modnum& operator -- () {
      if (v == 0) v = MOD;
      v --;
      return *this;
   }
   modnum& operator += (const modnum& o) {
      v += o.v;
      if (v >= MOD) v -= MOD;
      return *this;
   }
   modnum& operator -= (const modnum& o) {
      v -= o.v;
      if (v < 0) v += MOD;
      return *this;
   }
   modnum& operator *= (const modnum& o) {
      v = int(ll(v) * ll(o.v) % MOD);
      return *this;
   }
   modnum& operator /= (const modnum& o) {
      return *this *= o.inv();
   }
   friend modnum operator ++ (modnum& a, int) { modnum r = a; ++a; return r; }
   friend modnum operator -- (modnum& a, int) { modnum r = a; --a; return r; }
   friend modnum operator + (const modnum& a, const modnum& b) { return modnum(a) += b; }
   friend modnum operator - (const modnum& a, const modnum& b) { return modnum(a) -= b; }
   friend modnum operator * (const modnum& a, const modnum& b) { return modnum(a) *= b; }
   friend modnum operator / (const modnum& a, const modnum& b) { return modnum(a) /= b; }
};

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
   // BUILD
   void build(vector<ll> &ar, int cur, int l, int r) {
      if (l + 1 == r) {
         data[cur] = ar[l];
      } else {
         int mid = (l + r) / 2;
         int cl = cur * 2, cr = cur * 2 + 1;
         build(ar, cl, l, mid);
         build(ar, cr, mid, r);
         data[cur] = data[cl] + data[cr];
      }
   }
   void build(vector<ll> &ar) {
      build(ar, 1, 0, size);
   }
   void build(ll *ar, int cur, int l, int r) {
      if (l + 1 == r) {
         data[cur] = ar[l];
      } else {
         int mid = (l + r) / 2;
         int cl = cur * 2, cr = cur * 2 + 1;
         build(ar, cl, l, mid);
         build(ar, cr, mid, r);
         data[cur] = data[cl] + data[cr];
      }
   }
   void build(ll *ar) {
      build(ar, 1, 0, size);
   }
   void down(int cur, int l, int r) {
      int cl = cur * 2, cr = cur * 2 + 1;
      ll diff = lazy[cur] * (r - l) / 2;
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
         return ql + qr;
      }
   }
   ll ask(int left, int right) {
      return ask(left, right, 1, 0, size);
   }
   // ADD
   void add(int left, int right, ll val, int cur, int l, int r) {
      if (left <= l && r <= right) {
         lazy[cur] += val;
         data[cur] += val * (r - l);
      } else if (left >= r || l >= right) {
      } else {
         down(cur, l, r);
         int mid = (l + r) / 2;
         int cl = cur * 2, cr = cur * 2 + 1;
         add(left, right, val, cl, l, mid);
         add(left, right, val, cr, mid, r);
         data[cur] = data[cl] + data[cr];
      }
   }
   void add(int left, int right, ll val) {
      add(left, right, val, 1, 0, size);
   }
};

// ============= Solution ============= //
int main() {
   int T;
   cin >> T;
   while (T--) {
      int n;
      cin >> n;
      int m = n * n;
      vector<int> par(m), size(m);
      for (int i = 0; i < m; ++i) {
         par[i] = i;
         size[i] = 1;
      }
      auto id = [&](int x, int y) -> int {
         if (x > y) swap(x, y);
         return n * x + y;
      };
      auto find = yc([&](auto rec, int x) -> int {
         if (x == par[x]) return x;
         return par[x] = rec(par[x]);
      });
      auto join = [&](int a, int b) -> void {
         a = find(a);
         b = find(b);
         if (a == b) return;
         size[a] += size[b];
         par[b] = a;
      };
      vector<pii> bad;
      for (int i = 1; i <= n - 1; ++i) {
         for (int j = 1; j <= n - i; ++j) {
            string s;
            cin >> s;
            for (int k = 1; k <= n; ++k) {
               if (s[k - 1] == '1') {
                  pp(i - 1, k - 1, i + j - 1, k - 1);
                  join(id(i - 1, k - 1), id(i + j - 1, k - 1));
                  pp(id(i - 1, k - 1), size[find(id(i - 1, k - 1))]);
               } else {
                  bad.push_back(pii(id(i - 1, k - 1), id(i + j - 1, k - 1)));
               }
            }
         }
      }

      bool early = false;
      for (pii p: bad) {
         if (find(p.fi) == find(p.se)) {
            cout << "No\n";
            early = true;
            break;
         }
      }
      if (early) continue;

      auto ok = [&](vector<pii> edges) {
         pp(edges);
         int inf = 1000 << 20;
         vector<vector<int>> adj(n, vector<int>(n, inf));
         for (pii p: edges) {
            adj[p.fi][p.se] = adj[p.se][p.fi] = 1;
         }
         for (int i = 0; i < n; ++i) {
            adj[i][i] = 0;
         }
         for (int k = 0; k < n; ++k) {
            for (int i = 0; i < n; ++i) {
               for (int j = 0; j < n; ++j) {
                  adj[i][j] = min(adj[i][j], adj[i][k] + adj[k][j]);
               }
            }
         }
         pp(adj);
         for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
               for (int k = 0; k < n; ++k) {
                  if (find(id(i, j)) == find(id(i, k))) {
                     if (adj[i][j] != adj[i][k]) {
                        return false;
                     }
                  } else {
                     if (adj[i][j] == adj[i][k]) return false;
                  }
               }
            }
         }
         for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
               if (adj[i][j] == inf) return false;
            }
         }
         return true;
      };

      vector<pii> ans;
      for (int g = 0; g < m; ++g) {
         if (find(g) != g) continue;
         // pp(g, size[g]);
         if (size[g] == n - 1) {
            vector<pii> edges;
            for (int i = 0; i < n; ++i) {
               for (int j = 0; j < i; ++j) {
                  if (find(id(i, j)) == g) {
                     edges.push_back(pii(i, j));
                  }
               }
            }
            if (sz(edges) != n - 1) {
               continue;
            }
            if (ok(edges)) {
               ans = edges;
               break;
            }
         }
      }

      if (sz(ans)) {
         cout << "Yes\n";
         for (pii p: ans) {
            cout << p.fi + 1 << " " << p.se + 1 << "\n";
         }
      } else {
         cout << "No\n";
      }
   }
}

// ============== Notes =============== //
// common bugs
// - fastio
// - int overflow (especially intermediate expressionns)
// - forgot to initialize data (is 0 the right value? -1, inf, -inf?)
// - array bounds (indices bigger than MAXN?)
// - special cases (n=1? graph not connected?)
// - re-initialize efficiently between test cases