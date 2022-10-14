#include<bits/stdc++.h>
#define ll long long
#define mk make_pair
using namespace std;
const int N=4e5+5;
int T;
int n,m,k;
ll ans=0;

typedef pair<int,pair<int,int> > pip;
vector<pip> edge;
int pa[N];

int getpa(int x)
{
	return pa[x]==x ? x:pa[x]=getpa(pa[x]);
}

void work()
{
	int x,y,w;
	ans=0;
	int cnt=0;
	int mind=0x3f3f3f3f;
	cin>>n>>m>>k;
	for (int i=1;i<=n;i++)
			pa[i]=i;
	edge.clear();
	for (int i=0;i<m;i++)
	{
		scanf("%d%d%d",&x,&y,&w);
		mind=min(mind,abs(w-k));
		edge.push_back({w,{x,y}});
	}
	sort(edge.begin(),edge.end());
	for (int i=0;i<m;i++)
	{
		int px=getpa(edge[i].second.first);
		int py=getpa(edge[i].second.second);
		if (px==py)
			continue;
		pa[px]=py;
		cnt++;
		if (edge[i].first>k)
			ans+=edge[i].first-k;
		if (cnt==n-1)
		{
			if (edge[i].first<=k)
			{
				cout<<mind<<endl;
				return;
			}
			else
			{
				cout<<ans<<endl;
				return;
			}
		}
	}
}

int main()
{
	scanf("%d",&T);
	while(T--)
	{
		work();
	}
	return 0;
}