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
char str[1000005];
int k,n;

void preprocess()
{

}

int bef(int pos)
{
	int cnt=1;
	for(int i=pos-1;i>=0;i--)
	{
		if(str[i]=='1')
			break;
		cnt++;
	}
	return cnt;
}

int aft(int pos)
{
	int cnt=1;

	for(int i=pos+1;i<n;i++)
	{
		if(str[i]=='1')
			break;
		cnt++;
	}
	return cnt;
}

void solve()
{
	LL ans=0;
	n=strlen(str);
	
	VI pos;
	for(int i=0;i<n;i++)
		if(str[i]=='1')
			pos.pb(i);
	if(k==0)
	{
		pos.pb(n);
		LL z=pos[0];
		ans += z*(z+1)/2;
		
		for(int i=1;i<pos.size();i++)
		{
			LL z = pos[i]-pos[i-1]-1;
			ans += z*(z+1)/2;
		}
		cout<<ans<<endl;
		return;
	}
			
	int len=pos.size();
	for(int i=0;i+k<=len;i++)
		ans += (LL)bef(pos[i]) * aft(pos[i+k-1]);
	cout<<ans<<endl;
		
}



bool input()
{
	s(k);
	ss(str);
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