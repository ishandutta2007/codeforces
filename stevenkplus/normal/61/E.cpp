// =========== Template ========== //
#include <bits/stdc++.h>
using namespace std;
int fastio() { ios_base::sync_with_stdio(false); cout << fixed << setprecision(10); cin.tie(nullptr); return 0; }
int __fastio = fastio();
template<typename A, typename B> ostream& operator<<(ostream &os, const pair<A, B> &p);
template<typename T>ostream& operator<<(ostream& os, const vector<T>& v) { string sep = "{"; for (auto e: v) os << sep << e, sep = ", "; return os << "}"; }
template<typename A, typename B> ostream& operator<<(ostream &os, const pair<A, B> &p) { os << '(' << p.first << ", " << p.second << ')'; return os; }
void dbg_out() { cerr << endl; }
template<typename Head, typename... Tail> void dbg_out(Head H, Tail... T) { cerr << ' ' << H; dbg_out(T...); }
#ifdef STEVEN
#define pp(...) cerr << "(" << #__VA_ARGS__ << "):", dbg_out(__VA_ARGS__)
#else
#define pp(...)
#endif
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef long double ld;
#define fi first
#define se second

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


// =========== Solution ============= //

int main() {
  int n;
  cin >> n;
  LazySeg seg(n);
  vector<pii> v(n);
  vector<ll> left(n), right(n);
  for (int i = 0; i < n; ++i) {
    cin >> v[i].first;
    v[i].second = i;
  }
  sort(v.begin(), v.end());
  reverse(v.begin(), v.end());
  for (auto i: v) {
    seg.add(i.se, i.se + 1, 1);
    left[i.se] = seg.ask(0, i.se);
  }
  reverse(v.begin(), v.end());
  seg = LazySeg(n);
  for (auto i: v) {
    seg.add(i.se, i.se + 1, 1);
    right[i.se] = seg.ask(i.se + 1, n);
  }

  pp(left, right);
  ll ans = 0;
  for (int i = 0; i < n; ++i) {
    ans += 1LL * left[i] * right[i];
  }
  cout << ans << "\n";
}

// ============== Notes =============== //
// common bugs
// - fastio
// - int overflow (especially intermediate expressionns)
// - array bounds (indices bigger than MAXN? different MAXN vs MAXM?)
// - special cases (n=1? graph not connected?)
// - initialize & re-initialize efficiently between test cases
//
// history of bugs
// - 3/28/20 forgot to initialize set with dummy node (n) [cf 1136e]
// - 3/28/20 array bounds (map was size MAXN instead of MAXK) [cf 1210b]
// - 3/29/20 array bounds ([MAXN][MAXN][4] -> [MAXN][MAXN * 2][4]) [cf 1051d]
// - 3/29/20 special cases (answer cannot be empty string) [cf 848a]
// - 3/29/20 special case / bad initialization of (ans, ansi) when backtracking [cf 733f]