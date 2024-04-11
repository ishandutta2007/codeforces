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
#define MOD 1000000007
#define INF 0x3f3f3f3f
#define LLINF 0x3f3f3f3f3f3f3f3f
#define EPS 1e-5

#define _ 0
using namespace std;

char s[MAXN];
int n;

LL mpow(LL x,LL n)
{
	LL ans=1;
	while (n)
	{
		if (n&1)
			ans=ans*x%MOD;
		x=x*x%MOD;
		n>>=1;
	}
	return ans;
}

LL inv(LL x)
{
	return mpow(x,MOD-2);
}

const LL inv3=inv(3);
//LL dp[MAXN][4];
LL cnt[4];
LL sum[4];
void work()
{
	cin>>n>>s;
	int k=0;
	LL ans=0;
	for (int i=0;i<n;i++)
		if (s[i]=='?')
			cnt[3]++;
		else
			cnt[s[i]-'a']++;
	for (int i=0;i<n;i++)
	{
		if (s[i]=='b')
			ans+=(LL)(sum[0]*3+sum[3]*1)*((cnt[2]-sum[2])*9+(cnt[3]-sum[3])*3);
		else if (s[i]=='?')
			ans+=(LL)(sum[0]*3+sum[3]*1)*((cnt[2]-sum[2])*3+(cnt[3]-sum[3]-1)*1);
		if (s[i]=='?')
			sum[3]++;
		else
			sum[s[i]-'a']++;
		WRT(ans);
	}
	cout<<ans%MOD*inv3%MOD*inv3%MOD*inv3%MOD*mpow(3,cnt[3])%MOD<<endl;
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