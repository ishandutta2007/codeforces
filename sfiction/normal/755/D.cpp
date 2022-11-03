#include <cstdio>

const int MAXN = 1E6 + 10;

int n, k;
int a[MAXN];

void update(int i, int c){
	for (; i <= n; i = (i | i - 1) + 1)
		a[i] += c;
}

int query(int i){
	int ret = 0;
	for (; i > 0; i &= i - 1)
		ret += a[i];
	return ret;
}

int main(){
	scanf("%d%d", &n, &k);
	if (n - k < k)
		k = n - k;
	int u = 1;
	long long tot = 1;
	for (int i = 1; i <= n; ++i){
		int v = u + k;
		++tot;
		if (v <= n)
			tot += query(v - 1) - query(u);
		else
			tot += query(n) - query(u) + query((v -= n) - 1);
		update(u, 1), update(u = v, 1);
		printf("%lld%c", tot, "\n "[i < n]);
	}
	return 0;
}