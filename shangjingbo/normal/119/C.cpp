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

#define maxn 55
#define maxm 105

struct node
{
	long long a,b;
	int c,id;
	inline void read(){
		scanf("%I64d%I64d%d",&a,&b,&c);
	}
}a[maxn];

inline bool cmp(const node &a,const node &b)
{
	return a.c<b.c;
}

long long f[maxn][maxn][maxm];
struct Tpre
{
	short i,k;
}pre[maxn][maxn][maxm];
int n,m,k;

inline void print(int i,int j,int k)
{
	if (j!=1) print(pre[i][j][k].i,j-1,pre[i][j][k].k);
	printf("%d %I64d\n",a[i].id,a[i].a+k);
}

int main()
{
	scanf("%d%d%d",&n,&m,&k);
	for (int i=0;i<m;++i){
		a[i].read();
		a[i].id=i+1;
	}
	
	sort(a,a+m,cmp);
	
	memset(f,-1,sizeof(f));
	for (int i=0;i<m;++i){
		for (int j=0;j<=a[i].b-a[i].a;++j)
			f[i][1][j]=a[i].a+j;
		for (int j=0;j<i;++j)
		if (a[i].c>a[j].c){
			for (int sel=0;sel<n;++sel)
				for (int u=0;u<=a[j].b-a[j].a;++u)
				if (f[j][sel][u]!=-1){
					long long cur=f[j][sel][u];
					long long v;
					if (a[j].a+u<=a[i].b-k){
						v=(a[j].a+u)+k;
						if (v>=a[i].a && v<=a[i].b){
							int now=v-a[i].a;
							long long &res=f[i][sel+1][now];
							if (res<cur+v){
								res=cur+v;
								pre[i][sel+1][now].i=j;
								pre[i][sel+1][now].k=u;
							}
						}
					}
					
					if (a[j].a+u<=a[i].b/k){
						v=(a[j].a+u)*k;
						if (v<=a[i].b && v>=a[i].a){
							int now=v-a[i].a;
							long long &res=f[i][sel+1][now];
							if (res<cur+v){
								res=cur+v;
								pre[i][sel+1][now].i=j;
								pre[i][sel+1][now].k=u;
							}
						}
					}
				}
		}
	}
	long long ans=-1;
	for (int i=0;i<m;++i)
		for (int j=0;j<=a[i].b-a[i].a;++j)
		if (f[i][n][j]!=-1){
			if (f[i][n][j]>ans) ans=f[i][n][j];
		}
	
	if (ans==-1){
		puts("NO");
		return 0;
	}
	//cout << ans << endl;
	puts("YES");
	for (int i=0;i<m;++i)
		for (int j=0;j<=a[i].b-a[i].a;++j)
		if (f[i][n][j]==ans){
			print(i,n,j);
			return 0;
		}
	
	return 0;
}