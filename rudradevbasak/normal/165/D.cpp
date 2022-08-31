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
int n,m;
VI adjl[100005];
int a[100005];
int b[100005];

int centre;
int dist[100005];

VVI stree;
int chain[100005];

void preprocess()
{

}

int get(int lo,int hi,int chn,int ind,int beg,int end)
{
	if(beg>hi || end<lo) return 0;
	if(lo<=beg && end<=hi) return stree[chn][ind];
	
	int twice = ind+ind;
	int mid = (beg+end)>>1;
	return get(lo,hi,chn,twice,beg,mid) + get(lo,hi,chn,twice+1,mid+1,end);
}

int marke(int ind,int z)
{
	int x=a[ind];
	int y=b[ind];
	if(dist[x]<dist[y])
		swap(x,y);
		
	int chn = chain[x];
	int num = dist[x]-1;
	
	num += stree[chn].size()/2;
	stree[chn][num]=z;
	for(num>>=1; num; num>>=1)
		stree[chn][num] = stree[chn][num+num] + stree[chn][num+num+1];
}
	


void dfs(int u,int d)
{
	dist[u]=d;
	int k=0;
	for(int i=0;i<adjl[u].size();i++)
	{
		int v=adjl[u][i];
		if(dist[v]<0)
		{
			k++;
			dfs(v,d+1);
		}
	}
	
	if(k==0)
	{
		int len=4;
		while(len < d+1) len+=len;
		VI tree(len+len);
		stree.pb(tree);
	}
	chain[u]=stree.size()-1;
}


void solve()
{
	centre=1;
	for(int i=1;i<=n;i++)
		if(adjl[i].size()>2)
			centre=i;
		
	fill(dist,-1);
	dfs(centre,0);
	
	s(m);
	for(int i=0;i<m;i++)
	{
		int mode; s(mode);
		if(mode==3)
		{
			int x,y;
			s(x); s(y);
			if(dist[x]<dist[y]) swap(x,y);
			if(chain[x]==chain[y])
			{
				if(get(dist[y],dist[x]-1,chain[x],1,0,stree[chain[x]].size()/2-1) == 0)
					printf("%d\n",dist[x]-dist[y]);
				else
					printf("-1\n");
			}
			else
			{
				if(get(0,dist[x]-1,chain[x],1,0,stree[chain[x]].size()/2-1) == 0 && get(0,dist[y]-1,chain[y],1,0,stree[chain[y]].size()/2-1) == 0)
					printf("%d\n",dist[x]+dist[y]);
				else
					printf("-1\n");
			}
		}
		else
		{
			int ind; s(ind);
			marke(ind,mode-1);
		}
	}
			
	
		
}



bool input()
{
	s(n);
	for(int i=1;i<n;i++)
	{
		s(a[i]); s(b[i]);
		adjl[a[i]].pb(b[i]);
		adjl[b[i]].pb(a[i]);
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