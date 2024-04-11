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
 
#define MAXN 1010000
#define MAXM 2010000
#define MOD 998244353  //1000000007
#define INF 0x3f3f3f3f
#define LLINF 0x3f3f3f3f3f3f3f3f
#define EPS 1e-5
 
#define _ 0
using namespace std;
 
map<int,int> g[MAXN];
int xorsum=0;
int n,m;
set<int> e;
int col[MAXN];
vector<int> fxxk[MAXN];
 
/*  				???a?					*/ 
 
//Union_Find_Set 22? 
//union_find_set(int set_size=MAXN)		?????a?3y3? 
//void init(int n) 						3??? 
//void merge(int x,int y) 				o?2????o? 
//bool query(int x,int y) 				2?????a?????????o? 
 
class Union_Find_Set 
{
	int *pa;
	int n;
	
public:
	int Getpa(int x)
	{
		return pa[x]==x ? x:(pa[x]=Getpa(pa[x]));
	}
	
	int operator[](int x)
	{
		return Getpa(x);
	}
	
	Union_Find_Set(int _size=MAXN)
	{
		n=_size;
		pa=new int[_size+2];
		Init(_size);
	}
	
	~Union_Find_Set()
	{
		delete pa;
	}
	
	void Init(int n)
	{
		for (int i=0;i<=n;i++)
			pa[i]=i;
	}
	
	void Merge(int x,int y)
	{
		pa[Getpa(x)]=Getpa(y);
	}
	
	bool Query(int x,int y)
	{
		return Getpa(x)==Getpa(y);
	}
	
	int Size()
	{
		return n;
	}
} u;
typedef Union_Find_Set UFS;
/*  				????					*/ 
 
void add(int x,int y,int w)
{
	g[x][y]=w;
	g[y][x]=w;
	xorsum^=w;
}
 
typedef pair<int,pair<int,int> > pip;
vector<pip> edge;
LL ans=0;
void dfs(int pos,int c)
{
	//cout<<pos<<' '<<c<<endl;
	fxxk[c].push_back(pos);
	int lst=-1;
	col[pos]=c;
	while (lst<=n)
	{
		int t=*e.lower_bound(lst);
		lst=t+1;
		if (t>n)
			break;
		if (g[pos][t])
			continue;
		e.erase(t);
		u.Merge(pos,t);
		//cout<<pos<<' '<<t<<endl;
		//pip.insert({0,{pos,t}};
		dfs(t,c);
	}
}
 
void init()
{
	int x,y,w;
	cin>>n>>m;
	for (int i=0;i<m;i++)
	{
		scanf("%d%d%d",&x,&y,&w);
		add(x,y,w);
	}
}
 
void work()
{
	u.Init(n+1); 
	UFS ufs(n+1);
	ufs.Init(n+1);
	int colcnt=0; 
	for (int i=1;i<=n;i++)
	{
		if (col[i])
			continue;
		WRT(i); 
		col[i]=i;
		e.clear();
		for (int j=1;j<=n+1;j++)
			if (col[j]==0)
				e.insert(j);
		dfs(i,i);
		colcnt++;
	}
	LL maxedgenum=(LL)n*(n-1)/2;
	//WRT(maxedgenum)
	LL remainedgenum=maxedgenum-m;
	WRT(n-colcnt)
	WRT(remainedgenum)
	WRT(xorsum);
	if (n-colcnt!=remainedgenum)
		xorsum=0;
	for (int i=1;i<=n;i++)
		for (auto p:g[i])
		{
			//	cout<<i<<' '<<p.first<<' '<<col[i]<<"----"<<col[p.first]<<endl;
			if (p.second && p.first>i)
			{
				edge.push_back({p.second,{p.first,i}});
			}
		}
	sort(edge.begin(),edge.end());
	
	int cnt=0;
	LL fxxk=0;
	for (auto E:edge)
	{
		//cout<<E.second.first<<' '<<E.second.second<<' '<<E.first<<endl;
		if (!u.Query(E.second.first,E.second.second))
		{
			MRK();
			fxxk+=E.first;
			ufs.Merge(E.second.first,E.second.second);
			u.Merge(E.second.first,E.second.second);
		}
		else if (!ufs.Query(E.second.first,E.second.second))
		{
			ufs.Merge(E.second.first,E.second.second);
			xorsum=min(xorsum,E.first); 
		}
	}
	//WRT(ans);
	cout<<xorsum+fxxk<<endl;
}
 
int main()
{
	#ifdef _DEBUG_
	freopen("C:/Users/DELL/Documents/Dev-C++/sample.in","r",stdin);
	#endif
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