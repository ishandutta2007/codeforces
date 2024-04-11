#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <queue>
using namespace std;

#define lowbit(x) ((x)&(-(x)))
#define sqr(x) ((x)*(x))
#define PB push_back
#define MP make_pair

typedef unsigned long long ULL;
typedef long long LL;
typedef vector<int> VI;
typedef vector<string> VS;
typedef pair<int,int> PII;

struct Tpoint
{
	double x,y;
	Tpoint(){}
	Tpoint(double _x,double _y){x=_x;y=_y;}
	inline void read(){scanf("%lf%lf",&x,&y);}
	inline void show(){printf("%lf %lf\n",x,y);}
	inline double norm(){ return sqrt( sqr(x)+sqr(y) ); }
};

inline Tpoint operator +(const Tpoint &a,const Tpoint &b){ return Tpoint(a.x+b.x,a.y+b.y); }
inline Tpoint operator -(const Tpoint &a,const Tpoint &b){ return Tpoint(a.x-b.x,a.y-b.y); }
inline Tpoint operator *(const Tpoint &a,const double &b){ return Tpoint(a.x*b,a.y*b); }
inline Tpoint operator /(const Tpoint &a,const double &b){ return Tpoint(a.x/b,a.y/b); }
inline double det(const Tpoint &a,const Tpoint &b){ return a.x*b.y-a.y*b.x; }
inline double dot(const Tpoint &a,const Tpoint &b){ return a.x*b.x+a.y*b.y; }

int Cnt[(1<<10)+5],f[(1<<10)+5][(1<<10)+5],n,m,K,Ind[(1<<10)+5];
bool Adj[15][15];

inline int dfs(int tree,int leaf)
{
	if (Cnt[leaf]<2) return 0;
	if (Cnt[leaf]==2 && tree==leaf)
	{
		int u=Ind[lowbit(leaf)];
		int v=Ind[lowbit(leaf^(1<<u))];
		return Adj[u][v];
	}
	
	int &res=f[tree][leaf];
	if (res!=-1) return res;
	
	
	res=0;
	int u=Ind[lowbit(leaf)];
	for (int fa=0;fa<n;++fa)
	if (((1<<fa)&tree) && !((1<<fa)&leaf) && Adj[fa][u])
		res+=dfs(tree^(1<<u),leaf^(1<<u))+dfs(tree^(1<<u),leaf^(1<<u)^(1<<fa));
	
	return res;
}

int main()
{
	scanf("%d%d%d",&n,&m,&K);
	memset(Adj,false,sizeof(Adj));
	for (int i=0;i<m;++i)
	{
		int a,b;
		scanf("%d%d",&a,&b);
		--a;--b;
		Adj[a][b]=Adj[b][a]=true;
	}
	
	for (int i=0;i<n;++i)
		Ind[1<<i]=i;
	for (int i=1;i<1<<n;++i)
		Cnt[i]=Cnt[i/2]+(i&1);
	
	int Ans=0;
	memset(f,-1,sizeof(f));
	for (int leaf=0;leaf<1<<n;++leaf)
	if (Cnt[leaf]==K)
		Ans+=dfs((1<<n)-1,leaf);
	
	printf("%d\n",Ans);
	
	return 0;
}