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
int a[10005];
double lo,hi,mid;
int n,k;
double sum;

void preprocess()
{

}

void solve()
{
	for(int i=0;i<100;i++)
	{
		mid = (lo+hi)/2;
		
		double tr=0;
		for(int i=0;i<n;i++)
			if(a[i]>mid)
				tr+=(a[i]-mid);
		if(sum - (1.0 * tr *k)/100 >= mid * n)
			lo=mid;
		else
			hi=mid;
	}
	printf("%.9lf\n",mid);
		
}

bool input()
{
	s(n); s(k);
	lo=1000; hi=0;
	sum=0;
	for(int i=0;i<n;i++)
	{
		s(a[i]);
		lo=min(lo,a[i]+0.0);
		hi=max(hi,a[i]+0.0);
		sum+=a[i];
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