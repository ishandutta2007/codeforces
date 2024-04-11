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

pii getHash(string s) {
   int n = sz(s);
   return (hashing(s).get_hash(0, n));
}

vector<int> bases = hashing::get_bases();
int mod = hashing::mod;
vector<vector<int>>  p;
pii concat(pii pref, string s) {
   int n = sz(s);
   int shift0 = p[0][n];
   int shift1 = p[1][n];
   pii p = getHash(s);
   return pii((1LL * pref.fi * shift0 + p.fi) % mod, (1LL * pref.se * shift1 + p.se) % mod);
}

string toStr(int k, int len) {
   string res;
   for (int i = 0; i < len; ++i) {
      if (k % 2 == 0) res += '0';
      else res += '1';
      k /= 2;
   }
   reverse(res.begin(), res.end());
   return res;
}

int main() { // dobby is a free elf
   int T;
   cin >> T;
   while (T--) {
      int n, k;
      cin >> n >> k;
      string s;
      cin >> s;
      // int goalLen = min(2, k);
      int goalLen = min(20, k);
      int prefLen = k - goalLen;
      string pref, complPref;
      for (int i = 0; i < prefLen; ++i) pref += '0';
      for (int i = 0; i < prefLen; ++i) complPref += '1';
      pii complPrefHash = getHash(complPref);

      set<pii> seenHashes;
      auto hsh = hashing(s);
      for (int i = 0; i + k <= n; ++i) {
         pii h = (hsh.get_hash(i, k));
         seenHashes.insert(h);
      }
      p = hsh.p;

      string ans = "NO";
      string ansS = "";
      for (int i = 0; i < (1 << goalLen); ++i) {
         string complS = toStr((1 << goalLen) - 1 - i, goalLen);
         pii complHash = concat(complPrefHash, complS);
         if (!seenHashes.count(complHash)) {
            ans = "YES";
            ansS = pref + toStr(i, goalLen);
            break;
         }
      }


      cout << ans << "\n";
      if (ans == "YES") {
         cout << ansS << "\n";
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