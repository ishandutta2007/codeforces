#include <bits/stdc++.h>
#define DB double
#define LL long long

#define MST(a,b) memset((a),(b),sizeof(a))
#define MRK() cout<<"Mark"<<endl;
#define WRT(x) cout<<#x<<" = "<<(x)<<endl;

#define MAXN 1010000
#define MAXM 410000
#define MOD 998244353
#define INF 0x3f3f3f3f
#define LLINF 0x3f3f3f3f3f3f3f3f
#define EPS 1e-5

#define _ 0
using namespace std;

int factor[MAXN];
int a[MAXN];
vector<int> g[MAXN];
int n;
int depth[MAXN];
int ans=INF;
int visit[MAXN]; 
int lst[MAXN];

int main()
{
	factor[1]=1;
	for (int i=2;i<=1000000;i++)
		if (factor[i]==0)
			for (int j=i;j<=1000000;j+=i)
				if (!factor[j])
					factor[j]=i;
	//for (int i=1;i<=100;i++)
	//	cout<<i<<' '<<factor[i]<<endl;
	cin>>n;
	int x,y;
	int cnt=0;
	for (int i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
		x=factor[a[i]];
		cnt=0;
		while (factor[a[i]]==x && x!=1)
		{
			a[i]/=x;
			cnt++;
		}
		x=(cnt&1) ? x:1;
		cnt=0;
		y=factor[a[i]];
		while (factor[a[i]]==y && y!=1)
		{
			a[i]/=y;
			cnt++;
		}
		y=(cnt&1) ? y:1;
		//cout<<x<<'-'<<y<<endl;
		if (x==y)
		{
			cout<<1;
			return 0;
		}
		g[x].push_back(y);
		g[y].push_back(x);
	}
	for (int i=1;i<=1000;i++)
	{
		visit[i]=i;
		depth[i]=0;
		lst[i]=0;
		queue<int> q;
		q.push(i);
		while (!q.empty())
		{
			int pos=q.front();
			q.pop();
			for (auto p:g[pos])
				if (p!=lst[pos])
					if (visit[p]==i)
						ans=min(ans,depth[pos]+depth[p]+1);
					else
					{
						visit[p]=i;
						depth[p]=depth[pos]+1;
						lst[p]=pos;
						q.push(p);
					}
		}
	}
	if (ans==INF)
		cout<<-1;
	else
		cout<<ans;
	return ~~(0^_^0);
}