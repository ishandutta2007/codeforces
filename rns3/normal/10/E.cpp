#include <stdio.h>
#include <algorithm>
using namespace std;
#define M 500
#define inf 2100000000

int n, m, N, a[M], b[M], c[M], f[M], g[M];

int F(int t, int n){
	if(!t) return 0;
	int p = lower_bound(a + 1, a + n + 1, t + 1) - a - 1;
	int x = t / a[p], y = t % a[p]; b[m] = p, c[m++] = x;
	return x + F(y, p-1);
}

int main(){
	//freopen("1.in", "r", stdin);
	scanf("%d", &n); for(int i = 1; i <= n; i++) scanf("%d", a + i);
	sort(a + 1, a + n + 1); a[n+1] = a[n] + a[n-1];
	int ans = inf, T, C;
	for(int k = 3; k <= n; k++){
		int tp = a[k] - 1;
		for(int p = k - 1; p; p--){
			m = 0; F(tp, p); N = m; T = 0; C = 0;
			for(int i = 0; i < m; i++) f[i] = a[b[i]], g[i] = c[i];
			for(int i = 0; i < N; i++){
				T += f[i] * g[i]; C += g[i];
				for(int j = p; a[j] > tp - T; j--){
					int t = T + a[j]; if(t >= ans || t >= a[k+1]) continue;
					m = 0; if(F(t-a[k], k-1) > C) ans = t;
				}
			}
		}
		if(ans < inf) break;
	}
	if(ans < inf) printf("%d\n", ans); else puts("-1");
}