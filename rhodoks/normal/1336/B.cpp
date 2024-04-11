#include <bits/stdc++.h>
#define DB double
#define LL long long

#define MST(a,b) memset((a),(b),sizeof(a))
#define MRK() cout<<"Mark"<<endl;
#define WRT(x) cout<<#x<<" = "<<(x)<<endl;

#define MAXN 210000
#define MAXM 410000
#define MOD 998244353
#define INF 0x3f3f3f3f
#define LLINF 0x3f3f3f3f3f3f3f3f
#define EPS 1e-5

#define _ 0
using namespace std;

vector<int> r,g,b;
int nr,ng,nb;

LL getans(vector<int> &g,vector<int> &r,vector<int> &b)
{
	LL ans=LLINF;
	for (auto p:g)
	{
		int x,y;
		auto xptr=lower_bound(r.begin(),r.end(),p);
		auto yptr=(--upper_bound(b.begin(),b.end(),p+1));
		if (xptr!=r.end() && yptr>=b.begin())
		{
			x=*xptr;
			y=*yptr;
			ans=min(ans,(LL)(p-x)*(p-x)+(LL)(p-y)*(p-y)+(LL)(y-x)*(y-x));
		}
		
		
		xptr=lower_bound(b.begin(),b.end(),p);
		yptr=(--upper_bound(r.begin(),r.end(),p+1));
		if (xptr!=b.end() && yptr>=r.begin())
		{
			x=*xptr;
			y=*yptr;
			ans=min(ans,(LL)(p-x)*(p-x)+(LL)(p-y)*(p-y)+(LL)(y-x)*(y-x));
		}
	}
	return ans;
}

void work()
{
	int x;
	cin>>nr>>ng>>nb;
	r.clear();
	g.clear();
	b.clear();
	while (nr--)
	{
		scanf("%d",&x);
		r.push_back(x);
	}
	while (ng--)
	{
		scanf("%d",&x);
		g.push_back(x);
	}
	while (nb--)
	{
		scanf("%d",&x);
		b.push_back(x);
	}
	sort(r.begin(),r.end());
	sort(g.begin(),g.end());
	sort(b.begin(),b.end());
	LL ans=LLINF;
	ans=min(ans,getans(r,g,b));
	ans=min(ans,getans(g,r,b));
	ans=min(ans,getans(b,g,r));
	cout<<ans<<endl;
}

int main()
{
	int t;
	cin>>t;
	while (t--)
		work();
	return ~~(0^_^0);
}