#include <bits/stdc++.h>
using namespace std;
using uint = unsigned int;
using lint = long long int;
using ulint = unsigned long long int;
template<class T = int> using V = vector<T>;
template<class T = int> using VV = V< V<T> >;
template<class T, class U> void assign(V<T>& v, int n, const U& a) { v.assign(n, a); }
template<class T, class... Args> void assign(V<T>& v, int n, const Args&... args) { v.resize(n); for (auto&& e : v) assign(e, args...); }


struct MaxMonoidAct {
  using T = pair<int, int>;
  using U = T;
  static void ap(const U& f, T& x) { x = max(x, f); }
  static void cp(const U& g, U& f) { f = max(f, g); }
  static constexpr U id() { return {0, 0}; }
};

template<class MonoidAct> struct SegmentTree {
  using M = MonoidAct;
  using T = typename M::T;
  using U = typename M::U;

  const int n;

  SegmentTree(int n, const T& a) :
    n(n), val(n, a), laz(n, M::id()) {}
  template<class Itr> SegmentTree(Itr first, Itr last) :
    n(distance(first, last)), val(first, last), laz(n, M::id()) {}

  void push() {
    for (int i = 1; i < n; ++i) push(i);
  }

  T get(int i) {
    assert(0 <= i and i < n);
    for (int h = __lg(i += n); h > 0; --h) {
      push(i >> h);
    }
    return val[i - n];
  }

  void set(int l, int r, const U& f) {
    l = max(l, 0), r = min(r, n);
    if (l >= r) return;
    push(l, r);
    for (int i = l + n, j = r + n; i < j; i >>= 1, j >>= 1) {
      if (i & 1) ap(f, i++);
      if (j & 1) ap(f, --j);
    }
  }
  void set(int i, const T& a) {
    assert(0 <= i and i < n);
    for (int h = __lg(i += n); h > 0; --h) {
      push(i >> h);
    }
    val[i - n] = a;
  }

private:
  V<T> val;
  V<U> laz;

  void ap(const U& f, int i) {
    if (i < n) M::cp(f, laz[i]);
    else M::ap(f, val[i - n]);
  }

  void push(int i) {
    ap(laz[i], 2 * i);
    ap(laz[i], 2 * i + 1);
    laz[i] = M::id();
  }
  void push(int l, int r) {
    for (int hl = __lg(l + n), hr = __lg(r - 1 + n); hr > 0; --hl, --hr) {
      int al = l + n >> hl, ar = r - 1 + n >> hr;
      if (al < n) push(al);
      if (ar != al) push(ar);
    }
  }
};

using ST = SegmentTree<MaxMonoidAct>;

int main() {
  cin.tie(nullptr); ios_base::sync_with_stdio(false);
  int n, m, k; cin >> n >> m >> k;
  V<> s(k), t(k), d(k), w(k); for (int i = 0; i < k; ++i) cin >> s[i] >> t[i] >> d[i] >> w[i], --s[i], --t[i], --d[i];
  ST st(n, {0, 0});
  for (int j = 0; j < k; ++j) {
    st.set(s[j], t[j] + 1, {w[j], d[j]});
  }
  V<lint> a(n + 1);
  V< pair<int, int> > p(n);
  for (int i = n - 1; i >= 0; --i) {
    p[i] = st.get(i);
    if (p[i].first > 0) {
      a[i] = p[i].first + a[p[i].second + 1];
    } else {
      a[i] = a[i + 1];
    }
  }
  VV<lint> dp; assign(dp, n + 1, m + 1, 0);
  for (int i = n - 1; i >= 0; --i) {
    dp[i][0] = a[i];
    for (int x = 0; x < m; ++x) {
      dp[i][x + 1] = dp[i + 1][x];
      if (p[i].first > 0) {
        dp[i][x + 1] = min(dp[i][x + 1], p[i].first + dp[p[i].second + 1][x + 1]);
      } else {
        dp[i][x + 1] = min(dp[i][x + 1], dp[i + 1][x + 1]);
      }
    }
  }
  cout << *min_element(begin(dp[0]), end(dp[0])) << '\n';
}