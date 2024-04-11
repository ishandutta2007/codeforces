#include <bits/stdc++.h>
#define INL inline
#define REG register
#define DB double
#define LDB long double
#define ULL unsigned long long
#define LL long long

#define RPT(i,x,y) for (REG int i=(x);i<(y);i++)
#define DRPT(i,x,y) for (REG int i=(x);i>(y);i--)
#define MST(a,b) memset((a),(b),sizeof(a))
#define MRK() cout<<"Mark"<<endl; 
#define WRT(x) cout<<#x<<" = "<<(x)<<endl;
#define LINK(i,graph,pos) for (REG int i=graph.head[pos];i;i=graph.next[i])

#define MAXN 300100
#define MAXM 1010000
#define MOD 1000000007
#define INF 0x3f3f3f3f
#define LLINF 0x3f3f3f3f3f3f3f3f
#define EPS 1e-5

#define _ 0
using namespace std;


class GRAPH 
{
	public:
		int to[MAXM],next[MAXM];
		int head[MAXN];
		int cnt;
		
	GRAPH()
	{
		cnt=1;
	} 
	
	void add(int x,int y)
	{
		//cout<<x<<'-'<<y<<endl;
		next[cnt]=head[x];
		to[cnt]=y;
		head[x]=cnt++;
	}
};

GRAPH g;

int n;
int dp[MAXN];
int ans=0;

void init()
{
	ans=0;
	int x,y;
	memset(g.head,0,sizeof(int)*(n+5));
	cin>>n;
	g.cnt=1;
	for (int i=1;i<n;i++)
	{
		scanf("%d%d",&x,&y);
		g.add(x,y);
		g.add(y,x);
	}
}

void dfs(int pos,int pa)
{
	vector<int> v;
	int mx=0;
	dp[pos]=1;
	LINK(i,g,pos)
		if (g.to[i]!=pa)
		{
			dfs(g.to[i],pos);
			v.push_back(dp[g.to[i]]);
			mx=max(mx,dp[g.to[i]]);
		}
	dp[pos]+=mx;
	if (v.size()>=2)
		dp[pos]+=v.size()-1;
	if (pos!=pa)
		v.push_back(1);
	sort(v.begin(),v.end(),greater<int>());
	ans=max(ans,dp[pos]);
	if (v.size()>=2)
		ans=max(ans,v[0]+v[1]-1+(int)v.size());
	//if (v.size()>=2) 
	//	cout<<pos<<' '<<v[0]+v[1]-1+(int)v.size()<<endl;
}


int main()
{
	int t;
	cin>>t;
	while (t--)
	{
		init();
		dfs(1,1);
		cout<<ans<<endl;
	}
	return ~~(0^_^0);
}