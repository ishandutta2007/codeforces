#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1E5 + 10, MAXM = sqrt(MAXN) + 5;

int n;
int a[MAXN], b[MAXM][MAXN];

int main(){
	scanf("%d", &n);
	for (int i = 1; i <= n; ++i)
		scanf("%d", a + i);
	for (int k = 1; k <= n / k; ++k){
		b[k][n + 1] = 0;
		for (int i = n; i >= 1; --i)
			b[k][i] = 1 + b[k][min(i + a[i] + k, n + 1)];
	}
	
	int q;
	scanf("%d", &q);
	for (int qi = 0; qi < q; ++qi){
		int i, k;
		scanf("%d%d", &i, &k);
		if (k <= n / k)
			printf("%d\n", b[k][i]);
		else{
			int ans = 0;
			for (; i <= n; i += a[i] + k, ++ans);
			printf("%d\n", ans);
		}
	}
	return 0;
}