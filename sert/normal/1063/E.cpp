#pragma GCC diagnostic ignored "-Wunused-result"
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const int N = (int)1e3 + 34;
//const ll INF = (ll)1e18 + 41;
const int INF = (int)1e9 + 41;
const ll MD = (ll)1e9 + 7;
bool D = false;

int p[N], o[N];
bool u[N];
string ans[N];

void solve() {
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		ans[i].clear();
		for (int j = 0; j < n; j++) {
			ans[i].push_back('.');
		}
		u[i] = false;
		cin >> p[i];		
		p[i]--;

		o[p[i]] = i;
 	}

	int num = n;
	int h = n - 1;
	int lst = -1;
	for (int i = 0; i < n; i++) {
		//cerr << i << "\n";
		if (p[i] == i || u[i]) continue;

		u[i] = true;
		
		if (lst != -1) {
			ans[h][i] = ans[h][p[lst]] = (p[lst] > i ? '/' : '\\');
		} else {
			num--;
		}
		ans[n - 1][i] = '/';
		lst = i;

		h--;

		int v = o[i];
		while (v != i) {
			u[v] = true;
			ans[h][v] = ans[h][p[v]] = (v < p[v] ? '/' : '\\');
			h--;			
			v = o[v];
		}
	}

	cout << num << "\n";
	for (int i = 0; i < n; i++) {
		cout << ans[i] << "\n";
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