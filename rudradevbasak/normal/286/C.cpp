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
#define sc(n)                   {char temp[4]; ss(temp); n=temp[0];}
#define INF						(int)1e9
#define LINF					(long long)1e18
#define EPS						1e-9
#define maX(a,b)				((a)>(b)?(a):(b))
#define miN(a,b)				((a)<(b)?(a):(b))
#define abS(x)					((x)<0?-(x):(x))
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


#define debugger cerr
#define debug(args...)			{mdbg,args; debugger<<endl;}
#define PRINT_CONTAINER(o,v)    {if(v.size()==0) return o<<"{}"; o<<"{"; foreach(it,v) o<<*it<<" "; return o<<"\b}";}
struct multidebug {template<typename T> multidebug& operator , (const T &v) {debugger<<v<<" "; return *this;}} mdbg;
template<class T> ostream& operator << (ostream& o,const vector<T> &v) PRINT_CONTAINER(o,v)
template<class T> ostream& operator << (ostream& o,const set<T> &v) PRINT_CONTAINER(o,v)
template<class A,class B> ostream& operator << (ostream& o,const map<A,B> &v) PRINT_CONTAINER(o,v)
template<class A,class B> ostream& operator << (ostream& o,const pair<A,B> &p) {o<<"("<<p.first<<","<<p.second<<")"; return o;}
template<class T> void debugarr(T* v,int n) {debugger<<"{"; for(int i=0;i<n;i++) debugger<<v[i]<<" "; debugger<<"\b}"<<endl;}


typedef long long LL;
typedef pair<int,int> PII;
typedef pair<LL,LL> PLL;
typedef pair<int,PII> TRI;
typedef vector<int> VI;
typedef vector<LL> VL;
typedef vector<PII> VII;
typedef vector<TRI> VT;




/*Main code begins now */
int testnum;
int n;
const int MAXN = 1000005;
int arr[MAXN];
int prev[MAXN];
VI pos;
int stk[MAXN];
int ind[MAXN];
int top;

bool remove(int u)
{
	int v=u;
	top=0;
	while(u>=0)
	{
		if(top>0 && stk[top-1] == arr[u])
		{	
			arr[ind[top-1]] *= -1;
			top--;
			if(top==0)
			{
				prev[v+1] = prev[u];
				return true;
			}
		}
		else
		{
			stk[top] = arr[u];
			ind[top] = u;
			top++;
		}
		u = prev[u];
	}
	return false;
}
		

void solve()
{
	sort(all(pos));
	for(int itr=0;itr<pos.size();itr++)
	{
		int z = pos[itr];
		if(!remove(z))
		{
			printf("NO\n");
			return;
		}
	}
	printf("YES\n");
	for(int i=1;i<=n;i++)
		printf("%d ",arr[i]);
		
}

bool input()
{
	s(n);
	prev[0] = -1;
	prev[1] = 0;
	arr[0]=0;
	for(int i=1;i<=n;i++)
	{
		s(arr[i]);
		prev[i+1]=i;
	}
	arr[n+1]=0;
	int k; s(k);
	for(int i=0;i<k;i++)
	{
		int z; s(z);
		pos.pb(z);
	}
	pos.pb(n+1);
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