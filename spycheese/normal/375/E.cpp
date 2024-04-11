#include <bits/stdc++.h>
#define sz(x) ((int)((x).size()))
#define all(x) (x).begin(), (x).end()
#define X first
#define Y second

using namespace std;
typedef long long ll;
const double DINF = numeric_limits<double>::infinity();
const double DNAN = numeric_limits<double>::quiet_NaN();
const double EPS = 1e-9;
template<typename T> bool isZero(T const& x) { return x == T(0); }
bool isZero(float x) { return abs(x) < EPS; }
bool isZero(double x) { return abs(x) < EPS; }
bool isZero(long double x) { return abs(x) < EPS; }
template<typename T> int sgn(T const& x) { if (isZero(x)) return 0; return x > 0 ? 1 : -1; }

// ===============================================================================================

pair<double, vector<double>> simplex(vector<double> w, vector<vector<double>> a) {
  int n = sz(w);
  int m = sz(a);
  vector<int> left(m), up(n);
  iota(all(up), 0);
  iota(all(left), n);
  w.push_back(0);
  a.push_back(move(w));
  auto pivot = [&](int x, int y) {
    swap(left[x], up[y]);
    double k = a[x][y];
    a[x][y] = 1;
    vector<int> v;
    for (int j = 0; j <= n; j++) {
      a[x][j] /= k;
      if (!isZero(a[x][j]))
        v.push_back(j);
    }
    for (int i = 0; i <= m; i++) {
      if (isZero(a[i][y]) || i == x) continue;
      k = a[i][y];
      a[i][y] = 0;
      for (int j : v)
        a[i][j] -= k * a[x][j];
    }
  };
  while (true) {
    int x = -1;
    for (int i = 0; i < m; i++) if (sgn(a[i][n]) < 0 && (x == -1 || a[i][n] < a[x][n])) x = i;
    if (x == -1) break;
    int y = -1;
    for (int j = 0; j < n; j++) if (sgn(a[x][j]) < 0 && (y == -1 || a[x][j] < a[x][y])) y = j;
    if (y == -1) return {DNAN, {}};
    pivot(x, y);
  }
  while (true) {
    int y = -1;
    for (int j = 0; j < n; j++) if (sgn(a[m][j]) > 0 && (y == -1 || a[m][j] > a[m][y])) y = j;
    if (y == -1) break;
    int x = -1;
    for (int i = 0; i < m; i++) if (sgn(a[i][y]) > 0 && (x == -1 || a[i][n] / a[i][y] < a[x][n] / a[x][y])) x = i;
    if (x == -1) return {DINF, {}};
    pivot(x, y);
  }
  vector<double> ans(n);
  for (int i = 0; i < m; i++)
    if (left[i] < n)
      ans[left[i]] = a[i][n];
  return {-a[m][n], move(ans)};
}

int main() {
  int n, x;
  cin >> n >> x;
  vector<int> bl(n);
  for (int& a : bl) cin >> a;
  vector<vector<ll>> d(n, vector<ll>(n, 1e18));
  for (int i = 0; i < n; ++i)
    d[i][i] = 0;
  for (int i = 1; i < n; ++i) {
    int a, b, c;
    cin >> a >> b >> c;
    --a;
    --b;
    d[a][b] = d[b][a] = c;
  }
  for (int k = 0; k < n; ++k)
    for (int i = 0; i < n; ++i)
      for (int j = 0; j < n; ++j)
        d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
  int cnt = 0;
  for (int y : bl) cnt += y;

  vector<double> w;
  for (int i = 0; i < n; ++i)
    w.push_back(bl[i]);
  vector<vector<double>> a;
  {
    vector<double> b;
    for (int i = 0; i < n; ++i)
      b.push_back(1);
    b.push_back(cnt);
    a.push_back(b);
    for (double &y : b) y = -y;
    a.push_back(b);
  }
  for (int i = 0; i < n; ++i) {
    vector<double> b;
    for (int j = 0; j < n; ++j)
      b.push_back(d[i][j] <= x ? -1 : 0);
    b.push_back(-1);
    a.push_back(b);
  }
  double ans = simplex(w, a).X;
  if (isnan(ans))
    cout << "-1\n";
  else
    cout << cnt - int(round(ans)) << "\n";
}