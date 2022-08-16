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
int a,b;

pair<int,bool> reach(int pos,bool plus,bool top)
{
	if(!top)
	{
		if(plus)
		{
			pos+=(a-1);
			if(pos>=b)	return mp(b-(pos-b),false);
			else return mp(pos,true);
		}
		else
		{
			pos-=(a-1);
			if(pos<=1)	return mp(-pos+2,true);
			else return mp(pos,false);
		}
	}
	else
	{
		if(plus)
		{
			pos+=(a-1);
			if(pos>=b)	return reach(b-(pos-b),false,false);
			else return reach(pos,true,false);
		}
		else
		{
			pos-=(a-1);
			if(pos<=1)	return reach(-pos+2,true,false);
			else return reach(pos,false,false);
		}
	}			
}

void preprocess()
{

}
bool done[1000005];

void dfs(int pos,bool plus)
{
	done[pos]=true;
	pair<int,bool> nxt=reach(pos,plus,true);
	//printf("From %d %d to %d %d\n",pos,plus,nxt.first,nxt.second);
	if(!done[nxt.first])
		dfs(nxt.first,nxt.second);
}

void solve()
{
	int ans=0;
	
	fill(done,false);
	
	
	for(int i=1;i<=b;i++)
		if(!done[i])
		{
			dfs(i,true);
			done[i]=false;
			dfs(i,false);
			ans++;
		}
		
	printf("%d\n",ans);
}

bool input()
{
	s(a); s(b);
	if(a>b)
	{
		int t=a;
		a=b;
		b=t;
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