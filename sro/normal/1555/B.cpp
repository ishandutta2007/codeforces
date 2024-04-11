#include <bits/stdc++.h>
using namespace std;
#define SZ(x) ((int)(x).size())
#define rep(i, a) for (int i = 0; i < (a); ++i)
#define repi(i, a) for (int i = 1; i <= (a); ++i)
typedef long long ll;
const int Inf = 0x3f3f3f3f;

int W, H;

void solve() {
	int x1, y1, x2, y2;
	int w, h;
	scanf("%d%d%d%d%d%d%d%d", &W, &H, &x1, &y1, &x2, &y2, &w, &h);
	int ans = Inf;
	if (w + x2 - x1 <= W) ans = min(ans, max(0, w - x1)), ans = min(ans, max(0, x2 - (W - w)));
	if (h + y2 - y1 <= H) ans = min(ans, max(0, h - y1)), ans = min(ans, max(0, y2 - (H - h)));
	if (ans == Inf) ans = -1;
	printf("%d\n", ans);
}

int main() {
	int T; scanf("%d", &T);
	while(T--) solve();
	return 0;
}