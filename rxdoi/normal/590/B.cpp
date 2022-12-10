#include<cmath>
#include<cstdio>
#include<cctype>
#include<cstring>
#include<algorithm>

#define For(i,x,y) for (int i=x;i<y;i++)
using namespace std;

int IN()
{
	int c,f,x;
	while (!isdigit(c=getchar())&&c!='-');c=='-'?(f=1,x=0):(f=0,x=c-'0');
	while (isdigit(c=getchar())) x=(x<<1)+(x<<3)+c-'0';return !f?x:-x;
}

typedef long long LL;
typedef double Db;

struct Point
{
	Db x,y;
	void IN() {scanf("%lf%lf",&x,&y);}
} V,W,A;
Db a,b,c,d,L,R,res=-1;
int v,t;

Point operator * (Point A,Db b) {return (Point){A.x*b,A.y*b};}
Point operator - (Point A,Point B) {return (Point){A.x-B.x,A.y-B.y};}
Db Dist(Point A) {return sqrt(A.x*A.x+A.y*A.y);}

int main()
{
	scanf("%lf%lf%lf%lf",&a,&b,&c,&d);A=(Point){c-a,d-b};
	v=IN(),t=IN();
	V.IN(),W.IN();
	L=0,R=t;
	For(i,0,100)
	{
		Db Mid=(L+R)/2.0;
		if (Dist(A-V*Mid)<=v*Mid) res=Mid,R=Mid;else L=Mid;
	}
	if (res>=0) return printf("%.12lf\n",res),0;
	L=t,R=1e9;
	For(i,0,100)
	{
		Db Mid=(L+R)/2.0;
		if (Dist(A-V*t-W*(Mid-t))<=v*Mid) res=Mid,R=Mid;else L=Mid;
	}
	printf("%.12lf\n",res);
}