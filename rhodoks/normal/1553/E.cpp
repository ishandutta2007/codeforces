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

int n,m;
int p[MAXN];
int a[MAXN];
vector<int> ans;
void init()
{

}

void work(int mm)
{

	vector<int> v,pos,to,visit;
	v.resize(n+1);
	to.resize(n+1);
	pos.resize(n+1);
	visit.resize(n+1);
	for (int i=1;i<=n-mm;i++)
		v[i+mm]=i;
	for (int i=1;i<=mm;i++)
		v[i]=n-(mm-i);
	for (int i=1;i<=n;i++)
		pos[v[i]]=i;
	for (int i=1;i<=n;i++)
		to[i]=pos[p[i]];
	int sum=0;
	for (int i=1;i<=n;i++)
		if (visit[i]==0)
		{
			while (visit[i]==0)
			{
				visit[i]=1;
				i=to[i];
				sum++;
			}
			sum--;
		}
	if (sum<=m)
		ans.push_back(mm);
		//cout<<v[i]<<' ';
	//cout<<endl;
}

void work()
{
	ans.clear();
	cin>>n>>m;
	for (int i=0;i<=n;i++)
		a[i]=0;
	for (int i=1;i<=n;i++)
	{
		cin>>p[i];
		a[(-p[i]+i+n)%n]++;
	}
	//for (int i=0;i<n;i++)
	//	cout<<a[i]<<' ';
	//cout<<endl;
	for (int i=0;i<n;i++)
		if (a[i]+2*m>=n)
			work(i);
	printf("%d ",ans.size());
	for (auto p:ans)
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