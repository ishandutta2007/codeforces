#include <bits/stdc++.h>

using namespace std;
#define pii pair<int, int>
#define ll long long
const int mod = 1000000007;
const int maxn = 100010;

int n;
multiset<int> open;
ll x, y;

void add(ll & a, ll b) {
	a = (a+b)%mod;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	ll ans = 0LL;
	cin >> n >> x >> y;
	vector<pii> events;
	int l, r;

	for (int i = 0; i < n; i++) {
		cin >> l >> r;
		add(ans,  (r-l) * y);
		events.push_back(pii(l, 1));
		events.push_back(pii(r+1, 0));
	}

	sort(events.begin(), events.end());
	for (pii val : events) {
		int spot = val.first;
		int tp = val.second;
		if (tp == 0) {
			open.insert(spot);
		}
		else {
			if (open.size()) {
				int fg = *(open.rbegin());
				ll o1 = (spot - fg + 1LL) * y;
				add(ans, min(o1, x));

				open.erase(open.find(fg));
			}
			else {
				// cout << "ADDED A NEW" << endl;
				add(ans, x);
			}
		}
	}
	cout << ans << endl;

}