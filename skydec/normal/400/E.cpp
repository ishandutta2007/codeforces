#include<cstring>
#include<cstdlib>
#include<cstdio>
#include<cmath>
#include<algorithm>
#include<map>
#include<vector>
#define rep(i,j,k) for(int i=j;i<=k;i++)
#define per(i,j,k) for(int i=j;i>=k;i--)
#define lowbit(x) ((x)&(-(x)))
using namespace std;
#define MAXN 110000
typedef long long LL;
LL ans=0;int m;
LL js(int x){return x*1ll*(x+1)/2;}
int n;int a[MAXN];int tw[18];
int main()
{
	scanf("%d%d",&n,&m);rep(i,1,n)scanf("%d",&a[i]);tw[0]=1;rep(i,1,16)tw[i]=tw[i-1]*2;
	rep(q,0,16)
	{
		for(int i=1;i<=n;i++)
		{
			if(!(a[i]&tw[q]))continue;
			int j=i;
			while(j<n&&(a[j+1]&tw[q]))j++;
			ans+=tw[q]*1ll*js(j-i+1);
			i=j;
		}
	}
	rep(ppp,1,m)
	{
		int p,v;scanf("%d%d",&p,&v);
		rep(i,0,16)
		if((a[p]&tw[i])!=(v&tw[i]))
		{
			int l,r;l=r=p;
			while(l>1&&(a[l-1]&tw[i]))l--;
			while(r<n&&(a[r+1]&tw[i]))r++;
			if(v&tw[i])
			{
				ans-=tw[i]*1ll*(js(p-l)+js(r-p));
				ans+=tw[i]*1ll*js(r-l+1);
			}
			else
			{
				ans+=tw[i]*1ll*(js(p-l)+js(r-p));
				ans-=tw[i]*1ll*js(r-l+1);
			}
		}
		a[p]=v;
		printf("%I64d\n",ans);
	}
	return 0;
}