#include <stdio.h>
#define N 2010

typedef __int64 ll;
const ll P=1000000007;

ll fac[N], c[N][N], ans;
int a[N];
bool fl[N];

int main() {
	int n, i, m=0, x=0, st=1, j;
//	freopen ("in.txt", "r", stdin);
	scanf("%d", &n);
	for (i=0; i<n; i++) {
		scanf("%d", a+i);
		if (a[i]==-1) m++;
		else fl[a[i]-1]=1;
	}
	for (i=0; i<n; i++) if (a[i]==-1 && !fl[i]) x++;
	fac[0]=1;
	for (i=1; i<=x; i++) {
		c[i][0]=c[i][i]=1;
		for (j=1; j<i; j++) c[i][j]=(c[i-1][j-1]+c[i-1][j])%P;
	}
	for (i=1; i<=m; i++) fac[i]=fac[i-1]*i%P;
	ans=fac[m];
	for (i=1; i<=x; i++) {
		st*=-1;
		ans=((ans+st*fac[m-i]*c[x][i])%P+P)%P;
	}
	printf("%I64d\n", ans);
	return 0;
}