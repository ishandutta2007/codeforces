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
typedef pair<double, pair<double,double> > trid;

/*Main code begins now */
int testnum;
int N;
VVI adjList;
VVI adjLen;
bool done[100005];

trid dfs(int u)
{
	done[u]=true;
	vector<trid> arr;
	for(int i=0;i<adjList[u].size();i++)
	{
		int v = adjList[u][i];
		int l = adjLen[u][i];
		
		if(!done[v])
		{
			trid t = dfs(v);
			double e = t.first + l;
			double tot = t.second.first + l + l;
			double nn = t.second.second;
			
			arr.pb(mp(tot/nn, mp(e, tot)));
		}
	}
	
	sort(arr.begin(), arr.end());
	double exp=0,tot=0,nn=0;
	for(int i=0;i<arr.size();i++)
	{
		double n = arr[i].second.second/arr[i].first;
		exp+= n*(tot + arr[i].second.first);
		tot+= arr[i].second.second;
		nn += n;
	}
	nn++;
	return mp(exp/nn, mp(tot,nn));
}


void preprocess()
{

}

void solve()
{
	fill(done,false);
	trid t = dfs(0);
	double e = t.first;
	printf("%.9lf\n",(e*N)/(N-1));
}

bool input()
{
	s(N);
	adjList.resize(N);
	adjLen.resize(N);
	int a,b,d;
	for(int i=0;i<N-1;i++)
	{
		s(a); s(b); s(d);
		a--; b--;
		adjList[a].pb(b);
		adjLen[a].pb(d);
		
		adjList[b].pb(a);
		adjLen[b].pb(d);
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