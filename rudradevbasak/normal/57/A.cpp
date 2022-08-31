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
int n,x11,y11,x22,y22;


void preprocess()
{

}

int dist(int x,int y)
{
	if(y==0)
		return x;
	if(x==n)
		return n+y;
	if(y==n)
		return n+n+n-x;
	if(x==0)
		return n+n+n+n-y;
	return n+n+n+n;
}

void solve()
{
	int a,b;
	a=dist(x11,y11);
	b=dist(x22,y22);
	int x=abs(b-a);
	int y=abs((4*n-b)+a);
	int z=abs(b+(4*n-a));
	int ans=min(min(x,y),z);
	cout<<ans<<endl;
	
}

bool input()
{
	cin>>n>>x11>>y11>>x22>>y22;
	return true;
}


int main()
{

		input();
		solve();

}