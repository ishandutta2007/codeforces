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

#define MAXN 401000
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

GRAPH g,gr;

int n,m;
int mi1[MAXN],mi2[MAXN];
int in[MAXN],out[MAXN];
void init()
{
	cin>>n>>m;
	MST(mi1,INF);
	MST(mi2,INF);
	int x,y;
	for (int i=0;i<m;i++)
	{
		scanf("%d%d",&x,&y);
		g.add(x,y);
		gr.add(y,x);
		in[y]++;
		out[x]++;
	}
}

void topo1()
{
	queue<int> q;
	for (int i=1;i<=n;i++)
		if (in[i]==0)
			q.push(i);
	int cnt=0;
	while (!q.empty())
	{
		int pos=q.front();
		mi1[pos]=min(mi1[pos],pos);
		cnt++; 
		q.pop();
		LINK(i,g,pos)
		{
			mi1[g.to[i]]=min(mi1[g.to[i]],mi1[pos]);
			in[g.to[i]]--;
			if (in[g.to[i]]==0)
				q.push(g.to[i]);
		}
	}
	if (cnt!=n)
	{
		cout<<-1;
		exit(0);
	}
}

void topo2()
{
	queue<int> q;
	for (int i=1;i<=n;i++)
		if (out[i]==0)
			q.push(i);
	while (!q.empty())
	{
		int pos=q.front();
		mi2[pos]=min(mi2[pos],pos);
		q.pop();
		LINK(i,gr,pos)
		{
			mi2[gr.to[i]]=min(mi2[gr.to[i]],mi2[pos]);
			out[gr.to[i]]--;
			if (out[gr.to[i]]==0)
				q.push(gr.to[i]);
		}
	}
}

char s[MAXN];
int main()
{
	init();
	topo1();
	topo2();
	int ans=0;
	for (int i=1;i<=n;i++)
	{
		//cout<<i<<' '<<mi[i]<<endl;
		if (min(mi1[i],mi2[i])>=i)
		{
			s[i-1]='A';
			ans++;
		}
		else
			s[i-1]='E';
	}
	cout<<ans<<endl<<s<<endl;
	return ~~(0^_^0);
}