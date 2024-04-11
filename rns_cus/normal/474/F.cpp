#include <bits/stdc++.h>
using namespace std;

#define N 100100
#define M 20

int n, a[N], f[N][M], q, L, R;
vector <int> v[N];
map <int, int> mp;

int calc(int L, int R) {
	int Log = 31 - __builtin_clz(R - L + 1);
	return __gcd(f[L][Log], f[R-(1<<Log)+1][Log]);
}

int main() {
//	freopen("f.in", "r", stdin);
	scanf("%d", &n);
	for (int i = 1; i <= n; i ++) scanf("%d", &a[i]);
	for (int i = 1; i <= n; i ++) f[i][0] = a[i];
	int Log = 31 - __builtin_clz(n);
	for (int j = 1; j <= Log; j ++) {
		for (int i = 1; i <= n; i ++) if (i + (1 << j) - 1 <= n) {
			f[i][j] = __gcd(f[i][j-1], f[i+(1<<j-1)][j-1]);
		}
	}
	int cnt = 0;
	for (int i = 1; i <= n; i ++) {
		if (!mp.count(a[i])) mp[a[i]] = ++cnt;
		v[mp[a[i]]].push_back(i);
	}
	scanf("%d", &q);
	while (q --) {
		scanf("%d %d", &L, &R);
		int d = calc(L, R);
		int x = mp[d];
		if (!x) {
			printf("%d\n", R - L + 1); continue;
		}
		int st = lower_bound(v[x].begin(), v[x].end(), L) - v[x].begin();
		int en = lower_bound(v[x].begin(), v[x].end(), R + 1) - v[x].begin() - 1;
		printf("%d\n", R - L + 1 - (en - st + 1));
	}
	return 0;
}