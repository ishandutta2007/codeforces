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

struct edge
{
	int a,b,d,ind;
	edge(int aa,int bb,int dd,int i)
	{
		a=aa;
		b=bb;
		d=dd;
		ind=i;
	}
};

bool operator < (edge a,edge b)
{
	return a.d>b.d;
}

#define MAXN 100005
int treeSize[MAXN];
int parent[MAXN];
bool done[MAXN];

LL trees[MAXN];

int n;
vector<edge> arr;

VI adjList[MAXN];

void preprocess()
{

}

int dfs(int u,int par)
{
	parent[u]=par;
	treeSize[u]=1;
	for(int i=0;i<adjList[u].size();i++)
	{
		if(adjList[u][i]!=par)
			treeSize[u]+=dfs(adjList[u][i],u);
	}
	return treeSize[u];
}

LL compSize(int ind)
{
	if(parent[ind]<0) return treeSize[ind];
	return compSize(parent[ind]);
}

void update(int u,int val)
{
	treeSize[u]-=val;
	if(parent[u]>=0) update(parent[u],val);
}
	

void solve()
{
	fill(treeSize,0);
	fill(done,false);
	dfs(1,-1);
	
	int ind=0;
	while(ind<n-1)
	{
		int cur=arr[ind].d;
		int next=ind;
		while(next<(n-1) && arr[next].d==cur)
			next++;
			
		for(int i=ind;i<next;i++)
		{
			int a=arr[i].a;
			int b=arr[i].b;
			if(b==parent[a])
			{
				int t=a;
				a=b;
				b=t;
			}
			
			int total = compSize(a);
			int below = treeSize[b];
			
			
			trees[arr[i].ind]+=2LL * below * (total-below);
		}
		
		for(int i=ind;i<next;i++)
		{
			int a=arr[i].a;
			int b=arr[i].b;
			if(b==parent[a])
			{
				int t=a;
				a=b;
				b=t;
			}
			
			int below = treeSize[b];
			
			parent[b]=-1;
			update(a,below);
		}
		
		ind=next;
	}
	
	LL ans=0;
	for(int i=1;i<n;i++)
		ans=max(ans,trees[i]);
	int cnt=0;
	for(int i=1;i<n;i++)
		if(trees[i]==ans)
			cnt++;
	
	cout<<ans<<" "<<cnt<<endl;
	for(int i=1;i<n;i++)
		if(trees[i]==ans)
			cout<<i<<" ";
	
	
}

bool input()
{
	s(n);
	arr.clear();
	int x,y,z;
	for(int i=1;i<n;i++)
	{
		s(x); s(y); s(z);
		arr.pb(edge(x,y,z,i));
		adjList[x].pb(y);
		adjList[y].pb(x);
	}
	sort(arr.begin(),arr.end());
	
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