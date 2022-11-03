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

int f[1000005],p[100000],len;
bool vis[105];
int mark[105],T;
set<int> hash;
int head[105],next[105*105],vtx[105*105],low[105*105],high[105*105],tot;
int Ans[105],now[105],n,m;
map<int,int> gcd[105*105],lcm[105*105];
struct node
{
	int a,b,c,d;
}Edge[105*105];

inline void Add(int a,int b,int l,int h)
{
	vtx[tot]=b;
	next[tot]=head[a];
	low[tot]=l;
	high[tot]=h;
	head[a]=tot++;
	
	vtx[tot]=a;
	next[tot]=head[b];
	low[tot]=l;
	high[tot]=h;
	head[b]=tot++;
}

inline int calc(int x,int t)
{
	if (!t) return 1;
	int y=calc(x,t>>1);
	y*=y;
	if (t&1) y*=x;
	return y;
}

inline void fill(int u,int key,int x)
{
	vis[u]=true;
	Ans[u]*=calc(key,x);
	for (int p=head[u];p;p=next[p])
	if (!vis[vtx[p]]) fill(vtx[p],key,low[p]+high[p]-x);
}

inline bool dfs(int u,int x)
{
	if (mark[u]==T) return x==now[u];
	mark[u]=T;
	now[u]=x;
	for (int p=head[u];p;p=next[p])
	{
		if (low[p]==x)
		{
			if (!dfs(vtx[p],high[p])) return false;
		}else if (high[p]==x)
		{
			if (!dfs(vtx[p],low[p])) return false;
		}else return false;
	}
	return true;
}

int main()
{
	//freopen("C.in","r",stdin);
	//freopen("C.out","w",stdout);
	
	memset(f,-1,sizeof(f));
	for (int i=2;i<=1000000;++i)
	if (f[i]==-1)
	{
		f[i]=len;
		if (1000000/i>=i)
		for (int j=i*i;j<=1000000;j+=i)
		if (f[j]==-1) f[j]=len;
		p[len++]=i;
	}
	//printf("%d\n",len);
	
	scanf("%d%d",&n,&m);
	bool ok=true;
	for (int i=0;i<m;++i)
	{
		int a,b,c,d;
		scanf("%d%d%d%d",&a,&b,&c,&d);
		Edge[i].a=a;
		Edge[i].b=b;
		Edge[i].c=c;
		Edge[i].d=d;
		if (d%c)
		{
			ok=false;
			continue;
		}
		while (d>1)
		{
			int cnt=1,bak=f[d];
			d/=p[bak];
			while (d>1 && f[d]==bak)
			{
				++cnt;
				d/=p[bak];
			}
			
			int cc=0;
			while (c>1 && f[c]==bak)
			{
				++cc;
				c/=p[bak];
			}
			
			gcd[i][p[bak]]=cc;
			lcm[i][p[bak]]=cnt;
			
			hash.insert(p[bak]);
		}
	}
	
	if (!ok)
	{
		puts("NO");
		return 0;
	}
	
	for (int i=1;i<=n;++i)
		Ans[i]=1;
	
	for (set<int>::iterator it=hash.begin();it!=hash.end() && ok;++it)
	{
		int key=*it;
		memset(vis,false,sizeof(vis));
		memset(mark,-1,sizeof(mark));
		
		memset(head,0,sizeof(head));
		tot=2;
		for (int i=0;i<m;++i)
		if (lcm[i].count(key))
			Add(Edge[i].a,Edge[i].b,gcd[i][key],lcm[i][key]);
		else Add(Edge[i].a,Edge[i].b,0,0);
		
		for (int i=1;i<=n;++i)
		if (head[i] && !vis[i])
		{
			int p=head[i];
			++T;
			if (dfs(i,low[p])) fill(i,key,low[p]);
			else
			{
				++T;
				if (dfs(i,high[p])) fill(i,key,high[p]);
				else
				{
					ok=false;
					break;
				}
			}
		}
	}
	if (!ok)
	{
		puts("NO");
		return 0;
	}
	
	puts("YES");
	for (int i=1;i<=n;++i)
	{
		if (i>1) printf(" ");
		printf("%d",Ans[i]);
	}
	puts("");
	
	return 0;
}