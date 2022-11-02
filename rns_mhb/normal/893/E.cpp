#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define f0(i, a, b) for (int i = a; i < b; i ++)
#define f1(i, a, b) for (int i = a; i <= b; i ++)

const int mod = 1e9 + 7;

#define N 1000005

vector <int> v[N];

int n, fac[N] = {1, 1}, rfac[N] = {1, 1}, inv[N] = {0, 1};
int dp[N][20], a[N], b[N], pw[N] = {1, 2};

int C(int n, int k) {return 1ll * fac[n] * rfac[k] % mod * rfac[n-k] % mod;}

int func(int x, int y) {
    if (dp[x][y] >= 0) return dp[x][y];
    int &ans = dp[x][y]; ans = 0;
    for (auto z : v[x]) (ans += func(x/z, y-1)) %= mod;
	return ans;
}

int main() {
    f0(i, 2, N) {
        fac[i] = 1ll * fac[i-1] * i % mod;
        inv[i] = 1ll * (mod / i) * (mod - inv[mod % i]) % mod;
        rfac[i] = 1ll * rfac[i-1] * inv[i] % mod;
        pw[i] = 1ll * pw[i-1] * 2 % mod;
    }
    f0(i, 2, N) {
		a[i] = i;
		for (int j = i; j < N; j += i) v[j].pb(i);
    }
    f0(i, 2, N) {
        if (a[i] < i) continue;
        for (int j = i; j < N; j += i) {
            while (a[j] % i == 0) a[j] /= i;
        }
    }
    memset(dp, -1, sizeof dp);
    dp[1][0] = 1;
    f0(i, 2, N) dp[i][0] = 0;
    int q, x, y, z, ans;
    for (scanf("%d", &q); q --; ) {
		scanf("%d %d", &x, &y);
		z = min(y, 19); ans = 0;
        for (int i = 0; i <= z; i ++) ans = (ans + 1ll * func(x, i) * C(y, i)) % mod;
        printf("%d\n", 1ll * ans * pw[y-1] % mod);
    }
	return 0;
}