#include <bits/stdc++.h>
using namespace std;
#define SZ(x) ((int)(x).size())
#define rep(i, a) for (int i = 0; i < (a); ++i)
#define repi(i, a) for (int i = 1; i <= (a); ++i)
typedef long long ll;

int N;
int a[100005];

void solve() {
	scanf("%d", &N);
	rep(i, N) scanf("%d", a + i);
	ll res = 0;
	rep(i, N - 1) res = max(res, 1ll * a[i] * a[i + 1]);
	printf("%lld\n", res);
}

int main() {
	int T; scanf("%d", &T);
	while(T--) solve();
	return 0;
}