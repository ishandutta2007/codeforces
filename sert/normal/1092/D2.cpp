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
	cin >> n;
	vector<int> a(n);
	set<pair<int, int>> s;
	set<int> si;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		s.insert(make_pair(a[i], i));
		si.insert(i);
	}

	while ((int)s.size() >= 2) {
		int mn = s.begin()->second;
		auto it = si.find(mn);
		it++;
		int nx = *it;
		if (it == si.end() || a[mn] != a[nx]) {
			cout << "NO\n";
			return;
		}		
		si.erase(mn);
		si.erase(nx);
		s.erase(make_pair(a[mn], mn));
		s.erase(make_pair(a[nx], nx));
	}

	cout << "YES\n";
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