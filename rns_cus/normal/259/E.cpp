#include <bits/stdc++.h>
using namespace std;
#define N 100100
#define inf 1e9
#define mod 1000000007

typedef long long LL;


LL ans;
int p[N], runs, d[N][202], gas[N];
int n, a[N];
bool vis[N];

void get_prime() {
	for (int i = 2; i < N; i ++) {
		if (!vis[i]) p[++runs] = i;
		if (1ll * i * i >= N) continue;
		for (int j = i * i; j < N; j += i) vis[j] = 1;
	}
}

LL expmod(LL a, LL b) {
	LL rlt = 1, x = a;
	while (b) {
		if (b & 1) rlt = rlt * x % mod;
		x = x * x % mod, b >>= 1;
	}
	return rlt;
}

int main() {
//	freopen("e.in", "r", stdin);
	get_prime();
	d[1][gas[1]++] = 1;
	for (int i = 2; i <= 100000; i ++) {
		int x = i;
		for (int j = 1; j <= runs && p[j] * p[j] <= i; j ++) {
			if (x % p[j] == 0) {
				int ord = 0;
				while (x % p[j] == 0) x /= p[j], ord ++;
				int q = 1;
				for (int k = 0; k <= ord; k ++) {
					for (int l = 0; l < gas[x]; l ++) d[i][gas[i]++] = d[x][l] * q;
					q *= p[j];
				}
				break;
			}
		}
		if (x == i) {
			d[i][gas[i]++] = 1;
			d[i][gas[i]++] = i;
		}
		sort(d[i], d[i] + gas[i]);
		d[i][gas[i]] = inf;
	}

	scanf("%d", &n);
	for (int i = 1; i <= n; i ++) scanf("%d", &a[i]);
	sort(a + 1, a + n + 1);
	for (int D = 2; D <= a[n]; D ++) {
        LL rlt = 1;
        int x = 0, y = 0;
        for (int i = 0; i < gas[D]; i ++) {
			y = lower_bound(a + 1, a + n + 1, d[D][i+1]) - a - 1;
			if (i < gas[D] - 1) rlt = rlt * expmod(i + 1, y - x) % mod;
			else rlt = rlt * (expmod(i + 1, y - x) - expmod(i, y - x)) % mod;
			x = y;
        }
		ans = (ans + rlt) % mod;
	}
	cout << (ans + 1 + mod) % mod << endl;
	return 0;
}