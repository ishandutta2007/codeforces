#include <bits/stdc++.h>
using namespace std;
using lint = long long;
template<class T = int> using V = vector<T>;
template<class T = int> using VV = V< V<T> >;

template<class Int> Int rng(Int a, Int b) {
  static mt19937 mt(chrono::steady_clock::now().time_since_epoch().count());
  return uniform_int_distribution<Int>(a, b - 1)(mt);
}

namespace RandomizedBinarySearchTree {
  using T = pair<int, int>;
  T op(const T& x, const T& y) { return max(x, y); }
  T op(const T& x, const T& y, const T& z) { return op(op(x, y), z); }
  constexpr T e = {0, -1};
  using U = int;
  void ap(const U& f, T& x) {}
  void cp(const U& g, U& f) {}
  constexpr U id = 0;

  struct Node;
  using Tree = Node*;
  struct Node {
    int sz = 0;
    T val = e, acc = e;
    U laz = id;
    bool rev = false;
    Tree cl = nullptr, cr = nullptr;
    Node() {} // nil
    Node(const T& val); // leaf
    Node(const T& val, const T& acc, const U& laz, bool rev, Tree cl, Tree cr) :
      sz(cl->sz + 1 + cr->sz), val(val), acc(acc), laz(laz), rev(rev), cl(cl), cr(cr) {}
  };
  Tree nil = new Node();
  Node::Node(const T& val) : sz(1), val(val), acc(val), cl(nil), cr(nil) {}

  Tree apply(Tree t, const U& f) {
    if (t == nil) return t;
    ap(f, t->val);
    ap(f, t->acc);
    cp(f, t->laz);
    return t;
  }
  Tree reverse(Tree t) {
    if (t == nil) return t;
    swap(t->cl, t->cr);
    t->rev ^= true;
    return t;
  }
  Tree push(Tree t) {
    if (t->laz != id) {
      t->cl = apply(t->cl, t->laz);
      t->cr = apply(t->cr, t->laz);
      t->laz = id;
    }
    if (t->rev) {
      t->cl = reverse(t->cl);
      t->cr = reverse(t->cr);
      t->rev = false;
    }
    return t;
  }
  Tree update(Tree t) {
    t->sz = t->cl->sz + 1 + t->cr->sz;
    t->acc = op(t->cl->acc, t->val, t->cr->acc);
    return t;
  }

  template<class Itr> Tree build(Itr first, Itr last) {
    int n = distance(first, last);
    if (n == 0) return nil;
    Itr middle = next(first, n / 2);
    Tree cl = build(first, middle);
    Tree cr = build(next(middle), last);
    return new Node(*middle, op(cl->acc, *middle, cr->acc), id, false, cl, cr);
  }
  template<class Itr> Itr dump(Tree t, Itr res) {
    if (t == nil) return res;
    t = push(t);
    res = dump(t->cl, res);
    *res++ = t->val;
    res = dump(t->cr, res);
    return res;
  }
  Tree rebuild(Tree t) {
    V<T> v(t->sz);
    dump(t, begin(v));
    return build(begin(v), end(v));
  }

  Tree merge(Tree tl, Tree tr) {
    if (tr == nil) return tl;
    if (tl == nil) return tr;
    if (rng(0, tl->sz + tr->sz) < tl->sz) {
      tl = push(tl);
      tl->cr = merge(tl->cr, tr);
      return update(tl);
    } else {
      tr = push(tr);
      tr->cl = merge(tl, tr->cl);
      return update(tr);
    }
  }
  Tree merge(Tree tl, Tree tm, Tree tr) { return merge(merge(tl, tm), tr); }
  pair<Tree, Tree> split(Tree t, int i) {
    if (t == nil) return {nil, nil};
    t = push(t);
    if (i <= t->cl->sz) {
      Tree tl;
      tie(tl, t->cl) = split(t->cl, i);
      return {tl, update(t)};
    } else {
      Tree tr;
      tie(t->cr, tr) = split(t->cr, i - t->cl->sz - 1);
      return {update(t), tr};
    }
  }
  tuple<Tree, Tree, Tree> split(Tree t, int l, int r) {
    Tree tl, tm, tr;
    tie(tl, tr) = split(t, r);
    tie(tl, tm) = split(tl, l);
    return make_tuple(tl, tm, tr);
  }

