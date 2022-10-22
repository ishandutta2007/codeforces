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
  int n;
  cin >> n;

  vector <int> a(n), b(n);
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }
  for (int i = 0; i < n; ++i) {
    cin >> b[i];
  }
  sort(all(a));
  reverse(all(a));
  sort(all(b));
  reverse(all(b));

  int now = n - n / 4;
  ll suma = 0, sumb = 0;
  for (int i = 0; i < now; ++i) {
    suma += a[i], sumb += b[i];
  }
  int nowa = now, nowb = now;

  int m = n;
  while (suma < sumb) {
    ++m;
    int nxt = m - m / 4;
    while (nowb < n && nowb < nxt) {
      sumb += b[nowb++];
    }
    suma += 100;
    while (nowa > 0 && nowa + (m - n) > nxt) {
      suma -= a[--nowa];
    }
  }
  cout << m - n << "\n";
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