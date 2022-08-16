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

int n,m,k;
const int maxNode = 1000000;
int deg[maxNode];
VI adjList[maxNode];

int component[maxNode];			// what is component number of vertex v
int compSize[maxNode];			// how many vertices in comp c
int totalSCC;					// how many total components found

	
int dfsNum[maxNode], minDfsNum[maxNode], dfsNext;
int currentComp[maxNode], currentSize;
bool inComp[maxNode];

void dfs(int u)
{
	if( dfsNum[u] >= 0) return;
	
	minDfsNum[u] = dfsNum[u] = dfsNext++;
	
	currentComp[currentSize++] = u;	// Insert u in current component
	inComp[u] = true;

	for(int i = 0; i < deg[u]; i++)
	{
		int v = adjList[u][i];
		dfs(v);
		
		if( inComp[v] )		// Check is only for cross edges
			minDfsNum[u] = min (minDfsNum[u], minDfsNum[v] );	
	}

	if( minDfsNum[u] == dfsNum[u] )		// New component found 
	{
		while(true)
		{
			int v = currentComp[--currentSize];
			component[v] = totalSCC;
			compSize[totalSCC] ++;
			inComp[v] = false;
			if( u == v) break;
		}
		totalSCC ++;
	}
}

void scc(int N)
{

	memset( dfsNum, -1, sizeof dfsNum);	// dfsNum also works as visited array
	memset( compSize, 0, sizeof compSize);
	memset( inComp, false, sizeof inComp);
	
	currentSize = dfsNext= totalSCC = 0;
	
	for( int i = 0; i < N; i++ )
		if( dfsNum[i] < 0)	dfs( i );

}



void preprocess()
{

}

void solve()
{
	scc(n);
	int N=totalSCC;
	int small=0,big=0;
	int largest=0;
	int total=0;
	for(int i=0;i<N;i++)
	{
		if(compSize[i] == 1) small++;
		else
		{
			big++;
			total+=min(compSize[i],k);
		}
		largest=max(largest,compSize[i]);
	}
	
	if(k==1)
	{
		if(N>=2)
			printf("%d\n",N-2);
		else
			printf("0\n");
		return;
	}
	

	
	if(big==0)
	{
		printf("%d\n",(N-1)/2);
		return;
	}
	
	int ans=0;
	total -= 2*big - 2;
	small -= total;
	while(small>0)
	{
		ans++;
		small-=2;
	}
	
	printf("%d\n",ans);
	
		
}

bool input()
{
	s(n); s(m); s(k);
	fill(deg,0);
	
	int x,y;
	for(int i=0;i<m;i++)
	{
		s(x); s(y);
		x--; y--;
		deg[x]++; deg[y]++;
		adjList[x].pb(y);
		adjList[y].pb(x);

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