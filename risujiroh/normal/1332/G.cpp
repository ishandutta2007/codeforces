#include <bits/stdc++.h>
using namespace std;

template <class T> struct segtree {
  const int n;
  vector<T> t;
  segtree(int _n = 0) : n(_n), t(2 * n) {}
  T& operator[](int i) { return t[n + i]; }
  void build() { for (int i = n; i--; ) t[i] = t[2 * i] * t[2 * i + 1]; }
  T fold(int l, int r) const {
    T a, b;
    for (l += n, r += n; l < r; l >>= 1, r >>= 1) {
      if (l & 1) a = a * t[l++];
      if (r & 1) b = t[--r] * b;
    }
    return a * b;
  }
  void set(int i, T a) {
    t[i += n] = a;
    while (i >>= 1) t[i] = t[2 * i] * t[2 * i + 1];
  }
};

struct mini {
  pair<int, int> v = {0x3f3f3f3f, -1};
  mini operator*(mini b) const {
    return {min(v, b.v)};
  }
};

int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);
  int n, q;
  cin >> n >> q;
  vector<int> a(n);
  for (auto&& e : a) {
    cin >> e;
  }
  vector<int> lt(n + 1, n), gt(n + 1, n), mj(n, n);
  stack<int> inc, dec, ndec, ninc;
  vector<int> cnt(n);
  set<int> se;
  for (int i = n; i--; ) {
    while (not inc.empty() and a[inc.top()] >= a[i]) {
      inc.pop();
    }
    while (not dec.empty() and a[dec.top()] <= a[i]) {
      dec.pop();
    }
    while (not ndec.empty() and a[ndec.top()] > a[i]) {
      if (++cnt[ndec.top()] == 2) {
        se.insert(ndec.top());
      }
      ndec.pop();
    }
    while (not ninc.empty() and a[ninc.top()] < a[i]) {
      if (++cnt[ninc.top()] == 2) {
        se.insert(ninc.top());
      }
      ninc.pop();
    }
    if (not inc.empty()) {
      lt[i] = inc.top();
    }
    if (not dec.empty()) {
      gt[i] = dec.top();
    }
    auto it = se.upper_bound(max(lt[i], gt[i]));
    if (it != end(se)) {
      mj[i] = *it;
    }
    inc.push(i);
    dec.push(i);
    ndec.push(i);
    ninc.push(i);
  }
  segtree<mini> ud(n), du(n), seg(n), mni(n), mxi(n);
  for (int i = 0; i < n; ++i) {
    ud[i] = {{lt[gt[i]], i}};
    du[i] = {{gt[lt[i]], i}};
    seg[i] = {{mj[i], i}};
    mni[i] = {{a[i], i}};
    mxi[i] = {{-a[i], i}};
  }
  ud.build(), du.build(), seg.build(), mni.build(), mxi.build();
  while (q--) {
    int l, r;
    cin >> l >> r;
    --l;
    vector<int> res;
    {
      int i, j;
      tie(j, i) = ud.fold(l, r).v;
      if (j < r) {
        res = {i, gt[i], lt[gt[i]]};
      }
    }
    {
      int i, j;
      tie(j, i) = du.fold(l, r).v;
      if (j < r) {
        res = {i, lt[i], gt[lt[i]]};
      }
    }
    {
      int i, j;
      tie(j, i) = seg.fold(l, r).v;
      if (j < r) {
        res = {i, mni.fold(i + 1, j).v.second, mxi.fold(i + 1, j).v.second, j};
      }
    }
    sort(begin(res), end(res));
    int k = res.size();
    cout << k << '\n';
    for (int i = 0; i < k; ++i) {
      cout << res[i] + 1 << " \n"[i == k - 1];
    }
  }
}