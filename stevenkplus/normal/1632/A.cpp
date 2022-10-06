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

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

// AVX-enabled std::bitset Pragmas (before #includes!)
// - bitset<200000> takes ~ 1ms per 1000 operations on GNU C++14 & GNU C++17
// #pragma GCC optimize("Ofast","unroll-loops","omit-frame-pointer","inline") //Optimization flags
// #pragma GCC option("arch=native","tune=native","no-zero-upper") //Enable AVX
// #pragma GCC target("avx2")  //Enable AVX

// ordered_set with order_of_key and find_by_order
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
// WARNING: functions as a set (doesn't allow duplicates); insert pairs instead if duplicates are needed.
template<typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

namespace hopcroft_karp {
   using vi = vector<int>;
#define rep(i,a,b) for(int i = (a); i < (b); ++i)
#define all(x) x.begin(), x.end()
   bool dfs(int a, int L, vector<vi>& g, vi& btoa, vi& A, vi& B) {
      if (A[a] != L) return 0;
      A[a] = -1;
      for (int b : g[a]) if (B[b] == L + 1) {
         B[b] = 0;
         if (btoa[b] == -1 || dfs(btoa[b], L + 1, g, btoa, A, B))
            return btoa[b] = a, 1;
      }
      return 0;
   }
   int hopcroftKarp(vector<vi>& g, vi& btoa) {
      int res = 0;
      vi A(g.size()), B(btoa.size()), cur, next;
      for (;;) {
         fill(all(A), 0);
         fill(all(B), 0);
         /// Find the starting nodes for BFS (i.e. layer 0).
         cur.clear();
         for (int a : btoa) if(a != -1) A[a] = -1;
         rep(a,0,sz(g)) if(A[a] == 0) cur.push_back(a);
         /// Find all layers using bfs.
         for (int lay = 1;; lay++) {
            bool islast = 0;
            next.clear();
            for (int a : cur) for (int b : g[a]) {
               if (btoa[b] == -1) {
                  B[b] = lay;
                  islast = 1;
               }
               else if (btoa[b] != a && !B[b]) {
                  B[b] = lay;
                  next.push_back(btoa[b]);
               }
            }
            if (islast) break;
            if (next.empty()) return res;
            for (int a : next) A[a] = lay;
            cur.swap(next);
         }
         /// Use DFS to scan for augmenting paths.
         rep(a,0,sz(g))
            res += dfs(a, 0, g, btoa, A, B);
      }
   }
   // https://github.com/bqi343/USACO/blob/1fe61df6df2fbc1671a385bbdf395965ac512dce/Implementations/content/numerical/Arithmetic/BigInt.h bignum book code
   constexpr int base = 1000000000;
   constexpr int base_digits = 9;
   struct bigint {
      // value == 0 is represented by empty z
      vector<int> z; // digits
                     // sign == 1 <==> value >= 0
                     // sign == -1 <==> value < 0
      int sign;
      bigint() : sign(1) {}
      bigint(long long v) { *this = v; }
      bigint &operator=(long long v) {
         sign = v < 0 ? -1 : 1; v *= sign;
         z.clear(); for (; v > 0; v = v / base) z.push_back((int) (v % base));
         return *this;
      }
      bigint(const string &s) { read(s); }
      bigint &operator+=(const bigint &other) {
         if (sign == other.sign) {
            for (int i = 0, carry = 0; i < sz(other.z) || carry; ++i) {
               if (i == sz(z))
                  z.push_back(0);
               z[i] += carry + (i < sz(other.z) ? other.z[i] : 0);
               carry = z[i] >= base;
               if (carry)
                  z[i] -= base;
            }
         } else if (other != 0 /* prevent infinite loop */) {
            *this -= -other;
         }
         return *this;
      }
      friend bigint operator+(bigint a, const bigint &b) { return a += b; }
      bigint &operator-=(const bigint &other) {
         if (sign == other.sign) {
            if ((sign == 1 && *this >= other) || (sign == -1 && *this <= other)) {
               for (int i = 0, carry = 0; i < sz(other.z) || carry; ++i) {
                  z[i] -= carry + (i < sz(other.z) ? other.z[i] : 0);
                  carry = z[i] < 0;
                  if (carry)
                     z[i] += base;
               }
               trim();
            } else {
               *this = other - *this;
               this->sign = -this->sign;
            }
         } else {
            *this += -other;
         }
         return *this;
      }
      friend bigint operator-(bigint a, const bigint &b) { return a -= b; }
      bigint &operator*=(int v) {
         if (v < 0) sign = -sign, v = -v;
         for (int i = 0, carry = 0; i < sz(z) || carry; ++i) {
            if (i == sz(z))
               z.push_back(0);
            long long cur = (long long) z[i] * v + carry;
            carry = (int) (cur / base);
            z[i] = (int) (cur % base);
         }
         trim();
         return *this;
      }
      bigint operator*(int v) const { return bigint(*this) *= v; }
      friend pair<bigint, bigint> divmod(const bigint &a1, const bigint &b1) {
         int norm = base / (b1.z.back() + 1);
         bigint a = a1.abs() * norm;
         bigint b = b1.abs() * norm;
         bigint q, r;
         q.z.resize(sz(a.z));
         for (int i = (int) sz(a.z) - 1; i >= 0; i--) {
            r *= base;
            r += a.z[i];
            int s1 = sz(b.z) < sz(r.z) ? r.z[sz(b.z)] : 0;
            int s2 = sz(b.z) - 1 < sz(r.z) ? r.z[sz(b.z) - 1] : 0;
            int d = (int) (((long long) s1 * base + s2) / b.z.back());
            r -= b * d;
            while (r < 0)
               r += b, --d;
            q.z[i] = d;
         }
         q.sign = a1.sign * b1.sign;
         r.sign = a1.sign;
         q.trim();
         r.trim();
         return {q, r / norm};
      }
      friend bigint sqrt(const bigint &a1) {
         bigint a = a1;
         while (a.z.empty() || sz(a.z) % 2 == 1)
            a.z.push_back(0);
         int n = sz(a.z);
         int firstDigit = (int) ::sqrt((double) a.z[n - 1] * base + a.z[n - 2]);
         int norm = base / (firstDigit + 1);
         a *= norm;
         a *= norm;
         while (a.z.empty() || sz(a.z) % 2 == 1)
            a.z.push_back(0);
         bigint r = (long long) a.z[n - 1] * base + a.z[n - 2];
         firstDigit = (int) ::sqrt((double) a.z[n - 1] * base + a.z[n - 2]);
         int q = firstDigit;
         bigint res;
         for (int j = n / 2 - 1; j >= 0; j--) {
            for (;; --q) {
               bigint r1 = (r - (res * 2 * base + q) * q) * base * base +
                  (j > 0 ? (long long) a.z[2 * j - 1] * base + a.z[2 * j - 2] : 0);
               if (r1 >= 0) {
                  r = r1;
                  break;
               }
            }
            res *= base;
            res += q;
            if (j > 0) {
               int d1 = sz(res.z) + 2 < sz(r.z) ? r.z[sz(res.z) + 2] : 0;
               int d2 = sz(res.z) + 1 < sz(r.z) ? r.z[sz(res.z) + 1] : 0;
               int d3 = sz(res.z) < sz(r.z) ? r.z[sz(res.z)] : 0;
               q = (int) (((long long) d1 * base * base + (long long) d2 * base + d3) / (firstDigit * 2));
            }
         }
         res.trim();
         return res / norm;
      }
      bigint operator/(const bigint &v) const { return divmod(*this, v).first; }
      bigint operator%(const bigint &v) const { return divmod(*this, v).second; }
      bigint &operator/=(int v) {
         if (v < 0) sign = -sign, v = -v;
         for (int i = (int) sz(z) - 1, rem = 0; i >= 0; --i) {
            long long cur = z[i] + rem * (long long) base;
            z[i] = (int) (cur / v);
            rem = (int) (cur % v);
         }
         trim();
         return *this;
      }
      bigint operator/(int v) const { return bigint(*this) /= v; }
      int operator%(int v) const {
         if (v < 0) v = -v;
         int m = 0;
         for (int i = (int) sz(z) - 1; i >= 0; --i)
            m = (int) ((z[i] + m * (long long) base) % v);
         return m * sign;
      }
      bigint &operator*=(const bigint &v) { return *this = *this * v; }
      bigint &operator/=(const bigint &v) { return *this = *this / v; }
      bool operator<(const bigint &v) const {
         if (sign != v.sign)
            return sign < v.sign;
         if (sz(z) != sz(v.z))
            return sz(z) * sign < sz(v.z) * v.sign;
         for (int i = (int) sz(z) - 1; i >= 0; i--)
            if (z[i] != v.z[i])
               return z[i] * sign < v.z[i] * sign;
         return false;
      }
      bool operator>(const bigint &v) const { return v < *this; }
      bool operator<=(const bigint &v) const { return !(v < *this); }
      bool operator>=(const bigint &v) const { return !(*this < v); }
      bool operator==(const bigint &v) const { return !(*this < v) && !(v < *this); }
      bool operator!=(const bigint &v) const { return *this < v || v < *this; }
      void trim() {
         while (!z.empty() && z.back() == 0) z.pop_back();
         if (z.empty()) sign = 1;
      }
      bool isZero() const { return z.empty(); }
      friend bigint operator-(bigint v) {
         if (!v.z.empty()) v.sign = -v.sign;
         return v;
      }
      bigint abs() const {
         return sign == 1 ? *this : -*this;
      }
      long long longValue() const {
         long long res = 0;
         for (int i = (int) sz(z) - 1; i >= 0; i--)
            res = res * base + z[i];
         return res * sign;
      }
      friend bigint gcd(const bigint &a, const bigint &b) {
         return b.isZero() ? a : gcd(b, a % b);
      }
      friend bigint lcm(const bigint &a, const bigint &b) {
         return a / gcd(a, b) * b;
      }
      void read(const string &s) {
         sign = 1;
         z.clear();
         int pos = 0;
         while (pos < sz(s) && (s[pos] == '-' || s[pos] == '+')) {
            if (s[pos] == '-')
               sign = -sign;
            ++pos;
         }
         for (int i = (int) sz(s) - 1; i >= pos; i -= base_digits) {
            int x = 0;
            for (int j = max(pos, i - base_digits + 1); j <= i; j++)
               x = x * 10 + s[j] - '0';
            z.push_back(x);
         }
         trim();
      }
      friend istream &operator>>(istream &stream, bigint &v) {
         string s; stream >> s;
         v.read(s);
         return stream;
      }
      friend ostream &operator<<(ostream &stream, const bigint &v) {
         if (v.sign == -1)
            stream << '-';
         stream << (v.z.empty() ? 0 : v.z.back());
         for (int i = (int) sz(v.z) - 2; i >= 0; --i)
            stream << setw(base_digits) << setfill('0') << v.z[i];
         return stream;
      }
      static vector<int> convert_base(const vector<int> &a, int old_digits, int new_digits) {
         vector<long long> p(max(old_digits, new_digits) + 1);
         p[0] = 1;
         for (int i = 1; i < sz(p); i++)
            p[i] = p[i - 1] * 10;
         vector<int> res;
         long long cur = 0;
         int cur_digits = 0;
         for (int v : a) {
            cur += v * p[cur_digits];
            cur_digits += old_digits;
            while (cur_digits >= new_digits) {
               res.push_back(int(cur % p[new_digits]));
               cur /= p[new_digits];
               cur_digits -= new_digits;
            }
         }
         res.push_back((int) cur);
         while (!res.empty() && res.back() == 0)
            res.pop_back();
         return res;
      }
      typedef vector<long long> vll;
      static vll karatsubaMultiply(const vll &a, const vll &b) {
         int n = sz(a);
         vll res(n + n);
         if (n <= 32) {
            for (int i = 0; i < n; i++)
               for (int j = 0; j < n; j++)
                  res[i + j] += a[i] * b[j];
            return res;
         }
         int k = n >> 1;
         vll a1(a.begin(), a.begin() + k);
         vll a2(a.begin() + k, a.end());
         vll b1(b.begin(), b.begin() + k);
         vll b2(b.begin() + k, b.end());
         vll a1b1 = karatsubaMultiply(a1, b1);
         vll a2b2 = karatsubaMultiply(a2, b2);
         for (int i = 0; i < k; i++)
            a2[i] += a1[i];
         for (int i = 0; i < k; i++)
            b2[i] += b1[i];
         vll r = karatsubaMultiply(a2, b2);
         for (int i = 0; i < sz(a1b1); i++)
            r[i] -= a1b1[i];
         for (int i = 0; i < sz(a2b2); i++)
            r[i] -= a2b2[i];
         for (int i = 0; i < sz(r); i++)
            res[i + k] += r[i];
         for (int i = 0; i < sz(a1b1); i++)
            res[i] += a1b1[i];
         for (int i = 0; i < sz(a2b2); i++)
            res[i + n] += a2b2[i];
         return res;
      }
      bigint operator*(const bigint &v) const {
         vector<int> a6 = convert_base(this->z, base_digits, 6);
         vector<int> b6 = convert_base(v.z, base_digits, 6);
         vll a(a6.begin(), a6.end());
         vll b(b6.begin(), b6.end());
         while (sz(a) < sz(b))
            a.push_back(0);
         while (sz(b) < sz(a))
            b.push_back(0);
         while (sz(a) & (sz(a) - 1))
            a.push_back(0), b.push_back(0);
         vll c = karatsubaMultiply(a, b);
         bigint res;
         res.sign = sign * v.sign;
         for (int i = 0, carry = 0; i < sz(c); i++) {
            long long cur = c[i] + carry;
            res.z.push_back((int) (cur % 1000000));
            carry = (int) (cur / 1000000);
         }
         res.z = convert_base(res.z, 6, base_digits);
         res.trim();
         return res;
      }
   };
}

typedef priority_queue<pii, vector<pii>, greater<pii> > PQ;

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
      string s;
      cin >> s;
      if (s == "0" || s == "1" || s == "10" || s == "01") {
         cout << "YES\n";
      } else {
         cout << "NO\n";
      }
   }
}

// ============== Notes =============== //
// common bugs
// - fastio
// - int overflow (especially intermediate expressionns)
// - array bounds (indices bigger than MAXN?)
// - special cases (n=1? graph not connected?)
// - re-initialize efficiently between test cases