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
  ll n, a, b;
  cin >> n >> a >> b;

  if ((n - 1) % b == 0) {
    cout << "Yes\n";
    return;
  }

  if (a == 1) {
    cout << "No\n";
    return;
  }

  ll t = 1;
  int d = 0;
  while (t <= n) {
    ll z = n - t;
    if (z % b == 0) {
      cout << "Yes\n";
      return;
    }

    ++d;
    t = t * a;
  }

  cout << "No\n";
}

int main(){
#ifdef LOCAL
	freopen("B_input.txt", "r", stdin);
	//freopen("B_output.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);
	cin.tie(0);

  int t;
  cin >> t;

  for (int i = 0; i < t; ++i) {
    solve();
  }

}