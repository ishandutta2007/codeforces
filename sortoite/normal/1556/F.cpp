#include <bits/stdc++.h>
using namespace std;
const int mod = 1e9 + 7;

int inverse(int x) {
	if(x < 2) return x;
  return 1ll * inverse(mod % x) * (mod - mod / x) % mod;
}

const int NN = 15;
const int MM = 1 << NN;

int a[NN], pw[NN], rnd[NN][NN], dyna[MM], win[NN][MM];

inline int sum(int &u, int v) {
	(u = u + v) >= mod && (u = u - mod);
}

int solve() {
	for(int i = 0; i < NN; i ++) pw[i] = 1 << i;
	int n, m; cin >> n; m = 1 << n;
	for(int i = 0; i < n; i ++) {
		scanf("%d", a + i);
	}
	for(int i = 0; i < n; i ++) {
		for(int j = 0; j < n; j ++) {
			rnd[i][j] = 1ll * a[i] * inverse(a[i] + a[j]) % mod;
		}
	}
	for(int i = 0; i < n; i ++) {
		for(int j = 0; j < m; j ++) {
			win[i][j] = 1;
			for(int t = 0; t < n; t ++) if(j & pw[t]) {
				win[i][j] = 1ll * win[i][j] * rnd[i][t] % mod;
			}
		}
	}
	int ans = 0;
	for(int i = 0; i < n; i ++) {
		memset(dyna, 0, sizeof dyna);
		dyna[0] = 1;
		for(int j = 1; j < m; j ++) if(! (j & pw[i])) {
			dyna[j] = 1;
			for(int k = j; ; k = ((k - 1) & j)) if(k != j) {
				int x = k | pw[i], y = dyna[k];
				for(int i = 0; i < n; i ++) 
					if((k ^ j) & pw[i]) y = 1ll * y * win[i][x] % mod;
				if(y) sum(dyna[j], mod - y);
				if(k == 0) break;
			}
		}
		sum(ans, dyna[(m - 1) ^ pw[i]]);
	}
	return ans;
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.in", "r", stdin);
#endif
	cout << solve() << endl;
	return 0;
}