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
int a[MAXN];
vector<int> del;
int visit[MAXN]; 
int n;
int gcd(int x,int y)
{
	if (x<y)
		swap(x,y); 
	if (y==0)
		return x;
	return gcd(y,x%y);
}

void init()
{

}

void work()
{
	del.clear();
	scanf("%d",&n);
	set<pii> st;
	for (int i=1;i<=n;i++)
	{
		visit[i]=0;
		scanf("%d",&a[i]);
		st.insert({i,a[i]});
	}
	queue<int> q;
	for (int i=1;i<=n;i++)
		q.push(i);
	while (!q.empty())
	{
		int pos=q.front();
		q.pop();
		//WRT(st.size());
		if (st.size()==0 || visit[pos])
			continue;
		//MRK();
		auto nxt=st.lower_bound({pos+1,-1});
		//WRT(nxt->first)
		if (nxt==st.end())
			nxt=st.begin();
		int id=(*nxt).first;
		if (gcd(a[pos],a[id])==1)
		{
			st.erase({id,a[id]});
			visit[id]=1;
			del.push_back(id);
			q.push(pos);
		}
	}
	printf("%d ",del.size());
	for (auto p:del)
		printf("%d ",p);
	putchar('\n');
		
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