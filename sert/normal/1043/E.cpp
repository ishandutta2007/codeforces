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

struct KK {
	int x, y, n;
	KK (int xx = 0, int yy = 0, int nn = 0): x(xx), y(yy), n(nn) {}	
};

bool operator < (const KK &a, const KK &b) {
	return a.y - a.x < b.y - b.x;
}

void solve() {
	int n, m;
	cin >> n >> m;
	vector<KK> a(n);
	vector<int> x(n), y(n);
	vector<vector<int>> es(n);
	vector<int> pos(n);
	for (int i = 0; i < n; i++) {
		cin >> x[i] >> y[i];
		a[i] = KK(x[i], y[i], i);
	}
	auto raw = a;
	sort(a.begin(), a.end());
	for (int i = 0; i < n; i++) {
		pos[a[i].n] = i;
	}

	for (int i = 0; i < m; i++) {
		int v1, v2;
		cin >> v1 >> v2;
		v1--;
		v2--;
		es[v1].push_back(v2);
		es[v2].push_back(v1);
	}

	vector<ll> prefB(n + 1, 0), sufA(n + 1, 0);
	for (int i = 1; i <= n; i++) {
		prefB[i] = prefB[i - 1] + a[i - 1].y;		
	}	
	for (int i = n - 1; i >= 0; i--) {
		sufA[i] = sufA[i + 1] + a[i].x;
	}

	for (int i = 0; i < n; i++) {
		int ps = pos[i];
		ll numL = ps;
		ll numR = n - ps - 1;

		ll sum = prefB[numL] + numL * raw[i].x + sufA[n - numR] + numR * raw[i].y;
		for (int v: es[i]) {			
			sum -= min(raw[i].x + raw[v].y, raw[i].y + raw[v].x);
		}		
		cout << sum << " ";
	}
	cout << "\n";
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int tst = 1;
	//scanf("%d", &tst);
	//cin >> tst;
#ifdef MADE_BY_SERT
	D = true;	
	tst = 3;
	while (tst--) {
		solve();
	}
#else
	while (tst--) solve();
#endif
}