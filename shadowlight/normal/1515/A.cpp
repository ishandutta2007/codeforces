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
	int n, x;
	cin >> n >> x;

	vector <int> a(n);
	int sum = 0;

	for (int i = 0; i < n; ++i) {
		cin >> a[i];
		sum += a[i];
	}
	if (sum == x) {
		cout << "NO\n";
		return;
	}
	sort(all(a));
	bool w = false;
	int b = a[0], c = a.back();

	cout << "YES\n";
	if (n == 1) {
		cout << a[0] << "\n";
		return;
	}

	int now = 0;
	for (int i = 1; i < n - 1; ++i) {
		now += a[i];
		if (now == x) {
			w = true;
			if (b != a[i]) {
				cout << b << " ";
				now += b;
			} else {
				cout << c << " ";
				now += c;
			}
		}
		cout << a[i] << " ";
	}
	if (!w) {
		if (now + b == x) {
			cout << c << " " << b << " ";
		} else {
			cout << b << " " << c << " ";
		}
	} else {
		cout << sum - now << " ";
	}
	cout << "\n";
}

int main(){
#ifdef LOCAL
	freopen("A_input.txt", "r", stdin);
	//freopen("A_output.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int t;
	cin >> t;

	for (int i = 0; i < t; ++i) {
		solve();
	}

}