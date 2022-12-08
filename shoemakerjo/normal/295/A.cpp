#include <bits/stdc++.h>

#define maxn 200000
#define ll long long

using namespace std;

int BITu[maxn];
ll BIT[maxn];

void updateu(int u, int m, int diff) {
	while (u <= m) {
		BITu[u]+=diff;
		u += u & (-u);
	}
}

int queryu(int u) {
	int ans = 0;
	while (u > 0) {
		ans += BITu[u];
		u -= u&(-u);
	}
	return ans;
}

void update(int u, int m, ll diff) {
	while (u <= m) {
		BIT[u]+=diff;
		u += u & (-u);
	}
}

ll query(int u) {
	ll ans = 0;
	while (u > 0) {
		ans += BIT[u];
		u -= u&(-u);
	}
	return ans;
}

int main() {
	int n, m, k;
	cin >> n >> m >> k;
	ll cur;
	for (int i = 0; i <= n; i++) {
		BIT[i] = 0;
	}
	for (int i = 1; i <= n; i++) {
		cin >> cur;
		update(i, n, cur);
		update(i+1, n, 0-cur);

	}
	ll increases[m+1];
	int bounds[m+1][2];
	for (int i = 1; i <= m; i++) {
		cin >> bounds[i][0] >> bounds[i][1] >> increases[i];
	}
	for (int i = 0; i <= m; i++) {
		BITu[i] = 0;
	}
	int x, y;
	for (int i = 0; i < k; i++) {
		cin >> x >> y;
		// cout << "x: " << x << "   y: " << y << endl;
		updateu(x, m, 1);
		updateu(y+1, m, -1);
		// cout << "qx:   " << queryu(x) << "  qy:  " << 
		// queryu(y) << endl;
	}
	for (int i = 1; i <= m; i++) {
		// cout << "num:   " << i << " " << queryu(i) << endl;
		update(bounds[i][0], n, queryu(i)*increases[i]);
		update(bounds[i][1]+1, n, 0-queryu(i)*increases[i]);
	}
	for (int i = 1; i <= n; i++) {
		if (i > 1) cout << " ";
		cout << query(i);
	}
	cout << endl;
	cin >> n;
}