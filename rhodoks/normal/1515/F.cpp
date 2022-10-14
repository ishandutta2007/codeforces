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


typedef pair<int,int> pii;
unordered_map<int,int> g[MAXN];
LL n,m,x;
LL a[MAXN]; 
LL sum=0;

/*  									*/ 

//Union_Find_Set  
//union_find_set(int set_size=MAXN)		 
//void init(int n) 						 
//void merge(int x,int y) 				 
//bool query(int x,int y) 				 

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
		//a[Getpa(y)]+=a[Getpa(x)];
		//a[Getpa(x)]=0;
	}
	
	bool Query(int x,int y)
	{
		return Getpa(x)==Getpa(y);
	}
	
	int Size()
	{
		return n;
	}
};
typedef Union_Find_Set UFS;
UFS ufs(MAXN);
/*  									*/ 

int visit[MAXN];

struct CMP
{
	bool operator()(int x1,int x2)
	{
		return a[x1]<a[x2];
	}
};
priority_queue<int,vector<int>,CMP> pq;
 
void init()
{

}

void work()
{
	cin>>n>>m>>x;
	ufs.Init(n);
	int u,v;
	for (int i=1;i<=n;i++)
	{
		scanf("%lld",&a[i]);
		pq.push(i);
		sum+=a[i];
	}
	for (int i=1;i<=m;i++)
	{
		scanf("%d%d",&u,&v);
		g[u][v]=g[v][u]=i;
	}
	//cout<<sum<<' '<<x<<' '<<n-1<<endl;
	if (sum<(LL)x*(n-1))
	{
		cout<<"NO\n";
		return;
	}
	cout<<"YES\n";
	while (pq.size()>1)
	{
		int pos=pq.top();
		//WRT(pos);
		pq.pop();
		if (visit[pos])
			continue;
		vector<pii> tmp;
		
		vector<int> tmpi;
		for (auto p:g[pos])
		{
			//int to=ufs.Getpa(p.first);
			//cout<<p.first<<"-"<<p.second<<endl;
			if (ufs.Query(p.first,pos))
				tmpi.push_back(p.first);
		}
		for (auto p:tmpi)
		{
			g[p].erase(pos);
			g[pos].erase(p);
			
		}
			
		vector<int> key;
		key.push_back(pos);
		for (auto p:g[pos])
		{
			int to=ufs.Getpa(p.first);
			if (ufs.Query(to,pos))
				continue;
			if (a[pos]+a[to]>=x)
			{
				cout<<p.second<<endl;
				a[pos]=a[pos]+a[to]-x;
				WRT(a[pos]);
				ufs.Merge(to,pos);
				key.push_back(to);
			}
		}
		int mx=0;
		for (auto p:key)
			if (g[p].size()>g[mx].size())
				mx=p;
		for (auto p:key)
			if (p!=mx)
			{
				for (auto q:g[p])
					g[mx].insert(q);
				g[p].clear();
			}
		if (mx!=pos)
			g[pos].swap(g[mx]);
		if (g[pos].size()==0)
			continue;
		pq.push(pos);
	}
	
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