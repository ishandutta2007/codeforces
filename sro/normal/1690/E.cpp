#include <bits/stdc++.h>
using namespace std;
#define SZ(x) ((int)(x).size())
typedef long long ll;
const int Inf = 0x3f3f3f3f;

int N, K;
int a[200005];
int c[1005];

void solve() {
	scanf("%d%d", &N, &K);
	ll ans = 0;
	for (int i = 1; i <= N; ++i) scanf("%d", a + i), ++c[a[i] % K], ans += a[i] / K;
	int holy = 1;
	for (int i = K - 1; i; --i) {
		holy = max(holy, K - i);
		while (holy < K) {
			while (c[i] && c[holy]) {
				if (c[i] == 1 && i == holy) break;
				--c[i]; --c[holy];
				++ans;
			}
			if (!c[i]) break;
			++holy;
		}
	}
	for (int i = 0; i < K; ++i) c[i] = 0;
	printf("%lld\n", ans);
}

int main() {
	int T; scanf("%d", &T);
	while (T--) solve();
	return 0;
}