#include <bits/stdc++.h>
using namespace std;

#define N 1000100

int n, p[N], cnt[5];
bool vis[N];
const int mod = 1e9 + 7;

inline int calc(int n) {
	int k = n / 3, r = n % 3;
	int rlt = 0;
	if (r == 0) {
		rlt = 1;
		while (k --) rlt = 3ll * rlt % mod;
	}
	else if (r == 1) {
		rlt = 4, k --;
		while (k --) rlt = 3ll * rlt % mod;
	}
	else {
		rlt = 2;
		while (k --) rlt = 3ll * rlt % mod;
	}
	return rlt;
}

const int inf = 1e9;

inline int calc(int x, int y, int z) {
	if (z < 0) return inf;
	int rlt = 0;
	if (x < 0) {
		int c = -x;
		if (z < c) return inf;
		rlt += c, x += c, z -= c;
	}
	if (y < 0) {
		int c = (-y + 1) / 2;
		if (z < c) return inf;
		rlt += c, y += 2 * c, z -= c;
	}
	x += z; rlt += z;
	int d = min(x, y);
	x -= d, y -= d;
	assert(x % 3 == 0 && y % 3 == 0);
	return rlt + d + x / 3 * 2 + y;
}

int main() {
    int T;
    scanf("%d", &T);
    while (T --) {
		scanf("%d", &n);
		for (int i = 1; i <= n; i ++) vis[i] = 0, scanf("%d", &p[i]);
		printf("%d ", calc(n));
		for (int i = 0; i < 5; i ++) cnt[i] = 0;
		long long ans = 0;
		for (int i = 1; i <= n; i ++) {
			if (vis[i]) continue;
			int j = i, cur = 0;
			while (!vis[j]) vis[j] = 1, j = p[j], cur ++;
			int r = cur % 3, q = cur / 3;
			if (r == 1 && q > 0) q --, r += 3;
			ans += q;
			if (r != 0) cnt[r] ++;
			else ans --;
		}
		int rn = n % 3;
		int rlt = inf;
		if (rn == 1) {
			rlt = min(rlt, calc(cnt[1], cnt[2], cnt[4] - 1));
			rlt = min(rlt, calc(cnt[1], cnt[2] - 2, cnt[4]));
			rlt = min(rlt, calc(cnt[1] - 2, cnt[2] - 1, cnt[4]) + 1);
			rlt = min(rlt, calc(cnt[1] - 4, cnt[2], cnt[4]) + 2);
			rlt = min(rlt, calc(cnt[1] - 1, cnt[2], cnt[4]) + 1);
		}
		else if (rn == 2) {
			rlt = min(rlt, calc(cnt[1], cnt[2] - 1, cnt[4]));
			rlt = min(rlt, calc(cnt[1] - 2, cnt[2], cnt[4]) + 1);
		}
		else rlt = calc(cnt[1], cnt[2], cnt[4]);
		printf("%lld\n", ans + rlt);
    }

    return 0;
}