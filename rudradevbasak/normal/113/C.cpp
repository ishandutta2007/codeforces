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

typedef vector<int> VI;
typedef vector<vector<int> > VVI;
typedef long long LL;
typedef pair<int, int > PII;

/*Main code begins now */
int testnum;
int l,r;
int arr[5000000];

void preprocess()
{
	
}

void solve()
{
	int ans=0;
	if(l<=2 && 2<=r) ans++;
	fill(arr,0);
	
	for(int i=3;i<=18000;i+=2)
	{
		if( ( ( arr[i>>6] >> ((i>>1)&31) ) & 1) == 0)
		{
			for(int j=i*i;j<=300000000;j+=(i<<1))
				arr[j>>6] |= ( 1 << ((j>>1) & 31) );
			
			if(l<=i && i<=r && ((i&3)==1))
				ans++;
		}
	}
	
	
	for(int i=18001;i<300000000;i+=2)
	{
		if( ( ( arr[i>>6] >> ((i>>1)&31) ) & 1) == 0)
			if(l<=i && i<=r && ((i&3)==1))
				ans++;
	}
	printf("%d\n",ans);
}

bool input()
{
	s(l), s(r);
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