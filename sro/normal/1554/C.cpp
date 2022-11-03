#include <bits/stdc++.h>
using namespace std;
#define SZ(x) ((int)(x).size())
#define rep(i, a) for (int i = 0; i < (a); ++i)
#define repi(i, a) for (int i = 1; i <= (a); ++i)
typedef long long ll;

int N, M;

int calc(int mid) {
	bool les = 0;
	int res = 0;
	for (int i = 30; ~i; --i) {
		int ex = ((N >> i) & 1) ^ 1, cur = (mid >> i) & 1;
		if (les || ex <= cur) {
			res |= 1 << i;
			if (!les) les = (ex < cur);
		}
	}
	return res;
}

void solve() {
	scanf("%d%d", &N, &M);
	int L = -1, R = 1 << 30;
	while (R - L > 1) {
		int mid = (L + R) >> 1;
		if (calc(mid) <= M) L = mid;
		else R = mid;
	}
	printf("%d\n", R);
}

int main() {
	int T; scanf("%d", &T);
	while(T--) solve();
	return 0;
}