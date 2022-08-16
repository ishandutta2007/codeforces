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

int gcd(int a,int b)
{
	if(b==0) return a;
	return gcd(b,a%b);
}

void preprocess()
{

}
int a,b;
void solve()
{
	int g=gcd(a,b);
	VI factors;
	if(g==1)
	{
		factors.pb(1);
	}
	else
	for(int i=1;i*i<=g;i++)
		if(g%i == 0)
		{
			factors.pb(i);
			factors.pb(g/i);
		}
		
	sort(factors.begin(), factors.end());
	
	int n;
	s(n);
	int lo,hi;
	for(int i=0;i<n;i++)
	{
		s(lo); s(hi);
		VI::iterator it=upper_bound(factors.begin(),factors.end(), hi);
		it--;
		
		int z=*it;
		if(z>=lo && z<=hi)
			printf("%d\n",z);
		else
			printf("-1\n");
	}
		
}

bool input()
{
	s(a); s(b);
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