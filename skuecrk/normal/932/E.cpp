#include<cstdio>
const int MOD=1e9+7;
struct mint{int x;mint(int x=0):x(x){}};
inline mint operator+  (mint a,mint b){return a.x+b.x<MOD?a.x+b.x:a.x+b.x-MOD;}
inline mint operator-  (mint a){return MOD-a.x;}
inline mint operator-  (mint a,mint b){return a+-b;}
inline mint operator*  (mint a,mint b){return 1LL*a.x*b.x%MOD;}
inline mint operator<< (mint x,int y){mint r=1;for(;y;y>>=1,x=x*x)if(y&1)r=r*x;return r;}
inline mint operator~  (mint x){return x<<MOD-2;}
inline mint operator/  (mint a,mint b){return a*~b;}
inline mint&operator+= (mint&a,mint b){return a=a+b;}
inline mint&operator-= (mint&a,mint b){return a=a-b;}
inline mint&operator*= (mint&a,mint b){return a=a*b;}
inline mint&operator<<=(mint&x,int y){return x=x<<y;}
inline mint&operator/= (mint&a,mint b){return a=a/b;}
#define MN 5000
mint s[MN+5][MN+5],ans,C[MN+5];
int main()
{
	int n,k,i,j;
	scanf("%d%d",&n,&k);
	for(s[0][0]=i=1;i<=k;++i)for(j=1;j<=i;++j)s[i][j]=s[i-1][j-1]+s[i-1][j]*j;
	for(C[0]=i=1;i<=k;++i)C[i]=C[i-1]*(n-i+1);
	for(i=1;i<=k&&i<=n;++i)ans+=s[k][i]*C[i]*(mint(2)<<n-i);
	printf("%d",ans);
}