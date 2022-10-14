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

vector<int> g[MAXN];
int n,m,k;
int depth[MAXN];
int stak[MAXN];
int visit[MAXN]; 
queue<int> q;
void dfs(int pos,int f)
{
	depth[pos]=depth[f]+1;
	stak[depth[pos]]=pos;
	int cnt=0;
	for (auto p:g[pos])
		if (p!=f)
		{
			//cout<<pos<<' '<<p<<' '<<depth[p]<<endl;
			if (depth[p] && depth[pos]-depth[p]+1>=k)
			{
				cout<<2<<endl;
				cout<<depth[pos]-depth[p]+1<<endl;
				for (int i=depth[p];i<=depth[pos];i++)
					printf("%d ",stak[i]);
				exit(0);
			}
			if (!depth[p])
			{
				dfs(p,pos);
				cnt++;
			}
		}
	if (!visit[pos])
	{
		q.push(pos);
		for (auto p:g[pos])
			visit[p]=1;
	}
}

int main()
{
	int x,y;
	cin>>n>>m;
	k=(int)sqrt(n-1)+1;
	//WRT(k);
	for (int i=0;i<m;i++)
	{
		scanf("%d%d",&x,&y);
		//cout<<x<<' '<<y<<endl;
		g[x].push_back(y);
		g[y].push_back(x);
	}
	dfs(1,1);
	cout<<1<<endl;
	while (k--)
	{
		cout<<q.front()<<' ';
		q.pop();
	}
	return ~~(0^_^0);
}