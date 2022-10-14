#include <bits/stdc++.h>
#define DB double
#define LL long long

#define MST(a,b) memset((a),(b),sizeof(a))
#define MRK() cout<<"Mark"<<endl;
#define WRT(x) cout<<#x<<" = "<<(x)<<endl;

#define MAXN 210000
#define MAXM 10000
#define MOD 998244353
#define INF 0x3f3f3f3f
#define LLINF 0x3f3f3f3f3f3f3f3f
#define EPS 1e-5

#define _ 0
using namespace std;

int visit[MAXN];
int ans[MAXN];
queue<int> q;
int a[MAXN];
int n;

vector<int> g[MAXN];

int main()
{
	int n;
	cin>>n;
	for (int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	for (int i=1;i<=n;i++)
	{
		if (a[i]&1)
		{
			q.push(i);
			visit[i]=1;
		}
		if (i-a[i]>=1)
			g[i-a[i]].push_back(i);
		if (i+a[i]<=n)
			g[i+a[i]].push_back(i);
	}
	while (!q.empty())
	{
		int pos=q.front();
		q.pop();
		for (auto p:g[pos])
			if (!visit[p])
			{
				q.push(p);
				ans[p]=visit[p]=visit[pos]+1;
			}
	}
	MST(visit,0);
	for (int i=1;i<=n;i++)
		if (!(a[i]&1))
		{
			q.push(i);
			visit[i]=1;
		}
	while (!q.empty())
	{
		int pos=q.front();
		q.pop();
		for (auto p:g[pos])
			if (!visit[p])
			{
				q.push(p);
				ans[p]=visit[p]=visit[pos]+1;
			}
	}
	for (int i=1;i<=n;i++)
		cout<<ans[i]-1<<' ';
	return ~~(0^_^0);
}