#include <cstdio>
#include <algorithm>

using namespace std;

typedef long long ll;

const int MAXN = 1E5 + 10, MAXK = 10;

int n, K, a[MAXN];
int b[MAXN];
int m, c[MAXN];

ll f[MAXK + 1][MAXN];

ll s[MAXN];

inline int lowbit(int x){
	return x & (x ^ x - 1);
}

void update(int i, ll c){
	for (; i <= m; i += lowbit(i))
		s[i] += c;
}

ll query(int i){
	ll ret = 0;
	for (; i > 0; i -= lowbit(i))
		ret += s[i];
	return ret;
}

int main(){
	scanf("%d%d", &n, &K);
	for (int i = 0; i < n; ++i)
		scanf("%d", a + i), c[i] = a[i], f[0][i] = 1;
	sort(c, c + n);
	m = unique(c, c + n) - c;
	for (int i = 0; i < n; ++i)
		b[i] = upper_bound(c, c + m, a[i]) - c;

	for (int i = 0; i < K; ++i){
		for (int j = 1; j <= m; ++j)
			s[j] = 0;
		for (int j = 0; j < n; ++j){
			f[i + 1][j] = query(b[j] - 1);
			update(b[j], f[i][j]);
		}
	}

	ll ans = 0;
	for (int i = 0; i < n; ++i)
		ans += f[K][i];
	printf("%I64d\n", ans);
	return 0;
}