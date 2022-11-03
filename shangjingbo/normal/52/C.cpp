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

#define maxn 200005

int n,a[maxn],m;
long long Tree[maxn*4],cover[maxn*4];

inline void Build(int num,int l,int r)
{
	if (l==r)
	{
		Tree[num]=a[l];
		cover[num]=0;
		return;
	}
	int mid=(l+r)/2;
	Build(num*2,l,mid);
	Build(num*2+1,mid+1,r);
	Tree[num]=min(Tree[num*2],Tree[num*2+1]);
}

inline void Insert(int num,int l,int r,int ll,int rr,int delta)
{
	if (l==ll && r==rr)
	{
		Tree[num]+=delta;
		cover[num]+=delta;
		return;
	}
	
	if (cover[num])
	{
		cover[num*2]+=cover[num];
		cover[num*2+1]+=cover[num];
		Tree[num*2]+=cover[num];
		Tree[num*2+1]+=cover[num];
		
		cover[num]=0;
	}
	
	int mid=(l+r)/2;
	
	if (rr<=mid) Insert(num*2,l,mid,ll,rr,delta);
	else if (ll>mid) Insert(num*2+1,mid+1,r,ll,rr,delta);
	else
	{
		Insert(num*2,l,mid,ll,mid,delta);
		Insert(num*2+1,mid+1,r,mid+1,rr,delta);
	}
	
	Tree[num]=min(Tree[num*2],Tree[num*2+1]);
}

inline long long Query(int num,int l,int r,int ll,int rr)
{
	if (l==ll && r==rr) return Tree[num];
	if (cover[num])
	{
		cover[num*2]+=cover[num];
		cover[num*2+1]+=cover[num];
		Tree[num*2]+=cover[num];
		Tree[num*2+1]+=cover[num];
		
		cover[num]=0;
	}
	
	int mid=(l+r)/2;
	
	if (rr<=mid) return Query(num*2,l,mid,ll,rr);
	else if (ll>mid) return Query(num*2+1,mid+1,r,ll,rr);
	else return min( Query(num*2,l,mid,ll,mid),Query(num*2+1,mid+1,r,mid+1,rr) );
}

int main()
{
	scanf("%d",&n);
	for (int i=0;i<n;++i)
		scanf("%d",&a[i]);
	Build(1,0,n-1);
	
	scanf("%d\n",&m);
	for (int i=0;i<m;++i)
	{
		char s[1000];
		gets(s);
		//puts(s);
		int l,r,v;
		if (sscanf(s,"%d%d%d",&l,&r,&v)==3)
		{
			if (l<=r) Insert(1,0,n-1,l,r,v);
			else
			{
				Insert(1,0,n-1,l,n-1,v);
				Insert(1,0,n-1,0,r,v);
			}
		}else
		{
			if (l<=r) cout << Query(1,0,n-1,l,r) << endl;
			else cout << min( Query(1,0,n-1,l,n-1) , Query(1,0,n-1,0,r) ) << endl;
		}
	}
	
	return 0;
}