#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int MAXN = 3605;
const ll MOD = 998244353;
ll vdp[MAXN][MAXN], hdp[MAXN][MAXN], binom[MAXN][MAXN], fac[MAXN];
int rows[MAXN], cols[MAXN], h, w, n;

int main() {
    fac[0] = 1;
    for(ll i = 1; i < MAXN; i++)
        fac[i] = (fac[i - 1] * i) % MOD;
	for(int i = 0; i < MAXN; i++) {
		binom[i][0] = 1;
		for(int j = 1; j <= i; j++)
			binom[i][j] = (binom[i - 1][j - 1] + binom[i - 1][j]) % MOD;
	}
	cin >> h >> w >> n;
	for(int i = 0; i < n; i++) {
		int x, y;
		cin >> x >> y;
		rows[x] = cols[y] = 1;
		cin >> x >> y;
		rows[x] = cols[y] = 1;
	}
	hdp[0][0] = vdp[0][0] = 1;
	ll hfree = 0, vfree = 0;
	for(ll row = 1; row <= h; row++) {
		hfree += (rows[row] == 0);
		hdp[row][0] = 1;
		for(int k = 1; k < MAXN; k++) {
			hdp[row][k] = hdp[row - 1][k];
			if(row >= 2 && rows[row] == 0 && rows[row - 1] == 0)
				hdp[row][k] += hdp[row - 2][k - 1];
			if(hdp[row][k] >= MOD)
				hdp[row][k] -= MOD;
		}
	}
	for(ll col = 1; col <= w; col++) {
		vfree += (cols[col] == 0);
		vdp[col][0] = 1;
		for(int k = 1; k < MAXN; k++) {
			vdp[col][k] = vdp[col - 1][k];
			if(col >= 2 && cols[col] == 0 && cols[col - 1] == 0)
				vdp[col][k] += vdp[col - 2][k - 1];
			if(vdp[col][k] >= MOD)
				vdp[col][k] -= MOD;
		}
	}
	ll ans = 0;
	for(ll hdom = 0; hdom < MAXN; hdom++) {
		for(ll vdom = 0; vdom < MAXN; vdom++) {
			if(2*hdom + vdom > hfree)
				continue;
			if(2*vdom + hdom > vfree)
				continue;
			ll hoz = (hdp[h][hdom] * binom[hfree - 2*hdom][vdom]) % MOD;
			ll ver = (vdp[w][vdom] * binom[vfree - 2*vdom][hdom]) % MOD;
			ll tot = (hoz * ver) % MOD;
			tot = (tot * fac[hdom]) % MOD;
			tot = (tot * fac[vdom]) % MOD;
			ans = (ans + tot) % MOD;
		}
	}
	cout << ans << endl;
}