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
int x,y,z,k;


void preprocess()
{

}

void solve()
{
	LL xx,yy,zz;
	xx=min(x,min(y,z));
	zz=max(x,max(y,z));
	yy=x+y+z-xx-zz;
	
	LL a=k/3;
	if(a<xx)
	{
		k-=a;
	}
	else
	{
		a=xx-1;
		k-=a;
	}
	
	LL b=k/2;
	if(b<yy)
	{
		k-=b;
	}
	else
	{
		b=yy-1;
		k-=b;
	}
	
	LL c=k;
	if(c<zz)
	{
		k-=c;
	}
	else
	{
		c=zz-1;
		k-=c;
	}
	

	LL ans = (a+1)*(b+1)*(c+1);
	cout<<ans<<endl;
}

bool input()
{
	s(x); s(y); s(z); s(k);
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