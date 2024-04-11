#include <cstdio>
#include <algorithm>
#include <bitset>

using namespace std;

const int MAXN = 1E6 + 10;

int a[MAXN];
int cnt[MAXN];
bitset<MAXN> f;

int main(){
	int n, k;
	scanf("%d%d", &n, &k);
	for (int i = 1; i <= n; ++i)
		scanf("%d", a + i);
	int ans2 = 0;
	for (int i = 1; i <= n; ++i){
		if (a[i] < 0)
			continue;
		int len = 0;
		for (int u = i; a[u] > 0; ++len)
			u = -(a[u] = -a[u]);
		++cnt[len];
		ans2 += len >> 1;
	}
	ans2 = min(n, k + min(k, ans2));
	f.set(0);
	for (int i = 1; i <= n; ++i){
		if (cnt[i] == 0)
			continue;
		for (int t = cnt[i]; t; t >>= 1)
			f |= f << (t + 1 >> 1) * i;
	}
	printf("%d %d\n", k + !f[k], ans2);
	return 0;
}