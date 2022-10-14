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

int a[MAXN];
LL sum[MAXN];
int n;
map<int,int> mp;
bool check(int l,int r)
{
	return (a[l]^a[r])==sum[r-1]-sum[l];
}

LL highbit(int x)
{
	for (int i=30;i>=0;i--)
		if ((x>>i)&1)
			return (1<<i);
}

vector<LL> v;
void work()
{
	cin>>n;
	LL ans=0;
	for (int i=1;i<=n;i++)
	{
		cin>>a[i];
		sum[i]=sum[i-1]+a[i]; 
	}
	for (int i=1;i<=n;i++)
	{
		int tmp=2*highbit(a[i]);
		for (int j=i+2;j<=n;j++)
		{
			if ((a[i]^a[j])==sum[j-1]-sum[i])
				v.push_back((i<<31)|j);
			if (sum[j-1]-sum[i]>=tmp)
				break;
		}
		for (int j=i-2;j>=1;j--)
		{
			if ((a[i]^a[j])==sum[i-1]-sum[j])
				v.push_back((j<<31)|i);
			if (sum[i-1]-sum[j]>=tmp)
				break;
		}
	}
	sort(v.begin(),v.end());
	
	cout<<unique(v.begin(),v.end())-v.begin()<<endl;
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