#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define f1(i, a, b) for (int i = a; i <= b; i ++)

typedef vector <int> vi;

const int mod = 1e9 + 7;

#define N 2000005

int n, k;

int ps, p[N], mu[N], a[N], b[N];
bool vis[N];

vi v[N];

int expmod(int a, int b, int mod) {
	int res = 1;
	for ( ; b; b >>= 1) {
		if (b & 1) res = 1ll * res * a % mod;
		a = 1ll * a * a % mod;
	}
	return res;
}

void ppm() {
	mu[1] = 1;
	f1(i, 2, k) {
		if (!vis[i]) p[++ps] = i, mu[i] = -1;
		for (int j = 1; j <= ps && i * p[j] <= k; j ++) {
			int t = i * p[j];
			vis[t] = 1;
			if (i % p[j] == 0) break;
			mu[t] = -mu[i];
		}
	}
}

int main() {
    scanf("%d %d", &n, &k);
    ppm();
    f1(i, 1, k) if (mu[i]) {
		for (int j = i; j <= k; j += i) v[j].pb(i);
    }
    f1(i, 1, k) a[i] = expmod(i, n, mod);
    int ans = 0;
    f1(i, 1, k) {
		b[i] = b[i-1];
        for (auto x : v[i]) {
            b[i] = b[i] + mu[x] * (a[i/x] - a[i/x-1]);
            if (b[i] >= mod) b[i] -= mod;
			else if (b[i] < 0) b[i] += mod;
        }
        ans += b[i] ^ i;
        if (ans >= mod) ans -= mod;
    }
    printf("%d\n", ans);
	return 0;
}