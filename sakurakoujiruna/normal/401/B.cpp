#include <bits/stdc++.h>
using namespace std;

#define pb push_back
using pii = pair <int, int>;
using vp = vector <pii>;

int main() {
	ios :: sync_with_stdio(false);
	int x, n; cin >> x >> n;
	vp v = {{0, 0}, {x, x}};
	for(int i = 0; i < n; i ++) {
		int t; cin >> t;
		if(t == 1) {
			int d2, d1; cin >> d2 >> d1;
			v.pb({d2, d1});
		} else {
			int d2; cin >> d2;
			v.pb({d2, d2});
		}
	}
	sort(v.begin(), v.end());
	int mi = 0, ma = 0;
	for(int i = 1; i < v.size(); i ++) {
		int g = v[i].first - v[i - 1].second - 1;
		mi += g - g / 2;
		ma += g;
	}
	cout << mi << ' ' << ma << '\n';
	return 0;
}