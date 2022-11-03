#include <bits/stdc++.h>
using namespace std;
#define SZ(x) ((int)(x).size())
#define rep(i, a) for (int i = 0; i < (a); ++i)
#define repi(i, a) for (int i = 1; i <= (a); ++i)
typedef long long ll;

int M;
int a[2][100005];
int b[2][100005];

void solve() {
	scanf("%d", &M);
	rep(i, 2) {
		rep(j, M) scanf("%d", a[i] + j);
		b[i][0] = 0;
		rep(j, M) b[i][j + 1] = b[i][j] + a[i][j];
	}
	int ans = 0x3f3f3f3f;
	rep(i, M) ans = min(ans, max(b[1][i], b[0][M] - b[0][i + 1]));
	printf("%d\n", ans);
}

int main() {
	int T; scanf("%d", &T);
	while(T--) solve();
	return 0;
}