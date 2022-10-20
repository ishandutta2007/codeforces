#include <bits/stdc++.h>
using namespace std;
using lint = long long;
using VI = vector<int>;
using VVI = vector<VI>;

vector<lint> memo(20, -1);
lint fac(int n) {
  if (memo[n] != -1) return memo[n];
  if (n == 0) return memo[0] = 1;
  return memo[n] = n * fac(n - 1);
}

lint f(VI a) {
  int s = accumulate(a.begin(), a.end(), 0);
  lint res = fac(s);
  for (int i = 0; i < 10; i++) {
    res /= fac(a[i]);
  }
  return res;
}

lint g(VI a) {
  int n = 1;
  for (int i = 0; i < 10; i++) {
    if (a[i] > 1) n *= a[i];
  }
  lint res = 0;
  for (int i = 0; i < n; i++) {
    VI b = a;
    int t = i;
    for (int j = 0; j < 10; j++) {
      if (a[j] <= 1) continue;
      b[j] = t % a[j] + 1;
      t /= a[j];
    }
    res += f(b);
  }
  return res;
}

int main() {
  cin.tie(0); ios::sync_with_stdio(false);
  string s; cin >> s;
  int n = s.size();
  VI a(10);
  for (int i = 0; i < n; i++) {
    a[s[i] - '0']++;
  }
  lint res = g(a);
  if (a[0] > 0) {
    a[0]--;
    res -= g(a);
    if (a[0] > 0) {
      a[0] = 0;
      res -= g(a);
    }
  }
  cout << res << '\n';
  return 0;
}