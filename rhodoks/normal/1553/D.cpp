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

string s,t;
int dp[MAXN][2];
void init()
{
	
}

void work()
{
	cin>>s>>t;
	for (int i=0;i<=t.size();i++)
		dp[i][0]=dp[i][1]=INF;
	int ptr=0;
	for (ptr=0;ptr<s.size();ptr+=2)
		if (s[ptr]==t[0])
			break;
	dp[0][0]=ptr;
	//WRT(ptr)
	for (ptr=1;ptr<s.size();ptr+=2)
		if (s[ptr]==t[0])
			break;
	dp[0][1]=ptr;
	//WRT(ptr)
	for (int i=1;i<t.size();i++)
	{
		for (dp[i][1]=dp[i-1][0]+1;dp[i][1]<s.size();dp[i][1]+=2)
			if (s[dp[i][1]]==t[i])
				break; 
		for (dp[i][0]=dp[i-1][1]+1;dp[i][0]<s.size();dp[i][0]+=2)
			if (s[dp[i][0]]==t[i])
				break; 
		//cout<<dp[i][0]<<' '<<dp[i][1]<<endl;
	}
	if (dp[t.size()-1][(s.size()&1)^1]<s.size())
		printf("YES\n");
	else
		printf("NO\n"); 
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