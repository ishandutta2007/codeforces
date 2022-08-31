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

bool isLucky(int n)
{
	while(n)
	{
		int z=n%10;
		if(z!=4 && z!=7) return false;
		n /= 10;
	}
	return true;
}

VVI adjl;
bool done1[100005];
bool done2[100005];
int sc[100005];

int dfs1(int u)
{
	int cnt=1;
	done1[u]=true;
	for(int i=0;i<adjl[u].size();i++)
	{
		int v=adjl[u][i];
		if(!done1[v])
			cnt += dfs1(v);
	}
	return cnt;
}

void dfs2(int u,int val)
{
	sc[u]=val;
	done2[u]=true;
	for(int i=0;i<adjl[u].size();i++)
	{
		int v=adjl[u][i];
		if(!done2[v])
			dfs2(v,val);
	}
}

		

void preprocess()
{

}
int N;

void solve()
{
	fill(done1,false);
	fill(done2,false);
	for(int i=0;i<N;i++)
	{
		if(!done1[i])
		{
			int z=dfs1(i);
			dfs2(i,z);
		}
	}
	
	LL sum = 0;
	
	for(int i=0;i<N;i++)
	{
		LL z = N-sc[i];
		sum += z*(z-1);
	}
	
	cout<<sum<<endl;
}

bool input()
{
	s(N);
	adjl.resize(N);
	
	int a,b,w;
	for(int i=0;i<N-1;i++)
	{
		s(a); s(b); s(w);
		if(isLucky(w)) continue;
		a--; b--;
		adjl[a].pb(b);
		adjl[b].pb(a);
	}
	//cout<<"done"<<endl;
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