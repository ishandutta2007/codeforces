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
typedef long long LL;
#define MAXN 310000
int head[MAXN],next[MAXN*2],p[MAXN*2];
int d[MAXN];int n,P;LL ans=0;int sum[MAXN];int tot=0;
void L(int a,int b){tot++;p[tot]=b;next[tot]=head[a];head[a]=tot;}
int del[MAXN];
int main()
{
	scanf("%d%d",&n,&P);
	rep(i,1,n)
	{
		int a,b;scanf("%d%d",&a,&b);d[a]++;d[b]++;
		L(a,b);L(b,a);
	}
	rep(i,1,n)sum[d[i]]++;
	per(i,n,0)sum[i]+=sum[i+1];
	rep(i,1,n)
	{
		LL res=sum[max(P-d[i],0)];
		if(d[i]*2>=P)res--;
		for(int u=head[i];u;u=next[u])
		if(d[p[u]]+d[i]>=P)
		{
			d[p[u]]--;
			del[p[u]]++;
			if(d[p[u]]+d[i]<P)res--;
		}
		ans+=res;
		for(int u=head[i];u;u=next[u])
		{
			d[p[u]]+=del[p[u]];
			del[p[u]]=0;
		}
	}
	printf("%I64d\n",ans/2);
	return 0;
}