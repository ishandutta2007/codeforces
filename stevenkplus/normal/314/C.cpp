#include <cstdio>

using namespace std;

const int MAXS = 1 << 20;
const int MAXN = 100100;
const int MOD = 1E9 + 7;

typedef long long ll;

int N;

int BIT[MAXS];
int query(int idx) {
	int ret = 0;
	while (idx) {
		(ret += BIT[idx]) %= MOD;
		idx -= idx & -idx;
	}
	return ret;
}

void add(int idx, int val) {
	while (idx < MAXS) {
		(BIT[idx] += val) %= MOD;
		idx += idx & -idx;
	}
}

int subtr(ll a, ll b) {
	int ret = (a - b) % MOD;
	if (ret < 0) ret += MOD;
	return ret;
}

int prv[MAXS];
int vals[MAXN];

int main() {
	scanf("%d", &N);
	int ans = 0;
	for(int i = 1; i <= N; ++i) {
		int cur;
		scanf("%d", &cur);
		ll val = query(cur - 1);
		++val;
		int pr = vals[prv[cur]];
		val += pr;
		(val *= cur) %= MOD;

		vals[i] = val;

		prv[cur] = i;
		int diff = subtr(val, pr);
		(ans += diff) %= MOD;
		add(cur, diff);
	}

	printf("%d\n", ans);
	return 0;
}