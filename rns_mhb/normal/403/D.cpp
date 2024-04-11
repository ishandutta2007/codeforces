#include <stdio.h>
#define N 1010
#define M 50

typedef __int64 ll;

const ll Mod=1000000007;
ll f[N][M], c[N+M][N+M];
ll ans[N][N];
ll fac[M], tmp;
//f[m][k]: 0<=d1<=d2<=...<=dk, d1+d2+...+dk=m 

int main() {
	int i, j, k, u, n, s, T;
	fac[0]=1;
	for (i=1; i<M; i++) fac[i]=(fac[i-1]*i)%Mod;
	c[0][0]=1;
	for (i=1; i<N+M; i++) {
		c[i][0]=c[i][i]=1;
		for (j=1; j<i; j++) {
			c[i][j]=(c[i-1][j]+c[i-1][j-1])%Mod;
		}
	}
	for (i=0; i<N; i++) f[i][1]=1;
	for (j=2; j<M; j++) {
		for (i=0; i<N; i++) {
			u=i/j;
			f[i][j]=0;
			for (k=0; k<=u; k++) f[i][j]=(f[i][j]+f[i-k*j][j-1])%Mod;
		}
	}
	for (k=1; k<M; k++) {
		for (n=k*(k+1)/2; n<N; n++) {
			ans[n][k]=0;
			i=k*(k-1)/2;
			for (s=i; s<=n-k; s++) {
				tmp=(f[s-i][k]*fac[k])%Mod;
				tmp=(tmp*c[n-s][k])%Mod;
				ans[n][k]=(ans[n][k]+tmp)%Mod;
			}
		}
	}
//	freopen ("in.txt", "r", stdin);
	for (scanf("%d", &T); T--; ) {
		scanf("%d %d", &n, &k);
		printf("%I64d\n", ans[n][k]);
	}
}