#include <bits/stdc++.h>
using namespace std;

vector<int> ok(double a, const vector<int> &x, const vector<int> &b, int L) {
  int n = x.size();
  vector<double> dp(n);
  vector<int> par(n, -1);

  auto getQ = [&](int dist, int bt) {
    return bt * a - sqrt(abs(dist - L));    
  };

  for (int i = 0; i < n; i++) {
    double mx = getQ(x[i], b[i]);
    int pr = -1;

    for (int j = 0; j < i; j++) {
      double curQ = getQ(x[i] - x[j], b[i]) + dp[j];
      if (curQ > mx) {
        mx = curQ;
        pr = j;
      }
    }

    dp[i] = mx;
    par[i] = pr;
  }

  // cout << a << "\n";
  // for (int i = 0; i < n; i++) cout << dp[i] << " ";
  // cout << "\n";

  if (dp.back() > -1e-9)
    return par;
  else
    return {};
}

void solve() {
  int n, L;
  cin >> n >> L;
  vector<int> x(n), b(n);
  for (int i = 0; i < n; i++) {
    cin >> x[i] >> b[i];
  }

  double l = 0;
  double r = 1e7;
  vector<int> par;

  for (int i = 0; i < 100; i++) {
    double m = (l + r) / 2;
    vector<int> kk = ok(m, x, b, L);
    if (!kk.empty()) {
      par = kk;
      r = m;
    } else {
      l = m;
    }
  }  

  vector<int> path = {n - 1};
  while (par[path.back()] != -1) {
    path.push_back(par[path.back()]);
  }
  reverse(path.begin(), path.end());
  for (int x : path)
    cout << x + 1 << " ";
  cout << "\n";

#ifdef SERT
  cout << r << "\n";
#endif
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  solve();
}