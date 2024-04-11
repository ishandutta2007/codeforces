#include<bits/stdc++.h>
#define ll long long
#define int long long
using namespace std;
struct gogo
{
	int x,y;	
};
bool operator<(const gogo &a,const gogo &b)
{
	return a.y*b.x < a.x*b.y; 
}
gogo b[32];
int n;
int l;
main()
{
	scanf("%lld %lld",&n,&l);
	for(int i = 0;i<n;i++)
	{
		int x;
		scanf("%lld",&x);
		b[i]=(gogo){(1<<i),x};
	}
	sort(b,b+n);
	ll ans = 0;
	ll best = (ll)b[0].y*l;
	for(int i = 0;i<n;i++)
	{
		if (l==0) break;
		int t = b[i].x;
		int s = b[i].y;
		ll gi = ans + (ll)(1+(l-1)/t)*s;
		best = min(best,gi);
		ans += (l/t) * s;
		l -= (l/t)*t ;
	}
	ans = min(best,ans);
	printf("%lld\n",ans);
	return 0;
}