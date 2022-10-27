#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N = 200000 + 10;
int main() {
	ios::sync_with_stdio(false);
	cout.tie(NULL);
	int t;
	cin >> t;
	while (t --) {
		int n, p;
		cin >> n >> p;
		vector<int> a(n + 1);
		vector< pair<int,int> > v(n + 1);
		vector<bool> vis(n+2, 0);

		for (int i = 1; i <= n; i ++) {
			cin >> a[i];
			v[i] = {a[i], i};
		}
		sort(v.begin() + 1, v.begin() + 1 + n);

		LL ans = 0, c = 0;
		for (int i = 1; i <= n; i ++) {
			int x = v[i].first;
			int pos = v[i].second;
			if (vis[pos]) continue;
			if (x >= p) break;

			{
				int tmp = pos - 1;
				while (tmp >= 1 && a[tmp] % a[pos] == 0) {
					ans += x; c ++;
					//printf("add %d %d\n", pos, tmp);
					if (vis[tmp]) break;
					vis[tmp --] = 1;
				}
			}

			{
				int tmp = pos + 1;
				while (tmp <= n && a[tmp] % a[pos] == 0) {
					//printf("add %d %d\n", pos, tmp);
					ans += x; c ++;
					if (vis[tmp]) break;
					vis[tmp ++] = 1;
				}
			}
			vis[pos] = 1;
		}
		ans += 1LL * (n-1-c) * p;
		cout << ans << endl;
	}
}