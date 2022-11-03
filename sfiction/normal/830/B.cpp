#include <cstdio>
#include <algorithm>

using namespace std;

const int MAXN = 1E5 + 10;

int n, m;
int a[MAXN << 1], b[MAXN][2];
int cnt[MAXN << 1][2];
int nex[MAXN];
int c[MAXN];

int s[MAXN];

void update(int i){
	for (; i <= m; i = (i | i - 1) + 1)
		++s[i];
}

int query(int i){
	int ret = 0;
	for (; i > 0; i &= i - 1)
		ret += s[i];
	return ret;
}

int main(){	
	scanf("%d", &n);
	for (int i = 1; i <= n; ++i)
		scanf("%d", a + i);
	copy_n(a + 1, n, c);
	sort(c, c + n);
	m = unique(c, c + n) - c;
	for (int i = 1; i <= n; ++i)
		a[i] = lower_bound(c, c + m, a[i]) - c;
	copy_n(a + 1, n, a + n + 1);

	for (int n0 = n << 1, i = 1; i <= n0; ++i){
		update(a[i] + 1);
		cnt[i][0] = query(a[i]);
		cnt[i][1] = query(a[i] + 1);
	}

	fill_n(nex, m, n << 1 | 1);
	for (int i = n << 1; i > n; --i)
		nex[a[i]] = i;
	nex[m] = n + 1;
	for (int i = n; i >= 1; --i){
		b[i][0] = nex[a[i]];
		b[i][1] = nex[a[i] + 1];
		nex[a[i]] = i;
	}
	long long ans = nex[0];	

	sort(a + 1, a + n + 1);
	int u = nex[0];
	for (int i = 1; i < n; ++i){
		if (a[i] == a[i + 1])
			ans += (b[u][0] - u) - (cnt[b[u][0]][0] - cnt[u][0]);
		else
			ans += (b[u][1] - u) - (cnt[b[u][1]][0] - cnt[u][1]);
		u = b[u][a[i] != a[i + 1]];
		if (u > n)
			u -= n;
	}
	printf("%lld\n", ans);
	return 0;
}