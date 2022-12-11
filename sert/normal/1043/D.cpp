#pragma GCC diagnostic ignored "-Wunused-result"
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const int N = (int)1e6 + 34;
//const ll INF = (ll)1e18 + 41;
const int INF = (int)1e9 + 41;
const ll MD = (ll)1e9 + 7;
const ll P1 = 100005;
const ll P2 = 100007;
bool D = false;

ll PW1[N], PW2[N];
void init() {
	PW1[0] = PW2[0] = 1;
	for (int i = 1; i < N; i++) {
		PW1[i] = PW1[i - 1] * P1 % MD;
		PW2[i] = PW2[i - 1] * P2 % MD;
	}
}

vector<pair<ll, ll>> getHash(const vector<int> &a) {
	vector<pair<ll, ll>> res = {{0, 0}};
	for (int i = 0; i < (int)a.size(); i++) {
		res.push_back(make_pair((res[i].first * P1 + a[i]) % MD, (res[i].second * P2 + a[i]) % MD));
	}
	return res;
}

ll getHash(const vector<pair<ll, ll>> &h, int l, int r) {
	ll h1 = (h[r].first - h[l].first * PW1[r - l] + MD * MD) % MD;
	ll h2 = (h[r].second - h[l].second * PW2[r - l] + MD * MD) % MD;
	return h1 * MD + h2;
}

void solve() {
	int n, m;
	cin >> n >> m;
	vector<vector<int>> a(m, vector<int>(n));
	vector<vector<int>> pos(m, vector<int>(n));
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			cin >> a[i][j];
			a[i][j]--;
			pos[i][a[i][j]] = j;
		}
		a[i].push_back(-3431 - i);
		//hsh[i] = getHash(data);
	}

	if (m == 1) {
		ll kk = n;
		cout << kk * (kk + 1) / 2 << "\n";
		return;
	}

	ll ans = 0;
	ll st = 0;
	vector<int> pt(m);
	while (st < n) {
		for (int j = 1; j < m; j++) pt[j] = pos[j][a[0][st]];
		ll len = 0;
		bool ok = true;
		while (ok) {
			len++;
			for (int j = 1; j < m; j++) {
				if (a[j][pt[j] + len] != a[0][st + len]) ok = false;
			}
		}

		ans += (len * (len + 1)) / 2;
		st += len;
	}

	cout << ans << "\n";
}

int main() {
	init();
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