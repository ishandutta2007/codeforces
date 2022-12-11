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
	int n;
	ll x, y;
	cin >> n >> x >> y;

	ll ans = 0;
	vector<pair<int, int>> ev;
	for (int i = 0; i < n; i++) {
		int a, b;
		cin >> a >> b;
		ans = (ans + y * (b - a)) % MD;
		ev.emplace_back(a, -1);
		ev.emplace_back(b, 1);
	}
	sort(ev.begin(), ev.end());

	priority_queue<int> q;	

	for (int i = 0; i < (int)ev.size(); i++) {
		int tme = ev[i].first;
		int type = ev[i].second;
		if (type == 1) {
			q.push(tme);
		} else {			
			if (!q.empty() && y * (tme - q.top()) < x) {
				ans = (ans + y * (tme - q.top())) % MD;
				q.pop();
			} else {
				ans = (ans + x) % MD;
			}
		}
	}

	cout << ans << "\n";
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