  Tree insert(Tree t, int i, const T& val) {
    Tree tl, tr;
    tie(tl, tr) = split(t, i);
    return merge(tl, new Node(val), tr);
  }
  Tree erase(Tree t, int i) {
    Tree tl, tm, tr;
    tie(tl, tm, tr) = split(t, i, i + 1);
    return merge(tl, tr);
  }

  T get_val(Tree t, int i) {
    if (t == nil) return e;
    if (i == t->cl->sz) return t->val;
    t = push(t);
    if (i < t->cl->sz) return get_val(t->cl, i);
    else return get_val(t->cr, i - t->cl->sz - 1);
  }
  Tree set_val(Tree t, int i, const T& val) {
    if (t == nil) return t;
    t = push(t);
    if (i == t->cl->sz) {
      t->val = val;
      return update(t);
    }
    if (i < t->cl->sz) {
      t->cl = set_val(t->cl, i, val);
      return update(t);
    } else {
      t->cr = set_val(t->cr, i - t->cl->sz - 1, val);
      return update(t);
    }
  }

  T acc(Tree t, int l, int r) {
    if (t == nil or l <= 0 and t->sz <= r) return t->acc;
    t = push(t);
    T resl = l < t->cl->sz ? acc(t->cl, l, r) : e;
    T resr = t->cl->sz + 1 < r ? acc(t->cr, l - t->cl->sz - 1, r - t->cl->sz - 1) : e;
    T resm = l <= t->cl->sz and t->cl->sz < r ? t->val : e;
    return op(resl, resm, resr);
  }
  Tree act(Tree t, int l, int r, const U& f) {
    if (t == nil or l <= 0 and t->sz <= r) return apply(t, f);
    t = push(t);
    if (l < t->cl->sz) t->cl = act(t->cl, l, r, f);
    if (t->cl->sz + 1 < r) t->cr = act(t->cr, l - t->cl->sz - 1, r - t->cl->sz - 1, f);
    if (l <= t->cl->sz and t->cl->sz < r) ap(f, t->val);
    return update(t);
  }
  Tree reverse(Tree t, int l, int r) {
    Tree tl, tm, tr;
    tie(tl, tm, tr) = split(t, l, r);
    tm = reverse(tm);
    return merge(tl, tm, tr);
  }
}
namespace RBST = RandomizedBinarySearchTree;

template<class T> struct FenwickTree {
  const int n;
  V<T> t;
  FenwickTree(int n) : n(n), t(n + 1) {}
  void add(int i, T x) { for (++i; i <= n; i += i & -i) t[i] += x; }
  T sum(int i) const {
    T s = 0;
    for (; i; i -= i & -i) s += t[i];
    return s;
  }
  T sum(int l, int r) const { return sum(r) - sum(l); }
};

int main() {
  cin.tie(nullptr); ios::sync_with_stdio(false);
  int n, k; cin >> n >> k;
  auto t = RBST::nil;
  V<> ia(n + 1);
  for (int i = 0; i < n; ++i) {
    int a; cin >> a;
    t = insert(t, i, {a, i});
  }
  V<> res(n);
  int c = 1;
  FenwickTree<int> ft(n);
  while (t->sz) {
    int s = acc(t, 0, t->sz).second;
    s -= ft.sum(s);
    for (int i = min(s + k, t->sz - 1); i >= max(s - k, 0); --i) {
      int j = get_val(t, i).second;
      res[j] = c;
      t = erase(t, i);
      ft.add(j, 1);
    }
    c = 3 - c;
  }
  for (int i = 0; i < n; ++i) cout << res[i];
  cout << '\n';
}