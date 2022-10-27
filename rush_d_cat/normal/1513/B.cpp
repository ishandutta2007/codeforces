#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N = 200000 + 10;
int fac[N];
const int MOD = 1e9 + 7;
int main() {
	fac[0] = 1;
	for (int i = 1; i < N; i ++)
		fac[i] = 1LL * fac[i-1] * i % MOD;

	ios::sync_with_stdio(false);
	cout.tie(NULL);
	int t;
	cin >> t;
	while (t --) {
		int n;
		cin >> n;
		vector<int> a(n);
		for (int i = 0; i < n; i ++) cin >> a[i];

		int c[32] = {0};
		for (auto x: a) {
			for (int i = 0; i < 30; i ++) if (x>>i & 1) c[i] ++;
		}

		int valid = 0;
		for (auto x: a) {
			bool ok = true;
			for (int i = 0; i < 30; i ++) {
				if (c[i] != n) {
					if (x >> i & 1) ok = false;
				}
			}
			if (ok) valid ++;
		}
		
		LL res = 1LL * valid * (valid - 1) % MOD * fac[n-2] % MOD;
		cout << res << endl;
	} 
}
/*
0011000 
1111111
*/