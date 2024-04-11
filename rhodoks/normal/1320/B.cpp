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

#define MAXN 1001000
#define MAXM 2010000
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

GRAPH gr;
int n,m;
int dis[MAXN],num[MAXN];
int k;
vector<int> p;
int s,t;
void init()
{
	MST(dis,INF);
	cin>>n>>m;
	int x,y;
	for (int i=0;i<m;i++)
	{
		scanf("%d%d",&x,&y);
		gr.add(y,x);
		//g.add(x,y);
	}
	cin>>k;
	for (int i=0;i<k;i++)
	{
		scanf("%d",&x);
		p.push_back(x);
	}
	s=p[0];
	t=p[k-1];
}


int main()
{
	init();
	queue<int> q;
	q.push(t);
	num[t]=1;
	dis[t]=0;
	while (!q.empty())
	{
		int pos=q.front();
		q.pop();
		LINK(i,gr,pos)
		{
			int to=gr.to[i];
			if (dis[pos]+1==dis[to])
			{
				num[to]+=1;
			}
			else if (dis[pos]+1<dis[to])
			{
				num[to]=1;
				dis[to]=dis[pos]+1;
				q.push(to);
			}
		}
	}
	//for (int i=1;i<=n;i++)
	//	cout<<i<<' '<<dis[i]<<' '<<num[i]<<endl;
	int ans1=0,ans2=0;
	for (int i=1;i<k;i++)
	{
		if (dis[p[i]]+1==dis[p[i-1]])
		{
			if (num[p[i-1]]>=2)
				ans2++;
		}
		else
		{
			ans1++;
			ans2++;
		}
	}
	cout<<ans1<<' '<<ans2<<endl;
	return ~~(0^_^0);
}