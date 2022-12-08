#include <bits/stdc++.h>

using namespace std;
using ll = long long;
#define pll pair<ll, ll>

int n, k;
multiset<ll> cvals;
ll csum;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	vector<pll> stuff;

	cin >> n >> k;
	ll t, b;
	for (int i = 0; i < n; i++) {
		cin >> t >> b;
		stuff.push_back(pll(b, t));
	}
	sort(stuff.begin(), stuff.end());
	reverse(stuff.begin(), stuff.end());

	ll res = 0LL;
	for (pll vp : stuff) {
		t = vp.second;
		b = vp.first;

		cvals.insert(t);
		csum += t;
		if (cvals.size() > k) {
			csum -= *(cvals.begin());
			cvals.erase(cvals.begin());
		}
		res = max(res, b * csum);

	}

	cout << res << endl;

}