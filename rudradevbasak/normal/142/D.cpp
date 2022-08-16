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
//#include<debugger>

using namespace std;

#define s(n)					scanf("%d",&n)
#define sl(n) 					scanf("%lld",&n)
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
int R,C,K;


void preprocess()
{

}

void solve()
{

		
}



bool input()
{
	s(R); s(C); s(K);
	char temp[1005];
	int cnt=0;
	int sum=0;
	int cnt1=0;
	int ronly=0,gonly=0;
	VI diff;
	
	for(int i=0;i<R;i++)
	{
		ss(temp);
		int posr=-1,posg=-1,pose=-1;
		for(int j=0;j<C;j++)
		{
			if(temp[j]=='R')
				posr=j;
			else if(temp[j]=='G')
				posg=j;
			else
				pose=j;
		}
		
		if(posr>=0 && posg<0 && pose>=0)
			ronly++;
		if(posr<0 && posg>=0 && pose>=0)
			gonly++;
			
		if(posr>=0 && posg>=0)
		{
			cnt++;
			int d = abs(posr-posg)-1;
			sum += d;
			if(abs(posr-posg)==2)
				cnt1++;
			diff.pb(d);
		}
	}
	
	if(ronly>0 && gonly>0)
		printf("Draw\n");
	else if(gonly>0)
		printf("First\n");
	else if(ronly>0)
		printf("Second\n");
	else
	{
	
		bool nonz=false;
		for(int i=0;i<10;i++)
		{
			int tot=0;
			for(int j=0;j<diff.size();j++)
				if(diff[j]&(1<<i))
					tot++;
				
			if(tot%(K+1) != 0)
			{
				nonz=true;
				break;
			}
		}
		
		if(nonz)
			printf("First\n");
		else
			printf("Second\n");
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