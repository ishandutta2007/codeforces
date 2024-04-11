#include<bits/stdc++.h>
#define MAXN 200005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int t,n,k,a[MAXN];
vector<int> v,res;
int main()
{
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		for(int i=1;i<=n;i++)
		{
			scanf("%d",&a[i]);
		}
		a[n+1]=INF;
		v.clear(); res.clear();
		for(int i=2;i<=n-1;i++)
		{
			if(a[i]>a[i-1]&&a[i]>a[i+1]) v.push_back(i);
		}
		int ans=0,now=0;
		while(now<(int)v.size())
		{
			res.push_back(v[now]);
			if(now<(int)v.size()-1&&v[now+1]-v[now]<=2)
			{
				now+=2;
			}
			else now++;
			ans++;
		}
		printf("%d\n",ans);
		for(auto pos:res) a[pos+1]=max(a[pos],a[pos+2]);
		for(int i=1;i<=n;i++) printf("%d ",a[i]);
		puts("");
	}
	return 0;
}