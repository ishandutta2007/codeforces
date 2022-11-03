#include <bits/stdc++.h>
using namespace std;
#define SZ(x) ((int)(x).size())
#define rep(i, a) for (int i = 0; i < (a); ++i)
#define repi(i, a) for (int i = 1; i <= (a); ++i)
typedef long long ll;
const int Inf = 0x3f3f3f3f;

char a[100005], b[100005];
int N;
int tp[100005];

void solve() {
	scanf("%d", &N);
	scanf("%s", a + 1);
	scanf("%s", b + 1);
	repi(i, N) tp[i] = a[i] + b[i] - '0' - '0';
	int ans = 0;
	bool hv1 = 0, hv0 = 0;
	repi(i, N) {
		if (tp[i] == 1) {
			ans += 2;
			hv1 = hv0 = 0;
			continue;
		}
		if (tp[i] == 0) {
			hv0 = 0;
			if (hv1) ans += 2;
			else ++ans, hv0 = 1;
			hv1 = 0;
		}
		else {
			if (hv0) ++ans, hv0 = 0;
			else hv1 = 1;
		}
	}
	printf("%d\n", ans);
}

int main() {
	int T; scanf("%d", &T);
	while (T--) solve();
	return 0;
}