#include <bits/stdc++.h>
using namespace std;

#define N 200200

int n, m, a[N], b[N];
bool chg[N];
map <int, int> mp;

int main() {
//	freopen("e.in", "r", stdin);
	scanf("%d %d", &n, &m);
	int odd = (m + 1) / 2, even = m / 2;
	for (int i = 1; i <= n; i ++) {
		scanf("%d", &a[i]);
		if (a[i] > m) {
			if (mp[a[i]]) continue;
			mp[a[i]] = 1;
			if (a[i] & 1) odd ++;
			else even ++;
		}
	}
	if (odd < n / 2 || even < n / 2) {
		puts("-1"); return 0;
	}
	int cnt[2];
	cnt[0] = cnt[1] = n / 2;
	mp.clear();
	for (int i = 1; i <= n; i ++) {
		if (mp[a[i]] || !cnt[a[i]&1]) {
			chg[i] = 1; continue;
		}
		mp[a[i]] = 1, cnt[a[i]&1] --;
	}
	int x = 0;
	for (int i = 1; i <= m && x < cnt[1]; i += 2) {
		if (!mp[i]) b[x++] = i;
	}
	for (int i = 2; i <= m && x < cnt[0] + cnt[1]; i += 2) {
		if (!mp[i]) b[x++] = i;
	}
	printf("%d\n", x);
	x = 0;
	for (int i = 1; i <= n; i ++) {
		printf("%d%c", chg[i] ? b[x++] : a[i], i < n ? ' ' : '\n');
	}
	return 0;
}