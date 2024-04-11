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
  int n, k;
  cin >> n >> k;

  vector <int> res(k - 3, 1);
  n -= (k - 3);

  if (n % 2) {
    res.pb(n / 2);
    res.pb(n / 2);
    res.pb(1);
  } else if (n % 4 == 0) {
    res.pb(n / 4);
    res.pb(n / 4);
    res.pb(n / 2);
  } else {
    res.pb(n / 2 - 1);
    res.pb(n / 2 - 1);
    res.pb(2);
  }
  for (int x : res) {
    cout << x << " ";
  }
  cout << "\n";
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