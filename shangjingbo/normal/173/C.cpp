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

const int maxn	=	505;

queue< pair<PII,PII> > q;
int row[maxn][maxn],col[maxn][maxn],a[maxn][maxn],n,m;

inline int getRow(int i,int l,int r)
{
	if (l>r) return 0;
	return row[i][r+1]-row[i][l];
}

inline int getCol(int i,int l,int r)
{
	if (l>r) return 0;
	return col[i][r+1]-col[i][l];
}

int main()
{
	scanf("%d%d",&n,&m);
	memset(row,0,sizeof(row));
	memset(col,0,sizeof(col));
	for (int i=0;i<n;++i){
		for (int j=0;j<m;++j){
			scanf("%d",&a[i][j]);
			row[i][j+1]=row[i][j]+a[i][j];
			col[j][i+1]=col[j][i]+a[i][j];
		}
	}
	
	for (int i=0;i<n;++i){
		for (int j=0;j<m;++j){
			if (i+2<n && j+2<m){
				int sum=getRow(i,j,j+2)+a[i+1][j+2]+getRow(i+2,j,j+2);
				q.push(MP(MP(i,j),MP(3,sum)));
			}
			if (i+4<n && j+4<m){
				int sum=getRow(i,j,j+4)+getRow(i+4,j,j+4);
				sum+=getRow(i+2,j,j+2);
				sum+=a[i+3][j];
				sum+=getCol(j+4,i+1,i+3);
				q.push(MP(MP(i,j),MP(5,sum)));
			}
		}
	}
	
	int ans=-1000000000;
	while (q.size()){
		int x=q.front().first.first,y=q.front().first.second;
		int len=q.front().second.first,sum=q.front().second.second;
		q.pop();
		ans=max(ans,sum);
		
		if (x+len+1<n && y+len+1<m && x-2>=0 && y-2>=0){
			x-=2;
			y-=2;
			len+=4;
			sum+=getRow(x,y,y+len-1);
			sum+=getRow(x+len-1,y,y+len-1);
			sum+=getCol(y+len-1,x+1,x+len-2);
			sum+=getCol(y,x+2,x+len-2);
			sum+=a[x+2][y+1];
			
			q.push(MP(MP(x,y),MP(len,sum)));
		}
	}
	
	printf("%d\n",ans);
	
	return 0;
}