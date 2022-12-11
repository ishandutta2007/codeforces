#pragma GCC diagnostic ignored "-Wunused-result"
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const int N = (int)1e6 + 34;
//const ll INF = (ll)1e18 + 41;
const int INF = (int)1e9 + 41;
const ll MD = (ll)1e9 + 7;
bool D = false;

void solve() {
	int n, m;
	cin >> n >> m;
	vector<int> p(n * 2 + 1, -1), a(n * 2 + 1);
	vector<bool> u(n * 2 + 1, false);

	for (int i = 1; i <= n * 2; i++) cin >> a[i];
	for (int i = 0; i < m; i++) {
		int v1, v2;
		cin >> v1 >> v2;
		p[v1] = v2;
		p[v2] = v1;
	}

	int t;
	cin >> t;

	int num = 0;
	int x = -1;
	while (num < n * 2) {
		t = 3 - t;
		num++;	
		if (t == 2) {
			if (x != -1 && p[x] != -1 && !u[p[x]]) {
				cout << p[x] << endl;
				u[p[x]] = true;
				continue;
			}

			bool ok = false;
			for (int i = 1; !ok && i <= n * 2; i++) {
				if (!u[i] && p[i] != -1 && a[i] >= a[p[i]]) {
					u[i] = true;
					cout << i << endl;
					ok = true;
				}
			}
			if (ok) continue;

			int mx = -1;
			for (int i = 1; i <= n * 2; i++) {
				//cout << i << " " << p[i] << " " << (int)u[i] << "\n";
				if (p[i] == -1 && !u[i] && (mx == -1 || a[i] > a[mx])) {
					mx = i;
				}
			}
			cout << mx << endl;
			u[mx] = true;
		} else {			
			cin >> x;
			u[x] = true;				
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int tst = 1;
	//scanf("%d", &tst);
	//cin >> tst;
#ifdef MADE_BY_SERT
	D = true;	
	tst = 1;
	while (tst--) {
		solve();
	}
#else
	while (tst--) solve();
#endif
}