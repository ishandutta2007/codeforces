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

const int maxn	=	100005;

char s[maxn],t[maxn];
int cnt[100],tar[100];

int main()
{
	scanf("%s",s);
	scanf("%s",t);
	
	int ls=strlen(s),lt=strlen(t);
	
	for (int i=0;i<lt;++i)
		++tar[t[i]-'a'];
	
	int stat=0,ans=0;
	
	for (int i=0,j=0;i+lt<=ls;++i){
		while (j<i+lt){
			if (s[j]!='?'){
				++cnt[s[j]-'a'];
				if (cnt[s[j]-'a']>tar[s[j]-'a'])
					stat|=1<<s[j]-'a';
			}
			++j;
		}
//		printf("%d %d, %d\n",i,j,stat);
		if (stat==0) ++ans;
		
		if (s[i]!='?'){
			--cnt[s[i]-'a'];
			if (cnt[s[i]-'a']<=tar[s[i]-'a'])
				stat&=~(1<<s[i]-'a');
		}
	}
	
	cout << ans << endl;
	
	return 0;
}