#include <bits/stdc++.h>
#define DB double
#define LL long long

#define MST(a,b) memset((a),(b),sizeof(a))

#ifdef _DEBUG_
#define MRK() cout<<"Mark"<<endl;
#define WRT(x) cout<<#x<<" = "<<(x)<<endl;
#else
#define MRK() ;
#define WRT(x) ;
#endif

#define MAXN 2110000
#define MAXM 2010000
#define MOD 998244353  //1000000007
#define INF 0x3f3f3f3f
#define LLINF 0x3f3f3f3f3f3f3f3f
#define EPS 1e-5

#define _ 0
using namespace std;

vector<vector<int> > edge;
int n,m,q;
vector<int> g[MAXN];
int val[MAXN];
int pa[MAXN];

int getpa(int x)
{
	return pa[x]==x ? x:pa[x]=getpa(pa[x]);
}

int top[MAXN];
int son[MAXN];
int weight[MAXN];
int depth[MAXN];
int sze[MAXN];
void dfs1(int pos)
{
	sze[pos]=1;
	for (auto p:g[pos])
	{
		depth[p]=depth[pos]+1;
		pa[p]=pos;
		dfs1(p);
		sze[pos]+=sze[p];
		if (sze[p]>sze[son[pos]])
			son[pos]=p;
	}
}


void dfs2(int pos,int topf)
{
	top[pos]=topf;
	if (son[pos])
		dfs2(son[pos],topf);
	for (auto p:g[pos])
		if (p!=son[pos])
			dfs2(p,p);
}

int lca(int x,int y)
{
	if (x==0 || y==0)
		return x+y;
	while (top[x]!=top[y])
	{
    //cout<<x<<' '<<y<<' '<<top[x]<<' '<<top[y]<<' '<<depth[top[x]]<<' '<<depth[top[y]]<<endl;
		if (depth[top[x]]<depth[top[y]])
			swap(x,y);
		x=pa[top[x]];
	}
	return depth[x]>depth[y] ? y:x;
}

void init()
{

}


#define MID ((l+r)>>1)
#define LS (pos<<1)
#define RS (pos<<1|1)
class SegmentTree
{
public:
	int data[MAXN],tag[MAXN],lc[MAXN];
	
	void pushup(int pos)
	{
		data[pos]=lca(data[LS],data[RS]);
	}

	void pushdown(int pos)
	{
		if (tag[pos]==0)
		{
			tag[LS]=tag[RS]=0;
			data[LS]=data[RS]=0;
		}
		if (tag[pos]==1)
		{
			tag[LS]=tag[RS]=1;
			data[LS]=lc[LS];
			data[RS]=lc[RS];
		}
		tag[pos]=-1;
	}

	void build(int pos,int l,int r)
	{
		//cout<<pos<<endl;
		if (l==r)
		{
			tag[pos]=0;
			data[pos]=0;
			lc[pos]=l;
			return;
		}
		build(LS,l,MID);
		build(RS,MID+1,r);
        //cout<<lc[LS]<<' '<<lc[RS]<<endl;
		lc[pos]=lca(lc[LS],lc[RS]);
        //cout<<lc[pos]<<endl;
        //cout<<LS<<' '<<lc[LS]<<' '<<RS<<' '<<lc[RS]<<endl;
		pushup(pos);
        //cout<<pos<<' '<<l<<' '<<r<<' '<<lc[pos]<<' '<<data[pos]<<endl;
	}


	void modify(int pos,int l,int r,int L,int R,int x)
	{
		if (r<L || l>R)
			return;
		if (l>=L && r<=R)
		{
			if (x==1)
			{
				tag[pos]=1;
				data[pos]=lc[pos];
			}
			else
			{
				tag[pos]=0;
				data[pos]=0;
			}
			return;
		}
		pushdown(pos);
		modify(LS,l,MID,L,R,x);
		modify(RS,MID+1,r,L,R,x);
		pushup(pos);
        //cout<<pos<<' '<<l<<' '<<r<<" - "<<data[pos]<<endl;
	}

	int query()
	{
		return data[1];
	}
};

void work()
{
	int x,y,w;
	cin>>n>>q;
	for (int i=1;i<n;i++)
	{
		scanf("%d%d%d",&x,&y,&w);
		edge.push_back({w,x,y});
	}
	sort(edge.begin(), edge.end());
	for (int i=1;i<=n;i++)
	{
		pa[i]=i;
		val[i]=-1;
	}
	for (auto p:edge)
	{
		g[n+1].push_back(getpa(p[1]));
		g[n+1].push_back(getpa(p[2]));
        //cout<<n+1<<' '<<getpa(p[1])<<endl;
       // cout<<n+1<<' '<<getpa(p[2])<<endl;
		pa[getpa(p[1])]=n+1;
		pa[getpa(p[2])]=n+1;
		n++;
		val[n]=p[0];
        pa[n]=n;
	}
	dfs1(n);
	dfs2(n,n);
    //cout<<lca(4,5)<<endl;
    //for (int i=1;i<=n;i++)
     //   cout<<
	SegmentTree sgt;
	sgt.build(1,1,n);
	while (q--)
	{
		scanf("%d",&w);
		if (w==3)
		{
            //cout<<x<<' '<<sgt.query()<<endl;
			scanf("%d",&x);
			printf("%d\n",val[lca(x,sgt.query())]);
		}
		else
		{
			scanf("%d%d",&x,&y);
			sgt.modify(1,1,n,x,y,2-w);
		}
	}
}

int main()
{
	init();
	int casenum=1;
	//scanf("%d",&casenum);
	for (int testcase=1;testcase<=casenum;testcase++)
	{
		#ifdef _DEBUG_
		printf("Case #%d:\n",testcase);
		#endif
		work();
	}
	return ~~(0^_^0);
}