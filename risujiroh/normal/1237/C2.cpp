#include <bits/stdc++.h>
using namespace std;
using lint = long long;
template<class T = int> using V = vector<T>;
template<class T = int> using VV = V< V<T> >;

lint sq(lint x) {
  return x * x;
}

using namespace chrono;
auto start_t = steady_clock::now();
mt19937 mt(start_t.time_since_epoch().count());
template<class Z> Z rng(Z a, Z b) { return uniform_int_distribution<Z>(a, b - 1)(mt); }
double rng(double a, double b) { return uniform_real_distribution<double>(a, b)(mt); }
void start() { start_t = steady_clock::now(); }
int split(const string& s = "") {
  int res = duration_cast<milliseconds>(steady_clock::now() - start_t).count();
  if (!s.empty()) cerr << s << ": " << res << " ms\n";
  return res;
}

int main() {
  cin.tie(nullptr); ios::sync_with_stdio(false);
  int n; cin >> n;
  V<> x(n), y(n), z(n); for (int i = 0; i < n; ++i) cin >> x[i] >> y[i] >> z[i];
  V<> idx(n);
  iota(begin(idx), end(idx), 0);
  long double cx = rng(1, 2), cy = rng(1, 2), cz = rng(1, 2);
  long double cs = cx * cx + cy * cy + cz * cz;
  cx /= cs, cy /= cs, cz /= cs;
  sort(begin(idx), end(idx), [&](int i, int j) {
    return cx * (x[i] - x[j]) + cy * (y[i] - y[j]) + cz * (z[i] - z[j]) < 0;
  });
  set<int> se;
  for (int i = 0; i < n; ++i) se.insert(i);
  while (not se.empty()) {
    int i = idx[*begin(se)];
    se.erase(begin(se));
    int p = -1;
    long double mn = 1e18;
    for (auto it = begin(se); it != end(se); ++it) {
      int j = idx[*it];
      long double crr = sq(x[j] - x[i]) + sq(y[j] - y[i]) + sq(z[j] - z[i]);
      crr = sqrt(crr);
      if (crr < mn) {
        mn = crr;
        p = *it;
      }
      if (cx * (x[j] - x[i]) + cy * (y[j] - y[i]) + cz * (z[j] - z[i]) > mn) break;
    }
    se.erase(p);
    cout << i + 1 << ' ' << idx[p] + 1 << '\n';
  }
}