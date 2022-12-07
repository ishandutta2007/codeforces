#include<bits/stdc++.h>
#define cmax(a,b) a=max(a,b)
using namespace std;
const int N=12,M=2020;
int T,n,m,sx,tot;
int a[M][N],vmx[M],p[M],s[1<<N],dp[1<<N];
bool cmp(const int &a,const int &b){return vmx[a]>vmx[b];}
void Solve()
{
	int i,j,ns,vs,val,st,now;
	scanf("%d%d",&n,&m);
	memset(vmx,0,sizeof(vmx));
	for(i=0;i<n;i++)
	{
		for(j=1;j<=m;j++)
		{
			scanf("%d",&a[j][i]);
			cmax(vmx[j],a[j][i]);
		}
	}
	for(i=1;i<=m;i++) p[i]=i;
	sort(p+1,p+m+1,cmp);
	tot=min(n,m);
	memset(dp,0,sizeof(dp));
	sx=1<<n;
	for(i=1;i<=tot;i++)
	{
		//printf("#%d %d %d %d\n",i,p[i],a[i][0],a[i][1]);
		memset(s,0,sizeof(s));
		for(ns=0;ns<sx;ns++)
		{
			for(st=0;st<n;st++)
			{
				val=0;
				for(j=0,now=st;j<n;j++,now=(now==n-1)?0:(now+1))
				{
					if(ns&(1<<j)) val+=a[p[i]][now];
				}
				cmax(s[ns],val);
			}
		}
		for(ns=sx-1;ns>0;ns--)
		{
			for(vs=ns;vs;vs=(vs-1)&ns)
			{
				cmax(dp[ns],dp[ns^vs]+s[vs]);
			}
		}
	}
	printf("%d\n",dp[sx-1]);
}
int main()
{
	scanf("%d",&T);
	while(T--) Solve();
	return 0;
}