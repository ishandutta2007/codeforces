#include<bits/stdc++.h>
#define MAXN 200005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
#define RAND_MAX 0x7fffu   
using namespace std;
typedef long long ll;
typedef pair<ll,ll> P;
ll n,k;
P a[MAXN];
P b[MAXN];
int main()
{
	srand((unsigned)time(NULL));
	scanf("%I64d",&n);
	for(ll i=1;i<=n;i++)
		scanf("%I64d%I64d",&a[i].F,&a[i].S);
	if(n<=3)
	{
		puts("YES");
		return 0;
	}
	for(ll i=1;i<=300;i++)
	{
		ll res1=(rand()%n)+1;
		ll res2=(rand()%n)+1;
		while(res1==res2) res2=(rand()%n)+1;
		//printf("%I64d\n",res);
		ll t=0;
		for(ll j=1;j<=n;j++)
		{
			if(j==res1||j==res2) continue;
			ll x1=a[j].F-a[res1].F,y1=a[j].S-a[res1].S,x2=a[res2].F-a[res1].F,y2=a[res2].S-a[res1].S;
			if(x1*y2!=x2*y1) b[t++]=a[j]; 
		}
		if(t<=2) {puts("YES"); return 0;}
		bool f=true;
		for(ll j=2;j<t;j++)
		{
			ll x1=b[j].F-b[0].F,y1=b[j].S-b[0].S,x2=b[1].F-b[0].F,y2=b[1].S-b[0].S;
			if(x1*y2!=x2*y1) {f=false; break;}
		}
		if(f) {puts("YES"); return 0;}
	}
	puts("NO");
	return 0;
}