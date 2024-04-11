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

#define MAXN 310000
#define MAXM 2010000
#define MOD 998244353  //1000000007
#define INF 0x3f3f3f3f
#define LLINF 0x3f3f3f3f3f3f3f3f
#define EPS 1e-5

#define _ 0
using namespace std;

/*  									*/ 

//Union_Find_Set  
//union_find_set(int set_size=MAXN)		 
//void init(int n) 						 
//void merge(int x,int y) 				 
//bool query(int x,int y) 				 

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
	int getpa(int x)
	{
		return pa[x]==x ? x:(pa[x]=getpa(pa[x]));
	}
	
	Union_Find_Set(int _size=MAXN)
	{
		n=_size;
		pa=new int[_size+2];
		init(_size);
	}
	
	~Union_Find_Set()
	{
		delete pa;
	}
	
	void init(int n)
	{
		for (int i=0;i<=n;i++)
			pa[i]=i;
	}
	
	void merge(int x,int y)
	{
		pa[getpa(x)]=getpa(y);
	}
	
	bool query(int x,int y)
	{
		return getpa(x)==getpa(y);
	}
	
	int size()
	{
		return n;
	}
};
typedef Union_Find_Set UFS;

/*  									*/

int n,k;
int p[MAXN],depth[MAXN]; 
int lst[MAXN],nxt[MAXN];
vector<int> g[MAXN];
int x[MAXN],y[MAXN];
int in[MAXN];
vector<int> g1[MAXN];
vector<int> tmp[MAXN];
UFS ufs(MAXN);
bool topo()
{
	queue<int> q;
	for (int i=1;i<=n;i++)
		if (in[i]==0)
			q.push(i);
	while (!q.empty())
	{
		int pos=q.front();
		q.pop();
		for (auto p:g[pos])
		{
			in[p]--;
			if (in[p]==0)
				q.push(p);
		}
	}
	for (int i=1;i<=n;i++)
		if (in[i])
		{
			return false;
		}
	return true;
}

vector<int> ans;
bool topo1()
{
	queue<int> q;
	for (int i=1;i<=n;i++)
		if (in[i]==0 && ufs.getpa(i)==i)
			q.push(i);
	while (!q.empty())
	{
		int pos=q.front();
		for (auto p:tmp[pos])
			ans.push_back(p);
		q.pop();
		for (auto p:g1[pos])
		{
			in[p]--;
			if (in[p]==0)
				q.push(p);
		}
	}
	for (int i=1;i<=n;i++)
		if (in[i])
			return false;
	return true;
	
}

void work()
{
	cin>>n>>k;
	for (int i=1;i<=n;i++)
	{
		scanf("%d",&p[i]);
		if (p[i]==0)
			continue;
		in[i]++;
		g[p[i]].push_back(i);
	}
	for (int i=1;i<=k;i++)
	{
		scanf("%d%d",x+i,y+i);
		g[x[i]].push_back(y[i]);
		in[y[i]]++;
		nxt[x[i]]=y[i];
		lst[y[i]]=x[i];
		ufs.merge(x[i],y[i]);
	}
	if (!topo())
	{
		cout<<0<<endl;
		return;
	}
	for (int i=1;i<=n;i++)
		if (lst[i]==0)
		{
			int fa=ufs.getpa(i);
			int pos=i;
			tmp[fa].push_back(pos);
			while (nxt[pos])
			{
				pos=nxt[pos];
				tmp[fa].push_back(pos);
			}
		}
	for (int i=1;i<=n;i++)
	{
		if (ufs.getpa(p[i])==ufs.getpa(i) || p[i]==0)
			continue;
		g1[ufs.getpa(p[i])].push_back(ufs.getpa(i));
		//cout<<ufs.getpa(p[i])<<' '<<ufs.getpa(i)<<endl;
		in[ufs.getpa(i)]++;
	}
	for (int i=1;i<=k;i++)
	{
		if (ufs.getpa(x[i])==ufs.getpa(y[i]))
			continue;
		g1[ufs.getpa(x[i])].push_back(ufs.getpa(y[i]));
		//cout<<ufs.getpa(x[i])<<' '<<ufs.getpa(y[i])<<endl;
		in[ufs.getpa(y[i])]++;
	}
	if (!topo1())
	{
		cout<<0<<endl;
		return;
	}
	for (auto p:ans)
		printf("%d ",p);
	cout<<endl;
}

int main()
{
	#ifdef _DEBUG_
	freopen("C:/Users/DELL/Documents/Dev-C++/sample.in","r",stdin);
	#endif
	int casenum=1;
	//scanf("%d",&casenum);
	for (int testcase=1;testcase<=casenum;testcase++)
	{
		#ifdef _DEBUG_
		printf("Case #%d:",testcase);
		#endif
		work();
	}
	return ~~(0^_^0);
}