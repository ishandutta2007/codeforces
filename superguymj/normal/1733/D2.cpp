#include<bits/stdc++.h>
#define rep(i,x,y) for(int i=x; i<=y; ++i)

using namespace std;
typedef long long LL;
const int N=5005;
int n,x,y;
int m,p[N];
char s[N];
int a[N];
LL sum[N][N],f[N];

void solve()
{
	scanf("%d%d%d",&n,&x,&y);
	scanf("%s",s+1);
	rep(i,1,n) a[i]=s[i]-'0';
	scanf("%s",s+1);
	rep(i,1,n) a[i]^=(s[i]-'0');
	m=0;
	rep(i,1,n) if(a[i]) p[++m]=i;
	if(m&1)
	{
		puts("-1");
		return;
	}
	if(!m)
	{
		puts("0");
		return;
	}
	if(x>=y)
	{
		if(m>2 || p[1]+1<p[2]) printf("%lld\n",(LL)y*m/2);
		else printf("%d\n",min(y*2,x));
		return;
	}
	rep(i,1,m) rep(j,1,m) sum[i][j]=0;
	for(int i=2; i<=m; i+=2)
		rep(l,1,m-i+1)
		{
			int r=l+i-1;
			sum[l][r]=sum[l][r-2]+(LL)(p[r]-p[r-1])*x*2;
		}
	rep(i,1,m)
	{
		f[i]=f[i-1]+y;
		rep(j,0,i-1) if(!((i-j)&1))
			f[i]=min(f[i],f[j]+sum[j+1][i]);
	}
	printf("%lld\n",f[m]/2);
}

int main()
{
	int t;
	scanf("%d",&t);
	while(t--) solve();
	return 0;
}