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
	int nid = n / m;
	vector<int> a(n);
	vector<vector<pair<int, int>>> v(m);

	for (int i = 0; i < n; i++) {
		cin >> a[i];
		v[a[i] % m].push_back(make_pair(i, a[i]));		
	}	

	set<int> s;
	for (int i = 0; i < m * 2; i++) {
		if ((int)v[i % m].size() < nid) {
			s.insert(i);
		}
	}

	ll ans = 0;
	for (int i = 0; i < m; i++) {
		while ((int)v[i].size() > nid) {
			int ps = -1;
			while (true) {
				ps = *(s.begin());
				s.erase(s.begin());
				if (ps <= i || (int)v[ps % m].size() >= nid) continue;
				break;
			}

			v[ps % m].push_back(v[i].back());
			v[ps % m].back().second += ps - i;
			ans += ps - i;
			s.insert(ps);
			v[i].pop_back();
		}
	}

	vector<pair<int, int>> res;
	for (const auto &q: v) {
		for (const auto &it: q) {
			res.push_back(it);
		}
	}
	sort(res.begin(), res.end());
	cout << ans << "\n";
	for (int i = 0; i < (int)res.size(); i++) {
		cout << res[i].second << " ";
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
	tst = 2;
	while (tst--) {
		solve();
	}
#else
	while (tst--) solve();
#endif
}