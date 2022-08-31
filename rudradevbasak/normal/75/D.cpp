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
int n,m;
const int maxn=50;
const int maxm=250000;
LL sum[50];
LL tfel[50];
LL thgir[50];
LL mid[50];


int len[50];
int small[50][5000];
int big[maxm];
LL dp[maxm];

void preprocess()
{

}

void solve()
{
	for(int i=0;i<n;i++)
	{
		sum[i]=0;
		for(int j=0;j<len[i];j++)
			sum[i] += small[i][j];
			
		LL temp=0;
		tfel[i]=-INF;
		for(int j=0;j<len[i];j++)
		{
			temp+=small[i][j];
			tfel[i] = max(tfel[i],temp);
		}
		
		temp=0;
		thgir[i]=-INF;
		for(int j=len[i]-1;j>=0;j--)
		{
			temp+=small[i][j];
			thgir[i] = max(thgir[i],temp);
		}
		
		temp=0;	
		mid[i]=-INF;
		for(int j=0;j<len[i];j++)
		{
			temp=max(temp+small[i][j],(LL)small[i][j]);
			mid[i] = max(mid[i],temp);
		}
		
		//printf("%d : Sum is %lld   Left is %lld   Right is %lld   Mid is %lld\n",i,sum[i],tfel[i],thgir[i],mid[i]);
	}
	
	LL ans=-INF;
	LL temp=0;
	for(int i=0;i<m;i++)
	{
		ans = max(ans, max(temp+tfel[big[i]], mid[big[i]]) );
		temp = max(temp+sum[big[i]], thgir[big[i]]);
		
		//printf("At %d : ans is %lld   temp is %lld\n",i,ans,temp);
	}
	
	cout<<ans<<endl;
	

			
}

bool input()
{
	s(n); s(m);
	
	for(int i=0;i<n;i++)
	{
		s(len[i]);
		for(int j=0;j<len[i];j++)
			s(small[i][j]);
	}
	
	for(int i=0;i<m;i++)
	{		
		s(big[i]);
		big[i]--;
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