// =========== Template ========== //
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef long double ld;
#define fi first
#define se second

// =========== Book ============ //

int fastio() {
  ios_base::sync_with_stdio(0);
  cout << fixed << setprecision(10);
  cin.tie(0);
  return 0;
}
int __fastio = fastio();

// =========== Solution ============= //

int main() {
  int n, t;
  double p;
  cin >> n >> p >> t;
  vector<double> v(n + 1);
  v[0] = 1;

  for (int i = 0; i < t; ++i) {
    vector<double> w(n + 1);
    for (int j = 0; j <= n; ++j) {
      if (j < n) {
        w[j + 1] += v[j] * p;
      } else {
        w[j] += v[j] * p;
      }
      w[j] += v[j] * (1 - p);
    }
    v = w;
  }

  double sum = 0;
  for (int i = 0; i <= n; ++i) {
    sum += i * v[i];
  }
  cout << sum << "\n";
}

// ============== Notes =============== //
// common bugs
// - fastio
// - int overflow (especially intermediate expressionns)
// - array bounds (indices bigger than MAXN?)
// - special cases (n=1? graph not connected?)
// - re-initialize efficiently between test cases