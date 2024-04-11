#include <stdio.h>
#include <algorithm>
#define rep(i, j, k) for(int i = (j); i <= (k); ++i)
using namespace std;
const int maxn = 10010;
int c[maxn], f[maxn];
int main(){
	int n, m; scanf("%d%d", &n, &m);
	rep(i, 1, n) f[i] = n + 1;
	rep(k, 1, m){
		int a, b; scanf("%d%d", &a, &b);
		b = (b - a + n) % n;
		c[a]++; if(b < f[a]) f[a] = b;
	}
	rep(i, 1, n) c[n + i] = c[i], f[n + i] = f[i];
	rep(i, 1, n){
		int ans = 0;
		rep(j, 0, n-1) if(c[i + j])
			ans = max(ans, n * (c[i+j] - 1) + j + f[i+j]);
		printf("%d%c", ans, " \n"[i==n]);
	}
	return 0;
}