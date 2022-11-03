#include <bits/stdc++.h>
using namespace std;
#define SZ(x) ((int)(x).size())
#define rep(i, a) for (int i = 0; i < (a); ++i)
#define repi(i, a) for (int i = 1; i <= (a); ++i)
typedef long long ll;

int inline gcd(int a, int b) { return b ? gcd(b, a % b) : a; }

int N;
int x[6005], y[6005];
int ic[6005][2];
int g[6005][6005];

int main() {
	scanf("%d", &N);
	repi(i, N) scanf("%d%d", x + i, y + i);
	repi(i, N) repi(j, N) g[i][j] = (x[j] - x[i]) % 4 == 0 && (y[j] - y[i]) % 4 == 0;
	repi(i, N) repi(j, N) if (j != i) ++ic[i][!g[i][j]];
	ll res1 = 0, res3 = 0;
	repi(i, N) repi(j, N) if (j != i && g[i][j]) {
		int js = ic[i][1], os = ic[i][0] - 1;
		res1 += js; res3 += os;
	}
	printf("%lld\n", (res1 + res3 / 3) / 2);
	return 0;
}