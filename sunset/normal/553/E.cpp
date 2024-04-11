#include <bits/stdc++.h>

using namespace std;

using ld = double;

namespace fft {
const ld PI = acos(-1);

struct num {
  ld x, y;
  
  num(ld x = 0, ld y = 0) : x(x), y(y) {
  }

  num operator+(const num& o) const {
    return num(x + o.x, y + o.y);
  }

  num operator-(const num& o) const {
    return num(x - o.x, y - o.y);
  }

  num operator*(const num& o) const {
    return num(x * o.x - y * o.y, x * o.y + y * o.x);
  }
};

num conj(num a) {
  return num(a.x, -a.y);
}

vector<num> fa, fb, roots = {num(0, 0), num(1, 0)};
vector<int> rev = {0, 1};
int base = 1;

void ensure_base(int nbase) {
  if (nbase <= base) {
    return;
  }
  rev.resize(1 << nbase);
  for (int i = 0; i < (1 << nbase); ++i) {
    rev[i] = (rev[i >> 1] >> 1) | ((i & 1) << (nbase - 1));
  }
  roots.resize(1 << nbase);
  while (base < nbase) {
    ld angle = 2 * PI / (1 << (base + 1));
    for (int i = 1 << (base - 1); i < (1 << base); ++i) {
      roots[i << 1] = roots[i];
      ld ang = angle * ((i << 1) + 1 - (1 << base));
      roots[i << 1 | 1] = num(cos(ang), sin(ang));
    }
    ++base;
  }
}

void dft(vector<num>& a, int n) {
  int zeros = __builtin_ctz(n);
  ensure_base(zeros);
  int shift = base - zeros;
  for (int i = 0; i < n; ++i) {
    if (i < (rev[i] >> shift)) {
      swap(a[i], a[rev[i] >> shift]);
    }
  }
  for (int i = 1; i < n; i <<= 1) {
    for (int j = 0; j < n; j += i << 1) {
      for (int k = 0; k < i; ++k) {
        num x = a[j + k], y = a[j + k + i] * roots[i + k];
        a[j + k] = x + y;
        a[j + k + i] = x - y;
      }
    }
  }
}

vector<ld> multiply(const vector<ld>& a, const vector<ld>& b) {
  int need = a.size() + b.size() - 1, nbase = 0;
  while (1 << nbase < need) {
    ++nbase;
  }
  ensure_base(nbase);
  bool equal = a == b;
  int sz = 1 << nbase;
  if (sz > (int) fa.size()) {
    fa.resize(sz);
  }
  if (sz > (int) fb.size()) {
    fb.resize(sz);
  }
  for (int i = 0; i < (int) a.size(); i++) {
    fa[i] = num(a[i], 0);
  }
  for (int i = a.size(); i < sz; ++i) {
    fa[i] = num(0, 0);
  }
  dft(fa, sz);
  if (equal) {
    for (int i = 0; i < sz; ++i) {
      fb[i] = fa[i];
    }
  } else {
    for (int i = 0; i < (int) b.size(); ++i) {
      fb[i] = num(b[i], 0);
    }
    for (int i = (int) b.size(); i < sz; ++i) {
      fb[i] = num(0, 0);
    }
    dft(fb, sz);
  }
  num ratio(1.0 / sz, 0);
  for (int i = 0; i < sz; ++i) {
    fa[i] = fa[i] * fb[i] * ratio;
  }
  reverse(fa.begin() + 1, fa.begin() + sz);
  dft(fa, sz);
  vector<ld> c(need);
  for (int i = 0; i < need; ++i) {
    c[i] = fa[i].x;
  }
  return c;
}
}

using fft::multiply;

int main() {
#ifdef LOCAL
  freopen("input.txt", "r", stdin);
#endif
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, m, t, c;
  cin >> n >> m >> t >> c;
  vector<int> from(m), to(m), cost(m);
  vector<vector<ld>> p(m, vector<ld>(t));
  vector<vector<ld>> sum(m, vector<ld>(t + 1));
  for (int i = 0; i < m; ++i) {
    cin >> from[i] >> to[i] >> cost[i];
    --from[i]; --to[i];
    for (int j = 0; j < t; ++j) {
      int x;
      cin >> x;
      p[i][j] = x / 1e5;
    }
    for (int j = t - 1; ~j; --j) {
      sum[i][j] = p[i][j] + sum[i][j + 1];
    }
  }
  vector<ld> dist(n, 1e9);
  dist[n - 1] = c;
  for (int tt = 0; tt < n; ++tt) {
    for (int i = 0; i < m; ++i) {
      dist[from[i]] = min(dist[from[i]], dist[to[i]] + cost[i]);
    }
  }
  vector<vector<ld>> dp(n, vector<ld>(t + 1));
  vector<vector<ld>> ad(m, vector<ld>(t + 1));
  function<void(int, int)> solve = [&](int l, int r) {
    if (l == r) {
      for (int i = 0; i < n - 1; ++i) {
        dp[i][l] = 1e9;
      }
      for (int i = 0; i < m; ++i) {
        dp[from[i]][l] = min(dp[from[i]][l], ad[i][l] + cost[i] + dist[to[i]] * sum[i][t - l]);
      }
    } else {
      int mid = (l + r) >> 1;
      solve(mid + 1, r);
      for (int i = 0; i < m; ++i) {
        vector<ld> foo(r - mid);
        for (int j = 0; j < r - mid; ++j) {
          foo[j] = dp[to[i]][j + mid + 1];
        }
        vector<ld> bar(r - l);
        for (int j = 0; j < r - l; ++j) {
          bar[j] = p[i][r - l - j - 1];
        }
        vector<ld> baz = multiply(foo, bar);
        for (int j = 0; j <= mid - l; ++j) {
          ad[i][j + l] += baz[j + r - mid - 1];
        }
      }
      solve(l, mid);
    }
  };
  solve(0, t);
  cout << fixed << setprecision(9) << dp[0][0] << "\n";
  return 0;
}