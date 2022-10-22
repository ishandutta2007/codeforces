#include <bits/stdc++.h>
#define ll long long
#define db long double
#define x first
#define y second
#define mp make_pair
#define pb push_back
#define all(a) a.begin(), a.end()

using namespace std;

const int mod = 1000000007;

void add(int& a, int b) {
  a += b;
  if (a >= mod) a -= mod;
  if (a < 0) a += mod;
}

int mult(int a, int b) {
  return a * (ll)b % mod;
}

int bp(int a, int b) {
  int res = 1;
  while (b > 0) {
    if (b & 1) res = mult(res, a);
    a = mult(a, a);
    b >>= 1;
  }
  return res;
}

void solve() {
  string a, b;
  cin >> a >> b;
  int n = a.size();
  int m = b.size();

  for (int len = min(n, m); len >= 0; --len) {
    for (int i = 0; i < n; ++i) {
      if (i + len > n) break;
      for (int j = 0; j < m; ++j) {
        if (j + len > m) break;
        if (a.substr(i, len) != b.substr(j, len)) continue;
        cout << (n - len) + (m - len) << "\n";
        return;
      }
    }
  }
}

int main(){
#ifdef LOCAL
	freopen("C_input.txt", "r", stdin);
	//freopen("C_output.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);
	cin.tie(0);

  int t;
  cin >> t;
  for (int i = 0; i < t; ++i) {
    solve();
  }

}