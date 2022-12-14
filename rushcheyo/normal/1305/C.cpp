#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int N = 200005;
const int P = 998244353;
const int inf = 0x3f3f3f3f;

int power(int a, ll x) {
	int ans = 1;
	for (; x; x >>= 1, a = 1ll * a * a % P)
		if (x & 1) ans = 1ll * ans * a % P;
	return ans;
}
int gcd(int a, int b) {
	return !b ? a : gcd(b, a % b);
}

int n, m, a[N], t[N], cnt[1005];
vector<int> b;

void update(int x) { for (; x <= n; x += x & -x) ++t[x]; }
int query(int x) { int s = 0; for (; x; x -= x & -x) s += t[x]; return s; }

int main() {
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; ++i) scanf("%d", a + i), ++cnt[a[i] % m], b.push_back(a[i]);
	for (int i = 0; i < m; ++i) if (cnt[i] > 1) return puts("0"), 0;
	int ans = 1;
	for (int i = 1; i <= n; ++i)
		for (int j = i + 1; j <= n; ++j)
			ans = 1ll * ans * abs(a[j] - a[i]) % m;
	printf("%d\n", ans);
}