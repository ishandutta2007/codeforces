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
#define maxn 1055

char s1[maxn],s2[maxn];
int f[maxn][maxn];
struct node
{
	int x,y,type;
}pre[maxn][maxn];
int n,m;

inline void Update(int i,int j,int x,int y,int cost,int type)
{
	if (f[i][j]==-1 || f[i][j]>f[x][y]+cost)
	{
		f[i][j]=f[x][y]+cost;
		pre[i][j].x=x;
		pre[i][j].y=y;
		pre[i][j].type=type;
	}
}

inline void Print(int i,int j)
{
	if (i==0 && j==0) return;
	
	Print(pre[i][j].x,pre[i][j].y);
	
	int type=pre[i][j].type;
	if (type==3) return;
	if (type==2) printf("REPLACE %d %c\n",j,s2[j]);
	else if (type==1) printf("DELETE %d\n",j+1);
	else if (type==0) printf("INSERT %d %c\n",j,s2[j]);
}

int main()
{
	scanf("%s%s",s1+1,s2+1);
	
	memset(f,-1,sizeof(f));
	f[0][0]=0;
	n=strlen(s1+1);
	m=strlen(s2+1);
	for (int i=0;i<=n;++i)
		for (int j=0;j<=m;++j)
		if (f[i][j]!=-1)
		{
			if (j<m) Update(i,j+1,i,j,1,0);
			if (i<n) Update(i+1,j,i,j,1,1);
			if (i<n && j<m)
			{
				if (s1[i+1]==s2[j+1]) Update(i+1,j+1,i,j,0,3);
				else Update(i+1,j+1,i,j,1,2);
			}
		}
	
	printf("%d\n",f[n][m]);
	Print(n,m);
	
	return 0;
}