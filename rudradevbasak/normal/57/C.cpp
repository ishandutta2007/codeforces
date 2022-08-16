//Data Structure includes
#include<vector>
#include<stack>
#include<set>
#include<map>
#include<queue>
#include<deque>


//Other Includes
#include<iostream>
#include<algorithm>
#include<cstring>
#include<cassert>
#include<cstdlib>
#include<cstdio>
#include<cmath>

using namespace std;

#define FOR(i,a,b)					for(int i=a;i<b;i++)
#define REP(i,n)					FOR(i,0,n)
#define pb						 	push_back
#define s(n)						scanf("%d",&n)
#define sl(n) 						scanf("%lld",&n)
#define sf(n) 						scanf("%lf",&n)
#define fill(a,v) 					memset(a, v, sizeof a)
#define sz							size()
#define INF							(int)1e9
#define EPS							1e-9
#define bitcount					__builtin_popcount
#define all(x)						x.begin(), x.end()
#define gcd							__gcd
#define maX(a,b)					(a>b?a:b)
#define miN(a,b)					(a<b?a:b)

typedef vector<int> VI;
typedef vector<vector<int> > VVI;
typedef long long LL;
typedef pair<int, int > PII;

/*Main code begins now */
int testnum;
LL f[200005];
LL invf[200005];
LL mod=1000000007;
int n;

LL x,y;

void extgcd(LL a,LL b)
{
	if(b==0)
	{
		x=1;
		y=0;
	}
	else
	{
		extgcd(b,a%b);
		LL t=x;
		x=y;
		y=t-(a/b)*y;
	}
}

LL inverse(LL a)
{
	extgcd(a,mod);
	x=x%mod;
	while(x<0)
		x+=mod;
	while(x>=mod)
		x-=mod;
	return x;
}


void preprocess()
{
	f[0]=1;
	for(int i=1;i<=n+n;i++)
		f[i]=(f[i-1]*i)%mod;
	
		
	for(int i=0;i<=n;i++)
		invf[i]=inverse(f[i]);
	
}

void solve()
{
	LL ans=f[n+n-1];
	ans=(ans*invf[n-1])%mod;
	ans=(ans*invf[n])%mod;
	ans=(ans+ans)%mod;
	ans=(ans-n+mod)%mod;
	cout<<ans<<endl;
	
}

bool input()
{
	cin>>n;
	return true;
}


int main()
{

	input();
		preprocess();
	solve();
}