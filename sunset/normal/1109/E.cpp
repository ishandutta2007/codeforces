#include <bits/stdc++.h>

using namespace std;

const int MAX = (int) 1e5;

class node {
 public:
  vector<int> tag;
  int sum, mul;
};

int main() {
#ifdef wxh010910
  freopen("input.txt", "r", stdin);
#endif
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int n, md;
  cin >> n >> md;
  vector<int> factors;
  {
    int temp = md;
    for (int i = 2; i * i <= temp; ++i) {
      if (temp % i == 0) {
        factors.push_back(i);
        while (temp % i == 0) {
          temp /= i;
        }
      }
    }
    if (temp != 1) {
      factors.push_back(temp);
    }
  }
  vector<int> a(n);
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }
  vector<vector<int>> powers(factors.size(), vector<int>(1, 1));
  auto get_power = [&](int x, int y) {
    while ((int) powers[x].size() <= y) {
      powers[x].push_back((long long) powers[x].back() * factors[x] % md);
    }
    return powers[x][y];
  };
  vector<vector<pair<int, int>>> divisors(MAX + 1);
  vector<int> remain(MAX + 1);
  vector<int> inv(MAX + 1);
  for (int i = 1; i <= MAX; ++i) {
    remain[i] = i;
  }
  for (int i = 0; i < (int) factors.size(); ++i) {
    for (int j = factors[i]; j <= MAX; j += factors[i]) {
      int e = 0;
      while (remain[j] % factors[i] == 0) {
        remain[j] /= factors[i];
        ++e;
      }
      divisors[j].emplace_back(i, e);
    }
  }
  for (int i = 1; i <= MAX; ++i) {
    if (remain[i] == i) {
      int a = i, b = md, u = 0, v = 1;
      while (a) {
        int t = b / a;
        b -= t * a;
        swap(a, b);
        u -= t * v;
        swap(u, v);
      }
      if (u < 0) {
        u += md;
      }
      inv[i] = u;
    }
  }
  vector<node> tree(n * 2 - 1);
  auto pull = [&](int x, int z) {
    tree[x].sum = (tree[x + 1].sum + tree[z].sum) % md;
  };
  auto push = [&](int x, int z) {
    for (int i = 0; i < (int) tree[x].tag.size(); ++i) {
      if (tree[x].tag[i]) {
        int w = get_power(i, tree[x].tag[i]);
        tree[x + 1].tag[i] += tree[x].tag[i];
        tree[x + 1].sum = (long long) tree[x + 1].sum * w % md;
        tree[z].tag[i] += tree[x].tag[i];
        tree[z].sum = (long long) tree[z].sum * w % md;
        tree[x].tag[i] = 0;
      }
    }
    if (tree[x].mul != 1) {
      int w = tree[x].mul;
      tree[x + 1].sum = (long long) tree[x + 1].sum * w % md;
      tree[x + 1].mul = (long long) tree[x + 1].mul * w % md;
      tree[z].sum = (long long) tree[z].sum * w % md;
      tree[z].mul = (long long) tree[z].mul * w % md;
      tree[x].mul = 1;
    }
  };
  function<void(int, int, int, int, int, int)> multiply = [&](int x, int l, int r, int ll, int rr, int v) {
    if (ll <= l && r <= rr) {
      for (auto p : divisors[v]) {
        tree[x].tag[p.first] += p.second;
      }
      tree[x].sum = (long long) tree[x].sum * v % md;
      tree[x].mul = (long long) tree[x].mul * remain[v] % md;
    } else {
      int y = l + r >> 1, z = x + (y - l + 1 << 1);
      push(x, z);
      if (ll <= y) {
        multiply(x + 1, l, y, ll, rr, v);
      }
      if (rr > y) {
        multiply(z, y + 1, r, ll, rr, v);
      }
      pull(x, z);
    }
  };
  function<void(int, int, int, int, int)> divide = [&](int x, int l, int r, int p, int v) {
    if (l == r) {
      for (auto p : divisors[v]) {
        tree[x].tag[p.first] -= p.second;
      }
      tree[x].sum = tree[x].mul = (long long) tree[x].mul * inv[remain[v]] % md;
      for (int i = 0; i < (int) tree[x].tag.size(); ++i) {
        tree[x].sum = (long long) tree[x].sum * get_power(i, tree[x].tag[i]) % md;
      }
    } else {
      int y = l + r >> 1, z = x + (y - l + 1 << 1);
      push(x, z);
      if (p <= y) {
        divide(x + 1, l, y, p, v);
      }
      if (p > y) {
        divide(z, y + 1, r, p, v);
      }
      pull(x, z);
    }
  };
  function<int(int, int, int, int, int)> query = [&](int x, int l, int r, int ll, int rr) {
    if (ll <= l && r <= rr) {
      return tree[x].sum;
    } else {
      int y = l + r >> 1, z = x + (y - l + 1 << 1);
      push(x, z);
      int ans = 0;
      if (ll <= y) {
        ans = (ans + query(x + 1, l, y, ll, rr)) % md;
      }
      if (rr > y) {
        ans = (ans + query(z, y + 1, r, ll, rr)) % md;
      }
      return ans;
    }
  };
  function<void(int, int, int)> build = [&](int x, int l, int r) {
    tree[x].tag.resize(factors.size());
    tree[x].sum = tree[x].mul = 1;
    if (l == r) {
      multiply(x, l, r, l, r, a[l]);
    } else {
      int y = l + r >> 1, z = x + (y - l + 1 << 1);
      build(x + 1, l, y);
      build(z, y + 1, r);
      pull(x, z);
    }
  };
  build(0, 0, n - 1);
  int tt;
  cin >> tt;
  while (tt--) {
    int type;
    cin >> type;
    if (type == 1) {
      int l, r, v;
      cin >> l >> r >> v;
      --l;
      --r;
      multiply(0, 0, n - 1, l, r, v);
    } else if (type == 2) {
      int p, v;
      cin >> p >> v;
      --p;
      divide(0, 0, n - 1, p, v);
    } else {
      int l, r;
      cin >> l >> r;
      --l;
      --r;
      cout << query(0, 0, n - 1, l, r) << "\n";
    }
  }
  return 0;
}