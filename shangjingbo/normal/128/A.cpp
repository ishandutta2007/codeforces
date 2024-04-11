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

char s[10][10];
bool st[15][10][10],forbid[10][10];

const int dx[9]={0,1,1,1,0,-1,-1,-1,0};
const int dy[9]={1,0,1,-1,-1,0,1,-1,0};

int main()
{
	memset(st,false,sizeof(st));
	for (int i=0;i<8;++i)
		scanf("%s",s[i]);
	
	for (int i=0;i<8;++i){
		for (int j=0;j<8;++j){
			if (s[i][j]=='M') st[0][i][j]=true;
		}
	}
	bool remain=true;
	for (int it=0;it<10;++it){
		memset(forbid,false,sizeof(forbid));
		for (int x=0;x<8;++x)
			for (int y=0;y<8;++y){
				if (x>it && s[x-it-1][y]=='S')
					forbid[x][y]=true;
				if (x>=it && s[x-it][y]=='S')
					forbid[x][y]=true;
			}
		remain=false;
		for (int x=0;x<8;++x){
			for (int y=0;y<8;++y)if (st[it][x][y]){
				for (int k=0;k<9;++k){
					int tx=x+dx[k],ty=y+dy[k];
					if (tx>=0 && ty>=0 && tx<8 && ty<8 && !forbid[tx][ty]){
						st[it+1][tx][ty]=true;
						remain=true;
						if (s[tx][ty]=='A'){
							puts("WIN");
							return 0;
						}
					}
				}
			}
		}
	}
	
	if (remain) puts("WIN");
	else puts("LOSE");
	
	return 0;
}