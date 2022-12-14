#include<stdio.h>
#include<algorithm>
using namespace std;

#define N 3002

struct dt{
	int x, y;
} d[N];

bool cmp(dt d1, dt d2){
	if (d1.y != d2.y) return d2.y > d1.y;
	else return d2.x > d1.x;
}

int r, c, n, k, z[N], h[N];
long long rlt;

int main(){
	scanf("%d %d %d %d", &r, &c, &n, &k);
	for (int i = 1; i <= n; i ++) scanf("%d %d", &d[i].x, &d[i].y);
	sort(d + 1, d + n + 1, cmp);
	int v = 1;
	h[r+1] = 1;
	h[0] = 1;
	for (int u = 1; u <= c; u ++){
		int vv = v;
		for(; d[v].y == u; v ++) z[d[v].x] ++;
		for(int i = 1; i <= r; i ++) h[i] = z[i];
		int p = 1, q = 1, S = h[1], ans = 0;
		while (q != r || S >= k){
			if (S >= k){
				ans += r + 1 - q;
				S -= h[p++];
			}
			else S += h[++q];
		}
		rlt += ans;
		int us[N], pr[N], ne[N];
		for(int i = 1; i <= r + 1; i ++) pr[i] = h[i-1] ? i - 1 : pr[i-1];
		for(int i = r; i >= 0; i --) ne[i] = h[i+1] ? i + 1 : ne[i+1];
		int vh = 1;
		for(int uu = 1; uu < u; uu ++){
			for(; d[vh].y == uu; vh ++){
				int xx = d[vh].x, p = xx, q = xx;
				S = h[xx];
				while (pr[p] && S < k){
					p = pr[p];
					S += h[p];
				}
				while (p <= xx && q <= r){
					if (S < k){
						q = ne[q];
						S += h[q];
					}
					else {
						if (S == k) ans -= (p - pr[p]) * (ne[q] - q);
						S -= h[p];
						p = ne[p];
					}
				}
				if (!(-- h[xx])){
					ne[pr[xx]] = ne[xx];
					pr[ne[xx]] = pr[xx];
				}
			}
			rlt += ans;
		}
	}
	printf("%I64d\n", rlt);
	return 0;
}