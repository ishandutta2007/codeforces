#include <bits/stdc++.h>

using namespace std;

const int md = 998244353;

inline void add(int &x, int y) {
  x += y;
  if (x >= md) {
    x -= md;
  }
}

inline int mul(int x, int y) {
  return (int) ((long long) x * y % md);
}

inline int inv(int a) {
  if (a < 0) {
    a += md;
  }
  int b = md, u = 0, v = 1;
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
  return u;
}

int main() {
#ifdef wxh010910
  freopen("input.txt", "r", stdin);
#endif
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int n, m;
  cin >> n >> m;
  vector<int> a(n);
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }
  vector<int> w(n);
  int like = 0, dislike = 0, sum = 0;
  for (int i = 0; i < n; ++i) {
    cin >> w[i];
    if (a[i]) {
      like += w[i];
    } else {
      dislike += w[i];
    }
    sum += w[i];
  }
  vector<vector<int>> f(m + 1, vector<int>(m + 1));
  vector<vector<int>> g(m + 1, vector<int>(m + 1));
  for (int i = 0; i <= m; ++i) {
    f[i][m - i] = f[m - i][i] = g[i][m - i] = g[m - i][i] = 1;
  }
  for (int s = m - 1; ~s; --s) {
    for (int i = 0; i <= s; ++i) {
      int j = s - i;
      if (j > dislike) {
        continue;
      }
      int p = inv(sum + i - j);
      add(f[i][j], mul(f[i][j + 1], mul(dislike - j, p)));
      add(f[i][j], mul(f[i + 1][j], mul(like + i + 1, p)));
      if (j < dislike) {
        add(g[i][j], mul(g[i][j + 1], mul(dislike - j - 1, p)));
        add(g[i][j], mul(g[i + 1][j], mul(like + i, p)));
      }
    }
  }
  for (int i = 0; i < n; ++i) {
    if (a[i]) {
      cout << mul(w[i], f[0][0]) << "\n";
    } else {
      cout << mul(w[i], g[0][0]) << "\n";
    }
  }
  return 0;
}