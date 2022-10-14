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

#define MOD 998244353  //1000000007
#define INF 0x3f3f3f3f
#define LLINF 0x3f3f3f3f3f3f3f3f
#define EPS 1e-5

#define _ 0
using namespace std;

#define MAXN 300010
vector<int> g1[MAXN],g2[MAXN];
int n;

int ans=0;
int maxans=0;

int l[MAXN],r[MAXN];
int depth[MAXN];
int pa[MAXN];
int top[MAXN];
int son[MAXN];
int sze[MAXN];
int cnt=0;
void dfs1(int pos)
{
	l[pos]=r[pos]=++cnt;
	depth[pos]=depth[pa[pos]]+1;
	sze[pos]=1;
	for (auto p:g2[pos])
	{
		pa[p]=pos;
		dfs1(p);
		r[pos]=max(r[pos],r[p]);
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
	for (auto p:g2[pos])
		if (p!=son[pos])
			dfs2(p,p);
}


template <class DataType> 
class BinaryIndexTree
{
public:
	vector<DataType> bit;
	
	BinaryIndexTree(int _size=MAXN)
	{
		bit.resize(_size+2);
	}
	
	void resize(int _size)
	{
		bit.resize(_size+2,0);
	}
	
	void clear()
	{
		
	}
	
	int lowbit(int x)
	{
		return x&-x;
	}
	
	void add(int x,int a)
	{
		for (;x<bit.size();x+=lowbit(x))
			bit[x]+=a;
	}
	
	DataType query(int x)
	{
		DataType ans=0;
		for (;x;x-=lowbit(x))
			ans+=bit[x];
		return ans;
	}
	
	DataType query(int x,int y)
	{
		return query(y)-query(x-1);
	}
};
#define BIT BinaryIndexTree

BIT<int> bit;

int Qsubtree(int pos)
{
	return bit.query(l[pos],r[pos]);
}

int toprec[MAXN];
typedef pair<int*,int> ppi;
void dfs(int pos)
{
	int lstans=ans;
	
	
	vector<ppi> rec;
	if (Qsubtree(pos)==0)
	{
		int tmp=pos;
		int tmptop=top[pos];
		bool flag=0;
		
		while (1)
		{
			//cout<<pos<<' '<<toprec[tmptop]<<endl;
			//WRT(toprec[tmptop])
			//WRT(depth[tmp])
			if (toprec[tmptop] && depth[toprec[tmptop]]<=depth[tmp])
			{
				flag=1;
				rec.push_back({&toprec[tmptop],toprec[tmptop]});
				toprec[tmptop]=0;
			}
			rec.push_back({&toprec[top[pos]],toprec[top[pos]]});
			toprec[top[pos]]=pos;
			if (tmptop==1)
				break;
			//WRT(tmp);
			tmp=pa[tmptop];
			tmptop=top[tmp];
			//WRT(tmp)
			//WRT(tmptop);
		}
		
		if (flag==0)
			ans++;
	}
	
	maxans=max(maxans,ans);
	
	//cout<<pos<<' '<<ans<<endl;
	//for (int i=1;i<=n;i++)
	//	cout<<i<<' '<<top[i]<<' '<<toprec[i]<<endl;
	
	for (auto p:g1[pos])
		dfs(p);
		
	reverse(rec.begin(),rec.end());
	for (auto p:rec)
		*p.first=p.second;
		
	ans=lstans;
}



void init()
{
	
}

void work()
{
	int x,y;
	cin>>n;
	bit.resize(n+1);
	cnt=0;
	ans=0;
	maxans=0;
	for (int i=0;i<=n;i++)
	{
		g1[i].clear();
		g2[i].clear();
		sze[i]=top[i]=pa[i]=depth[i]=l[i]=r[i]=son[i]=toprec[i]=0;
	}
	
	for (int i=2;i<=n;i++)
	{
		scanf("%d",&x);
		g1[x].push_back(i);
	}
	for (int i=2;i<=n;i++)
	{
		scanf("%d",&x);
		g2[x].push_back(i);
	}
	dfs1(1);
	dfs2(1,1);
	dfs(1);
	cout<<maxans<<endl;
}

int main()
{
	#ifdef _DEBUG_
	freopen("C:/Users/DELL/Documents/Dev-C++/sample.in","r",stdin);
	#endif
	init();
	int casenum=1;
	scanf("%d",&casenum);
	for (int testcase=1;testcase<=casenum;testcase++)
	{
		#ifdef _DEBUG_
		printf("Case #%d:\n",testcase);
		#endif
		work();
	}
	return ~~(0^_^0);
}