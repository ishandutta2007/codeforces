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
#define maxn 1005

char s[maxn][maxn];
int row[maxn],col[maxn];

int main()
{
	int n,m;
	scanf("%d%d",&n,&m);
	for (int i=0;i<n;++i)
		scanf("%s",s[i]);
	memset(row,0,sizeof(row));
	memset(col,0,sizeof(col));
	for (int i=0;i<n;++i)
		for (int j=0;j<m;++j)
		if (s[i][j]=='*')
		{
			++row[i];
			++col[j];
		}
	long long Ans=0;
	for (int i=0;i<n;++i)
	if (row[i]>1)
		for (int j=0;j<m;++j)
		if (s[i][j]=='*')
			Ans+=(long long)(row[i]-1)*(col[j]-1);
	
	cout << Ans << endl;
	
	return 0;
}