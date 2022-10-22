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
  int n, p;
  cin >> n >> p;

  vector <int> a(n);
  vector <pair <int, int>> b;
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
    b.pb({a[i], i});
  }
  sort(all(b));

  vector <bool> joined(n - 1, false);
  int cnt = n;

  ll res = 0;
  for (auto [x, pos] : b) {
    if (x >= p) break;
    int g = a[pos];
    int was = pos;
    while (pos < n - 1 && !joined[pos]) {
      g = __gcd(g, a[pos + 1]);
      if (g == x) {
        joined[pos] = 1;
        --cnt;
        res += x;
        ++pos;
      } else {
        break;
      }
    }
    pos = was;
    g = a[pos];
    while (pos > 0 && !joined[pos - 1]) {
      g = __gcd(g, a[pos - 1]);
      if (g == x) {
        joined[pos - 1] = 1;
        --cnt;
        res += x;
        --pos;
      } else {
        break;
      }
    }
  }

  res += p * (ll) (cnt - 1);
  cout << res << "\n";
}

int main(){
#ifdef LOCAL
	freopen("D_input.txt", "r", stdin);
	//freopen("D_output.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);
	cin.tie(0);

  int n;
  cin >> n;
  for (int i = 0; i < n; ++i) {
    solve();
  }

}