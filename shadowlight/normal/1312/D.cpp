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
const int N = 2e5 + 7;

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

int f[N], rf[N];

void init() {
	f[0] = 1, rf[0] = 1;
	for (int i = 1; i < N; i++) {
		f[i] = f[i - 1] * (ll) i % MOD;
		rf[i] = rev(f[i]);
	}
}

int C(int n, int k) {
	if (k > n || k < 0) {
		return 0;
	}
	return f[n] * (ll) rf[n - k] % MOD * rf[k] % MOD;
}

int main(){
#ifdef LOCAL
	freopen("D_input.txt", "r", stdin);
	//freopen("D_output.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n, m;
	cin >> n >> m;

	init();

	int val = C(m, n - 1);
	val = val * (ll) (n - 2) % MOD;
	val = val * (ll) power(2, n - 3) % MOD;
	cout << val << "\n";
}