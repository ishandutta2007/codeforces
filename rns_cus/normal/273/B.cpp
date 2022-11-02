#include <bits/stdc++.h>

using namespace std;

#define N 200200

map <int, bool> mp[N];

int n, a[N], b[N], m, tmp[N], cnt;
int f[N], ff[N];
int g[N], h[N], p[N];

int main() {
	scanf("%d", &n);
	for(int i = 1; i <= n; i ++) {
		scanf("%d", a + i);
		tmp[cnt ++] = a[i];
	}
	for(int i = 1; i <= n; i ++) {
		scanf("%d", b +i);
		tmp[cnt ++] = b[i];
	}
	sort(tmp, tmp + cnt); cnt = unique(tmp, tmp + cnt) - tmp;
	for(int i = 1; i <= n; i ++) a[i] = lower_bound(tmp, tmp + cnt, a[i]) - tmp + 1;
	for(int i = 1; i <= n; i ++) b[i] = lower_bound(tmp, tmp + cnt, b[i]) - tmp + 1;
	scanf("%d", &m);
	f[0] = 1; ff[0] = 1; p[0] = 1;
	for(int i = 1; i < N; i ++) {
		f[i] = 1LL * i * f[i-1] % m;
		if(i & 1) ff[i] = 1LL * i * ff[i-1] % m;
		else ff[i] = 1LL * i / 2 * ff[i-1] % m;
		p[i] = 2 * p[i-1] % m;
	}
	for(int i = 1; i <= n; i ++) {
		mp[a[i]][i] = 1;
		g[a[i]] ++;
	}
	for(int i = 1; i <= n; i ++) {
		if(!mp[b[i]].count(i)) {
			mp[b[i]][i] = 1; g[b[i]] ++;
		} else {
			h[b[i]] ++;
		}
	}
	int rt = 1;
	for(int i = 1; i <= cnt; i ++) if(g[i] > 1) {
		rt = 1LL * rt * ff[g[i] + h[i]] % m;
		rt = 1LL * rt * p[(g[i] + h[i]) / 2 - h[i]] % m;
	}
	printf("%d\n", rt);
	return 0;
}