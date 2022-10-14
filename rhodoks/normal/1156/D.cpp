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

#define MAXN 210000
#define MAXM 410000
#define MOD 998244353
#define INF 0x3f3f3f3f
#define LLINF 0x3f3f3f3f3f3f3f3f
#define EPS 1e-5

#define _ 0
using namespace std;


class GRAPH 
{
	public:
		int to[MAXM],next[MAXM],weight[MAXM];
		int head[MAXN];
		int cnt;
		
	GRAPH()
	{
		cnt=1;
	} 
	
	void add(int x,int y,int z)
	{
		next[cnt]=head[x];
		weight[cnt]=z;
		to[cnt]=y;
		head[x]=cnt++;
	}
};

GRAPH g;

LL dp1[MAXN][2],dp2[MAXN][2];
LL n;

LL ans=0;

void init()
{
	cin>>n;
	int x,y,z;
	RPT(i,0,n-1)
	{
		scanf("%d%d%d",&x,&y,&z);
		g.add(x,y,z);
		g.add(y,x,z);
	}
}

void dfs(int pos,int fa,int from)
{
	bool flag=true;
	LINK(i,g,pos)
		if (g.to[i]!=fa)
		{
			//cout<<dp1[pos][0]<<'-'<<dp1[pos][1]<<'-'<<dp2[pos][0]<<'-'<<dp2[pos][1]<<endl;
			flag=false;
			dfs(g.to[i],pos,g.weight[i]);
			if (g.weight[i]==0)
			{
				//WRT(dp1[g.to[i]][0]);
				//WRT(dp2[g.to[i]][0]+dp2[g.to[i]][1]);
				//WRT((dp1[g.to[i]][0])*(dp2[pos][0]+dp2[pos][1])+(dp2[g.to[i]][0]+dp2[g.to[i]][1])*(dp1[pos][0]));
				ans+=(dp1[g.to[i]][0])*(dp2[pos][0]+dp2[pos][1])+(dp2[g.to[i]][0]+dp2[g.to[i]][1])*(dp1[pos][0]);
				dp1[pos][0]+=dp1[g.to[i]][0];
				dp2[pos][0]+=dp2[g.to[i]][0]+dp2[g.to[i]][1];
			}
			else
			{
				//WRT((dp1[g.to[i]][0]+dp1[g.to[i]][1])*(dp2[pos][0])+(dp2[g.to[i]][1])*(dp1[pos][0]+dp1[pos][1]));
				ans+=(dp1[g.to[i]][0]+dp1[g.to[i]][1])*(dp2[pos][1])+(dp2[g.to[i]][1])*(dp1[pos][0]+dp1[pos][1]);
				dp1[pos][1]+=dp1[g.to[i]][0]+dp1[g.to[i]][1];
				dp2[pos][1]+=dp2[g.to[i]][1];
			}
			//WRT(g.to[i]);
			//WRT(ans);
		}
	ans+=dp1[pos][0]+dp1[pos][1]+dp2[pos][0]+dp2[pos][1];
	if (from==-1)
		return;
	dp1[pos][from]+=1;
	dp2[pos][from]+=1;
	if (from==1)
	{
		dp1[pos][1]+=dp1[pos][0];
		dp1[pos][0]=0;
		dp2[pos][0]=0;
	}
	else
	{
		dp1[pos][1]=0;
		dp2[pos][0]+=dp2[pos][1];
		dp2[pos][1]=0;
	}
	//cout<<dp1[pos][0]<<' '<<dp1[pos][1]<<' '<<dp2[pos][0]<<' '<<dp2[pos][1]<<endl;
	///WRT(pos);
	//WRT(ans);
}

int main()
{
	init();
	dfs(1,0,-1);
	cout<<ans<<endl;
	//RPT(pos,1,n+1)
	//	cout<<pos<<' '<<dp1[pos][0]<<' '<<dp1[pos][1]<<' '<<dp2[pos][0]<<' '<<dp2[pos][1]<<endl;
	return ~~(0^_^0);
}