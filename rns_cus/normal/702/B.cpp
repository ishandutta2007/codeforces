#include <bits/stdc++.h>
using namespace std;

int n, x;
map <int, int> mp;

int main() {
//	freopen("b.in", "r", stdin);
	scanf("%d", &n);
	long long ans = 0;
	for (int i = 1; i <= n; i ++) {
		scanf("%d", &x);
		ans += mp[x];
		for (int j = 1; j <= 31; j ++) if ((1 << j) > x) mp[(1<<j)-x] ++;
	}
	cout << ans << endl;
	return 0;
}