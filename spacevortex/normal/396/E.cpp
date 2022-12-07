#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N=1e6+50,n=1e6+5;
ll m,K,cnt=0,num;
ll a[N],b[N],f[N],pre[N],id[N],pri[N];
int main()
{
	ios::sync_with_stdio(false);
	ll i,j,x,y,tmp;
	cin>>m;
	for(i=1;i<=m;i++)
	{
		cin>>x>>y;
		a[x]+=y;
	}
	for(i=2;i<=n;i++)
	{
		if(!pre[i]) 
		{
			pre[i]=i;pri[++cnt]=i;
		}
		for(j=1;j<=cnt&&i*pri[j]<=n;j++)
		{
			pre[i*pri[j]]=pri[j];
			if(i%pri[j]==0) break;
		}
	}
	for(i=2;i<=n;i++) id[i]=i/pre[i];
	cin>>K;
	for(i=1;i<=min(K,20ll);i++)
	{
		memset(f,0,sizeof(f));
		memset(b,0,sizeof(b));
		for(j=n;j>=2;j--)
		{
			if(a[j+1]>0) f[j]++;
			b[pre[j]]+=f[j];
			f[id[j]]+=f[j];
		}
		for(j=1;j<=n;j++) 
		{
			a[j]=max(a[j]-1,0ll)+b[j];
		}
	}
	K-=min(K,20ll);
	memset(f,0,sizeof(f));
	memset(b,0,sizeof(b));
	for(i=n;i>=2;i--)
	{
		b[pre[i]]+=f[i];
		f[id[i]]+=f[i];

		a[i]+=b[i];
		tmp=min(a[i],K);
		a[i]-=tmp;
		f[i-1]+=tmp;
	}
	num=0;
	for(i=1;i<=n;i++) if(a[i]) num++;
	printf("%lld\n",num);
	for(i=1;i<=n;i++)
	{
		if(a[i]) printf("%lld %lld\n",i,a[i]);
	}
	return 0;
}