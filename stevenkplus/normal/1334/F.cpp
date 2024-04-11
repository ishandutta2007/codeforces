// =========== Template ========== //
#include <bits/stdc++.h>
using namespace std;
int fastio() { ios_base::sync_with_stdio(false); cout << fixed << setprecision(10); cin.tie(nullptr); return 0; }
int __fastio = fastio();
template<typename A, typename B> ostream& operator<<(ostream &os, const pair<A, B> &p);
template<typename A, typename B> ostream& operator<<(ostream &os, const map<A, B> &m) { os << "{"; string sep = ""; for (auto e: m) os << sep << e.first << ": " << e.second, sep = ", "; return os << "}"; }
template<typename T>ostream& operator<<(ostream& os, const vector<T>& v) { os << "["; string sep = ""; for (auto e: v) os << sep << e, sep = ", "; return os << "]"; }
template<typename A, typename B> ostream& operator<<(ostream &os, const pair<A, B> &p) { os << '(' << p.first << ", " << p.second << ')'; return os; }
void dbg_out() { cerr << endl; }
template<typename Head, typename... Tail> void dbg_out(Head H, Tail... T) { cerr << ' ' << H; dbg_out(T...); }
#ifdef STEVEN
#define pp(...) cerr << "\t[" << #__VA_ARGS__ << "]:\t", dbg_out(__VA_ARGS__)
#else
#define pp(...)
#endif
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef long double ld;
#define fi first
#define se second
#define sz(x) (int((x).size()))
#define data _data
// =========== Book ============ //

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


const ll big = 5E14;
// ============= Solution ============= //

int main() {
  int n;
  cin >> n;
  vector<int> a(n), p(n);
  for (int &i: a) cin >> i;
  for (int &i: p) cin >> i;
  int m;
  cin >> m;
  vector<int> b(m);
  for (int &i: b) cin >> i;
  pp(a);
  pp(b);
  LazySeg seg(m + 1);
  seg.add(1, m + 1, big * 10); // yeah, it'll overflow higher-up nodes but whatever
  for (int i = 0; i < n; ++i) {
    int el = lower_bound(b.begin(), b.end(), a[i]) - b.begin();
    pp(el);
    if (p[i] < 0) {
      seg.add(el + 1, m + 1, p[i]);
    }
    if (el < sz(b) && b[el] == a[i]) {
      ll prv = seg.ask(el, el + 1);
      ll cur = seg.ask(el + 1, el + 2);
      ll val = min(cur, prv);
      seg.add(el + 1, el + 2, val - cur);
    }
    seg.add(0, el + 1, p[i]);
  }
  ll ans = seg.ask(m, m + 1);
  if (ans > big) {
    cout << "NO\n";
  } else {
    cout << "YES\n";
    cout << ans << "\n";
  }
}

// ============== Notes =============== //
// common bugs
// - fastio
// - int overflow (especially intermediate expressionns)
// - array bounds (indices bigger than MAXN?)
// - special cases (n=1? graph not connected?)
// - re-initialize efficiently between test cases