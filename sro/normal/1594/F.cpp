#include <bits/stdc++.h>
using namespace std;
#define SZ(x) ((int)(x).size())
typedef long long ll;
const int Inf = 0x3f3f3f3f;

ll S, N, K;

void solve() {
	scanf("%lld%lld%lld", &S, &N, &K);
	ll gr = (S + 1) / (K << 1);
	if (S == K) return puts("YES"), void();
	ll ch = gr * K + min(K, (S + 1) % (K << 1));
	if (ch >= N + 1) puts("NO");
	else puts("YES");
}

int main() {
	int T; scanf("%d", &T);
	while (T--) solve();
	return 0;
}