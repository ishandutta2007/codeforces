#include<bits/stdc++.h>
using namespace std;
using P = pair<int, int>;
const int M = 1000000007;
// const int M = 998244353;
const long long LM = 1LL << 60;
using usize = size_t;

class range_mode_query {
  class b_node {
  public:
    usize value;
    usize rank;

    b_node(const usize value, const usize rank) : value(value), rank(rank) {}
  };

public:
  class s_node {
  public:
    usize mode;
    usize freq;

    s_node(const usize mode, const usize freq) : mode(mode), freq(freq) {}
  };

private:
  std::vector<b_node> b;
  std::vector<std::vector<usize>> q;
  std::vector<std::vector<s_node>> s;
  usize t;

public:
  range_mode_query() = default;

  range_mode_query(const std::vector<usize> a) : t(1) {
    const usize n = a.size();
    b.assign(n, b_node(0, 0));
    q.assign(n, {});
    while (t * t < n)
      t += 1;
    for (usize i = 0; i != n; i += 1) {
      const usize e = a[i];
      assert(e < n);
      b[i] = b_node(e, q[e].size());
      q[e].push_back(i);
    }
    s.assign(n / t + 1, std::vector<s_node>(n / t + 1, s_node(0, 0)));
    for (usize f = 0; f * t <= n; f += 1) {
      std::vector<usize> freq(n, 0);
      s_node cur(0, 0);
      for (usize l = f + 1; l * t <= n; l += 1) {
        for (usize i = (l - 1) * t; i != l * t; i += 1) {
          const usize e = a[i];
          freq[e] += 1;
          if (freq[e] > cur.freq)
            cur = s_node(e, freq[e]);
        }
        s[f][l] = cur;
      }
    }
  }

  s_node query(const usize first, const usize last) const {
    assert(first < last);
    assert(last <= b.size());
    usize bf = first / t + 1;
    usize bl = last / t;
    if (bf >= bl) {
      s_node cur(0, 0);
      for (usize i = first; i != last; i += 1) {
        const b_node &e = b[i];
        const std::vector<usize> &v = q[e.value];
        usize idx;
        while ((idx = e.rank + cur.freq) < v.size() && v[idx] < last)
          cur = s_node(e.value, cur.freq + 1);
      }
      return cur;
    }
    s_node cur = s[bf][bl];
    for (usize i = first; i != bf * t; i += 1) {
      const b_node &e = b[i];
      const std::vector<usize> &v = q[e.value];
      usize idx;
      while ((idx = e.rank + cur.freq) < v.size() && v[idx] < last)
        cur = s_node(e.value, cur.freq + 1);
    }
    for (usize i = bl * t; i != last; i += 1) {
      const b_node &e = b[i];
      const std::vector<usize> &v = q[e.value];
      usize idx;
      while ((idx = e.rank - cur.freq) < v.size() && v[idx] >= first)
        cur = s_node(e.value, cur.freq + 1);
    }
    return cur;
  }
};

int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);
    int n, q;
    cin >> n >> q;
    vector<usize> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        --a[i];
    }
    range_mode_query rmq(a);
    for (int i = 0; i < q; ++i) {
        int l, r;
        cin >> l >> r;
        --l;
        auto res = rmq.query(l, r);
        int len = r - l;
        int f = res.freq;
        cout << max(f - (len - f), 1) << '\n';

    }
    return 0;
}