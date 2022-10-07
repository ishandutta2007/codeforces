#include <cstdio>
#include <map>
#include <algorithm>

using namespace std;

typedef long long ll;

typedef pair<int, int> pii;
typedef pair<ll, pii> state;

const int MAXM = 100;
const int MOD = 1E9 + 7;
const int MAXL = 100;

char buf[123456];

bool bad[MAXM][MAXM];

ll N;
int M, K;

map<ll, int> stuff;
int cnt = 2;
int A[MAXL];
int B[MAXL];

ll split(ll n) {
	ll a = 1;
	while (a * 2 + 1 < n) {
		a = a * 2;
	}
	return a + 1;
//	return (n + 1) / 2;
}

int assign(ll n) {
	int &ret = stuff[n];
	if (ret) return ret;
	ret = cnt++;
	ll mid = split(n);
	A[ret] = assign(mid);
	B[ret] = assign(n - mid + 1);
	return ret;
}

ll dp[MAXL][MAXM][MAXM];

ll get(int n, int start, int end) {
	ll &ret = dp[n][start][end];
	if (ret) return ret - 1;
	if (n == 1) {
		if (bad[start][end]) ret = 0;
		else ret = 1;
	} else {
		int s1 = A[n], s2 = B[n];
		for(int i = 0; i < M; ++i) {
			ll a = get(s1, start, i);
			ll b = get(s2, i, end);
			(ret += a * b) %= MOD;
		}
	}
	return ret++;
}

int conv(char c) {
	if (c >= 'a' && c <= 'z') {
		return c - 'a';
	} else {
		return 26 + (c - 'A');
	}
}

int main() {
	scanf("%I64d %d %d", &N, &M, &K);
	if (N == 1) {
		printf("%d\n", M);
		return 0;
	}

	stuff[2] = 1;
	int assn = assign(N);

	for(int i = 0; i < K; ++i) {
		scanf("%s", buf);
		int a = conv(buf[0]);
		int b = conv(buf[1]);
		bad[a][b] = true;
	}

	ll sum = 0;
	for(int i = 0; i < M; ++i) {
		for(int j = 0; j < M; ++j) {
			(sum += get(assn, i, j)) %= MOD;
		}
	}

	int ans = int(sum);
	printf("%d\n", ans);
	return 0;
}