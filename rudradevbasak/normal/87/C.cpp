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
#define MAXN 100005
int grundy[MAXN];
int xsum[MAXN];

int nn;
vector<int> nims;

void preprocess()
{
	grundy[0]=0;
	grundy[1]=0;
	xsum[0]=0;
	xsum[1]=0;
	for(int i=2;i<=MAXN;i++)
	{
		grundy[i]=0;
		nims.clear();
		for(int n=1;n*(n+1)<=2*i;n++)
		{
			int left=i-(n*(n+1)/2);
			if(left<0 || left%(n+1) != 0) continue;
			
			int base = left/(n+1);
			int cur = xsum[base-1] ^ xsum[base+n];
			nims.pb(cur);
		}
		sort(nims.begin(),nims.end());
		
		int mex=0;
		for(int j=0;j<nims.size();j++)
		{
			if(nims[j]<mex) continue;
			if(nims[j]==mex) mex++;
			else	break;
		}
		grundy[i]=mex;
		xsum[i]=xsum[i-1]^mex;
	}
	
}

void solve()
{
	if(grundy[nn]==0)
	{
		printf("-1\n");
		return;
	}
	else
	{
		int ans=INF;
		for(int n=1;n*(n+1)<=2*nn;n++)
		{
			int left=nn-(n*(n+1)/2);
			if(left<0 || left%(n+1) != 0) continue;
			
			int base = left/(n+1);
			int cur = xsum[base-1] ^ xsum[base+n];
			if(cur==0 && n<ans)
				ans=n;
		}
		printf("%d\n",ans+1);
	}
}

bool input()
{
	s(nn);
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