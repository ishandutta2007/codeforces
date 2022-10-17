#include<cstdio>
const int N=5e6+1;
bool f[N];
long long g[N];
int i,j,t,l,r,n,ans,p[N];
int main() {
	scanf("%d%d%d",&t,&l,&r);
	for(i=1; i++<r;) {
		if(!f[i])p[p[++n]=i]=i;
		for(j=1; j<=n&&i*p[j]<=r; ++j)
			if(f[i*p[j]]=1,p[i*p[j]]=p[j],i%p[j]==0)j=n;
		g[i]=1ll*i*(p[i]-1)/2+g[i/p[i]];
	}
	for(i=r; i>=l; --i)
		ans=(1ll*ans*t+g[i])%1000000007;
	printf("%d",ans);
}