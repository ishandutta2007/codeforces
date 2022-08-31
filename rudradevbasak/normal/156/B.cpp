#include<vector>
#include<stack>
#include<set>
#include<map>
#include<queue>
#include<deque>
#include<string>
#include<iostream>
#include<algorithm>
#include<cstring>
#include<cassert>
#include<cstdlib>
#include<cstdio>
#include<cmath>
#include<string>

using namespace std;

#define s(n)					scanf("%d",&n)
#define sf(n) 					scanf("%lf",&n)
#define ss(n) 					scanf("%s",n)
#define INF						(int)1e9
#define LINF					(long long)1e18
#define EPS						1e-9
#define maX(a,b)				((a)>(b)?(a):(b))
#define miN(a,b)				((a)<(b)?(a):(b))
#define abS(x)					((x)<0?-(x):(x))
#define FOR(i,a,b)				for(int i=a;i<b;i++)
#define REP(i,n)				FOR(i,0,n)
#define foreach(v,c)            for( typeof((c).begin()) v = (c).begin();  v != (c).end(); ++v)
#define mp						make_pair
#define FF						first
#define SS						second
#define tri(a,b,c)				mp(a,mp(b,c))
#define XX						first
#define YY						second.first
#define ZZ						second.second
#define pb						push_back
#define fill(a,v) 				memset(a,v,sizeof a)
#define all(x)					x.begin(),x.end()
#define SZ(v)					((int)(v.size()))
#define DREP(a)					sort(all(a)); a.erase(unique(all(a)),a.end())
#define INDEX(arr,ind)			(lower_bound(all(arr),ind)-arr.begin())
#define debug(args...)			{dbg,args; cerr<<endl;}
#define dline					cerr<<endl	

void sc(char &c){
	char temp[4];	ss(temp);	
	c=temp[0];
}

struct debugger
{
	template<typename T> debugger& operator , (const T& v)
	{	
		cerr<<v<<" ";	
		return *this;	
	}
} dbg;




typedef long long LL;
typedef pair<int,int> PII;
typedef pair<LL,LL> PLL;
typedef pair<int,PII> TRI;

typedef vector<int> VI;
typedef vector<LL> VL;
typedef vector<PII> VII;
typedef vector<PLL> VLL;
typedef vector<TRI> VT;

typedef vector<VI> VVI;
typedef vector<VL> VVL;
typedef vector<VII> VVII;
typedef vector<VLL> VVLL;
typedef vector<VT> VVT;


/*Main code begins now */

int testnum;
const int MAXN=100005;
bool kill[MAXN];
int pcnt[MAXN];
int ncnt[MAXN];
int ptot,ntot;
int arr[MAXN];


int n,m;


void preprocess()
{

}

void solve()
{
	s(n); s(m);
	fill(pcnt,0);
	fill(ncnt,0);
	fill(kill,false);
	ptot=0;
	ntot=0;
	
	int x;
	for(int i=0;i<n;i++)
	{
		s(x);
		if(x>0)
		{
			pcnt[x-1]++;
			ptot++;
		}
		else
		{
			ncnt[(-x)-1]++;
			ntot++;
		}
		arr[i]=x;
	}
	//debug(ptot,ntot);
	
	int kcnt=0;
	for(int i=0;i<n;i++)
	{
		//debug("haha",i,ncnt[i],pcnt[i],ncnt[i]+(ptot-pcnt[i]));
		if(pcnt[i]+(ntot-ncnt[i]) == m)
		{
			kill[i]=true;
			kcnt++;
		}
	}
			
	for(int i=0;i<n;i++)
	{
		int x=arr[i];
		if(x>0)
		{
			if(kill[x-1] && kcnt==1)
				printf("Truth\n");
			else if(kill[x-1])
				printf("Not defined\n");
			else
				printf("Lie\n");
		}
		else
		{
			x=-x;
			if(kill[x-1] && kcnt==1)
				printf("Lie\n");
			else if(kill[x-1])
				printf("Not defined\n");
			else
				printf("Truth\n");
		}
	}
		
}



bool input()
{
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