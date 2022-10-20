#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include "debug.h"
#else
#define DEBUG(...)
#endif

vector<int> sieve(int n) {
  vector<bool> b(n / 3 + 1, true);
  vector<int> res{2, 3};
  for (int p = 5, d = 4; p * p <= n; p += d = 6 - d) if (b[p / 3])
    for (int i = p * p, di = p % 3 * 2 * p; i <= n; i += di = 6 * p - di)
      b[i / 3] = false;
  for (int p = 5, d = 4; p <= n; p += d = 6 - d) if(b[p / 3]) res.push_back(p);
  while (not res.empty() and res.back() > n) res.pop_back();
  return res;
}

bitset<271> all;
template <class T> struct foldable_deque {
  vector<T> l, r, cuml = {all}, cumr = {all};
  T fold() const { return cuml.back() & cumr.back(); }
  void build(vector<T> v) {
    l = r = {}, cuml = cumr = {all};
    int n = v.size();
    for (int i = n / 2; i < n; ++i) push_back(v[i]);
    for (int i = n / 2; i--; ) push_front(v[i]);
  }
  void push_front(T a) { l.push_back(a), cuml.push_back(a & cuml.back()); }
  void push_back(T a) { r.push_back(a), cumr.push_back(cumr.back() & a); }
  void pop_front() {
    if (l.empty()) build({begin(r) + 1, end(r)});
    else l.pop_back(), cuml.pop_back();
  }
  void pop_back() {
    if (r.empty()) build({rbegin(l), rend(l) - 1});
    else r.pop_back(), cumr.pop_back();
  }
};

vector<int> head;
int m;
int solve(const vector<bitset<271>>& a) {
  int n = size(a), res = 0;
  foldable_deque<bitset<271>> deq;
  auto chk = [&](const auto& bs) {
    for (int i = 0; i < m; ++i) {
      if ((int)bs._Find_next(head[i] - 1) >= head[i + 1]) {
        return false;
      }
    }
    return true;
  };
  for (int l = 0, r = 0; l < n; ++l) {
    while (r < n and chk(deq.fold() & a[r])) {
      deq.push_back(a[r]);
      ++r;
    }
    res = max(res, r - l);
    deq.pop_front();
  }
  return res;
}

int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);
  all.set();
  auto primes = sieve(40);
  m = size(primes);
  vector<int> exponents(m);
  head.resize(m + 1);
  for (int i = 0; i < m; ++i) {
    int t = 1;
    while (t * primes[i] <= 40) {
      t *= primes[i];
      ++exponents[i];
    }
    head[i + 1] = head[i] + t;
  }
  assert(head[m] == 271);
  vector<vector<bitset<271>>> masks(41);
  for (int len = 1; len <= 40; ++len) {
    masks[len].resize(len);
    for (int pos = 0; pos < len; ++pos) {
      masks[len][pos].set();
      for (int i = 0; i < m; ++i) {
        int mod = head[i + 1] - head[i];
        int d = gcd(len, mod);
        for (int r = 0; r < mod; ++r) {
          if (r % d != pos % d) {
            masks[len][pos][head[i] + r] = 0;
          }
        }
      }
    }
  }
  int n, lim;
  cin >> n >> lim;
  vector<int> len(n);
  vector<vector<pair<int, bitset<271>>>> v(lim);
  for (int i = 0; i < n; ++i) {
    cin >> len[i];
    for (int pos = 0; pos < len[i]; ++pos) {
      int x;
      cin >> x;
      --x;
      v[x].emplace_back(i, masks[len[i]][pos]);
    }
  }
  vector<int> res(lim);
  for (int x = 0; x < lim; ++x) {
    int sz = size(v[x]);
    vector<bitset<271>> a;
    for (int t = 0; t < sz; ++t) {
      a.push_back(v[x][t].second);
      if (t == sz - 1 or v[x][t].first + 1 < v[x][t + 1].first) {
        res[x] = max(res[x], solve(a));
        a.clear();
      }
    }
  }
  for (auto e : res) {
    cout << e << '\n';
  }
}