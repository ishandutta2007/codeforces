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

#define mp							make_pair
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
vector<pair<LL,LL> > e;
int n;
LL v;

struct event
{
	LL t,x,v;
	LL q;
	
	event(LL a, LL b, LL c)
	{
		t = a;
		x = b;
		v = c;
		q=v*t-x;
	}
};

bool canReach(event a, event b)
{
	return (b.t-a.t)*b.v >= abs(b.x-a.x);
}

bool operator < (event a, event b)
{
	return a.q > b.q;
}

vector<LL> M;
vector<LL> seq;


void preprocess()
{

}


void solve()
{
	sort(e.begin(),e.end());
	for(int i = 0; i < n; i++)
		seq.push_back(e[i].second);
	int L = 0;
	M.resize(1);
	
	for(int i=0;i<n;i++)
	{
		int lo, hi;
		lo = 0; hi = L;
		
		while(hi>lo)
		{
			int mid = lo + (hi-lo+1)/2;
			if(seq[M[mid]] <= seq[i] )
				lo=mid;
			else
				hi=mid-1;
		}

		int j=lo;
		if(j == 0)
		{
			if(e[i].first < 0 || e[i].second < 0)
				continue;
		}

	 	if(j == L)
	 	{
	 		M.pb(i);
	 		L++;
	 	}
	 	else if(seq[i]<seq[M[j+1]])
       		M[j+1] = i;
	}

	int L1 = 0;
	M.resize(1);
	M[0]=-INF;
	for(int i=0;i<n;i++)
	{
		int lo, hi;
		lo = 0; hi = L1;
		
		while(hi>lo)
		{
			int mid = lo + (hi-lo+1)/2;
			if(seq[M[mid]] <= seq[i] )
				lo=mid;
			else
				hi=mid-1;
		}
		
		int j=lo;
	 	if(j == L1)
	 	{
	 		M.pb(i);
	 		L1++;
	 	}
	 	else if(seq[i]<seq[M[j+1]])
       		M[j+1] = i;
	}


	printf("%d %d\n",L,L1);
				
			

				
}

void input()
{
	s(n);
	int x,t;
	for(int i=0;i<n;i++)
	{
		s(x); s(t);
		e.pb( mp( (LL)x, (LL)t ) );
	}
	s(x);
	v=x;
	for(int i=0;i<n;i++)
		e[i] = mp( e[i].first + v*e[i].second, - e[i].first + v*e[i].second);
}


int main()
{

		input();
		solve();

}