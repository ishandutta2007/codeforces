#include <cstdio>
#include <iostream>
#include <algorithm>

using namespace std;

typedef long long ll;

const int MAXN = 100100;
const int SQ = 1010;

int ar[MAXN];

ll ans[MAXN];
int N, Q, K;

ll go(int k) {
	int cur = N - 1;
	ll num = 1;
	ll left = num;
	ll mult = 0;
	ll ret = 0;
	while (cur >= 0) {
		ret += ar[cur] * mult;
		--cur;
		--left;
		if (left == 0) {
			num *= k;
			left = num;
			++mult;
		}
	}
	return ret;
}

int main() {
	scanf("%d", &N);
	for(int i = 0; i < N; ++i) {
		scanf("%d", ar + i);
	}

	sort(ar, ar + N);
	for(int i = 1; i < N && i < SQ; ++i) {
		ans[i] = go(i);
	}

	if (SQ < N) {
		ll cur = 0;
		for(int i = 0; i < N - 1; ++i) {
			cur += 2 * ar[i];
		}
		for(int i = 0; i < SQ; ++i) {
			cur -= ar[N - i - 2];
		}

		for(int i = SQ; i < N; ++i) {
			ans[i] = cur;
			cur -= ar[N - i - 2];
		}
	}

	scanf("%d", &Q);
	for(int i = 0; i < Q; ++i) {
		scanf("%d", &K);
		if (K >= N) K = N - 1;
		if (i) printf(" ");
		cout << ans[K];
	}
	printf("\n");
	return 0;
}