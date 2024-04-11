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

const int maxn	=	1005;

const int dx[4]	=	{0,1,0,-1};
const int dy[4]	=	{-1,0,1,0};

char s[maxn][maxn];
int n,m;
int d[maxn][maxn][4];
bool vis[maxn][maxn][4];

deque< pair<PII,int> > q;

int main()
{
	scanf("%d%d",&n,&m);
	for (int i=0;i<n;++i)
		scanf("%s",s[i]);
	
	memset(d,-1,sizeof(d));
	memset(vis,false,sizeof(vis));
	
	q.push_back( MP(MP(n-1,m-1),0) );
	d[n-1][m-1][0]=0;
	vis[n-1][m-1][0]=true;
	while (q.size()){
		int x=q.front().first.first,y=q.front().first.second;
		int dir=q.front().second;
		vis[x][y][dir]=true;
		q.pop_front();
		
		if (d[0][0][0]!=-1 && d[x][y][dir]>=d[0][0][0]) continue;
		
		int tx=x+dx[dir],ty=y+dy[dir];
		if (tx>=0 && ty>=0 && tx<n && ty<m){
			if (d[tx][ty][dir]==-1 || d[tx][ty][dir]>d[x][y][dir]){
				d[tx][ty][dir]=d[x][y][dir];
				if (!vis[tx][ty][dir]){
					vis[tx][ty][dir]=true;
					q.push_front(MP( MP(tx,ty),dir ));
				}
			}
		}
		
		if (s[x][y]=='#'){
			for (int k=0;k<4;++k){
				if (d[x][y][k]==-1 || d[x][y][k]>d[x][y][dir]+1){
					d[x][y][k]=d[x][y][dir]+1;
					if (!vis[x][y][k]){
						vis[x][y][k]=true;
						q.push_back(MP( MP(x,y),k ));
					}
				}
			}
		}
	}
	
	printf("%d\n",d[0][0][0]);
	
	
	return 0;
}