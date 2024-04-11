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

#define maxn 1005

int father[maxn],cc[maxn],cnt[maxn];
char s[maxn];

inline int Find(int x)
{
	if (x==father[x]) return x;
	return father[x]=Find(father[x]);
}

int main()
{
	scanf("%s",s+1);
	int n=strlen(s+1);
	for (int i=1;i<=n;++i) father[i]=i;
	for (int i=2;i<=n;++i){
		bool ok=true;
		for (int j=2;j<i && ok;++j)
		if (i%j==0) ok=false;
		
		if (ok){
			for (int j=1;i*j<=n;++j)
				father[Find(i)]=Find(i*j);
		}
	}
	
	for (int i=1;i<=n;++i){
		++cc[s[i]];
		++cnt[Find(i)];
	}
	
	int sp=-1;
	for (int i=1;i<=n;++i)
	if (sp==-1 || cnt[i]>cnt[sp]){
		sp=i;
	}
	
	int color=-1;
	for (int i='a';i<='z';++i)
	if (cc[i]>=cnt[sp]){
		color=i;
	}
	
	if (color==-1){
		puts("NO");
		return 0;
	}
	puts("YES");
	cc[color]-=cnt[sp];
	for (int i=1;i<=n;++i)
	if (Find(i)==Find(sp)) printf("%c",color);
	else{
		for (char ch='a';ch<='z';++ch)
		if (cc[ch]){
			printf("%c",ch);
			--cc[ch];
			break;
		}
	}

	
	return 0;
}