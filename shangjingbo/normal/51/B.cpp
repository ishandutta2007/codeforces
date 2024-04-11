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

VI ans;
int stack[10000],top=0;
char list[1000000];

int main()
{
	int len=0;
	while (1)
	{
		char ch=getchar();
		if (ch==-1) break;
		if (ch=='<' || ch=='>' || ch=='/' || ch>='a' && ch<='z') list[len++]=ch;
	}
	list[len]=0;
	
	//puts(list);
	ans.clear();
	for (int i=0;i<len;++i)
	if (list[i]=='<')
	{
		int j=i+1;
		string s="";
		while (list[j]!='>')
		{
			s+=list[j];
			++j;
		}
		
		if (s=="table")
		{
			stack[++top]=0;
		}else if (s=="td") ++stack[top];
		else if (s=="/table")
		{
			ans.PB(stack[top--]);
		}
		i=j;
	}
	sort(ans.begin(),ans.end());
	
	for (int i=0;i<ans.size();++i)
	{
		if (i) printf(" ");
		printf("%d",ans[i]);
	}
	puts("");
	
	return 0;
}