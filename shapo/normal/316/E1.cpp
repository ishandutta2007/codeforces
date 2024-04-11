#include <cstdio>
#include <cmath>

using namespace std;

typedef long long ll;

#define maxn 10050

int a[maxn];
int f[maxn];
int n, m, t;
int v, x;
int l, r;
const int MD = 1000000000;

int main() {
	scanf("%d%d", &n, &m);
	f[0] = f[1] = 1;
	for (int i = 2; i <= n; ++i)
		f[i] = (f[i - 1] + f[i - 2]) % MD;
	for (int i = 1; i <= n; ++i)
		scanf("%d", a + i);
	int ans;
	for (int i = 1; i <= m; ++i) {
		scanf("%d", &t);
		switch (t) {
			case 1 :
				scanf("%d%d", &x, &v);
				a[x] = v;
				break;
			case 2:
				scanf("%d%d", &l, &r);
				ans = 0;
				for (int i = 0; i <= r - l; ++i)
					ans = (ans + (ll)(a[i + l]) * f[i]) % MD;
				printf("%d\n", ans);
				break;
			case 3:
				break;
			default:
				break;
		}
	}
	return 0;
}