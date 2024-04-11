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

class Seg {
   int size;
   vector<ll> data;
   public:
   Seg(int _size) {
      size = 1;
      while (size < _size) size *= 2;
      data = vector<ll>(size * 2);
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
   // ASK
   ll ask(int left, int right, int cur, int l, int r) {
      if (left <= l && r <= right) {
         return data[cur];
      } else if (left >= r || l >= right) {
         return 0;
      } else {
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
   // SET
   void inc(int left, int right, ll val, int cur, int l, int r) {
      if (left <= l && r <= right) {
         data[cur] += val * (r - l);
      } else if (left >= r || l >= right) {
      } else {
         int mid = (l + r) / 2;
         int cl = cur * 2, cr = cur * 2 + 1;
         inc(left, right, val, cl, l, mid);
         inc(left, right, val, cr, mid, r);
         data[cur] = data[cl] + data[cr];
      }
   }
   void inc(int left, ll val) {
      inc(left, left + 1, val, 1, 0, size);
   }
};




// ============= Solution ============= //

int main() {
   int n, m, q;
   cin >> n >> m >> q;
   vector<int> a(n), b(m);
   for (int &i: a) cin >> i;
   for (int &i: b) cin >> i;
   
   // track segtree of b vals, where b[i] --> inc(b[i], b[i]);
   // a min, b min, a max, b max
   // a sum

   multiset<ll> avals(a.begin(), a.end()), bvals(b.begin(), b.end());
   ll asum = 0;
   for (int i: a) asum += i;

   int maxn = 1E6 + 10;
   Seg bsums(maxn), bcounts(maxn);
   for (int i: b) {
      bsums.inc(i, i);
      bcounts.inc(i, 1);
   }

   for (int i = 0; i < q; ++i) {
      int qt, pos, x, k;
      cin >> qt;
      if (qt == 1) {
         cin >> pos >> x;
         --pos;
         avals.erase(avals.find(a[pos]));
         asum -= a[pos];
         a[pos] = x;
         avals.insert(a[pos]);
         asum += a[pos];
      } else if (qt == 2) {
         cin >> pos >> x;
         --pos;
         bvals.erase(bvals.find(b[pos]));
         bsums.inc(b[pos], -b[pos]);
         bcounts.inc(b[pos], -1);
         b[pos] = x;
         bvals.insert(b[pos]);
         bsums.inc(b[pos], b[pos]);
         bcounts.inc(b[pos], 1);
      } else {
         cin >> k;
         const ll infl = 1LL << 60;
         ll amin = *avals.begin();
         ll amax = *avals.rbegin();
         ll bmin = *bvals.begin();
         ll bmax = *bvals.rbegin();
         ll ans = -infl;
         auto checkA = [&](ll astart) {
            ll start = astart - k;
            ll av = asum - astart + k - (n - 1) * min(min(amin, bmin), start);
            ll bv = bsums.ask(start, maxn) - bcounts.ask(start, maxn) * start;
            ans = max(ans, av - bv);
         };
         auto checkB = [&](ll bstart) {
            ll start = bstart - k;
            ll av = asum - (n) * min(min(amin, bmin), start);
            ll bv = bsums.ask(start, maxn) - bcounts.ask(start, maxn) * start;
            ans = max(ans, av - bv);
         };

         // for (int i: a) checkA(i);
         // for (int i: b) checkB(i);
         checkA(amax);
         checkA(amin);
         checkB(bmax);
         checkB(bmin);
         auto it = avals.lower_bound(bmax + k);
         if (it != avals.end()) {
            checkA(*it);
         }
         if (it != avals.begin()) {
            --it;
            checkA(*it);
         }

         cout << ans << "\n";
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