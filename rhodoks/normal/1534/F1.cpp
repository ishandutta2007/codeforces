#include <bits/stdc++.h>
#define INL inline
#define REG register
#define DB double
#define LDB long double
#define ULL unsigned long long
#define LL long long

#define RPT(i,x,y) for (REG int i=x;i<y;i++)
#define DRPT(i,x,y) for (REG int i=x;i>y;i--)
#define MST(a,b) memset(a,b,sizeof(a))
#define LINK(i,graph,pos) for (REG int i=graph.head[pos];i;i=graph.next[i])

#define MAXN 1000100
#define MAXM 8000100
#define MOD 998244353
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
		//cout<<x<<' '<<y<<endl;
		next[cnt]=head[x];
		to[cnt]=y;
		head[x]=cnt++;
	}
};

GRAPH g,g1;

int n,m;
bool instak[MAXN];
int stak[MAXN];
int dfn[MAXN];
int low[MAXN];
int color[MAXN];
int cnt;
int tim;

int r,c;
string s[MAXN];
int mp(int x,int y)
{
	return x*c+y+1;
}
int lst[MAXN];

bool check(int x,int y)
{
	return x>=0 && x<r && y>=0 && y<c;
}

int blank=0;
void init()
{
	cin>>r>>c;
	n=r*c;
	for (int i=0;i<r;i++)
		cin>>s[i];
	for (int i=0;i<r;i++)
		for (int j=0;j<c;j++)
			if (s[i][j]=='.')
				blank++;
	for (int i=0;i<=c+10;i++)
		lst[i]=-1;
	for (int i=r-1;i>=0;i--)
	{
		for (int j=0;j<c;j++)
		{
			int pos=mp(i,j);
			if (s[i][j]!='#')
				continue;
			if (lst[j]!=-1)
				g.add(pos,mp(lst[j],j-1));
			if (lst[j+1]!=-1)
				g.add(pos,mp(lst[j+1],j));
			if (lst[j+2]!=-1)
				g.add(pos,mp(lst[j+2],j+1));
			//continue;
			if (check(i-1,j) && s[i-1][j]=='#')
				g.add(pos,mp(i-1,j)); 
			if (check(i+1,j) && s[i+1][j]=='#')
				g.add(pos,mp(i+1,j)); 
			if (check(i,j-1) && s[i][j-1]=='#')
				g.add(pos,mp(i,j-1)); 
			if (check(i,j+1) && s[i][j+1]=='#')
				g.add(pos,mp(i,j+1)); 
		}
		for (int j=0;j<c;j++)
			if (s[i][j]=='#')
				lst[j+1]=i;
	}
	for (int i=1;i<=n;i++)
		color[i]=i;
}

void tarjan(int x)
{
	stak[++cnt]=x;
	instak[x]=true;
	low[x]=dfn[x]=++tim;
	LINK(i,g,x)
	{
		int to=g.to[i];
		if (!dfn[to])
		{
			tarjan(to);
			low[x]=min(low[x],low[to]);
		}
		else
			if (instak[to])
				low[x]=min(low[x],dfn[to]);
	}
	if (dfn[x]==low[x])
		do
		{
			color[stak[cnt]]=x;
			instak[stak[cnt]]=false;
		}
		while (stak[cnt--]!=x);
}

int indeg[MAXN];
int main()
{
	init();
	RPT(i,1,n+1)
		if (dfn[i]==0)
			tarjan(i);
	RPT(i,1,n+1)
		LINK(j,g,i)
		{
			if (color[i]==color[g.to[j]])
				continue;
			//cout<<color[g.to[j]]<<endl;
			indeg[color[g.to[j]]]++;
		}
	//cout<<n<<' '<<blank<<endl;
	int ans=0;
	for (int i=0;i<r;i++)
		for (int j=0;j<c;j++)
		{
			int pos=mp(i,j);
			//cout<<i<<' '<<j<<' '<<s[i][j]<<' '<<pos<<' '<<color[pos]<<' '<<indeg[pos]<<endl;
			if (color[pos]==pos && indeg[pos]==0 && s[i][j]=='#')
				ans++;
		}
		//cout<<g.cnt<<endl;
	cout<<ans<<endl;
	
	return ~~(0^_^0);
}