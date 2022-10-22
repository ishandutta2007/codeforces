#include <bits/stdc++.h>
#define ll long long

using namespace std;

const ll INF = 1e18 + 7;

struct Seg {
	ll pos;
	bool open;
	ll id;
};

bool operator<(Seg a, Seg b) {
	if (a.pos != b.pos) {
		return a.pos < b.pos;
	}
	return a.open > b.open;
}

struct Smth {
	ll w, d, id;
};

bool operator<(Smth a, Smth b) {
	if (a.w != b.w) {
		return a.w > b.w;
	}
	if (a.d != b.d) {
		return a.d > b.d;
	}
	return a.id < b.id;
}

void solve() {
	ll n, m, k;
	cin >> n >> m >> k;
	vector <vector <ll> > dp(n + 2, vector <ll> (m + 1, INF));
	dp[1][0] = 0;
	ll s[k], t[k], d[k], w[k];
	vector <Seg> segs;	
	for (ll i = 0; i < k; i++) {
		cin >> s[i] >> t[i] >> d[i] >> w[i];
		segs.push_back({s[i], true, i});
		segs.push_back({t[i] + 1, false, i});
	}
	sort(segs.begin(), segs.end());
	ll pos = 1;
	vector <ll> val(n + 1, -1);
	set <Smth> q;
	for (auto t : segs) {
		while (pos < t.pos) {
			if (!q.size()) {
				val[pos] = -1;
			} else {
				val[pos] = q.begin()->id;
			}
			pos++;
		}
		ll id = t.id;
		// cout << t.pos << " " << t.id << " " << q.size() << "\n";
		if (t.open) {
			q.insert({w[id], d[id], id});
		} else {
			q.erase({w[id], d[id], id});
		}
	}
	/*for (ll i = 1; i <= n; i++) {
		cout << val[i] << " ";
	}
	cout << "\n";*/
	for (ll i = 1; i <= n; i++) {
		for (ll j = 0; j <= m; j++) {
			ll pos = val[i];
			ll dn, wn;
			if (pos != -1) {
				dn = d[pos] + 1;
				wn = w[pos];
			} else {
				dn = i + 1, wn = 0;
			}
			dp[dn][j] = min(dp[dn][j], dp[i][j] + wn);
			if (j != m) {
				dp[i + 1][j + 1] = min(dp[i + 1][j + 1], dp[i][j]);
			}
			//cout << i << " " << dp[i][j] << "\n";
		}
		//cout << "\n";
	}
	ll res = INF;
	for (ll i = 0; i <= m; i++) {
		res = min(res, dp[n + 1][i]);
	}
	cout << res << "\n";
}

const ll TESTS = 1;

int main() {
	//freopen("input.txt", "r", stdin);
	for (ll i = 0; i < TESTS; i++) {
		solve();
	}
}