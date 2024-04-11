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
//=============================================================================================
#define maxn 705
#define maxm (maxn*maxn)

int n,m,mat[maxn][maxn],a[maxm],b[maxm],Adj[maxn][maxn];
int d[maxn];

int main()
{
	scanf("%d%d",&n,&m);
	for (int i=0;i<m;++i)
	{
		scanf("%d%d",&a[i],&b[i]);
		--a[i];--b[i];
		++d[a[i]];
		++d[b[i]];
		mat[a[i]][b[i]]=mat[b[i]][a[i]]=1;
	}
	
	for (int e=0;e<m;++e)
	{
		int i=a[e],k=b[e];
		for (int j=0;j<n;++j)
		if (mat[k][j])
			++Adj[i][j];
		swap(i,k);
		for (int j=0;j<n;++j)
		if (mat[k][j])
			++Adj[i][j];
	}
	long long Ans=0;
	for (int e=0;e<m;++e)
	{
		int i=a[e];
		int j=b[e];
		for (int k=0;k<n;++k)
		{
			if (mat[i][k] & mat[j][k]) Ans-=d[k]-2;
			if (i!=k && j!=k)
			{
				Ans+=(long long)Adj[i][k]*Adj[k][j];
				if (mat[k][i]) Ans-=Adj[i][k];
				if (mat[k][j]) Ans-=Adj[j][k];
				if (mat[k][i] & mat[k][j]) ++Ans;
			}
		}
	}
	
	printf("%I64d\n",Ans/5);
	
	return 0;
}