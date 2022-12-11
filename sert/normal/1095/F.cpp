#pragma GCC diagnostic ignored "-Wunused-result"
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const int N = (int)1e6 + 34;
const ll INF = (ll)1e18 + 41;
// const int INF = (int)1e9 + 41;
const ll MD = (ll)1e9 + 7;
bool D = false;

ll a[N];
vector<pair<int, ll>> es[N];
void solve() {
	set<pair<ll, int>> s0, s1;
	int n, m;
	cin >> n >> m;
	vector<ll> d(n, INF);
	d[0] = 0;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		s0.insert(make_pair(a[i], i));
		es[i].clear();
	}

	for (int i = 0; i < m; i++) {
		int v1, v2;
		ll c;
		cin >> v1 >> v2 >> c;
		v1--;
		v2--;
		es[v1].emplace_back(v2, c);
		es[v2].emplace_back(v1, c);
	}

	ll ans = 0;
	priority_queue<pair<ll, int>> q;
	vector<bool> u(n, false);

	for (int i = 0; i < n; i++) {
		q.push(make_pair(-d[i], i));
	}	

	while (!q.empty()) {
		int v = q.top().second;
		if (u[v]) {
			q.pop();
			continue;
		}	

		if (v == 0 || d[v] < s0.begin()->first + s1.begin()->first) {
			q.pop();
			ans += d[v];	
			//cout << "+ " << v + 1 << " " << d[v] << endl;		
		} else {
			v = s0.begin()->second;
			ans += s0.begin()->first + s1.begin()->first;
			//cout << "* " << v + 1 << " " << s0.begin()->first + s1.begin()->first << endl;
		}

		//cout << v << endl;
		u[v] = true;

		s1.insert(make_pair(a[v], v));
		s0.erase(make_pair(a[v], v));

		for (auto p: es[v]) {
			int w = p.first;
			ll we = p.second;
			//cout << "  " << w << " " << we << endl;
			if (d[w] > we) {
				d[w] = we;
				q.push(make_pair(-d[w], w));
			}
		}
	}

	cout << ans << "\n";
}

int main() {
#ifdef LOCAL
	freopen("a.in", "r", stdin);
#endif
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