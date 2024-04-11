#include <bits/stdc++.h>
using namespace std;
int gcd(int x, int y) {
	return y == 0 ? x : gcd(y, x % y);
}
typedef long long ll;
const ll mod = 998244353;
int main() {
	ios::sync_with_stdio(false);
	cout.tie(0);
	/*
	for (int i = 1; i <= 16; i ++) {
		vector<int> p(i);
		iota(p.begin(), p.end(), 1);
		int ans = 0;
		do {
			int s = 0;
			for (int j = 0; j < i; j ++) s = gcd(s, (j+1) * p[j]);
			if (s > 1) ans ++;
		} while (next_permutation(p.begin(), p.end()));
		cout << i << " " << ans << "\n";
	}
	*/
	vector<ll> fac(1000 + 1);
	fac[0] = 1;
	for (int i = 1; i <= 1000; i ++)
		fac[i] = fac[i-1] * i % mod; 

	int t;
	cin >> t;
	while (t --) {
		int n;
		cin >> n;
		if (n % 2 == 1) cout << 0 << "\n";
		else cout << fac[n/2] * fac[n/2] % mod << "\n";
	}
}

/*
1 2 3 4 5 6

*/