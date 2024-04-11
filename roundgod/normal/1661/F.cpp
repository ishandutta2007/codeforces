#pragma GCC optimize(3)
#include<bits/stdc++.h>
#define MAXN 200005
#define INF 1000000000000000000LL
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<ll,int> P;
int n,a[MAXN];
int used[MAXN];
ll res[MAXN];
ll m;
ll calc(int len,int num)
{
	int x=len/(num+1);
	int rem=len%(num+1);
	return 1LL*(num+1-rem)*x*x+1LL*rem*(x+1)*(x+1);
}
pair<ll,int> check(ll x)
{
	ll res=0; int num=0;
	for(int i=1;i<=n;i++)
	{
		int dif=a[i]-a[i-1];
		if(dif==1) {res+=calc(dif,0); continue;}
		int l=0,r=dif;
		while(r-l>1)
		{
			int mid=(l+r)/2;
			if(calc(dif,mid-1)-calc(dif,mid)>=x) l=mid; else r=mid;
		}
		res+=calc(dif,l); num+=l;
	}	
	return make_pair(res,num);
}
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++) scanf("%d",&a[i]);
	scanf("%lld",&m);
	ll l=-1,r=INF;
	while(r-l>1)
	{
		ll mid=(l+r)/2;
		if(check(mid).F<=m) l=mid; else r=mid;
	}
	P p=check(l);
	int cnt=p.S;
	printf("%lld\n",cnt-(m-p.F)/l);
}