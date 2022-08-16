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
#define ss(n) 						scanf("%s",n)
#define fill(a,v) 					memset(a, v, sizeof a)
#define sz							size()
#define INF							(int)1e9
#define EPS							1e-9
#define bitcount					__builtin_popcount
#define all(x)						x.begin(), x.end()
#define gcd							__gcd
#define maX(a,b)					(a>b?a:b)
#define miN(a,b)					(a<b?a:b)
#define DREP(a)						sort(all(a)); a.erase(unique(all(a)),a.end())
#define INDEX(arr,ind)				lower_bound(all(arr),ind)-arr.begin()

typedef vector<int> VI;
typedef vector<vector<int> > VVI;
typedef long long LL;
typedef vector<long long > VLL;
typedef pair<int, int > PII;

/*Main code begins now */
int testnum;
int n;
int par[2005];
int dep[5005];


void preprocess()
{

}

int memo(int u)
{
	if(dep[u]>=0) return dep[u];
	if(par[u]==-1) return dep[u]=1;
	return dep[u] = memo(par[u])+1;
}

void solve()
{
	fill(dep,-1);
	int best=0;
	for(int i=1;i<=n;i++)
		best=max(best,memo(i));
	cout<<best<<endl;
}

bool input()
{
	s(n);
	int x;
	for(int i=1;i<=n;i++)
	{
		s(x);
		par[i]=x;
	}
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