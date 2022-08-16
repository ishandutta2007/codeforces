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
vector <long long> x;
vector <long long> y;
int N;


long long vsum(vector <long long> vals)
{
	long long sum = 0;
	long long sumsq = 0;
	
	for(int i = 0; i < N; i++)
	{
		sum += vals[i];
		sumsq += vals[i] * vals[i];
	}
	
	return N*sumsq - sum * sum ;
}

void solve()
{
	cout<<(vsum(x) + vsum(y)) << endl;
}

void input()
{
	s(N);
	int xx, yy;
	for(int i = 0; i < N; i++)
	{
		s(xx); s(yy);
		x.push_back((LL)xx);
		y.push_back((LL)yy);
	}
}


int main()
{
		input();
		solve();
}