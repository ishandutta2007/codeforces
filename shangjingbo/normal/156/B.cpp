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

int n,m,pos[100005],neg[100005],say[100005];
bool mark[100005];

int main()
{
	scanf("%d%d",&n,&m);
	int ps=0,ns=0;
	for (int i=1;i<=n;++i){
		int x;
		scanf("%d",&x);
		if (x>0){
			++pos[x];
			++ps;
		}else{
			++neg[-x];
			++ns;
		}
		say[i]=x;
	}
	
	int possible=0;
	for (int i=1;i<=n;++i){
		int tr=pos[i]+ns-neg[i];
		if (tr==m){
			mark[i]=true;
			++possible;
		}
	}
	
	for (int i=1;i<=n;++i){
		int x=say[i];
		if (x>0){
			if (possible==1 && mark[x]){
				puts("Truth");
			}else{
				if (!mark[x]){
					puts("Lie");
				}else{
					puts("Not defined");
				}
			}
		}else{
			x=-x;
			if (!mark[x]){
				puts("Truth");
			}else{
				if (mark[x]){
					if (possible==1) puts("Lie");
					else puts("Not defined");
				}
			}
		}
	}
	
	return 0;
}