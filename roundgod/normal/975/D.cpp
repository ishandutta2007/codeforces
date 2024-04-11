#include<bits/stdc++.h>
#define MAXN 300005
#define INF 1000000000
#define MOD 1000000007
using namespace std;
typedef long long ll;
struct node
{
	ll pos,x,y;
};
ll n,a,b;
node wcy[MAXN];
bool cmp(node p,node q)
{
	if(p.x*a-p.y!=q.x*a-q.y) return p.x*a-p.y<q.x*a-q.y;
	return p.x<q.x;
}
int main()
{
	scanf("%I64d%I64d%I64d",&n,&a,&b);
	for(ll i=0;i<n;i++)
		scanf("%I64d%I64d%I64d",&wcy[i].pos,&wcy[i].x,&wcy[i].y);
	sort(wcy,wcy+n,cmp);
	ll cnt=1,ans=0;
	for(ll i=1;i<n;i++)
	{
		if(wcy[i].x*a-wcy[i].y==wcy[i-1].x*a-wcy[i-1].y) cnt++;
		else
		{
			ans+=cnt*(cnt-1);
			cnt=1;
		}
	}
	ans+=cnt*(cnt-1);
	cnt=1;
	for(ll i=1;i<n;i++)
	{
		if(wcy[i].x==wcy[i-1].x&&wcy[i].y==wcy[i-1].y) cnt++;
		else
		{
			ans-=cnt*(cnt-1);
			cnt=1;
		}
	}
	ans-=cnt*(cnt-1);
	printf("%I64d\n",ans);
	return 0;
}