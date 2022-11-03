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

const int limit	=	4000000;

bool f[limit+5];
int pr[limit],len;

int main()
{
	memset(f,true,sizeof(f));
	len=0;
	for (int i=2;i<=limit;++i)if (f[i]){
		pr[len++]=i;
		if (i<=limit/i)
		for (int j=i*i;j<=limit;j+=i) f[j]=false;
	}
	LL n;
	cin >> n;
	vector<LL> fac;
	fac.clear();
	for (int i=0;i<len && (LL)pr[i]*pr[i]<=n;++i){
		while (n%pr[i]==0){
			fac.PB(pr[i]);
			n/=pr[i];
		}
	}
	if (n>1) fac.PB(n);
	
	if (fac.size()==2){
		cout << 2 << endl;
	}else{
		cout << 1 << endl;
		if (fac.size()>2){
			cout << fac[0]*fac[1] << endl;
		}else cout << 0 << endl;
	}

	return 0;
}