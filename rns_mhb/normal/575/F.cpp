#include<bits/stdc++.h>
using namespace std;

#define N 5050

int n, x, l[N], r[N], fl[N], fr[N];
typedef long long ll;

int dis(int y, int i) {
	if (y < l[i]) return l[i] - y;
	if (y > r[i]) return y - r[i];
	return 0;
}

ll dp[N<<1], ep[N<<1], tmp[N<<1];

int main() {
	scanf("%d%d", &n, &x);
	vector<int> v;
	for (int i = 1; i <= n; i ++) {
		scanf("%d%d", &l[i], &r[i]);
		v.push_back(l[i]);
		v.push_back(r[i]);
	}
	v.push_back(x);
	sort(v.begin(), v.end());
	int sz = unique(v.begin(), v.end()) - v.begin();
	for (int i = 1; i <= n; i ++) {
		fl[i] = lower_bound(v.begin(), v.begin() + sz, l[i]) - v.begin();
		fr[i] = lower_bound(v.begin(), v.begin() + sz, r[i]) - v.begin();
	}
	int now = lower_bound(v.begin(), v.begin() + sz, x) - v.begin();
	for (int i = 0; i < sz; i ++) dp[i] = abs(x - v[i]) + dis(v[i], 1);
	for (int i = 2; i <= n; i ++) {
		tmp[sz-1] = v[sz-1] + dp[sz-1];
		for (int j = sz - 2; j >= 0; j --) tmp[j] = min(tmp[j+1], v[j] + dp[j]);
		ll cur = 1e18;
		for (int j = 0; j < sz; j ++) {
			ep[j] = dis(v[j], i) + min(tmp[j] - v[j], cur + v[j]);
			cur = min(cur, dp[j] - v[j]);
		}
		swap(dp, ep);
	}
	ll ans = *min_element(dp, dp + sz);
	cout<<ans<<endl;
}