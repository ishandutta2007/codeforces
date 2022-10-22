#include <bits/stdc++.h>

using namespace std;

typedef int ll;
typedef long double ld;
typedef pair<ll, ll> pll;

#define all(x)                      (x).begin(),(x).end()
#define X                           first
#define Y                           second
#define sep                         ' '
#define endl                        '\n'
#define debug(x)                    cerr << #x << ": " <<  x << endl;

ll poww(ll a, ll b, ll md) {
	return (!b ? 1 : (b & 1 ? a * poww(a * a % md, b / 2, md) % md : poww(a * a % md, b / 2, md) % md));
}

const ll MAXN = 2e5 + 10;
const ll INF = 1e9 + 10;
const ll MOD = 1e9 + 7; // 998244353; // 1e9 + 9;

pll sg[9][2 * MAXN];
int n, m;

pll mmin(pll x, pll y) {
	int tmp[4] = {x.X, x.Y, y.X, y.Y};
	sort(tmp, tmp + 4);
	return {tmp[0], tmp[1]};
}

void build(int ind) { 
	for (int i = n - 1; i > 0; --i) sg[ind][i] = mmin(sg[ind][i << 1], sg[ind][i<<1|1]);
}

void modify(int ind, int p, int value) {
	for (sg[ind][p += n] = {value, INF}; p > 1; p >>= 1) sg[ind][p >> 1] = mmin(sg[ind][p], sg[ind][p ^ 1]);
}

pll rmq(int ind, int l, int r) {
	pll res = {INF, INF};
	for (l += n, r += n; l < r; l >>= 1, r >>= 1) {
		if (l & 1) res = mmin(res, sg[ind][l++]);
		if (r & 1) res = mmin(res, sg[ind][--r]);
	}

	return res;
}

int main() {
	for (int ind = 0; ind < 9; ind++) for (int i = 0; i < 2 * MAXN; i++) sg[ind][i] = {INF, INF};
	scanf("%d %d", &n, &m);
	for (int i = 0; i < n; i++) {
		int x, j = 0, tx;
		scanf("%d", &x);
		tx = x;
		while (tx > 0 || j < 9) {
			if (tx % 10) sg[j][n + i] = {x, INF};		
			else sg[j][n + i] = {INF, INF};
			j++;
			tx /= 10;
		}
	}

	for (int i = 0; i < 9; i++) build(i);
	while (m--) {
		int cmd, l, r;
		scanf("%d %d %d", &cmd, &l, &r);
		if (cmd == 1) {
			int j = 0, tr = r;
			l--;
			while (tr > 0 || j < 9) {
				if (tr % 10) modify(j, l, r);
				else modify(j, l, INF);
				j++;
				tr /= 10;
			} 
		} else {
			l--; r--;
			ll ans = -1;
			for (int j = 0; j < 9; j++) {
				pll tans = rmq(j, l, r + 1);
				if (tans.X == INF || tans.Y == INF) continue;
				if (ans == -1) ans = tans.X + tans.Y;
				else ans = min(ans, tans.X + tans.Y);
			}


			printf("%d \n", ans);
		}
	}
	return 0;
}