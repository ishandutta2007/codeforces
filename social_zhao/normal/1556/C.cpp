#include<bits/stdc++.h>
#define int long long
using namespace std;

int get() {
	int x = 0, f = 1; char c = getchar();

	while(!isdigit(c)) { if(c == '-') f = -1; c = getchar(); }
	while(isdigit(c)) { x = x * 10 + c - '0'; c = getchar(); }
	return x * f;
}

const int N = 1005;
int n, c[N], sum[N], ans, f[N][N];

signed main() {
	n = get();
	for(int i = 1; i <= n; i++) c[i] = get();
	for(int i = 1; i <= n; i++) sum[i] = (i & 1)? (sum[i - 1] + c[i]) : (sum[i - 1] - c[i]);
	memset(f, 0, sizeof(f));
	for(int i = 1; i <= n; i++) {
		int now = 0, mx = 0x3f3f3f3f3f3f3f3f;
		for(int j = i; j <= n; j++) {
			if(j & 1) now += c[j];
			else now -= c[j];
			mx = min(mx, now);
			f[i][j] = mx;
		}
	}
	for(int i = 1; i <= n; i += 2) {
		for(int j = i + 1; j <= n; j += 2) {
			int l = c[i], r = c[j], s = sum[j] - sum[i - 1];
			if(!(i & 1)) s = -s;
//			printf("%lld %lld: %lld %lld %lld\n", i, j, l, r, s);
			if(s > 0) l -= s;
			if(s < 0) r += s;
//			printf("-> %lld %lld\n", l, r);
//			if(f[i + 1][j - 1] < 0) l = min(l, -f[i + 1][j - 1]);
			if(l < 1 || r < 1 || l + f[i + 1][j - 1] < 0) continue;
			if(f[i + 1][j - 1] < 0) l += f[i + 1][j - 1] + 1;
			ans += min(l, r);
		}
	}
	printf("%lld\n", ans);
	return 0;
}

/*
4
56469941 5548511 4430733 90042425
*/