#include <functional>
#include <algorithm>
#include <iostream>
#include <cassert>
#include <vector>
#include <map>
using namespace std;
typedef pair<int, int> P;

/**
 * @brief Lazy-Segment-Tree()
 * @docs docs/lazy-segment-tree.md
 */
template< typename Monoid, typename OperatorMonoid, typename F, typename G, typename H >
struct LazySegmentTree {
private:
  int n{}, sz{}, height{};
  vector< Monoid > data;
  vector< OperatorMonoid > lazy;
  const F f;
  const G g;
  const H h;
  const Monoid M1;
  const OperatorMonoid OM0;

  inline void update(int k) {
    data[k] = f(data[2 * k + 0], data[2 * k + 1]);
  }

  inline void all_apply(int k, const OperatorMonoid &x) {
    data[k] = g(data[k], x);
    if(k < sz) lazy[k] = h(lazy[k], x);
  }

  inline void propagate(int k) {
    if(lazy[k] != OM0) {
      all_apply(2 * k + 0, lazy[k]);
      all_apply(2 * k + 1, lazy[k]);
      lazy[k] = OM0;
    }
  }

public:
  LazySegmentTree() = default;

  explicit LazySegmentTree(int n, const F f, const G g, const H h,
                           const Monoid &M1, const OperatorMonoid &OM0)
      : n(n), f(f), g(g), h(h), M1(M1), OM0(OM0) {
    sz = 1;
    height = 0;
    while(sz < n) sz <<= 1, height++;
    data.assign(2 * sz, M1);
    lazy.assign(2 * sz, OM0);
  }

  explicit LazySegmentTree(const vector< Monoid > &v, const F f, const G g, const H h,
                           const Monoid &M1, const OperatorMonoid &OM0)
      : LazySegmentTree(v.size(), f, g, h, M1, OM0) {
    build(v);
  }

  void build(const vector< Monoid > &v) {
    assert(n == (int) v.size());
    for(int k = 0; k < n; k++) data[k + sz] = v[k];
    for(int k = sz - 1; k > 0; k--) update(k);
  }

  void set(int k, const Monoid &x) {
    k += sz;
    for(int i = height; i > 0; i--) propagate(k >> i);
    data[k] = x;
    for(int i = 1; i <= height; i++) update(k >> i);
  }

  Monoid get(int k) {
    k += sz;
    for(int i = height; i > 0; i--) propagate(k >> i);
    return data[k];
  }

  Monoid operator[](int k) {
    return get(k);
  }

  Monoid prod(int l, int r) {
    if(l >= r) return M1;
    l += sz;
    r += sz;
    for(int i = height; i > 0; i--) {
      if(((l >> i) << i) != l) propagate(l >> i);
      if(((r >> i) << i) != r) propagate((r - 1) >> i);
    }
    Monoid L = M1, R = M1;
    for(; l < r; l >>= 1, r >>= 1) {
      if(l & 1) L = f(L, data[l++]);
      if(r & 1) R = f(data[--r], R);
    }
    return f(L, R);
  }

  Monoid all_prod() const {
    return data[1];
  }

  void apply(int k, const OperatorMonoid &x) {
    k += sz;
    for(int i = height; i > 0; i--) propagate(k >> i);
    data[k] = g(data[k], x);
    for(int i = 1; i <= height; i++) update(k >> i);
  }

  void apply(int l, int r, const OperatorMonoid &x) {
    if(l >= r) return;
    l += sz;
    r += sz;
    for(int i = height; i > 0; i--) {
      if(((l >> i) << i) != l) propagate(l >> i);
      if(((r >> i) << i) != r) propagate((r - 1) >> i);
    }
    {
      int l2 = l, r2 = r;
      for(; l < r; l >>= 1, r >>= 1) {
        if(l & 1) all_apply(l++, x);
        if(r & 1) all_apply(--r, x);
      }
      l = l2, r = r2;
    }
    for(int i = 1; i <= height; i++) {
      if(((l >> i) << i) != l) update(l >> i);
      if(((r >> i) << i) != r) update((r - 1) >> i);
    }
  }

  template< typename C >
  int find_first(int l, const C &check) {
    if(l >= n) return n;
    l += sz;
    for(int i = height; i > 0; i--) propagate(l >> i);
    Monoid sum = M1;
    do {
      while((l & 1) == 0) l >>= 1;
      if(check(f(sum, data[l]))) {
        while(l < sz) {
          propagate(l);
          l <<= 1;
          auto nxt = f(sum, data[l]);
          if(not check(nxt)) {
            sum = nxt;
            l++;
          }
        }
        return l + 1 - sz;
      }
      sum = f(sum, data[l++]);
    } while((l & -l) != l);
    return n;
  }

  template< typename C >
  int find_last(int r, const C &check) {
    if(r <= 0) return -1;
    r += sz;
    for(int i = height; i > 0; i--) propagate((r - 1) >> i);
    Monoid sum = 0;
    do {
      r--;
      while(r > 1 and (r & 1)) r >>= 1;
      if(check(f(data[r], sum))) {
        while(r < sz) {
          propagate(r);
          r = (r << 1) + 1;
          auto nxt = f(data[r], sum);
          if(not check(nxt)) {
            sum = nxt;
            r--;
          }
        }
        return r - sz;
      }
      sum = f(data[r], sum);
    } while((r & -r) != r);
    return -1;
  }
};

template< typename Monoid, typename OperatorMonoid, typename F, typename G, typename H >
LazySegmentTree< Monoid, OperatorMonoid, F, G, H > get_lazy_segment_tree
    (int N, const F &f, const G &g, const H &h, const Monoid &M1, const OperatorMonoid &OM0) {
  return LazySegmentTree{N, f, g, h, M1, OM0};
}

template< typename Monoid, typename OperatorMonoid, typename F, typename G, typename H >
LazySegmentTree< Monoid, OperatorMonoid, F, G, H > get_lazy_segment_tree
    (const vector< Monoid > &v, const F &f, const G &g, const H &h, const Monoid &M1, const OperatorMonoid &OM0) {
  return LazySegmentTree{v, f, g, h, M1, OM0};
}

vector<P> v[300005];
int t[300005], l[300005], r[300005];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m;
    cin >> n >> m;
    map<int, int> mp;
    for(int i = 0; i < m; i++){
        cin >> t[i] >> l[i] >> r[i];
        t[i]--; l[i]--;
        mp[l[i]]++;
        mp[r[i]]++;
    }
    int k = 0;
    for(P p : mp) mp[p.first] = k++;
    for(int i = 0; i < m; i++) v[t[i]].push_back(P(mp[l[i]], mp[r[i]]));
    auto F = [](P a, P b){return max(a, b);};
    auto G = [](P a, P f){return ((f.first == -1) ? a : f);};
    auto H = [](P g, P f){return ((f.first == -1) ? g : f);};
    auto seg = get_lazy_segment_tree(k, F, G, H, P(0, -1), P(-1, -1));
    int last[300005];
    for(int i = 0; i < n; i++){
        P x = P(0, -1);
        for(P p : v[i]){
            P q = seg.prod(p.first, p.second);
            x = max(x, P(q.first + 1, q.second));
        }
        last[i] = x.second;
        x.second = i;
        for(P p : v[i]) seg.apply(p.first, p.second, x);
    }
    P x = seg.all_prod();
    cout << n - x.first << endl;
    int u = x.second;
    bool b[300005]{0};
    while(u != -1){
        b[u] = true;
        u = last[u];
    }
    for(int i = 0; i < n; i++){
        if(!b[i]) cout << i + 1 << " ";
    }
    cout << endl;
}