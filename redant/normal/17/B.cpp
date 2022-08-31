/*
LANG: C++
ID: AnilKishore (RedAnt/FlyingAnt)
 */

#include <cstdio>
#include <iostream>
#include <cmath>
#include <cstring>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <string>
#include <cstdlib>

using namespace std;

typedef long long LL;
typedef vector<int> VI;
typedef vector<VI> VVI;
typedef pair<int,int> PI;

#define INF 100000000
#define PB push_back
#define MP make_pair
#define LL long long
#define FILL(v,x) memset(v,x,sizeof(v))
#define ALL(v) (v).begin(),(v).end()
#define SI(x) scanf("%d",&x)

#define MXN 1003
#define MXC 1000005

int V[MXN], cost[MXN][MXN], val[MXN];
int n,m,tosee;
vector<int> adj[MXN];

class Node
{
	public:
	int i,j,c;
	Node(int ii,int jj,int cc):i(ii),j(jj),c(cc){}
};

bool operator<(const Node& n1,const Node& n2)
{
	return n1.c<n2.c;
}

priority_queue<Node> pq;


void dfs(int cn)
{
	for(int i=0;i<adj[cn].size();i++)
		if(!V[adj[cn][i]] && cost[cn][adj[cn][i]]!=MXC)
		{
			V[adj[cn][i]]=1; tosee--; dfs(adj[cn][i]);
		}
}


int main()
{
	int i,j,k,a,b,c,bigq=-1,bigi=-1;
	LL r = 0;
	SI(n);
	for(i=1;i<=n;i++){ SI(val[i]); if(bigq<val[i]){ bigq=val[i]; bigi=i; }  }
	SI(m);
	for(i=1;i<=n;i++) for(j=1;j<=n;j++) cost[i][j]=MXC;
	for(i=0;i<m;i++)
	{
		SI(a); SI(b); SI(c);
		if(cost[a][b]>c) cost[a][b]=c;
	}

	for(i=1;i<=n;i++) for(j=1;j<=n;j++)
	{
		if(cost[i][j]==MXC) continue;
		Node sn(i,j,cost[i][j]);
		r+=cost[i][j];
		pq.push(sn);
		adj[i].PB(j);
	}

	FILL(V,0);
	V[bigi]=1; tosee=n-1;
	dfs(bigi);

	if(tosee>0) r=-1;
	else
	{
		while(!pq.empty())
		{
			Node cn = pq.top(); pq.pop();
			i=cn.i; j=cn.j; c=cn.c;
			//printf(" %2d---->%2d , cost = %2d ",i,j,c);
			cost[i][j]=MXC;
			
			FILL(V,0);
			V[bigi]=1; tosee=n-1;
			dfs(bigi);
			if(tosee==0)
			{
				r-=c;
				//puts(" : yes ");
			}
			else
			{
				cost[i][j]=c; 
				//puts(" : no ");
			}
		}
	}

	cout<<r<<endl;
	return 0;
}