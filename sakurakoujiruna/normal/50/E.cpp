#include <bits/stdc++.h>
using namespace std;

using ll = long long;

struct Seg {
	int l, r;
	bool operator <(Seg s) const {
		return l < s.l;
	}
};

int main() {
	ios :: sync_with_stdio(false);
	int n, m; cin >> n >> m;
	ll ans = 0;
	for(int b = 1; b <= n; b ++)
		if(ll(b) * b <= m)
			ans += ll(b) * b * 2;
		else ans += m * 2;

	vector <Seg> v;
	int last = 0;
	for(int b = 1; b <= n; b ++) {
		while(ll(last) * last + m < ll(b) * b)
			last ++;
		if(last != b) {
			v.push_back({-b - b + 1, -b - last});
			v.push_back({-b + last, -b + b - 1});
		}
	}
	sort(v.begin(), v.end());

	ll sum = 0, merge = 0; last = -1e9;
	for(Seg s : v) {
		sum += s.r - s.l + 1;
		if(last < s.l)
			last = s.l - 1;
		if(s.r > last) {
			merge += s.r - last;
			last = s.r;
		}
	}

	cout << ans + merge - sum << '\n';
	return 0;
}