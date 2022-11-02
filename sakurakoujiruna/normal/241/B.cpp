#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const ll mod = 1e9L + 7;
const ll inv2 = (mod + 1) / 2;

int bit(int n, int i) {
	return (n >> i) & 1;
}

const int N = 5e4L + 11;
int a[N];
int nxt[N * 31][2];
int cnt[N * 31];
unsigned short int c[N * 31][31][2];
int par[N * 31];

pair <ll, ll> solve(int n, int lim) {
	ll r1 = 0, r2 = 0;
	for(int i = 1; i <= n; i ++) {
		int p = 1, pre = 0;
		for(int j = 30; j >= 0; j --) {
			if(!bit(lim, j)) {
				int now = pre | (1 << j);
				int q = nxt[p][bit(a[i], j) ^ 1];
				r1 += cnt[q];
				r2 += ll(now) * cnt[q];
				for(int k = 0; k < j; k ++)
					if(bit(a[i], k))
						r2 += (1LL << k) * c[q][k][0];
					else
						r2 += (1LL << k) * c[q][k][1];
				r2 %= mod;
			}
			p = nxt[p][bit(lim ^ a[i], j)];
			pre |= bit(lim, j) << j;
		}
	}
	return {r1, r2};
}

int main() {
	ios :: sync_with_stdio(0);
	int n; ll m; cin >> n >> m; m *= 2;
	int tc = 1;
	for(int i = 1; i <= n; i ++) {
		int x; cin >> x; a[i] = x;
		int p = 1;
		for(int j = 30; j >= 0; j --) {
			if(!nxt[p][bit(x, j)]) {
				nxt[p][bit(x, j)] = ++ tc;
				par[tc] = p;
			}
			p = nxt[p][bit(x, j)];
		}
		cnt[p] ++;
		for(int j = 0; j <= 30; j ++) {
			p = par[p];
			cnt[p] = cnt[nxt[p][0]] + cnt[nxt[p][1]];
			for(int k = 0; k <= 30; k ++) {
				c[p][k][0] = c[nxt[p][0]][k][0] + c[nxt[p][1]][k][0];
				c[p][k][1] = c[nxt[p][0]][k][1] + c[nxt[p][1]][k][1];
			}
			c[p][j][0] += cnt[nxt[p][0]];
			c[p][j][1] += cnt[nxt[p][1]];
		}
	}
	int l = -1, r = (1 << 30);
	while(l + 1 < r) {
		int im = (l + r) >> 1;
		auto p = solve(n, im);
		if(p.first >= m)
			l = im;
		else
			r = im;
	}
	auto p = solve(n, l);
	ll ans = p.second - ll(p.first - m) * (l + 1);
	ans = ans % mod * inv2 % mod;
	cout << (ans + mod) % mod << '\n';
}