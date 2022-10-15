#include<bits/stdc++.h>
#define MAXN 200005
#define INF 2000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int t,n,a[MAXN],b[MAXN];
int main()
{
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		for(int i=1;i<=n;i++) scanf("%d",&a[i]);
		for(int i=1;i<=n;i++) scanf("%d",&b[i]);
		vector<P> v;
		int cost=INF;
		for(int i=1;i<=n;i++) cost=min(cost,abs(b[i]-a[1]));
		v.push_back(make_pair(cost,1));
		cost=INF;
		for(int i=1;i<=n;i++) cost=min(cost,abs(b[i]-a[n]));
		v.push_back(make_pair(cost,2));
		cost=INF;
		for(int i=1;i<=n;i++) cost=min(cost,abs(a[i]-b[1]));
		v.push_back(make_pair(cost,4));
		cost=INF;
		for(int i=1;i<=n;i++) cost=min(cost,abs(a[i]-b[n]));
		v.push_back(make_pair(cost,8));
		v.push_back(make_pair(abs(a[1]-b[1]),5));
		v.push_back(make_pair(abs(a[1]-b[n]),9));
		v.push_back(make_pair(abs(a[n]-b[1]),6));
		v.push_back(make_pair(abs(a[n]-b[n]),10));
		ll ans=1LL*INF*INF;
		for(int i=0;i<(1<<8);i++)
		{
			ll sum=0; int mask=0;
			for(int j=0;j<8;j++) 
				if(i&(1<<j))
				{
					sum+=v[j].F;
					mask|=v[j].S;
				}
			if(mask==15) ans=min(ans,sum);
		}
		printf("%lld\n",ans);
	}
	return 0;
	return 0;
}