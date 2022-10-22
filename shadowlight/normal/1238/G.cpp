#include <bits/stdc++.h>
#define db long double
#define ll long long
#define x first
#define y second
#define mp make_pair
#define pb push_back
#define all(a) a.begin(), a.end()

using namespace std;

const int INF = 1e18 + 7;

struct Query {
	int t, a, b;
};

bool operator<(Query a, Query b) {
	if (a.t != b.t) {
		return a.t < b.t;
	}
	return a.b < b.b;
}

multiset <pair <int, int> > q;

int n, m, c, c0;

void solve() {
	q.clear();
	cin >> n >> m >> c >> c0;
	vector <Query> qs;
	for (int i = 0; i < n; i++) {
		int t, a, b;
		cin >> t >> a >> b;
		qs.push_back({t, a, b});
	}
	sort(qs.begin(), qs.end());
	qs.push_back({m, 1, 0});
	int pr = 0;
	q.insert({0, c0});
	int sum = c0;
	ll res = 0;
	for (auto t : qs) {
		int need = t.t - pr;
		while (q.size() && need > 0) {
			auto p = *q.begin();
			q.erase(q.begin());
			ll tet = min(need, p.second);
			res += tet * p.first;
			sum -= tet, p.second -= tet, need -= tet;
			if (p.second) {
				q.insert(p);
			}
		}
		pr = t.t;
		if (need) {
			cout << "-1\n";
			return;
		}
		q.insert({t.b, t.a});
		sum += t.a;
		while (sum > c) {
			auto p = *q.rbegin();
			q.erase(q.find(p));
			int t = min(sum - c, p.second);
			sum -= t, p.second -= t;
			if (p.second) {
				q.insert(p);
			}
		}
	}
	cout << res << "\n";
}


int main(){
#ifdef LOCAL
	freopen("G_input.txt", "r", stdin);
	//freopen("G_output.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int q;
	cin >> q;
	for (int i = 0; i < q; i++) {
		solve();
	}

}