#include <bits/stdc++.h>

using namespace std;

#define ll long long

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;
	ll ans = 0LL;
	vector<tuple<double, ll, ll>> vs;
	string cur;
	for (int i = 0; i < n; i++) {
		cin >> cur;
		int sc = 0;
		int hc = 0;
		for (int j = 0; j < cur.length(); j++) {
			if (cur[j] == 's') sc++;
			else {
				hc++;
				ans += (sc+0LL);
			}
		}
		double d;
		if (hc == 0) {
			d = 1000000000000000000000000000.0;
		}
		else d = (sc+0.0)/(hc+0.0);
		vs.push_back(make_tuple(d, sc, hc));
	}
	sort(vs.begin(), vs.end());
	reverse(vs.begin(), vs.end());
	ll cs = 0LL;
	for (int i = 0; i < n; i++) {
		ll sc = get<1>(vs[i]);
		ll hc = get<2>(vs[i]);
		ans += cs*hc;
		cs += sc;
	}
	cout << ans << endl;
	cin >> ans;
}