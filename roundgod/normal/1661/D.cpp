#pragma GCC optimize(3)
#include<bits/stdc++.h>
#define MAXN 300005
#define INF 1000000000000000000LL
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n,k;
ll b[MAXN];
ll d2[MAXN],d1[MAXN],delta[MAXN];
void go(int pos,ll num)
{
	d2[pos]+=(k-1)*num;
	d2[pos-1]-=k*num;
	d2[pos-k]+=num;
}
int main()
{
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;i++) scanf("%lld",&b[i]);
	ll ans=0;
	for(int i=n;i>=k+1;i--)
	{
		d1[i]=d1[i+1]+d2[i];
		delta[i]=delta[i+1]+d1[i];
		b[i]-=delta[i];
		if(b[i]>0)
		{
			ll need=(b[i]+k-1)/k;
			b[i]-=need*k;
			ans+=need;
			go(i-1,need);
		}
	}
	ll res=0;
	for(int i=k;i>=1;i--)
	{
		d1[i]=d1[i+1]+d2[i];
		delta[i]=delta[i+1]+d1[i];
		b[i]-=delta[i];
		if(b[i]>0) res=max(res,(b[i]+i-1)/i);
	}
	ans+=res;
	printf("%lld\n",ans);
	return 0;
}