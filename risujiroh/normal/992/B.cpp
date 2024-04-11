#include <bits/stdc++.h>
using namespace std;
using lint = long long;
using VI = vector<int>;
using VVI = vector<VI>;
map<lint, int> factor(lint n) {
  assert(n > 0);
  map<lint, int> res;  
  lint i = 2;
  while (i * i <= n) if (n % i == 0) res[i]++, n /= i; else i++;
  if (n != 1) res[n]++;
  return res;
}
lint power(lint x, lint n, lint mod = numeric_limits<lint>::max()) {
  assert(n >= 0);
  if (n == 0) return 1;
  return power(x * x % mod, n / 2, mod) * (n % 2 ? x : 1) % mod;
}

int main() {
  cin.tie(0); ios::sync_with_stdio(false);
  lint l, r, x, y; cin >> l >> r >> x >> y;
  auto fx = factor(x), fy = factor(y);
  map<lint, int> fxy;
  fxy = fx;
  for (auto&& i : fy) {
    fxy[i.first] += i.second;
  }
  int d = 1;
  for (auto&& i : fxy) {
    d *= i.second + 1;
  }
  vector<lint> div(d);
  for (int i = 0; i < d; i++) {
    lint t = 1;
    int ic = i;
    for (auto&& j : fxy) {
      t *= power(j.first, ic % (j.second + 1));
      ic /= j.second + 1;
    }
    div[i] = t;
  }
  int res = 0;
  auto lcm = [](auto a, auto b) { return a / __gcd(a, b) * b; };
  for (auto&& a : div) {
    lint b = x * y / a;
    res += l <= a and a <= r and l <= b and b <= r and __gcd(a, b) == x and lcm(a, b) == y;
  }
  cout << res << '\n';
  return 0;
}