#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
LL c[62][62];
LL m, k;
LL F(LL x) {
	int cur = 0;
	LL ans = 0;
	for (int i = 60; i >= 0; i --) {
		if (x >> i & 1) {
			if (k >= cur)
			ans += c[i][k - cur];
			cur ++;
		}
	}
	return ans;
}
bool chk(LL x) {
	return F(2 * x) - F(x) >= m;
}
int main() {
	for (int i = 0; i < 62; i ++) c[i][0] = 1;
	for (int i = 1; i < 62; i ++)
		for (int j = 1; j <= i; j ++)
			c[i][j] = c[i-1][j] + c[i-1][j-1];
	cin >> m >> k;
	LL lef = 0, rig = 1e18;
	while (rig - lef > 1) {
		LL mid = (lef + rig) >> 1;
		if (chk(mid)) rig = mid;
		else lef = mid;
	}
	cout << rig << endl;
}