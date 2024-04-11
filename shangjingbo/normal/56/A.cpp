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
#include <sstream>
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

const string s[11]={"ABSINTH", "BEER", "BRANDY", "CHAMPAGNE", "GIN", "RUM", 
"SAKE", "TEQUILA", "VODKA", "WHISKEY", "WINE"};
const int m=11;

int main()
{
	set<string> hash;
	hash.clear();
	
	int n;
	cin >> n;
	
	for (int i=0;i<m;++i)
		hash.insert(s[i]);
	
	int Ans=0;
	for (int i=0;i<n;++i)
	{
		string t;
		cin >> t;
		
		if (t[0]>='0' && t[0]<='9')
		{
			stringstream in(t);
			int x;
			in >> x;
			if (x<18) ++Ans;
		}else if (hash.count(t))
		{
			++Ans;
		}
	}
	
	printf("%d\n",Ans);
	
	return 0;
}