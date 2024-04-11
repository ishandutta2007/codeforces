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

const int base	=	1000000007;
const int maxn	=	5005;

int f[maxn][maxn];
char s[maxn],t[maxn];

inline void Plus(int &a,int b)
{
	a+=b;
	if (a>=base) a-=base;
}

int main()
{
	scanf("%s%s",s,t);
	int n=strlen(s),m=strlen(t);
	for (int i=0;i<n;++i){
		f[0][i]=1;
	}
	
	for (int i=0;i<m;++i){
		for (int j=0;j<=n;++j)if (f[i][j]){
			Plus(f[i+1][j],f[i][j]);
			if (i<m && j<n && t[i]==s[j]) Plus(f[i+1][j+1],f[i][j]);
		}
	}
	
	int ans=0;
	for (int i=0;i<=n;++i) Plus(ans,f[m][i]);
	ans-=n;
	if (ans<0) ans+=base;
	
	printf("%d\n",ans);
	
	return 0;
}