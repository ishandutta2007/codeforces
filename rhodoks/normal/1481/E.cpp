#include <bits/stdc++.h>
#define DB double
#define LL long long

#define MST(a,b) memset((a),(b),sizeof(a))
# 
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

int n;
int a[MAXN]; 
int l[MAXN],r[MAXN];
int cnt[MAXN];
typedef pair<int,int> pii;
vector<pii> g[MAXN];
int dp[MAXN];
int ans=0;
int mx[MAXN]; 
void work()
{
	cin>>n;
	for (int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
		r[a[i]]=i;
		if (l[a[i]]==0)
			l[a[i]]=i;
		cnt[a[i]]++;
	}
	int c=0;
	for (int i=1;i<=n;i++)
		if (cnt[i])
			g[l[i]].push_back({r[i],cnt[i]});
	for (int i=0;i<=n;i++)
	{
		for (auto p:g[i+1])
		{
			dp[p.first]=max(dp[i]+p.second,dp[p.first]);
		}
		dp[i+1]=max(dp[i+1],dp[i]); 
	}
	for (int i=1;i<=n;i++)
	{
		ans=max(ans,cnt[a[i]]+dp[i-1]);
		cnt[a[i]]--;
	}
	/*
	for (int i=1;i<=n;i++)
		if (cnt[i])
		{
			int tmp=1,j=r[i]-1;
			for (;a[j]==i;j--)
				tmp++;
			ans=max(ans,mx[j]+tmp);
		}
	*/	
	ans=max(ans,dp[n]);
	cout<<n-ans<<endl;
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
		printf("Case #%d:\n",testcase);
		#endif
		work();
	}
	return ~~(0^_^0);
}