#include <bits/stdc++.h>
#define DB double
#define LL long long
#define ULL unsigned long long

#define MST(a,b) memset((a),(b),sizeof(a))
#define MRK() cout<<"Mark"<<endl;
#define WRT(x) cout<<#x<<" = "<<(x)<<endl;

#define MAXN 510000
#define MAXM 410000
#define MOD 998244353
#define INF 0x3f3f3f3f
#define LLINF 0x3f3f3f3f3f3f3f3f
#define EPS 1e-5

#define _ 0
using namespace std;

LL gcd(LL x,LL y)
{
	if (x<y)
		swap(x,y); 
	if (y==0)
		return x;
	return gcd(y,x%y);
}

vector<int> g[MAXN];
int t;
int n,m;
LL c[MAXN];
int u,v;
ULL hash1[MAXN],hash2[MAXN];
typedef pair<ULL,ULL> pll;
map<vector<int>,LL> mp;
 
int main()
{
	cin>>t;
	while (t--)
	{
		mp.clear();
		scanf("%d%d",&n,&m); 
		for (int i=1;i<=n;i++)
		{
			g[i].clear();
			scanf("%lld",&c[i]);
		}
		while (m--)
		{
			scanf("%d%d",&u,&v);
			g[v].push_back(u);
		}
		
		for (int i=1;i<=n;i++)
		{
			sort(g[i].begin(),g[i].end());
			if (g[i].size())
				mp[g[i]]+=c[i];
		}
		LL ans=0;
		for (auto p:mp)
		{
			ans=gcd(ans,p.second);
			//WRT(p.second);
		}
                cout<<ans<<endl;
	}
	return ~~(0^_^0);
}