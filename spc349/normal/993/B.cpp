#include <bits/stdc++.h>
#define fi first
#define se second
#define mp make_pair
using namespace std;

typedef pair <int, int> pii;

pii a[20], b[20];

int GetNum(pii a, pii b) {
	if (a.fi > a.se) swap(a.fi, a.se);
	if (b.fi > b.se) swap(b.fi, b.se);
	if (a == b) return -1;
	if (a.fi == b.fi || a.fi == b.se) return a.fi;
	if (a.se == b.fi || a.se == b.se) return a.se;
	return -1;
}

int main() {
	int n, m; cin >> n >> m;
	for (int i = 0; i < n; i++) cin >> a[i].fi >> a[i].se;
	for (int i = 0; i < m; i++) cin >> b[i].fi >> b[i].se;
	int ans = -1;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			int tmp = GetNum(a[i], b[j]);
			if (tmp == -1) continue;
			if (ans == -1) ans = tmp;
			else if (ans != tmp) ans = -2;
		}
	}
	if (ans > 0) {
		cout << ans << endl;
		return 0;
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			int tmp = GetNum(a[i], b[j]);
			if (tmp == -1) continue;
			for (int k = 0; k < m; k++) {
				int ttt = GetNum(a[i], b[k]);
				if (ttt != -1 && ttt != tmp) {
					cout << -1 << endl;
					return 0;
				}
			}
			for (int k = 0; k < n; k++) {
				int ttt = GetNum(a[k], b[j]);
				if (ttt != -1 && ttt != tmp) {
					cout << -1 << endl;
					return 0;
				}
			}
		}
	}
	cout << 0 << endl;
	return 0;
}