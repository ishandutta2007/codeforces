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

vector <int> mice; int N;
vector <int> cheese; int M;

bool useen[100005];
bool vseen[100005];

bool mTaken[100005];
bool cTaken[100005];

vector<int> adjList[100005];
int matchR[100005];
int matchL[100005];

void preprocess()
{

}

int minD(int mval)
{
	vector <int>::iterator upos = upper_bound(cheese.begin(), cheese.end(), mval);
	int ans=INF;
	vector <int>::iterator lpos = upos-1;
	if( upos != cheese.end())
		ans=min(ans, abs((*upos)-mval));
	if( upos != cheese.begin())
		ans=min(ans, abs((*lpos)-mval));
	return ans;
}


bool bpm(int ind)
{
	for(int i=0;i<adjList[ind].size();i++)
	{
		int v=adjList[ind][i];
		if(vseen[v]) continue;
		vseen[v]=true;
		
		if(matchR[v]<0 || bpm(matchR[v]))
		{
			matchR[v]=ind;
			matchL[ind]=v;
			return true;
		}
	}
	return false;
}
			

void solve()
{
	int hungry=N;
	fill(mTaken,false);
	fill(cTaken,false);
	for(int i=0;i<M;i++)
	{
		vector <int>::iterator upos = upper_bound(mice.begin(), mice.end(), cheese[i]);
		int uind=upos-mice.begin();
		int lind=uind-1;
		if(uind==N || uind==0)
			continue;
		
		if(cheese[i] - mice[lind] == mice[uind] - cheese[i])
		{
			//printf("Nearest to %d is %d, %d\n", cheese[i], mice[lind], mice[uind]);
		
			int d=minD(mice[uind]);
			if(d != mice[uind] - cheese[i])
				continue;
			d = minD(mice[lind]);
			if(d != cheese[i] - mice[lind])
				continue;
			
			cTaken[i] = true;
			
			if(!mTaken[uind])	hungry--;
			if(!mTaken[uind-1])	hungry--;
			
			mTaken[uind] = true;
			mTaken[uind - 1] = true;
			
		}
	}
	//printf("hungry now = %d\n",hungry);
	
	//create bp graph;
	for(int i=0;i<N;i++)
	{
		if(mTaken[i]) continue;
		int mval=mice[i];
		vector <int>::iterator upos = upper_bound(cheese.begin(), cheese.end(), mval);
		vector <int>::iterator lpos = upos-1;
		int uind = upos-cheese.begin();
		int lind = uind-1;
		
		int d=INF;
		if( upos != cheese.end())
			d=min(d, abs((*upos)-mval));
		if( upos != cheese.begin())
			d=min(d, abs((*lpos)-mval));

		if( upos != cheese.end())
			if( d == abs((*upos)-mval))
				if(!cTaken[uind])
					adjList[i].pb(uind);
				
		if( upos != cheese.begin())
			if( d == abs((*lpos)-mval))
				if(!cTaken[lind])
					adjList[i].pb(lind);
	}
	
	fill(matchR,-1);
	fill(matchL,-1);
	
	for(int i=0;i<N;i++)
	{
		fill(vseen,false);
		if(bpm(i)) hungry--;
	}
	printf("%d\n",hungry);
}

void input()
{
	s(N);
	s(M);
	int useless; s(useless); s(useless);
	
	for(int i = 0; i < N; i++)
	{
		s(useless);
		mice.push_back(useless);
	}
	for(int i = 0; i < M; i++)
	{
		s(useless);
		cheese.push_back(useless);
	}
}


int main()
{

		input();
		solve();

}