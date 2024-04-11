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
  string s;
  cin >> s;
  int n = s.size();

  int minr = 10;

  int N = (1 << n);
  for (int mask = 0; mask < N; ++mask) {
    bool bad = false;
    for (int i = 0; i < n; ++i) {
      if (s[i] == '?') continue;
      if ((bool) (mask & (1 << i)) != s[i] - '0') {
        bad = true;
        break;
      }
    }
    if (bad) continue;

    int a = 0, b = 0;
    for (int i = 0; i < n; ++i) {
      if (mask & (1 << i)) {
        if (i % 2 == 0) {
          ++a;
        } else {
          ++b;
        }
      }
      int rema = (n - i - 1) / 2;
      int remb = (n - i) / 2;
      if (a + rema < b || b + remb < a) {
        minr = min(minr, i + 1);
        break;
      }
    }
  }
  cout << minr << "\n";
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