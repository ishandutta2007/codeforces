#include <cstdio>
#include <cmath>
#include <cstring>
#include <cstdlib>

#include <iostream>
#include <algorithm>
#include <string>

#include <vector>
#include <set>
#include <map>
#include <queue>

using namespace std;

typedef long long LL;
typedef vector<int> VI;
typedef pair<int,int> PI;

#define PB(x) push_back(x)
#define MP(x,y) make_pair(x,y)
#define F first
#define S second
#define SET(v,x) memset(v,x,sizeof v)
#define FOR(i,a,b) for(int _n(b),i(a);i<_n;i++) 
#define EACH(it,v) for(typeof((v).begin()) it = (v).begin();it!=(v).end();it++)
#define REP(i,n) FOR(i,0,n)
#define ALL(v) (v).begin(),(v).end()
#define SORT(v) sort(ALL(v))
#define SZ(v) int(v.size())
#define SI ({int x;scanf("%d",&x);x;})

#define MX 100005

const LL MOD = 1000000007;

LL fac[MX];

LL powm(LL a, LL p)
{
	LL r = 1;
	for(;p;p>>=1)
	{
		if(p&1) r*=a; if(r>=MOD) r%=MOD;
		a*=a; if(a>=MOD) a%=MOD;
	}
	return r;
}

LL nCr(LL n,LL r)
{
	if(r>n) return 0;
	r = min(r,n-r);
	if(r==0) return 1;
	LL ans = fac[n] * powm(fac[n-r],MOD-2);
	if(ans>=MOD) ans%=MOD;
	ans *= powm(fac[r],MOD-2);
	if(ans>=MOD) ans%=MOD;
	return ans;
}

void pre()
{
	fac[0] = 1;
	for(int i=1;i<MX;i++)
	{
		fac[i] = fac[i-1]*i;
		if(fac[i]>=MOD) fac[i]%=MOD;
	}	
}

inline bool isLucky(int x)
{
	for(;x;x/=10) if(x%10!=4 && x%10!=7) return false;
	return true;
}

int main()
{
	pre();
	map<int,int> M;
	int unLuckyCnt = 0;
	
	int n = SI, k = SI;
	
	while(n--)
	{
		int x = SI;
		if(isLucky(x)) M[x]++;
		else unLuckyCnt++;
	}

	int luckyCount = SZ(M);
	LL **dp = new LL*[2] ;//luckyCount+1];
	dp[0] = new LL[luckyCount+1];
	dp[1] = new LL[luckyCount+1];

	int c = 0, p = 1;
	for(int j=0;j<=luckyCount;j++) dp[c][j] = 0;
	dp[c][0] = 1;

	EACH(it,M)
	{
		c^=1; p^=1;
		int cnt = it->second;
		
		dp[c][0] = 1;
		for(int j=1;j<=luckyCount;j++)
		{
			dp[c][j] = dp[p][j];
			dp[c][j] += (dp[p][j-1] * cnt)%MOD;
			if(dp[c][j]>=MOD) dp[c][j]-=MOD;
		}
	}

	LL ans = 0;

	for(int i=0;i<=min(k,luckyCount);i++)
	{
		ans += dp[c][i] * nCr(unLuckyCnt,k-i);
		if(ans>=MOD ) ans%=MOD;
	}

	printf("%lld\n",ans);

	//cout<<

	return 0;
}