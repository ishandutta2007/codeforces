#include<bits/stdc++.h>
#define MAXN 200005
#define INF 1000000000
#define MOD 1000000007
#define x first
#define y second
using namespace std;
typedef long long ll;
typedef pair<ll,ll> P;
ll n;
P a[MAXN];
int main()
{
	scanf("%I64d",&n);
	for(ll i=0;i<n;i++) scanf("%I64d%I64d",&a[i].x,&a[i].y);
	sort(a,a+n);
	ll cnt=1,ans=0;
	for(ll i=1;i<n;i++)
	{
		if(a[i].x==a[i-1].x) cnt++;
		else
		{
			ans+=cnt*(cnt-1)/2;
			cnt=1;
		}
	}
	ans+=cnt*(cnt-1)/2;
	for(ll i=0;i<n;i++) swap(a[i].x,a[i].y);
	sort(a,a+n);
	cnt=1;
	for(ll i=1;i<n;i++)
	{
		if(a[i].x==a[i-1].x) cnt++;
		else
		{
			ans+=cnt*(cnt-1)/2;
			cnt=1;
		}
	}
	ans+=cnt*(cnt-1)/2;	
	cnt=1;
	for(ll i=1;i<n;i++)
	{
		if(a[i].x==a[i-1].x&&a[i].y==a[i-1].y) cnt++;
		else
		{
			ans-=cnt*(cnt-1)/2;
			cnt=1;
		}
	}
	ans-=cnt*(cnt-1)/2;
	printf("%I64d\n",ans);
	return 0;
}