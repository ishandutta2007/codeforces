#include<bits/stdc++.h>
#define MAXN 100005
#define MAXL 61
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
ll q,t;
ll x,k;
ll shiftv[MAXL],shifts[MAXL];
ll pow2[MAXL];
ll find_level(ll x)
{
	if(x==1) return 0;
	return find_level(x/2)+1;
}
int main()
{
	scanf("%I64d",&q);
	memset(shiftv,0,sizeof(shiftv));
	memset(shifts,0,sizeof(shifts));
	pow2[0]=1;
	for(ll i=1;i<=60;i++)
		pow2[i]=pow2[i-1]*2;
	for(ll i=0;i<q;i++)
	{
		scanf("%I64d",&t);
		if(t==1)
		{
			scanf("%I64d%I64d",&x,&k);
			ll lv=find_level(x);
			ll num=pow2[lv];
			shiftv[lv]=((shiftv[lv]+k)%num+num)%num;
		}
		else if(t==2)
		{
			scanf("%I64d%I64d",&x,&k);
			ll lv=find_level(x);
			ll num=pow2[lv];
			shifts[lv]=((shifts[lv]+k)%num+num)%num;
		}
		else
		{
			scanf("%I64d",&x);
			ll lv=find_level(x);
			printf("%I64d ",x);
			x=(((x-pow2[lv]+shiftv[lv]+shifts[lv])%pow2[lv])+pow2[lv])%pow2[lv]+pow2[lv];
			while(x>1)
			{
				x=x/2;
				lv--;
				printf("%I64d ",((x-pow2[lv]-shiftv[lv])%pow2[lv]+pow2[lv])%pow2[lv]+pow2[lv]);
				x=(x-pow2[lv]+shifts[lv])%pow2[lv]+pow2[lv];
			}
			puts("");
		}
	}
	return 0;
}