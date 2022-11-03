#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <string>
#include <sstream>
using namespace std;

#define MP make_pair
#define PB push_back

#define sqr(x) ((x)*(x))
#define lowbit(x) ((x)&(-(x)))

typedef long long LL;
typedef unsigned long long ULL;
typedef vector<int> VI;
typedef pair<int,int> PII;
typedef vector<string> VS;

const double pi	=	acos(-1.0);
const double eps	=	1e-8;

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

int n,a[105];

int main()
{
	scanf("%d",&n);
	int f=100000,l=-1;
	for (int i=0;i<n;++i){
		int x;
		scanf("%d",&x);
		a[i]=x;
		f=min(f,x);
		l=max(l,x);
	}
	
	int ans1=0,ans2=0;
	for (int i=0;i<n;++i){
		if (a[i]==l){
			ans1+=i;
			for (int j=i;j>0;--j)
				swap(a[j],a[j-1]);
			break;
		}
	}
	for (int i=n-1;i>=0;--i)
		if (a[i]==f){
			ans1+=n-1-i;
			break;
		}

	cout << ans1 << endl;
	
	
	return 0;
}