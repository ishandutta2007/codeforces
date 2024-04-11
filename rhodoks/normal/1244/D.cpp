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

#define MAXN 100100
#define MAXM 201000
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
		next[cnt]=head[x];
		to[cnt]=y;
		head[x]=cnt++;
	}
};

GRAPH g;

int c[3][101000];
int deg[101000];
int n;
vector<int> v;
LL dp[16][101000];
int lst[16][101000];
int col[101000];
void dfs(int pos,int f)
{
	v.push_back(pos);
	LINK(i,g,pos)
		if (g.to[i]!=f)
			dfs(g.to[i],pos);
}

int main()
{
	int tmp;
	int x,y;
	cin>>n;
	for (int i=0;i<3;i++)
		for (int j=1;j<=n;j++)
			scanf("%d",&c[i][j]);
	for (int i=0;i<n-1;i++)
	{
		scanf("%d%d",&x,&y);
		g.add(x,y);
		g.add(y,x);
		deg[x]++;
		deg[y]++;
		if (deg[x]>=3 || deg[y]>=3)
		{
			cout<<-1;
			return 0;
		}
	}
	for (int i=1;i<=n;i++)
		if (deg[i]==1)
		{
			tmp=i;
			break;
		}
	dfs(tmp,tmp);
	MST(dp,INF);
	int pos=0;
	dp[0][0]=0;
	//WRT(v[0]);
	for (auto p:v)
	{
		pos++;
		for (int i=0;i<3;i++)
		{
			for (int j=0;j<16;j++)
				if (((j%4)!=i+1) && ((j/4)!=i+1))
				{
					if (dp[j][pos-1]+c[i][p]<dp[((j%4)<<2)+i+1][pos])
					{
						dp[((j%4)<<2)+i+1][pos]=dp[j][pos-1]+c[i][p];
						lst[((j%4)<<2)+i+1][pos]=j;
					}
				}
		}
	}
	LL mi=LLINF;
	int r;
	for (int i=0;i<16;i++)
		if (dp[i][n]<mi)
		{
			mi=dp[i][n];
			r=i;
		}
	cout<<mi<<endl;
	pos=n;
	for (int i=n-1;i>=0;i--)
	{
		col[v[i]]=r%4;
	//col[v[0]]=r/4;
		r=lst[r][pos];
		pos--;
	}
	for (int i=1;i<=n;i++)
		cout<<col[i]<<' ';
	return ~~(0^_^0);
}