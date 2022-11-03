#include <bits/stdc++.h>
using namespace std;
#define SZ(x) ((int)(x).size())
#define rep(i, a) for (int i = 0; i < (a); ++i)
#define repi(i, a) for (int i = 1; i <= (a); ++i)
typedef long long ll;

ll N;

void solve() {
	scanf("%lld", &N);
	if (N < 6) N = 6;
	if (N & 1) ++N;
	printf("%lld\n", N / 2 * 5);
}

int main() {
	int T; scanf("%d", &T);
	while(T--) solve();
	return 0;
}