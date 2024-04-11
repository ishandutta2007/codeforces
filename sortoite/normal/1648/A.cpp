#include<bits/stdc++.h>
using namespace std;

const int N = 1e5 + 10;
vector<vector<int>> a;
long long sum[N], cnt[N];

int main() {
#ifdef TRUE
	freopen("in.in", "r", stdin);
#endif
	int n, m; cin >> n >> m;
	a.resize(n);
	for(auto & b : a) {
		b.resize(m);
		for(auto &c : b) {
			scanf("%d", &c);
		}
	}
	long long ans = 0;
	for(int i = 0; i < n; i ++) {
		for(int j = 0; j < m; j ++) {
			ans += 1ll * cnt[a[i][j]] * i - sum[a[i][j]];
			sum[a[i][j]] += i;
			cnt[a[i][j]] ++;
		}
	}
	memset(cnt, 0, sizeof cnt);
	memset(sum, 0, sizeof cnt);
	for(int i = 0; i < m; i ++) {
		for(int j = 0; j < n; j ++) {
			ans += 1ll * cnt[a[j][i]] * i - sum[a[j][i]];
			sum[a[j][i]] += i;
			cnt[a[j][i]] ++;
		}
	}
	cout << ans << endl;
	return 0;
}