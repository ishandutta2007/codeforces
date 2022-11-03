#include <bits/stdc++.h>
using namespace std;
#define SZ(x) ((int)(x).size())
typedef long long ll;
const int Inf = 0x3f3f3f3f;

int N, K;
char s[200005];

void solve() {
	scanf("%d%d", &N, &K);
	scanf("%s", s + 1);
	int wc = 0;
	for (int i = 1; i <= K; ++i) wc += (s[i] == 'W');
	int res = wc;
	for (int i = K + 1; i <= N; ++i) {
		wc += (s[i] == 'W');
		wc -= (s[i - K] == 'W');
		res = min(res, wc);
	}
	printf("%d\n", res);
}

int main() {
	int T; scanf("%d", &T);
	while (T--) solve();
	return 0;
}