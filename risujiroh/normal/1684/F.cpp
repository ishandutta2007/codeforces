#include <bits/stdc++.h>

#ifndef LOCAL
#define LOCAL 0
#define DUMP(...) void(0)
#endif

using namespace std;

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int t;
  cin >> t;
  while (t--) {
    int n, m;
    cin >> n >> m;
    vector<int> a(n);
    for (int& e : a) cin >> e;
    vector<array<int, 2>> segs(m);
    for (auto&& [l, r] : segs) {
      cin >> l >> r;
      --l;
    }
    {
      sort(begin(segs), end(segs), [](auto x, auto y) {
        return x[1] != y[1] ? x[1] < y[1] : y[0] < x[0];
      });
      vector<array<int, 2>> nsegs;
      for (auto [l, r] : segs) {
        while (!empty(nsegs) && !(nsegs.back()[0] < l)) {
          nsegs.pop_back();
        }
        nsegs.push_back({l, r});
      }
      m = int(size(nsegs));
      segs = move(nsegs);
    }
    map<int, vector<int>> mp;
    for (int i = 0; i < n; ++i) {
      mp[a[i]].push_back(i);
    }
    vector<int> tree(2 * n, -1);
    auto chmax = [&](int l, int r, int x) {
      for (l += n, r += n; l < r; l >>= 1, r >>= 1) {
        if (l & 1) {
          tree[l] = max(tree[l], x);
          ++l;
        }
        if (r & 1) {
          --r;
          tree[r] = max(tree[r], x);
        }
      }
    };
    for (auto&& [_, v] : mp) {
      array<int, 2> first{-1, -1};
      for (int z = 0; z + 1 < int(size(v)); ++z) {
        auto it = upper_bound(begin(segs), end(segs), v[z],
                              [](auto x, auto y) { return x < y[0]; });
        if (it == begin(segs)) continue;
        --it;
        if ((*it)[1] <= v[z + 1]) continue;
        first = *it;
        break;
      }
      if (first[0] == -1) continue;
      array<int, 2> last;
      for (int z = int(size(v)); 1 < z--;) {
        auto it = upper_bound(begin(segs), end(segs), v[z],
                              [](auto x, auto y) { return x < y[1]; });
        if (it == end(segs)) continue;
        if (v[z - 1] < (*it)[0]) continue;
        last = *it;
        break;
      }
      assert(last[0] != -1);
      {
        int lz = int(lower_bound(begin(v), end(v), first[0]) - begin(v));
        int rz = int(lower_bound(begin(v), end(v), first[1]) - begin(v));
        chmax(0, v[lz] + 1, v[rz - 2] + 1);
        chmax(v[lz] + 1, v[lz + 1] + 1, v[rz - 1] + 1);
        chmax(v[lz + 1] + 1, n, 0x3f3f3f3f);
      }
      {
        int lz = int(lower_bound(begin(v), end(v), last[0]) - begin(v));
        int rz = int(lower_bound(begin(v), end(v), last[1]) - begin(v));
        chmax(0, v[lz] + 1, v[rz - 2] + 1);
        chmax(v[lz] + 1, v[lz + 1] + 1, v[rz - 1] + 1);
        chmax(v[lz + 1] + 1, n, 0x3f3f3f3f);
      }
      if (LOCAL) {
        int L = *next(lower_bound(begin(v), end(v), first[0]));
        int R = *prev(lower_bound(begin(v), end(v), last[1]), 2) + 1;
        if (L < R) {
          chmax(0, L + 1, R);
          chmax(L + 1, n, 0x3f3f3f3f);
        }
      }
    }
    int ans = n;
    for (int l = 0; l < n; ++l) {
      int mn = max(l, tree[n + l]);
      for (int i = n + l; i >>= 1;) {
        mn = max(mn, tree[i]);
      }
      ans = min(ans, mn - l);
    }
    cout << ans << '\n';
  }
}