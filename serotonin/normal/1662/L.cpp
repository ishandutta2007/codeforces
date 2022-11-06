#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int N = 200010;
const int INF = 1e8 + 69;

struct FenwickTree {
  int n;
  vector <int> f;

  FenwickTree (int n = 0) : n(n) {
    f.resize(n + 1, -INF);
  }

  void update (int p, int v) {
    while (p <= n) f[p] = max(f[p], v), p += p & -p;
  }

  int get (int p) {
    int ret = -INF;
    while (p) ret = max(ret, f[p]), p -= p & -p;
    return ret;
  }
};

int n, dp[N], rev[N]; 
vector <ll> t[N << 1];
FenwickTree f[N << 1];
ll v, tym[N], a[N], y[N];
tuple <ll, int, ll> yo[N];

void update (int p, int v, ll who) {
  p += n;
  while (p) {
    vector <ll> &vec = t[p];
    FenwickTree &fen = f[p];
    int pos = lower_bound(vec.begin(), vec.end(), who) - vec.begin();
    fen.update(pos + 1, v);
    p >>= 1;
  }
}

int query (int l, int r, ll up) {
  int ret = -INF;
  for (l += n, r += n; l < r; l >>= 1, r >>= 1) {
    if (l & 1) {
      vector <ll> &vec = t[l];
      FenwickTree &fen = f[l++];
      int pos = upper_bound(vec.begin(), vec.end(), up) - vec.begin();
      ret = max(ret, fen.get(pos));
    }
    if (r & 1) {
      vector <ll> &vec = t[--r];
      FenwickTree &fen = f[r];
      int pos = upper_bound(vec.begin(), vec.end(), up) - vec.begin();
      ret = max(ret, fen.get(pos));
    }
  }
  return ret;
}

int main() {
  cin >> n >> v; ++n;
  for (int i = 1; i < n; ++i) {
    scanf("%lld", tym + i);
  }
  for (int i = 1; i < n; ++i) {
    scanf("%lld", a + i);
  }
  for (int i = 0; i < n; ++i) {
    yo[i] = make_tuple(v * tym[i] - a[i], i, v * tym[i] + a[i]);
    // cerr << i << " --> " << v * tym[i] - a[i] << " " << v * tym[i] + a[i] << '\n';
  }
  sort(yo, yo + n);
  for (int i = 0; i < n; ++i) {
    y[i] = get<2>(yo[i]);
    rev[get<1>(yo[i])] = i;
    // cerr << get<1>(yo[i]) << " --> " << get<0>(yo[i]) << " " << get<2>(yo[i]) << '\n';
  }
  for (int i = 0; i < n; ++i) {
    t[n + i] = {y[i]}, f[n + i] = FenwickTree(1);
  }
  for (int i = n - 1; i; --i) {
    merge(t[i << 1].begin(), t[i << 1].end(), t[i << 1 | 1].begin(), t[i << 1 | 1].end(), back_inserter(t[i]));
    f[i] = FenwickTree(t[i].size());
  }
  for (int i = 0; i < n; ++i) {
    int pos = rev[i];
    if (i) dp[i] = 1 + query(0, pos, y[pos]);
    update(pos, dp[i], y[pos]);
    // cerr << i << " --> " << pos << " " << y[pos] << " " << dp[i] << '\n';
  }
  cout << *max_element(dp, dp + n) << '\n';
  return 0;
}