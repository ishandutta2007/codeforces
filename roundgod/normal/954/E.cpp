#include<bits/stdc++.h>
#define MAXN 300005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<ll,ll> P;
ll abx(ll x) {return max(-x,x);}
ll n,T;
ll a[MAXN];
P a1[MAXN],a2[MAXN];
int main()
{
	scanf("%I64d",&n);
	scanf("%I64d",&T);
	for(int i=1;i<=n;i++)
		scanf("%I64d",&a[i]);
	int t1=0,t2=0;
	double ans=0;
	ll x;
	for(int i=1;i<=n;i++)
	{
		scanf("%I64d",&x);
		x-=T;
		if(x==0) ans+=a[i];
		if(x>0) {a1[t1].F=x; a1[t1].S=a[i]; t1++;}
		if(x<0) {a2[t2].F=-x; a2[t2].S=a[i]; t2++;}
	}
	if(t1==0||t2==0)
	{
		printf("%.15f\n",(double)ans);
		return 0;
	}
	sort(a1,a1+t1);
	sort(a2,a2+t2);
	ll sum=0;
	for(int i=0;i<t1;i++)
	{
		sum+=a1[i].F*a1[i].S;
		ans+=a1[i].S;
	}
	for(int i=0;i<t2;i++)
	{
		sum-=a2[i].F*a2[i].S;
		ans+=a2[i].S;
	}
	//printf("%I64d %.15f\n",sum,ans);
	if(sum>0)
	{
		for(int i=t1-1;i>=0;i--)
		{
			if(sum>a1[i].F*a1[i].S) {sum-=a1[i].F*a1[i].S; ans-=a1[i].S;}
			else {ans-=(double)sum/(double)a1[i].F; break;}
		}
	}
	if(sum<0)
	{
		for(int i=t2-1;i>=0;i--)
		{
			if(sum+a2[i].F*a2[i].S<0) {sum+=a2[i].F*a2[i].S; ans-=a2[i].S;}
			else {ans+=(double)sum/(double)a2[i].F; break;}
		}
	}
	printf("%.15f\n",ans);
	return 0;
}