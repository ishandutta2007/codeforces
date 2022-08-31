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
int dpa[200005];
int dpb[200005];
VI posn[26];
char s[200005];
char t[200005];
int ns,nt;
void solve()
{
	ns=strlen(s);
	nt=strlen(t);
	for(int i=0;i<nt;i++)
	{
		int z = t[i]-'a';
		posn[z].pb(i);
	}
	
	dpa[0]=0;
	for(int i=0;i<ns;i++)
	{
		dpa[i+1]=dpa[i];
		int z = dpa[i];
		if(z<nt && s[i]==t[z])
			dpa[i+1] = z+1;
	}
	
	dpb[ns]=0;
	for(int i=ns-1;i>=0;i--)
	{
		int z=dpb[i+1];
		dpb[i]=z;
		if(z<nt && s[i]==t[nt-1-z])
			dpb[i] = z+1;
	}
	
	bool nf = false;
	for(int i=0;i<ns;i++)
	{
		int b = dpa[i];
		
		int e = dpb[i+1];
		
		//debug(i,b,e);
		if(b+e+1 < nt)
			nf=true;
		else
		{
			int ind = s[i]-'a';
			
			VI::iterator it = lower_bound(all(posn[ind]), nt-e-1);
			int diff = it - posn[ind].begin();
			if(diff<0 || diff>=posn[ind].size())
			{
				nf=true;
				break;
			}
			if(it == posn[ind].end() || (*it) > b)
				nf=true;
		}
	}
	
	if(nf)
		printf("No\n");
	else
		printf("Yes\n");
		
}

bool input()
{
	ss(s);
	ss(t);
	return true;
}


int main()
{
	int T=1;
	for(testnum=1;testnum<=T;testnum++)
	{
		if(!input()) break;
		solve();
	}
}