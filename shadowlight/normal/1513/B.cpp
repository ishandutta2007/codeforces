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

int rev(int a) {
	return bp(a, mod - 2);
}

const int N = 2e5 + 7;

int f[N], rf[N];

int C(int n, int k) {
	if (k < 0 || k > n) {
		return 0;
	}
	return f[n] * (ll) rf[k] % mod * rf[n - k] % mod;
}

void init() {
	f[0] = 1;
	rf[0] = 1;
	for (int i = 1; i < N; ++i) {
		f[i] = f[i - 1] * (ll) i % mod;
		rf[i] = rev(f[i]);
	}
}

void solve() {
	int n;
	cin >> n;
	vector <int> a(n);
	int and_sum = -1;
	map <int, int> cnt;
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
		if (and_sum == -1) {
			and_sum = a[i];
		}
		and_sum &= a[i];
		++cnt[a[i]];
	}
	int xx = cnt[and_sum];
	if (xx < 2) {
		cout << "0\n";
		return;
	}
	int res = xx * (ll) (xx - 1) % mod;
	res = mult(res, f[n - 2]);
	cout << res << "\n";
}

int main(){
#ifdef LOCAL
	freopen("B_input.txt", "r", stdin);
	//freopen("B_output.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	init();

	int t;
	cin >> t;
	for (int i = 0; i < t; ++i) {
		solve();
	}

}