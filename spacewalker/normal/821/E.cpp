#include <cstdio>
#include <vector>
#include <algorithm>
#define MOD 1000000007

using namespace std;
typedef long long ll;
typedef vector<vector<ll>> matrix;

matrix mmult(matrix a, matrix b) {
	int n = a.size();
	matrix res(n, vector<ll>(n, 0));
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			for (int k = 0; k < n; ++k) {
				res[i][j] = (res[i][j] + (a[i][k] * b[k][j]) % MOD) % MOD;
			}
		}
	}
	return res;
}

matrix identity(int n) {
	matrix res(n, vector<ll>(n, 0));
	for (int i = 0; i < n; ++i) {
		res[i][i] = 1;
	}
	return res;
}

matrix expon(matrix a, ll n) {
	if (n == 1) {
		return a;
	} else if (n == 0) {
		return identity(a.size());
	} else {
		return mmult(expon(mmult(a, a), n / 2), (n % 2 == 1 ? a : identity(a.size())));
	}
}

vector<ll> fastforward(vector<ll> &init, ll steps) {
	int n = init.size();
	matrix trans(n, vector<ll>(n, 0));
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			if (i == j - 1 || i == j || i == j + 1) {
				trans[i][j] = 1;
			}
		}
	}
	matrix ftrans = expon(trans, steps);
	vector<ll> finalr(n);

	for (int i = 0; i < n; ++i) {
		//printf("init[%d] = %lld\n", i, init[i]);
		for (int j = 0; j < n; ++j) {
			//printf("ftrans[%d][%d] = %lld\n", j, i, ftrans[j][i]);
			finalr[i] = (finalr[i] + (ftrans[j][i] * init[j]) % MOD) % MOD;
		}
		//printf("finalr[%d] = %lld\n", i, finalr[i]);
	}
	return finalr;
}

int main() {
	int n; ll k; scanf("%d %lld", &n, &k);
	vector<ll> upTo(n, 0);
	vector<int> height(n, 0);
	ll dummy;
	for (int i = 0; i < n; ++i) {
		scanf("%lld %lld %d", &dummy, &upTo[i], &height[i]);
		++height[i];
	}

	if (upTo[n-1] >= k) {
		upTo[n-1] = k;
	}

	vector<vector<ll>> endOfSegments(n, vector<ll>());

	vector<ll> start(height[0], 0);
	start[0] = 1;
	endOfSegments[0] = fastforward(start, upTo[0]);
	//printf("fast forwarding up to x = %lld\n", upTo[0]);

	for (int i = 1; i < n; ++i) {
		vector<ll> cstart(height[i], 0);
		for (int j = 0; j < min(height[i-1], height[i]); ++j) {
			cstart[j] = endOfSegments[i-1][j];
		}
		endOfSegments[i] = fastforward(cstart, upTo[i] - upTo[i - 1]);
	}

	printf("%lld", endOfSegments[n-1][0]);
	return 0;
}