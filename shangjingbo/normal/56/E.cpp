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
#define maxn 100005

int Tree[maxn*4],n,Ans[maxn];
struct node
{
	int x,h,id;
}a[maxn];

inline bool cmp(const node &a,const node &b)
{
	return a.x<b.x;
}

inline void Insert(int num,int l,int r,int pos,int delta)
{
	Tree[num]=max(Tree[num],delta);
	if (l==r) return;
	int mid=(l+r)>>1;
	if (pos<=mid) Insert(num*2,l,mid,pos,delta);
	else Insert(num*2+1,mid+1,r,pos,delta);
}

inline int Query(int num,int l,int r,int ll,int rr)
{
	if (ll<=a[l].x && a[r].x<=rr) return Tree[num];
	if (ll>a[r].x || rr<a[l].x) return 0;
	if (l==r) return 0;
	
	int mid=(l+r)>>1;
	return max( Query(num*2,l,mid,ll,rr) , Query(num*2+1,mid+1,r,ll,rr) );
}

int main()
{
	scanf("%d",&n);
	for (int i=0;i<n;++i)
	{
		scanf("%d%d",&a[i].x,&a[i].h);
		a[i].id=i;
	}
	sort(a,a+n,cmp);
	
	memset(Tree,0,sizeof(Tree));
	for (int i=n-1;i>=0;--i)
	{
		int j=Query(1,0,n-1,a[i].x+1,a[i].x+a[i].h-1);
		if (j<=i) j=i;
		Ans[a[i].id]=j-i+1;
		
		Insert(1,0,n-1,i,j);
	}
	
	for (int i=0;i<n;++i)
	{
		if (i) printf(" ");
		printf("%d",Ans[i]);
	}
	puts("");
	
	return 0;
}