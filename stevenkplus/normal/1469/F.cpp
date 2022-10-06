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
struct hashing {
    static constexpr int dimensions = 2;
    static constexpr int mod = (1u << 31) - 1;
    vector<vector<int>> hashes, p;

    static const vector<int> &get_bases() {
        static mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
        static vector<int> bases;
        while (bases.size() < dimensions) {
            bases.emplace_back(uniform_int_distribution<int>((int)1e9, mod - 1)(rng));
        }
        return bases;
    }

    hashing(const string &s) : hashes(dimensions), p(dimensions) {
        int n = s.size();
        const vector<int> &bases = get_bases();
        for (int d = 0; d < dimensions; ++d) {
            hashes[d].resize(n + 1);
            p[d].resize(n + 1);
            p[d][0] = 1;
            long long base = bases[d];
            for (int i = 0; i < n; i++) {
                hashes[d][i + 1] = (hashes[d][i] * base + s[i]) % mod;
                p[d][i + 1] = p[d][i] * base % mod;
            }
        }
    }

    pii get_hash(int i, int len) {
        pii res;
        for (int d = 0; d < dimensions; ++d) {
            int hash = (int)((hashes[d][i + len] + (long long)hashes[d][i] * (mod - p[d][len])) % mod);
            if (d == 0) {
               res.fi = hash;
            } else {
               res.se = hash;
            }
        }
        return res;
    }
};
// ============= Solution ============= //

// https://gist.github.com/bf2bd013e0948d6f6633dc397bf45e54
int main() { // dobby is a free elf
   int n, k;
   cin >> n >> k;
   vector<int> v(n);
   for (int &i: v) cin >> i;
   sort(v.begin(), v.end());
   reverse(v.begin(), v.end());


   int maxd = 1E7;
   auto check = [&](int ans) -> bool {
      vector<int> d(maxd + 1);
      ll sum = 1;
      d[0] = -1;
      auto inc = [&](int l, int r, int val) {
         pp(l, r, val);
         r = min(r, ans + 1);
         l = min(l, r);

         if (l > 0) {
            d[l - 1] += val;
         }
         d[r - 1] -= val;
         sum += (r - l) * val;
         pp(sum);
      };

      int cur = 0, curval = 1;
      if (sum >= k) return true;
      for (int i: v) {
         int a = (i - 1) / 2, b = i / 2;
         while (cur < ans && curval == 0) {
            curval += d[cur];
            ++cur;
         }
         if (cur >= ans) break;
         --curval;
         pp(cur, curval, i);
         inc(cur, cur + 1, -1);
         inc(cur + 2, cur + 2 + a, 1);
         inc(cur + 2, cur + 2 + b, 1);
         pp(sum);
         if (sum >= k) return true;
      }
      return false;
   };

   int lo = 0;
   int hi = maxd;
   // check(5);
   // return 0;
   while (lo < hi) {
      int mid = (lo + hi) / 2;
      if (mid == hi) --mid;
      if (check(mid)) {
         hi = mid;
      } else {
         lo = mid + 1;
      }
   }
   if (lo == maxd) lo = -1;
   cout << lo << "\n";
}

// ============== Notes =============== //
// common bugs
// - fastio
// - int overflow (especially intermediate expressionns)
// - array bounds (indices bigger than MAXN?)
// - special cases (n=1? graph not connected?)
// - re-initialize efficiently between test cases