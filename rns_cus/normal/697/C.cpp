#include <bits/stdc++.h>
using namespace std;

typedef long long LL;

LL ex[101];

int deep(LL x) {
	for (int i = 1; i <= 61; i ++) {
		if (x >= ex[i-1] && x < ex[i]) return i;
	}
}

LL lca(LL a, LL b) {
	int da = deep(a), db = deep(b);
	for (int i = da; i > db; i --) a = a / 2;
	for (int i = db; i > da; i --) b = b / 2;
	while (a != b) a /= 2, b /= 2;
	return a;
}

int q, type;
LL a, b, c, w;
map <LL, LL> mp[2];

int main() {
//	freopen("c.in", "r", stdin);
	for (int i = 0; i <= 62; i ++) ex[i] = 1ll << i;
	cin >> q;
	while (q --) {
		cin >> type;
		if (type == 1) {
			cin >> a >> b >> w;
			c = lca(a, b);
			while (a != c) {
				if (a & 1) a /= 2, mp[1][a] += w;
				else a /= 2, mp[0][a] += w;
			}
			while (b != c) {
				if (b & 1) b /= 2, mp[1][b] += w;
				else b /= 2, mp[0][b] += w;
			}
		}
		else {
			cin >> a >> b;
			c = lca(a, b);
			LL ans = 0;
			while (a != c) {
				if (a & 1) a /= 2, ans += mp[1][a];
				else a /= 2, ans += mp[0][a];
			}
			while (b != c) {
				if (b & 1) b /= 2, ans += mp[1][b];
				else b /= 2, ans += mp[0][b];
			}
			cout << ans << endl;
		}
	}
	return 0;
}