#include<bits/stdc++.h>
#define MAXN 100005
#define INF 1000000000
#define INF2 100000000000000000LL
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int l,n;
int a[MAXN],choice[MAXN];
P valid[MAXN];
int main()
{
	scanf("%d%d",&l,&n);
	a[0]=0; a[n+1]=l;
	for(int i=1;i<=n;i++) scanf("%d",&a[i]);
	if(n==1)
	{
		printf("%d %d\n",0,l);
		return 0;
	}
	int maxi=0;
	for(int i=1;i<=n;i++) maxi=max(maxi,(a[i]+i-1)/i);
	for(int i=n;i>=1;i--) maxi=max(maxi,(l-a[i]+n-i)/(n-i+1));
	int lb=0,rb=INF;
	while(rb-lb>1)
	{
		int mid=(lb+rb)/2;
		ll tmin=INF2;
		bool f=true;
		for(int i=2;i<=n-1;i++)
		{
			ll x=a[i]-1LL*mid*(i+1);
			if(x>tmin) {f=false; break;} else tmin=min(tmin,a[i]-1LL*mid*i);
		}
		if(f) rb=mid; else lb=mid;
	}
	maxi=max(maxi,rb);
	int mini=INF;
	lb=0,rb=INF;
	while(rb-lb>1)
	{
		int mid=(lb+rb)/2;
		ll tmax=-INF2;
		bool f=true;
		for(int i=0;i<=n-1;i++)
		{
			ll x=a[i]-1LL*mid*i;
			tmax=max(tmax,x);
			if(tmax>1LL*a[i+2]-1LL*mid*(i+1)) {f=false; break;} 
		}
		if(f) lb=mid; else rb=mid;
	}
	mini=lb;
	assert(mini<=maxi);
	//printf("%d %d\n",mini,maxi);
	int last=0;
	for(int i=1;i<=n-1;i++)
	{
		int lb=mini-(i==1?a[1]:a[i]-a[i-1]-valid[i-1].F);
		int rb=maxi-(i==1?a[1]:a[i]-a[i-1]-valid[i-1].S);
		lb=max(lb,0); rb=min(rb,a[i+1]-a[i]);
		if(i==n-1)
		{
			int lastlb=mini-(l-a[n]),lastrb=(maxi-(l-a[n]));
			lb=max(lb,a[n]-a[i]-lastrb);
			rb=min(rb,a[n]-a[i]-lastlb);
		}
		assert(lb<=rb);
		valid[i]=P(lb,rb);
		//printf("%d %d %d\n",i,valid[i].F,valid[i].S);
	}
	vector<P> v;
	choice[n]=a[n+1]-a[n];
	for(int i=n-1;i>=1;i--)
	{
		int lb=valid[i].F,rb=valid[i].S;
		int lastlb=mini-choice[i+1],lastrb=maxi-choice[i+1];
		lb=max(lb,a[i+1]-a[i]-lastrb);
		rb=min(rb,a[i+1]-a[i]-lastlb);
		assert(lb<=rb);
		choice[i]=lb;
		v.push_back(P(a[i]+choice[i],a[i+1]+choice[i+1]));
	}
	v.push_back(P(0,a[1]+choice[1]));
	reverse(v.begin(),v.end());
	for(auto p:v) printf("%d %d\n",p.F,p.S);
	return 0;
}