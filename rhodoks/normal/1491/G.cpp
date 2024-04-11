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

int p[MAXN];
int n;
int visit[MAXN];
typedef pair<int,int> pii;
vector<pii> ans;

void Swap(int x,int y)
{
	ans.push_back({x,y});
	int tx=-p[x];
	int ty=-p[y];
	p[y]=tx;
	p[x]=ty;
}

vector<int> find(int x)
{
	vector<int> tmp;
	visit[x]=1;
	tmp.push_back(x); 
	while (!visit[p[x]])
	{
		x=p[x];
		tmp.push_back(x);
		visit[x]=1;
	}
	return tmp;
}

vector<vector<int> > loop;
void init()
{

}

void merge(vector<int> v1,vector<int> v2)
{
	MRK();
	int s1=v1.size();
	int s2=v2.size();
	Swap(v1[s1-1],v2[s2-1]);
	for (int i=0;i<s2-1;i++)
		Swap(v1[s1-1],v2[i]); 
	for (int i=0;i<s1-1;i++)
		Swap(v1[i],v2[s2-1]); 
	Swap(v1[s1-1],v2[s2-1]);
}

void work()
{
	cin>>n;
	for (int i=1;i<=n;i++)
		scanf("%d",&p[i]);
	for (int i=1;i<=n;i++)
		if (p[i]!=i && !visit[i])
			loop.push_back(find(i));
		/*
	for (auto p:loop)
	{
		for (auto q:p)
			cout<<q<<' ';
		cout<<endl;
	}
	*/
	if (loop.size()==1 && loop[0].size()>=3)
	{
		auto v=loop[0];
		int s=v.size();
		Swap(v[s-3],v[s-1]);
		for (int i=0;i<s-3;i++)
			Swap(v[i],v[s-3]);
		Swap(v[s-3],v[s-2]);
		Swap(v[s-2],v[s-1]);
		Swap(v[s-3],v[s-1]);
	}
	else
	{
		WRT(loop.size())
		for (int i=2;i<=loop.size();i+=2)
		{
			merge(loop[i-2],loop[i-1]);
		}
		if (loop.size()%2==1)
		{
			int key=1;
			for (;p[key]!=key;key++);
			WRT(key);
			auto v=loop[loop.size()-1];
			int s=v.size();
			Swap(v[s-1],key);
			for (int i=0;i<s;i++)
				Swap(v[i],key);
		}
	}
	cout<<ans.size()<<endl;
	for (auto p:ans)
		printf("%d %d\n",p.first,p.second); 
	//for (int i=1;i<=n;i++)
	//	assert(i==p[i]);
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