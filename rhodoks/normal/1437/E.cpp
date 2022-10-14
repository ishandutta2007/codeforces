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
vector<int> v;
int n,m,x;
int dp[MAXN];
int work(int l,int r)
{
	for (int i=0;i<(r-l+4);i++)
		dp[i]=INF+1;
	dp[0]=a[l];
	int cnt=0;
	for (int i=l+1;i<r;i++)
	{
		//WRT(i)
		if (a[i]<a[l]+i-l || a[i]>a[r]-(r-i))
		{
			continue;
		}
		cnt=i-l;
		WRT(i)
		WRT(a[i])
		WRT(a[i]-cnt)
		int pos=upper_bound(dp,dp+(r-l+4),a[i]-cnt)-dp;
		dp[pos]=a[i]-cnt;
	}
	return r-l-(upper_bound(dp,dp+(r-l+4),a[r]-(r-l))-dp);
}

int main()
{
	#ifdef _DEBUG_
	freopen("C:/Users/DELL/Documents/Dev-C++/sample.in","r",stdin);
	#endif
	cin>>n>>m;
	for (int i=1;i<=n;i++)
		cin>>a[i];
	a[0]=-INF;
	a[n+1]=INF;
	v.push_back(0);
	for (int i=0;i<m;i++)
	{
		scanf("%d",&x);
		v.push_back(x);
	}
	v.push_back(n+1);
	n+=2;
	m+=2;
	int ans=0;
	for (int i=0;i<v.size()-1;i++)
	{
		if (v[i+1]-v[i]>a[v[i+1]]-a[v[i]])
		{
			cout<<-1<<endl;
			return 0;
		}
		//WRT(work(v[i],v[i+1]))
		ans+=work(v[i],v[i+1]);
	}
	cout<<ans<<endl;
	return ~~(0^_^0);
}