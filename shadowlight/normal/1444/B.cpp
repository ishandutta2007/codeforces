#include <bits/stdc++.h>
#define ll long long
#define db long double
#define x first
#define y second
#define mp make_pair
#define pb push_back
#define all(a) a.begin(), a.end()

using namespace std;

const int MOD = 998244353;
const int N = 2e6 + 7;

int f[N];

void init() {
	f[0] = 1;
	for (int i = 1; i < N; ++i) {
		f[i] = i * (ll) f[i - 1] % MOD;
	}
}

int power(int a, int k) {
	if (!k) {
		return 1;
	}
	int b = power(a, k / 2);
	b = b * (ll) b % MOD;
	if (k % 2) {
		return a * (ll) b % MOD;
	} else {
		return b;
	}
}

int rev(int a) {
	return power(a, MOD - 2);
}

int C(int n, int k) {
	return f[n] * (ll) rev(f[k]) % MOD * (ll) rev(f[n - k]) % MOD;
}

int main(){
#ifdef LOCAL
	freopen("B_input.txt", "r", stdin);
	//freopen("B_output.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	init();

	int n;
	cin >> n;
	vector <int> a(2 * n);
	for (int i = 0; i < 2 * n; ++i) {
		cin >> a[i];
	}
	sort(all(a));
	ll sum = 0;
	for (int i = 0; i < 2 * n; ++i) {
		sum += a[i] * (i < n ? -1 : 1);
	}
	sum %= MOD;
	sum += MOD;
	sum %= MOD;

	ll res = 0;

	for (int a = 0; a <= n; ++a) {
		ll val = C(n, a) * (ll) C(n, n - a) % MOD;
		res += val;
		if (res >= MOD) {
			res -= MOD;
		}
	}

	cout << res * (ll) sum % MOD;

}