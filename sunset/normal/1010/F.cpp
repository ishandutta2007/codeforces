#include <bits/stdc++.h>

using namespace std;

const int md = 998244353;

int add(int x, int y) {
  x += y;
  if (x >= md) {
    x -= md;
  }
  return x;
}

int sub(int x, int y) {
  x -= y;
  if (x < 0) {
    x += md;
  }
  return x;
}

int mul(int x, int y) {
  return (long long)x * y % md;
}

int power(int x, int y) {
  int result = 1;
  for (; y; y >>= 1, x = mul(x, x)) {
    if (y & 1) {
      result = mul(result, x);
    }
  }
  return result;
}

namespace ntt {
int base = 1, root = -1, max_base = -1;
vector<int> roots = {0, 1}, rev = {0, 1};

void init() {
  int temp = md - 1;
  max_base = 0;
  while (!(temp & 1)) {
    temp >>= 1;
    ++max_base;
  }
  root = 2;
  while (true) {
    if (power(root, 1 << max_base) == 1 && power(root, 1 << max_base - 1) != 1) {
      break;
    }
    ++root;
  }
}

void ensure_base(int nbase) {
  if (max_base == -1) {
    init();
  }
  if (nbase <= base) {
    return;
  }
  assert(nbase <= max_base);
  rev.resize(1 << nbase);
  for (int i = 0; i < (1 << nbase); ++i) {
    rev[i] = rev[i >> 1] >> 1 | ((i & 1) << nbase - 1);
  }
  roots.resize(1 << nbase);
  while (base < nbase) {
    int z = power(root, 1 << max_base - 1 - base);
    for (int i = 1 << base - 1; i < 1 << base; ++i) {
      roots[i << 1] = roots[i];
      roots[i << 1 | 1] = mul(roots[i], z);
    }
    ++base;
  }
}

void dft(vector<int> &a) {
  int n = a.size(), zeros = __builtin_ctz(n);
  ensure_base(zeros);
  int shift = base - zeros;
  for (int i = 0; i < n; ++i) {
    if (i < rev[i] >> shift) {
      swap(a[i], a[rev[i] >> shift]);
    }
  }
  for (int i = 1; i < n; i <<= 1) {
    for (int j = 0; j < n; j += i << 1) {
      for (int k = 0; k < i; ++k) {
        int x = a[j + k], y = mul(a[j + k + i], roots[i + k]);
        a[j + k] = add(x, y);
        a[j + k + i] = sub(x, y);
      }
    }
  }
}

vector<int> padd(vector<int> a, vector<int> b) {
  if (a.size() < b.size()) {
    a.resize(b.size());
  }
  for (int i = 0; i < b.size(); ++i) {
    a[i] = add(a[i], b[i]);
  }
  return a;
}

vector<int> psub(vector<int> a, vector<int> b) {
  if (a.size() < b.size()) {
    a.resize(b.size());
  }
  for (int i = 0; i < b.size(); ++i) {
    a[i] = sub(a[i], b[i]);
  }
  return a;
}

vector<int> pmul(vector<int> a, vector<int> b, bool equal = false) {
  int need = a.size() + b.size() - 1, nbase = 0;
  while (1 << nbase < need) {
    ++nbase;
  }
  ensure_base(nbase);
  int size = 1 << nbase;
  a.resize(size);
  b.resize(size);
  dft(a);
  if (equal) {
    b = a;
  } else {
    dft(b);
  }
  int inv = power(size, md - 2);
  for (int i = 0; i < size; ++i) {
    a[i] = mul(mul(a[i], b[i]), inv);
  }
  reverse(a.begin() + 1, a.end());
  dft(a);
  a.resize(need);
  while (!a.empty() && !a.back()) {
    a.pop_back();
  }
  return a;
}

vector<int> psqr(vector<int> a) {
  return pmul(a, a, true);
}
}

using ntt::padd;
using ntt::psub;
using ntt::pmul;
using ntt::psqr;

int main() {
#ifdef wxh010910
  freopen("input.txt", "r", stdin);
#endif
  int n;
  long long x;
  scanf("%d %lld", &n, &x);
  int value = x % md;
  vector<vector<int>> adj(n);
  for (int i = 0; i < n - 1; ++i) {
    int x, y;
    scanf("%d %d", &x, &y);
    --x;
    --y;
    adj[x].push_back(y);
    adj[y].push_back(x);
  }
  vector<int> parent(n, -1), size(n, 1), son(n, -1);

  function<void(int)> hld = [&](int x) {
    for (auto y : adj[x]) {
      if (y != parent[x]) {
        parent[y] = x;
        hld(y);
        size[x] += size[y];
        if (!~son[x] || size[y] > size[son[x]]) {
          son[x] = y;
        }
      }
    }
  };

  vector<vector<int>> answer(n);

  function<pair<vector<int>, vector<int>>(int, int, vector<vector<int>>&)> solve = [&](int l, int r, vector<vector<int>> &all) {
    if (l == r - 1) {
      return make_pair(all[l], all[l]);
    } else {
      int mid = l + r >> 1;
      pair<vector<int>, vector<int>> left = solve(l, mid, all), right = solve(mid, r, all);
      return make_pair(pmul(left.first, right.first), padd(left.second, pmul(left.first, right.second)));
    }
  };

  function<void(int)> dfs = [&](int x) {
    for (int y = x; ~y; y = son[y]) {
      for (auto z : adj[y]) {
        if (z != parent[y] && z != son[y]) {
          dfs(z);
        }
      }
    }
    vector<vector<int>> all;
    if (x) {
      all.push_back(vector<int> {0, 1});
    }
    for (int y = x; ~y; y = son[y]) {
      bool have = false;
      for (auto z : adj[y]) {
        if (z != parent[y] && z != son[y]) {
          all.push_back(answer[z]);
          have = true;
        }
      }
      if (!have) {
        all.push_back(vector<int> {0, 1});
      }
    }
    answer[x] = solve(0, all.size(), all).second;
  };

  hld(0);
  dfs(0);

  int binom = 1, result = 0;
  for (int i = 1; i <= n; ++i) {
    result = add(result, mul(answer[0][i], binom));
    binom = mul(binom, add(value, i));
    binom = mul(binom, power(i, md - 2));
  }
  printf("%d\n", result);

  return 0;
}