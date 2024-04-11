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

const int N = 60;
typedef array<ll, N> bignum;
const ll base = 1E7;
bignum operator*(bignum a, bignum b) {
   bignum c = {0};
   for (int i = 0; i < N; ++i) {
      for (int j = 0; i + j < N; ++j) {
         c[i + j] += a[i] * b[j];
      }
   }
   for (int i = 0; i + 1 < N; ++i) {
      c[i + 1] += c[i] / base;
      c[i] %= base;
   }
   return c;
}

bool operator<(bignum a, bignum b) {
   for (int i = N - 1; i >= 0; --i) {
      if (a[i] != b[i]) return a[i] < b[i];
   }
   return false;
}

bignum fromLL(ll x) {
   return {x};
}

// ============= Solution ============= //
int main() {
   int n, d;
   cin >> n >> d;
   vector<int> v(n);
   for (int &i: v) cin >> i;
   sort(v.begin(), v.end());
   reverse(v.begin(), v.end());
   vector<vector<int>> k(10);
   for (int i: v) {
      k[i % 10].push_back(i);
   }

   vector<int> take, rem;
   if (d == 0) {
      take = v;
   } else if (d == 5) {
      for (int i: v) {
         if (i % 2 == 1) {
            take.push_back(i);
         }
      }
   } else if (d % 2 == 1) {
      for (int i = 1; i <= 9; i += 2) {
         if (i == 5) continue;
         int t = max(0, sz(k[i]) - ((i == 1 || i == 6) ? 1 : (i == 4 || i == 9) ? 2 : 4));
         take.insert(take.end(), k[i].begin(), k[i].begin() + t);
         rem.insert(rem.end(), k[i].begin() + t, k[i].end());
      }
   } else {
      for (int i = 1; i <= 9; i += 1) {
         if (i == 5) continue;
         int t = max(0, sz(k[i]) - ((i == 1 || i == 6) ? 1 : (i == 4 || i == 9) ? 2 : 4));
         take.insert(take.end(), k[i].begin(), k[i].begin() + t);
         rem.insert(rem.end(), k[i].begin() + t, k[i].end());
      }
   }
   pp(take, rem);
   int cur = 1;
   for (int i: take) cur = cur * i % 10;

   vector<int> r;
   ld maxp = 1;//fromLL(1);
   for (int i = 0; i < 1 << (sz(rem)); ++i) {
      int prod = cur;
      ld p = 1;//fromLL(1);
      vector<int> kk;
      for (int j = 0; j < sz(rem); ++j) {
         if ((i >> j) & 1) {
            kk.push_back(rem[j]);
            prod = prod * rem[j] % 10;
            p = p * rem[j];//fromLL(rem[j]);
         }
      }
      if (prod == d) {
         if (p >= maxp) {
            maxp = p;
            r = kk;
         }
      }
   }

   vector<int> fin = take;
   fin.insert(fin.end(), r.begin(), r.end());
   cur = 1;
   for (int i: fin) {
      cur = cur * i % 10;
   }
   pp(fin);
   if (sz(fin) == 0 || cur != d) {
      cout << "-1\n";
   } else {
      cout << sz(fin) << "\n";
      for (int i: fin) {
         cout << i << " ";
      }
      cout << "\n";
   }
}

// ============== Notes =============== //
// common bugs
// - fastio
// - int overflow (especially intermediate expressionns)
// - array bounds (indices bigger than MAXN?)
// - special cases (n=1? graph not connected?)
// - re-initialize efficiently between test cases