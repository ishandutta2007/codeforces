#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<ll, ll> pll;

#define all(x)			(x).begin(),(x).end()
#define X			first
#define Y			second
#define sep			' '
#define endl			'\n'
#define debug(x)		cerr << #x << ": " <<  x << endl;

const ll MAXN = 1e6 + 10;

ll n, e, R[MAXN];
vector<ll> vec[MAXN];
bool P[MAXN];

inline void solve() {
	cin >> n >> e;
	for (int i = 0; i < n; i++) {
		int x;
		cin >> x;
		if (x == 1) vec[i % e].push_back(0);
		else if (!P[x]) vec[i % e].push_back(1);
		else vec[i % e].push_back(2);
	}

	ll ans = 0;
	for (int i = 0; i < e; i++) {
		int m = vec[i].size();
		R[m - 1] = m;
		for (int j = m - 2; j >= 0; j--) {
			if (vec[i][j + 1]) R[j] = j + 1;
			else R[j] = R[j + 1];
		}

		ll lst = -1;
		for (ll j = 0; j < m; j++) {
			if (!vec[i][j]) continue;
			if (vec[i][j] == 1) ans += (j - lst) * (R[j] - j) - 1;
			lst = j;
		} 
	}

	cout << ans << endl;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	for (int i = 2; i < MAXN; i++)
		if (!P[i])
			for (int j = i + i; j < MAXN; j += i)
				P[j] = true;

	int t;
	cin >> t;
	while (t--) {
		for (int i = 0; i < n + 5; i++) vec[i].clear();
		solve();
	}
	return 0;
}