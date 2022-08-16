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

void debugarr(int * arr,int n)
{
	cout<<"[";
	for(int i=0;i<n;i++)
		cout<<arr[i]<<" ";
	cout<<"]"<<endl;
}





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
int p[10000];
int nump;
int pwr[6];

int isp[100000];
int mat[5][5];

int begs[6][100000];
int eends[6][100000];

void preprocess()
{
	pwr[0]=1;
	for(int i=1;i<6;i++)
		pwr[i]=pwr[i-1]*10;
	
	fill(isp,true);
	nump=0;

	
	for(int i=2;i<100000;i++)
		if(isp[i])
		{
			p[nump++]=i;
			for(int j=i+i;j<100000;j+=i)
				isp[j]=false;
		}
	//debug("sieve");
		
	fill(begs,nump);
	fill(eends,0);
	for(int len=1;len<=4;len++)
		for(int i=0;i<100000;i++)
		{
			
			int lo = (i/pwr[len])*pwr[len];
			int hi = lo+pwr[len];
			begs[len][i] = lower_bound(p,p+nump,lo)-p;
			eends[len][i] = lower_bound(p,p+nump,hi)-p;
		}
		
	//debug("pre done");
}

int n;
int k;
int ans;
int nums[6];

void recurse(int lvl)
{
	if(lvl==k)
	{
		ans += eends[1][nums[k]] - begs[1][nums[k]];
		return;
	}
	else
	{
		int lo = begs[k-lvl+1][nums[lvl]];
		int hi = eends[k-lvl+1][nums[lvl]];
		//debug("recurse",lvl,nums[lvl],lo,hi);
		//if(lvl==3) debugarr(nums,5);
		for(int i=lo;i<hi;i++)
		{
			
			int temp=p[i];
			for(int j=k;j>lvl;j--)
			{
				nums[j] += (temp%10) * pwr[k-lvl];
				temp /= 10;
			}
			
			recurse(lvl+1);
			
			temp=p[i];
			for(int j=k;j>lvl;j--)
			{
				nums[j] -= (temp%10) * pwr[k-lvl];
				temp /= 10;
			}
		}
	}
}

void solve()
{
	ans=0;
	recurse(2);
	cout<<ans<<endl;
}



bool input()
{
	s(n);
	int temp=n;
	k=0;
	while(temp)
	{
		temp/=10;
		k++;
	}
	
	temp=n;
	for(int i=k;i>1;i--)
	{
		nums[i]=(temp%10)*pwr[k-1];
		temp/=10;
	}
	
	return true;
}


int main()
{
	preprocess();
	int T; s(T);
	for(testnum=1;testnum<=T;testnum++)
	{
		if(!input()) break;
		solve();
	}
}