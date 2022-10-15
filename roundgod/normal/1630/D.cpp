#include<bits/stdc++.h>
#define MAXN 1000005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int t,n,m,k,a[MAXN];
int main()
{
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%d",&n,&m);
		for(int i=0;i<n;i++) scanf("%d",&a[i]);
		int g;
		scanf("%d",&g);
		for(int i=1;i<=m-1;i++)
		{
			int x;
			scanf("%d",&x);
			g=__gcd(g,x);
		}
		ll sum=0;
		for(int i=0;i<g;i++)
		{
			vector<int> tmp;
			for(int j=i;j<n;j+=g) tmp.push_back(a[j]);
			sort(tmp.begin(),tmp.end());
			for(int k=0;k<(int)tmp.size();k+=2)
			{
				if(k==(int)tmp.size()-1) sum+=tmp[k];
				else sum+=max(tmp[k]+tmp[k+1],-tmp[k]-tmp[k+1]);
			}
		}
		ll ans=0;
		for(int i=0;i<g;i++)
		{
			vector<int> tmp;
			for(int j=i;j<n;j+=g) tmp.push_back(a[j]);
			sort(tmp.begin(),tmp.end());
			ans+=-tmp[0];
			for(int k=1;k<(int)tmp.size();k+=2)
			{
				if(k==(int)tmp.size()-1) ans+=tmp[k];
				else ans+=max(tmp[k]+tmp[k+1],-tmp[k]-tmp[k+1]);
			}
		}
		ans=max(ans,sum);
		printf("%lld\n",ans);
	}
	return 0;
}