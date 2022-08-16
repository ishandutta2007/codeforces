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
int n;
VI pos[2000][26];
char temp[1000005];
int m;
int ind[2000];
int nxt[26][2000];

char str[2005];
int len;
PII dp[2005];

void solve()
{
	for(int i=0;i<26;i++)
		for(int j=m-1;j>=0;j--)
		{
			if(j==m-1)
				nxt[i][j]=m;
			else
			{
				if(pos[ind[j+1]][i].size()>0)
					nxt[i][j]=j+1;
				else
					nxt[i][j]=nxt[i][j+1];
			}			
			//debug(i,j,nxt[i][j]);
		}
	//debug("nxt calc done");
	
	for(int i=0;i<=2000;i++)
		dp[i] = mp(-1,-1);
	dp[0]=mp(0,-1);
	
	for(int i=0;i<len;i++)
	{
		int z = str[i]-'a';
		for(int j=i;j>=0;j--)
		{
			int index = dp[j].FF;
			int curpos = dp[j].SS;
			if(index<0) continue;
			
			//first check in current string
			int curstr = ind[index];
			VI::iterator it = upper_bound(all(pos[curstr][z]),curpos);
			if(it==pos[curstr][z].end())
			{
				int nxtstr = nxt[z][index];
				if(nxtstr != m)
				{
					int firstpos = pos[ind[nxtstr]][z][0];
					if(dp[j+1].FF<0 || mp(nxtstr,firstpos) < dp[j+1])
						dp[j+1] = mp(nxtstr,firstpos);
				}
			}
			else
			{
				int nextpos = *it;
				if(dp[j+1].FF<0 || mp(index,nextpos)<dp[j+1])
					dp[j+1] = mp(index,nextpos);
			}
		}
	}
	
	int ans=0;
	for(int i=0;i<=len;i++)
		if(dp[i].FF>=0)
			ans = max(ans,i);
	printf("%d\n",ans);
}

bool input()
{
	s(n);
	for(int i=0;i<n;i++)
	{
		ss(temp);
		int k=strlen(temp);
		for(int j=0;j<k;j++)
		{
			int z = temp[j]-'a';
			pos[i][z].pb(j);
		}
	}
	//debug("pos calc done");
	
	s(m);
	for(int i=0;i<m;i++)
	{
		s(ind[i]);
		ind[i]--;
	}
		
	ss(str);
	len = strlen(str);
			
	//debug("input done");
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