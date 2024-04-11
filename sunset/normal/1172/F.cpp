#include <bits/stdc++.h>

using namespace std;

const long long INF = 1ll << 60;

class segtree {
  int n;
  long long p;
  vector<long long> sum;
  vector<vector<long long>> tree;

  void build(int x, int l, int r, vector<int>& a) {
    if (l == r) {
      tree[x] = {-INF, p - a[l]};
      sum[x] = a[l];
    } else {
      int y = (l + r) >> 1, z = x + ((y - l + 1) << 1);
      build(x + 1, l, y, a);
      build(z, y + 1, r, a);
      tree[x].assign(r - l + 2, INF);
      for (int i = 0, j = 0; i < (int) tree[x + 1].size(); ++i) {
        long long xleft = tree[x + 1][i], xright = i + 1 < (int) tree[x + 1].size() ? tree[x + 1][i + 1] - 1 : INF;
        long long yleft = xleft + sum[x + 1] - i * p, yright = xright + sum[x + 1] - i * p;
        while (j && tree[z][j] > yleft) {
          j--;
        }
        while (j + 1 < (int) tree[z].size() && tree[z][j + 1] <= yleft) {
          j++;
        }
        while (j < (int) tree[z].size() && tree[z][j] <= yright) {
          tree[x][i + j] = min(tree[x][i + j], max(xleft, tree[z][j] - sum[x + 1] + i * p));
          j++;
        }
        if (j == (int) tree[z].size()) {
          j--;
        }
      }
      tree[x][0] = -INF;
      sum[x] = sum[x + 1] + sum[z];
    }
  }

 public:
  segtree(int n, long long p, vector<int> a) : n(n), p(p) {
    tree.resize(2 * n - 1);
    sum.resize(2 * n - 1);
    build(0, 0, n - 1, a);
  }

  long long query(int x, int l, int r, int ll, int rr, long long v) {
    if (ll <= l && r <= rr) {
      return v + sum[x] - p * (upper_bound(tree[x].begin(), tree[x].end(), v) - tree[x].begin() - 1);
    } else {
      int y = (l + r) >> 1, z = x + ((y - l + 1) << 1);
      if (rr <= y) {
        return query(x + 1, l, y, ll, rr, v);
      } else if (ll > y) {
        return query(z, y + 1, r, ll, rr, v);
      } else {
        return query(z, y + 1, r, ll, rr, query(x + 1, l, y, ll, rr, v));
      }
    }
  }
};

int main() {
#ifdef LOCAL
  freopen("input.txt", "r", stdin);
#endif
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, m;
  long long p;
  cin >> n >> m >> p;
  vector<int> a(n);
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }
  segtree seg(n, p, a);
  while (m--) {
    int l, r;
    cin >> l >> r;
    l--;
    r--;
    cout << seg.query(0, 0, n - 1, l, r, 0) << "\n";
  }
  return 0;
}