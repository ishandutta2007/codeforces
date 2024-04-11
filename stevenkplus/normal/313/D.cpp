#include <cstdio>
#include <iostream>
#include <vector>

using namespace std;

#define repi(i, a) for(typeof((a).begin()) i = (a).begin(), _##i = (a).end(); i != _##i; ++i)
typedef long long ll;

const int MAXN = 310;
const int MAXM = 100100;

int R[MAXM];
int C[MAXM];
vector<int> guys[MAXN];

ll dp[MAXN][MAXN];
int trans[MAXN][MAXN];

int N, M, K;
ll getdp(int n, int k) {
	if (k <= 0) return 0;
	if (n == N) {
		return -1;
	}

	ll &ret = dp[n][k];
	if (ret) return ret - 2;
	ret = getdp(n + 1, k);
	for(int i = n + 1; i <= N; ++i) {
		if (trans[n][i] != -1) {
			ll val = getdp(i, k - (i - n));
			if (val != -1) {
				val += trans[n][i];
				if (ret == -1 || val < ret) {
					ret = val;
				}
			}
		}
	}

	ret += 2;
	return ret - 2;
}

int main() {
	scanf("%d %d %d", &N, &M, &K);
	for(int i = 0; i <= N; ++i) {
		for(int j = 0; j <= N; ++j) {
			trans[i][j] = -1;
		}
	}

	for(int i = 0; i < M; ++i) {
		int a, b, c;
		scanf("%d %d %d", &a, &b, &c);
		--a;
		if (trans[a][b] == -1 || c < trans[a][b]) {
			trans[a][b] = c;
		}
	}

	for(int i = 0; i < N; ++i) {
		for(int j = 0; j <= N; ++j) {
			if (trans[i][j] != -1 && (trans[i + 1][j] == -1 || trans[i][j] < trans[i + 1][j])) {
				trans[i + 1][j] = trans[i][j];
			}
		}
	}

	ll ans = getdp(0, K);

	cout << ans << "\n";
	return 0;
}