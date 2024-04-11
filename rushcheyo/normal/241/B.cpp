#include <bits/stdc++.h>
using namespace std;

const int N = 50005;
typedef long long ll;
int n, m, a[N], tot = 1, ch[N * 30][30], size[N * 30], mn[N * 30], mx[N * 30], sum[N][30];

int check(int mid) {
	ll ans = 0;
	for (int i = 1; i <= n; i++) {
		int x = 1;
		for (int j = 29; j >= 0; j--) {
			int d1 = a[i] >> j & 1, d2 = mid >> j & 1;
			if (d2 == 0) ans += size[ch[x][d1 ^ 1]];
			x = ch[x][d1 ^ d2];
		}
	}
	return ans >> 1;
}

int main() {
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i++) scanf("%d", a + i);
	sort(a + 1, a + 1 + n);
	for (int i = 1; i <= n; i++)
		for (int j = 0; j <= 29; j++)
			sum[i][j] = sum[i - 1][j] + (a[i] >> j & 1);
	for (int i = 0; i <= n * 30; i++) mn[i] = n + 1, mx[i] = 0;
	for (int i = 1; i <= n; i++) {
		int x = 1;
		for (int j = 29; j >= 0; j--) {
			int d = a[i] >> j & 1;
			if (!ch[x][d]) ch[x][d] = ++tot;
			x = ch[x][d];
			size[x]++;
			mn[x] = min(mn[x], i);
			mx[x] = max(mx[x], i);
		}
	}
	int l = 0, r = (1 << 30) - 1, cnt;
	while (l < r) {
		int mid = l + r >> 1;
 		if (m <= check(mid)) l = mid + 1;
		else r = mid;
	}
	cnt = check(l);
	ll ans = 0;
	for (int i = 1; i <= n; i++) {
		int x = 1, pre = 0;
		for (int j = 29; j >= 0; j--) {
			int d1 = a[i] >> j & 1, d2 = l >> j & 1;
			if (d2 == 0) {
				int rt = ch[x][d1 ^ 1], tot = size[rt];
				if (tot) {
					ans += (ll)tot * pre;
					for (int k = j; k >= 0; k--) {
						int s = sum[mx[rt]][k] - sum[mn[rt] - 1][k];
						if (a[i] >> k & 1) s = tot - s;
						ans += (ll)s << k;
					}
				}
			}
			pre |= l & (1 << j);
			x = ch[x][d1 ^ d2];
		}
	}
	ans >>= 1;
	ans += (ll)(m - cnt) * l;
	printf("%d\n", (int)(ans % 1000000007));
	return 0;
}