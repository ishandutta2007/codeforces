#include <bits/stdc++.h>
using namespace std;

void init() {
#ifdef FIRE_MIND
    freopen("a.in", "r", stdin);
    ///freopen("a.out", "w", stdout);
#endif
}
#define pb push_back
#define fi first
#define se second

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;

const double EPS = 1e-9;
const int INF = (int)1e9 + 41;
const int N = (int)1e6 + 34;

int a[N];
void solve() {
    int n, k;
	scanf("%d%d", &n, &k);
	for (int i = 0; i < n; i++) scanf("%d", a + i);
	int cur = 0;
	double ans = -1;
	a[n] = a[n - 1] + k + 2;
	for (int i = 0; i < n; i++) {
        while (a[cur + 1] <= a[i] + k) cur++;
        if (cur - i > 1) {
            ans = max(ans, (a[cur] - a[i + 1] + 0.0) / (a[cur] - a[i] + 0.0));
        }
	}
	if (ans < -0.5) printf("-1\n");
	else printf("%.9f\n", (double)ans);
}

int main() {
    init();
	solve();
	//solve();
	//solve();
    return 0;
}