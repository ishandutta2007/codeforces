#include<bits/stdc++.h>
#define MAXN 2000005
#define F first
#define S second
#define MOD 1000000007
#define INF 1000000000
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
ll q,l,r,k;
ll f[MAXN],g[MAXN];
ll find(ll x)
{
	if(f[x]!=-1) return f[x];
	if(x<10) return f[x]=x;
	if(x%10==0) return f[x]=find(x/10); else return f[x]=find((x/10))*(x%10);
}
ll findg(ll x)
{
	if(g[x]!=-1) return g[x];
	if(x<10) return g[x]=x;
	return g[x]=findg(f[x]);
}
ll cnt[MAXN][10];
int main()
{
	memset(f,-1,sizeof(f));
	memset(g,-1,sizeof(g));
	for(ll i=1;i<=1000000;i++)
		find(i);
	for(ll i=1;i<=1000000;i++)
		findg(i);
	memset(cnt,0,sizeof(cnt));
	cnt[0][0]=1;
	for(ll i=1;i<=1000000;i++)
		for(ll j=0;j<10;j++)
			if(g[i]==j) cnt[i][j]=cnt[i-1][j]+1; else cnt[i][j]=cnt[i-1][j];
	scanf("%I64d",&q);
	for(ll i=0;i<q;i++)
	{
		scanf("%I64d%I64d%I64d",&l,&r,&k);
		printf("%I64d\n",cnt[r][k]-cnt[l-1][k]);
	}
	return 0;
}