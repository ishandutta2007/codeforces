#include <stdio.h>
#include <memory.h>
#define N 25
#define clr(a) memset(a, 0, sizeof(a))

bool vis[N][N];

int main() {
	int T, n, p, i, j, k;
//	freopen ("in.txt", "r", stdin);
	for (scanf("%d", &T); T--; ) {
		scanf("%d %d", &n, &p);
		clr(vis);
		for (i=1; i<=n; i++) {
			j=i+1;
			if (j>n) j-=n;
			k=j+1;
			if (k>n) k-=n;
			printf("%d %d\n%d %d\n", i, j, i, k);
			vis[i][j]=vis[j][i]=1;
			vis[i][k]=vis[k][i]=1;
		}
		k=0;
		for (i=1; i<=n; i++) {
			for (j=i+1; j<=n; j++) if (!vis[i][j]) {
				if (k==p) break;
				printf("%d %d\n", i, j);
				vis[i][j]=vis[j][i]=1;
				k++;
			}
			if (j<=n) break;
		}
	}
	return 0;
}