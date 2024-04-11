#include <cstdio>
#include <cstring>

using namespace std;

typedef long long ll;

const ll MOD = 1E9 + 7;
const int MAXK = 10;

int N, K;

int ar[MAXK];

int cnt = 0;

bool vis[MAXK];

bool good() {
	for(int i = 0; i < K; ++i) {
		int cur = i;
		memset(vis, 0, sizeof(vis));
		vis[0] = true;

		while (!vis[cur]) {
			vis[cur] = true;
			cur = ar[cur];
		}
		if (cur != 0) return false;
	}
	return true;
}

void dfs(int cur) {
	if (cur == K) {
		if (good()) ++cnt;
	} else {
		for(int i = 0; i < K; ++i) {
			ar[cur] = i;
			dfs(cur + 1);
		}
	}
}

ll powmod(ll a, ll b) {
	if (b == 0) return 1;
	ll k = powmod(a, b / 2);
	k = (k * k % MOD);
	if (b & 1) {
		(k *= a) %= MOD;
	}


	return k;
}

int main() {
	scanf("%d %d", &N, &K);

	if (K == 8) {
		cnt = 2097152;
	} else{
		dfs(0);
	}

	int extr = N - K;
	ll prod = powmod(extr, extr);
	(prod *= cnt) %= MOD;
	printf("%d\n", int(prod));
	return 0;
}