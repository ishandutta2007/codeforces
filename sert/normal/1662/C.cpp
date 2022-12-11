#include <bits/stdc++.h>
using namespace std;
#ifdef SERT
#include "kek.h"
#endif

using ll = long long;
constexpr ll MD = 998244353;

struct Matrix {
  int n;
  int m;
  vector<vector<int>> a;
  explicit Matrix(int n = 0, int m = 0): n(n), m(m) {
    a.assign(n, vector<int>(m, 0));
  }
  Matrix operator*(const Matrix &x) const {
    assert(m == x.n);
    Matrix res(n, x.m);
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < x.m; j++) {
        ll sum = 0;
        for (int k = 0; k < m; k++) {
          sum += static_cast<ll>(a[i][k]) * x.a[k][j];
          if ((k & 7) == 0) sum %= MD;
        }
        res.a[i][j] = static_cast<int>(sum % MD);
      }
    }
    return res;
  }
  Matrix operator-(const Matrix &x) const {
    assert(n == x.n && m == x.m);
    Matrix res(n, m);
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        res.a[i][j] = a[i][j] - x.a[i][j];
        if (res.a[i][j] < 0) res.a[i][j] += MD;
      }
    }
    return res;
  }
  [[nodiscard]] ll getScore() const {
    ll score = 0;
    for (int i = 0; i < min(n, m); i++) {
      score += a[i][i];
    }
    return score % MD;
  }
  friend ostream& operator<<(ostream &fo, const Matrix &x) {
    for (const auto &row : x.a) {
      for (int val : row) cout << val << " ";
      cout << "\n";
    }
    return fo;
  }
};

Matrix pow(const Matrix &m, int deg) {
  if (deg == 1) return m;
  if (deg % 2) return m * pow(m, deg - 1);
  const auto q = pow(m, deg / 2);
  return q * q;
}

void solve() {
  int n, m, k;
  cin >> n >> m >> k;
  Matrix A(n, n), D(n, n);
  vector<int> deg(n, 0);
  while (m--) {
    int v1, v2;
    cin >> v1 >> v2;
    v1--;
    v2--;
    A.a[v1][v2] = A.a[v2][v1] = 1;
    //cout << v1 << " " << v2 << "\n";
    deg[v1]++;
    deg[v2]++;
    D.a[v1][v1]++;
    D.a[v2][v2]++;
  }

  auto S1 = A;
  auto S2 = A * A - D;

  //cout << S1 << "\n" << A * A << "\n" << D << "\n" << S2 << "\n";

  if (k == 1) { cout << "0\n"; return; }
  if (k == 2) { cout << S2.getScore() << "\n"; return; }

  Matrix S(n * 2, n);
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      S.a[i][j] = S2.a[i][j];
      S.a[i + n][j] = S1.a[i][j];
    }
  }

  Matrix L(n * 2, n * 2);
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      L.a[i][j] = A.a[i][j];
    }
    L.a[i + n][i] = 1;
    L.a[i][i + n] = static_cast<int>((MD - (deg[i] - 1)) % MD);
  }

  //cout << S << "\n";
  //cout << L << "\n";

  auto A1 = pow(L, k - 2);
  auto A2 = A1 * S;

  cout << A2.getScore() << "\n";

  //cout << S2 << "\n";
  //cout << A2 << "\n";
}

int main() {
  cout.precision(3);
  cout << fixed;
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
#ifdef SERT
  freopen("../a.in", "r", stdin);
  solve();
  solve();
  solve();
#else
  solve();
#endif
}