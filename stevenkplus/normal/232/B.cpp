#include <iostream>

using namespace std;

typedef long long ll;

const int MOD = 1000000007;
const int MAXN = 111;

int N;
ll M;
int K;

ll powmod(ll base, ll pow) {
	if (pow == 0) return 1;
	ll k = powmod(base, pow / 2);
	(k *= k) %= MOD;
	if (pow & 1) {
		(k *= base) %= MOD;
	}
	return k;
}

int cnts[MAXN];
ll dp[MAXN][MAXN * MAXN];
ll choose[MAXN];
ll powmods[MAXN][2];

ll getdp(int n, int k) {
	if (n == N) {
		if (k == 0) return 1;
		else return 0;
	}
	ll &ret = dp[n][k];
	if (ret) return ret - 1;

	for(int i = 0; i <= N; ++i) {
		if (i > k) break;
		ll nxt = getdp(n + 1, k - i);
		ll ways = powmods[i][cnts[n]];
		(ways *= nxt) %= MOD;
		(ret += ways) %= MOD;
	}

	return ret++;
}

int main() {
	cin >> N >> M >> K;
	choose[0] = 1;
	for(int i = 0; i < N; ++i) {
		for(int j = i; j >= 0; --j) {
			(choose[j + 1] += choose[j]) %= MOD;
		}
	}

	ll div = M / N;
	int rem = M % N;
	for(int i = 0; i < N; ++i) {
		if (i < rem) cnts[i] = 1;
	}
	for(int i = 0; i < 2; ++i) {
		for(int j = 0; j <= N; ++j) {
			powmods[j][i] = powmod(choose[j], div + i);
		}
	}

	ll ans = getdp(0, K);
	cout << ans << "\n";
	return 0;
}