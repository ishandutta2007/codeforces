#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N = 200000 + 10;
const LL mod = 998244353;
 
int n;
LL a[N], s[N][2];
 
 
LL solve() {
	for (int i = 1; i <= n; i ++) s[i][0] = s[i-1][0] + a[i];
	for (int i = 1; i <= n; i ++) s[i][1] = (i>=2?s[i-2][1]:0) + a[i];
	LL ans = 0;
	
	//printf("solve C....P\n");
	// C......P
	for (int i = 1; i < n; i ++) {
		LL c = s[i][0];
		LL p = s[n][0] - s[i][0];
		if (c >= p) continue;
		int lef = 0, rig = (n - i - 1) / 2 + 1;
		while (rig - lef > 1) {
			int mid = (lef + rig) >> 1;
			LL tmp = s[i + mid * 2][1] - s[i][1];
			if (c + tmp < p - tmp) lef = mid; else rig = mid;
		}
		ans += (lef + 1);
	}
	//printf("ans(add CP) = %lld\n", ans);
 
	//printf("solve P....P\n");
	// P.....P
	ans += 1; // all P
	for (int i = 2; i < n; i ++) {
		LL c = s[i][0] - a[1];
		LL p = a[1] + s[n][0] - s[i][0];
		if (c >= p) continue;
		//printf("i=%d,c=%lld,p=%lld\n", i,c,p);
		int lef = 0, rig = (n - i - 1) / 2 + 1;
		while (rig - lef > 1) {
			int mid = (lef + rig) >> 1;
			LL tmp = s[i + mid * 2][1] - s[i][1];
			if (c + tmp < p - tmp) lef = mid; else rig = mid;
		}
		//printf("add %d\n", lef+1);
		ans += (lef + 1);
	}
	//printf("ans(add PP) = %lld\n", ans);
	// C......C
	for (int i = 1; i <= n; i ++) {
		LL c = s[i][0] + a[n];
		LL p = s[n-1][0] - s[i][0];
		if (c >= p) continue;
		int lef = 0, rig = (n - i - 2) / 2 + 1;
		while (rig - lef > 1) {
			int mid = (lef + rig) >> 1;
			LL tmp = s[i + mid * 2][1] - s[i][1];
			if (c + tmp < p - tmp) lef = mid; else rig = mid;
		}
		ans += (lef + 1);
	}
	//printf("ans(add CC) = %lld\n", ans);
 
	// P.....C
	for (int i = 2; i < n; i ++) if (s[i][0] > s[n][0] - s[i][0]) ans ++;
	for (int i = 2; i < n; i ++) {
		LL c = s[i][0] - a[1] + a[n];
		LL p = a[1] + s[n-1][0] - s[i][0];
		if (c >= p) continue;
		//printf("i=%d,c=%lld,p=%lld\n", i,c,p);
		int lef = 0, rig = (n - i - 2) / 2 + 1;
		while (rig - lef > 1) {
			int mid = (lef + rig) >> 1;
			LL tmp = s[i + mid * 2][1] - s[i][1];
			if (c + tmp < p - tmp) lef = mid; else rig = mid;
		}
		//printf("add %d\n", lef + 1);
		ans += (lef + 1);
	}
	//printf("ans (add PC) = %lld\n", ans);
	//cout << ans << endl;
	return ans;
}
 
int check() {
	int ans = 0;
	for (int i = 0; i < 1<<n; i ++) {
		vector<int> f1, f2; LL s1 = 0, s2 = 0;
		for (int j = 0; j < n; j ++) {
			if (i >> j & 1) {
				f1.push_back(j), s1 += a[j+1]; 
			} else {
				f2.push_back(j), s2 += a[j+1];
			}
		}
		bool ok = 1;
		ok &= (s1 < s2);
		for (int x = 1; x + 1 < f1.size(); x ++) {
			ok &= (f1[x] - f1[x-1] <= f1[x+1] - f1[x]);
		}
		for (int x = 1; x + 1 < f2.size(); x ++) {
			ok &= (f2[x] - f2[x-1] >= f2[x+1] - f2[x]);
		}
		if (ok) ans ++;
	}
	return ans;
}
 
int main() {
	ios::sync_with_stdio(false);
	cout.tie(NULL);
	int t; cin >> t;
	while (t --) {
		cin >> n;
		//n = 10;
		for (int i = 1; i <= n; i ++) {
			cin >> a[i];
			//a[i] = rand() % 100 + 1;
		}
		//for (int i = 1; i <= n; i ++) cout << a[i] << " \n"[i==n];
		//LL res = solve(); LL res2 = check();
		//cout << res << " " << res2 << endl;
		//assert(res == res2);
		LL res = (n >= 5 ? solve() : check());
		cout << res % mod << endl;
	}
}