#include <cstdio>
using namespace std;
const int N = 2022;

int t, n, x, p[N], ans[5 * N], len;

int main(){
	scanf("%d", &t);
	while(t--){
		len = 0;
		scanf("%d", &n);
		for(int i = 1; i <= n; i++){
			scanf("%d", &x);
			if((i & 1) != (x & 1)) len = -1;
			p[x] = i;
		}
		for(int i = n; len != -1 && i > 1; i -= 2){
			ans[++len] = p[i];
			for(int j = 1; j <= n; j++) if(p[j] < p[i]) p[j] = p[i] - p[j] + 1;
			p[i] = 1;
			int pnxt = p[i - 1] - 1;
			ans[++len] = pnxt;
			for(int j = 1; j <= n; j++) if(p[j] <= pnxt) p[j] = pnxt - p[j] + 1;
			pnxt += 2;
			ans[++len] = pnxt;
			for(int j = 1; j <= n; j++) if(p[j] <= pnxt) p[j] = pnxt - p[j] + 1;
			ans[++len] = 3;
			for(int j = 1; j <= n; j++) if(p[j] <= 3) p[j] = 4 - p[j];
			ans[++len] = i;
			for(int j = 1; j <= n; j++) if(p[j] <= i) p[j] = i - p[j] + 1;
		}
		printf("%d\n", len);
		for(int i = 1; i <= len; i++) printf("%d ", ans[i]);
		if(len != -1) putchar('\n');
	}
}