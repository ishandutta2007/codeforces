#include<cstdio>
const int N=2005;
int a,b,c,tot,p[N],mu[N],g[N][N];
bool np[N]={true,true};
int gcd(int a,int b) {
	if (b==0) return a;
	if (g[a][b]) return g[a][b];
	return g[a][b]=gcd(b,a%b);
}
int F(int n,int m) {
	int ret=0;
	for (int i=1;i<=n;i++)
		if (gcd(i,m)==1) ret+=n/i;
	return ret;
}
int main() {
	scanf("%d%d%d",&a,&b,&c);
	mu[1]=1;
	for (int i=2;i<=2000;i++) {
		if (!np[i]) p[++tot]=i,mu[i]=-1;
		for (int j=1;j<=2000&&p[j]*i<=b;j++) {
			np[p[j]*i]=true;
			if (i%p[j]==0) break;
			mu[i*p[j]]=-mu[i];
		}
	}
	int ans=0;
	for (int i=1;i<=a;i++)
		for (int j=1;j<=b&&j<=c;j++)
			if (gcd(i,j)==1) ans+=a/i*mu[j]*F(b/j,i)*F(c/j,i);
	printf("%d\n",ans&((1<<30)-1));
}