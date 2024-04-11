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

int f[105][25*105];

inline void Plus(int &a,int b)
{
	a+=b;
	if (a>=base) a-=base;
}

int main()
{
	memset(f,0,sizeof(f));
	f[0][0]=1;
	
	for (int i=0;i<100;++i){
		for (int j=0;j<=26*i;++j)if (f[i][j]){
			for (int k=0;k<26;++k)
				Plus(f[i+1][j+k],f[i][j]);
		}
	}
	int T;
	scanf("%d",&T);
	for (;T>0;--T){
		char s[105];
		scanf("%s",s);
		int sum=0;
		for (int i=0;s[i];++i) sum+=s[i]-'a';
		int res=f[strlen(s)][sum];
		Plus(res,base-1);
		printf("%d\n",res);
	}
	
	return 0;
}