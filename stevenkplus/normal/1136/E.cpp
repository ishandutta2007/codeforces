// =========== Template ========== //
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef long double ld;
#define fi first
#define se second

// =========== Book ============ //

int fastio() {
  ios_base::sync_with_stdio(0);
  cout << fixed << setprecision(10);
  cin.tie(0);
  return 0;
}
int __fastio = fastio();

class LazySeg {
  int size;
  vector<ll> data;
  vector<ll> lazy;
  public:
    LazySeg(int _size) {
      size = _size;
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

const int MAXN = 1 << 17;
ll ar[MAXN];
ll ksum[MAXN];
set<int> live; // 0 and n are always "live"
ll k[MAXN]; // k[i] only has meaning if i is in live

LazySeg seg(MAXN);
int n;
void makelive(int x) {
  if (live.find(x) != live.end()) return;
  auto p = live.lower_bound(x);
  --p;
  int y = *p;
  ar[x] = ar[y] + ksum[x] - ksum[y];
  live.insert(x);
}

// inc & propagate, recursively if necessary
void inc(int x, ll val) {
  int nxt = *live.upper_bound(x);
  ar[x] += val;
  seg.add(x, nxt, val);
  if (nxt < n) {
    ll nval = ar[x] + ksum[nxt] - ksum[x];
    if (nval > ar[nxt]) {
      inc(nxt, nval - ar[nxt]);
      live.erase(nxt);
    }
  }
}

int main() {
  cin >> n;
  for (int i = 0; i < n; ++i) {
    live.insert(i);
    cin >> ar[i];
  }
  live.insert(n);
  for (int i = 0; i < n - 1; ++i) {
    cin >> k[i];
    ksum[i + 1] = ksum[i] + k[i];
  }
  seg.build(ar);
  int q;
  cin >> q;
  for (int i = 0; i < q; ++i) {
    char type;
    int a, b;
    cin >> type >> a >> b;
    if (type == '+') {
      --a;
      makelive(a);
      inc(a, b);
    } else {
      --a; --b;
      ll res = seg.ask(a, b + 1);
      cout << res << "\n";
    }
  }
}

// ============== Notes =============== //
// common bugs
// - fastio
// - int overflow (especially intermediate expressionns)
// - array bounds (indices bigger than MAXN? different MAXN vs MAXM?)
// - special cases (n=1? graph not connected?)
// - re-initialize efficiently between test cases
//
// history of bugs
// - 3/28/20 array bounds (map was size MAXN instead of MAXK)