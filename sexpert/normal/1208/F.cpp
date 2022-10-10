#include <bits/stdc++.h>
using namespace std;
typedef array<int, 2> ii;

const int LG = 21;
ii dp[1 << LG];

ii merge(ii p, ii q) {
	array<int, 4> v = {p[0], q[0], p[1], q[1]};
	sort(v.rbegin(), v.rend());
	return {v[0], v[1]};
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	for(int i = 0; i < (1 << LG); i++)
		dp[i] = {-1, -1};
	int n;
	cin >> n;
	vector<int> v(n);
	for(auto &x : v)
		cin >> x;
	for(int i = 0; i < n; i++)
		dp[v[i]] = merge(dp[v[i]], ii{i, -1});
	for(int b = LG - 1; b >= 0; b--)
		for(int msk = (1 << LG) - 1; msk >= 0; msk--)
			if((msk & (1 << b)) == 0)
				dp[msk] = merge(dp[msk], dp[msk ^ (1 << b)]);
	int ans = 0;
	for(int i = 0; i < n - 2; i++) {
		int x = v[i], m = 0;
		for(int b = LG - 1; b >= 0; b--) {
			if(x & (1 << b))
				continue;
			int nm = m ^ (1 << b);
			if(min(dp[nm][0], dp[nm][1]) > i)
				m = nm;
		}
		ans = max(ans, x + m);
	}
	cout << ans << '\n';
}