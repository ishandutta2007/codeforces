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
  string s, t;
  cin >> s >> t;

  int n = s.size();
  for (int i = 0; i < n; ++i) {
    for (int a = 1; a <= n - i; ++a) {
      int b = t.size() - a;
      if (b < 0 || (i + a - b - 1) < 0) continue;
      string tt = s.substr(i, a);
      string rr = s.substr((i + a) - b - 1, b);
      reverse(all(rr));
      if (tt + rr == t) {
        cout << "YES\n";
        return;
      }
    }
  }
  cout << "NO\n";
}

int main(){
#ifdef LOCAL
	freopen("B_input.txt", "r", stdin);
	//freopen("B_output.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);
	cin.tie(0);

  int q;
  cin >> q;
  for (int i = 0; i < q; ++i) {
    solve();
  }

}