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
#define INF							(LL)1e18
#define EPS							1e-9
#define bitcount					__builtin_popcount
#define all(x)						x.begin(), x.end()
#define gcd							__gcd
#define maX(a,b)					(a>b?a:b)
#define miN(a,b)					(a<b?a:b)
#define DREP(a)						sort(all(a)); a.erase(unique(all(a)),a.end())
#define INDEX(arr,ind)				lower_bound(all(arr),ind)-arr.begin()

typedef vector<int> VI;
typedef vector<vector<int> > VVI;
typedef long long LL;
typedef vector<long long > VLL;
typedef pair<int, int > PII;

/*Main code begins now */
int testnum;
LL psum[200005];
LL dp[200005];

vector<pair<int,LL > > races[200005];

LL stree[1<<19];
LL lazy[1<<19];
const int BASE = 1<<18;

void add(int ind,int beg,int end,int lo,int hi,LL val)
{
	if(beg>hi || end<lo) return;
	if(beg<=lo && end>=hi)
	{
		lazy[ind]+=val;
		stree[ind]+=val;
		int cur=(ind>>1);
		while(cur>0)
		{
			stree[cur] = max(stree[(cur<<1)],stree[(cur<<1)+1])+lazy[cur];
			cur>>=1;
		}
	}
	else
	{
		add((ind<<1),beg,end, lo,((lo+hi)>>1),val);
		add((ind<<1)+1,beg,end, ((lo+hi)>>1)+1,hi,val);
	}
}

LL findMax(int ind,int beg,int end,int lo,int hi)
{
	if(beg>hi || end<lo) return -INF;
	if(beg<=lo && end>=hi) return stree[ind];
	
	return lazy[ind] + max( findMax((ind<<1),beg,end, lo,((lo+hi)>>1)), findMax((ind<<1)+1,beg,end, ((lo+hi)>>1)+1,hi));
}

void add(int beg,int end,LL val)
{
	add(1,beg,end,0,BASE-1,val);
	//cout<<"Add : "<<beg<<","<<end<<" : "<<val<<endl;
}

LL findMax(int beg,int end)
{
	LL val = findMax(1,beg,end,0,BASE-1);
	//cout<<"FindMAX : "<<beg<<","<<end<<" : "<<val<<endl;
	return val;
}
		
	


int n,m;


void preprocess()
{

}

void solve()
{
	for(int j=0;j<races[0].size();j++)
		add(0,BASE-1,-races[0][j].second);
	dp[0]=max((LL)0,-findMax(0,0));
	add(0,0,dp[0]);
	
	for(int i=1;i<n;i++)
	{
		for(int j=0;j<races[i].size();j++)
			add(races[i][j].first,BASE-1,-races[i][j].second);
			
		LL ans=max((LL)0,dp[i-1]); // do nothing
		LL z=-findMax(i,i);
		
		ans = max(ans,z);
		ans = max(ans, findMax(0,i-1)+z);
		
		dp[i]=ans;
		add(i,i,dp[i]);
	}
	
	//for(int i=0;i<n;i++)
	//	cout<<"DP ["<<i<<"] = "<<dp[i]<<endl;
		
	
	cout<<dp[n-1]<<endl;
}


bool input()
{
	fill(psum,0);
	s(n); s(m);
	
	fill(stree,0);
	fill(lazy,0);
	
	int x;
	for(int i=0;i<n;i++)
	{
		s(x);
		
		if(i==0) psum[i]=x;
		else psum[i]=x+psum[i-1];
		
		add(i,i,psum[i]);
		
	}
	
	int lb,ub,p;
	for(int i=0;i<m;i++)
	{
		s(lb); s(ub); s(p);
		lb--;
		ub--;
		races[ub].pb(mp(lb,(LL)p));
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