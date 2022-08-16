//Data Structure includes
#include<vector>
#include<stack>
#include<set>
#include<map>
#include<queue>
#include<deque>
#include<string>


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
#define mp						 	make_pair
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
LL a,b;


void preprocess()
{

}
LL convert(LL n)
{
	LL ans=0;
	LL pow=1;
	while(n>0)
	{
		int x=n%10;
		if(x!=0)
		{
			ans+=pow*x;
			pow*=10;
		}
		n/=10;
	}
	return ans;
}

void solve()
{
	LL c=a+b;
	//printf("%lld %lld %lld",convert(a),convert(b),convert(c));
	if(convert(a) + convert(b) == convert(c))
		printf("YES\n");
	else
		printf("NO\n");
}

bool input()
{
	int x,y;
	s(x); s(y);
	a=x; b=y;
	return true;
}


int main()
{
	preprocess();
	int T=1;
	for(testnum=1;testnum<=T;testnum++)
	{
		if(!input()) break;
		solve();
	}
}