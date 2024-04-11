#include <bits/stdc++.h>
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()

using namespace std;
typedef long double ld;

vector<int> papply(vector<int> const& a, vector<int> const& b) {
  vector<int> c(sz(a));
  for (int i = 0; i < sz(a); ++i)
    c[i] = b[a[i]];
  return c;
}

int solve(vector<int> p, vector<int> const& p2) {
  for (int i = 0; i <= sz(p) + 2; ++i) {
    if (is_sorted(all(p))) return i;
    p = papply(p2, p);
  }
  return 1e9;
}

int main() {
  int n;
  cin >> n;
  n *= 2;
  vector<int> p(n);
  for (int i = 0; i < n; ++i) { cin >> p[i]; --p[i]; }
  vector<int> p1(n), p2(n);
  for (int i = 0; i < n / 2; ++i) {
    p1[i] = i + n / 2;
    p1[i + n / 2] = i;
    p2[i * 2] = i * 2 + 1;
    p2[i * 2 + 1] = i * 2;
  }

  int ans = min({
    solve(p, papply(p1, p2)) * 2,
    solve(p, papply(p2, p1)) * 2,
    solve(papply(p1, p), papply(p1, p2)) * 2 + 1,
    solve(papply(p2, p), papply(p2, p1)) * 2 + 1,
  });
  if (ans > 1e8) ans = -1;
  cout << ans << "\n";
}