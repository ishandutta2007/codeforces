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
};
typedef Union_Find_Set UFS;

UFS ufs;
int n;
int a[MAXN];
int x,y;
int casenum=1;
set<int> st[MAXN];
void init()
{

	cin>>n>>casenum;
	ufs.Init(MAXN);
	for (int i=1;i<=n;i++)
	{
		//a[i]=1000000-i;
		cin>>a[i];
		int t=a[i];
		for (int j=2;j*j<=t;j++)
			while (t%j==0)
			{
				ufs.Merge(a[i],j);
				//cout<<a[i]<<' '<<j<<endl;
				t/=j;
			}
		if (t>1)
		{
			ufs.Merge(a[i],t);
				//cout<<a[i]<<' '<<t<<endl;
		}
	}
	for (int i=1;i<=n;i++)
	{
		vector<int> v;
		int t=a[i]+1;
		for (int j=2;j*j<=t;j++)
			while (t%j==0)
			{
				v.push_back(j);
				//st[ufs.Getpa(a[i])].insert(ufs.Getpa(j)); 
				//st[ufs.Getpa(j)].insert(ufs.Getpa(a[i])); 
				//cout<<a[i]<<' '<<j<<endl;
				t/=j;
			}
		if (t>1)
		{
			v.push_back(t);
			//st[ufs.Getpa(a[i])].insert(ufs.Getpa(t)); 
			//st[ufs.Getpa(t)].insert(ufs.Getpa(a[i])); 
		}
		v.push_back(a[i]);
		for (auto &p:v)
			p=ufs.Getpa(p);
		sort(v.begin(),v.end());
		int m=unique(v.begin(),v.end())-v.begin();
		v.resize(m);
		for (auto p:v)
			for (auto q:v)
				st[p].insert(q);
	}
}

void work()
{
	scanf("%d%d",&x,&y);
	if (ufs.Query(a[x],a[y]))
	{
		printf("0\n");
		return; 
	}
	if (st[ufs.Getpa(a[x])].find(ufs.Getpa(a[y]))!=st[ufs.Getpa(a[x])].end())
	{
		printf("1\n");
		return; 
		
	}
	
	printf("2\n");
	
}

int main()
{
	#ifdef _DEBUG_
	freopen("C:/Users/DELL/Documents/Dev-C++/sample.in","r",stdin);
	#endif
	init();
	for (int testcase=1;testcase<=casenum;testcase++)
	{
		work();
	}
	return ~~(0^_^0);
}