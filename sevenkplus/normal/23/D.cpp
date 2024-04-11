#include<cstdio>
#include<cmath>
#include<vector>
using namespace std;
#define pb push_back
const double eps=1e-7;
struct P{double x,y;P(){}P(double _x,double _y):x(_x),y(_y){}void get(){scanf("%lf%lf",&x,&y);}};
inline double crs(P a,P b,P c){return (b.x-a.x)*(c.y-a.y)-(c.x-a.x)*(b.y-a.y);}
inline P ref(P a,P b){return P(a.x*2-b.x,a.y*2-b.y);}
inline double sqr(P a){return a.x*a.x+a.y*a.y;}
inline P cet(P a,P b,P c)
{
	double d=2*(a.x*(b.y-c.y)+b.x*(c.y-a.y)+c.x*(a.y-b.y));
	return P((sqr(a)*(b.y-c.y)+sqr(b)*(c.y-a.y)+sqr(c)*(a.y-b.y))/d,(sqr(a)*(c.x-b.x)+sqr(b)*(a.x-c.x)+sqr(c)*(b.x-a.x))/d);
}
bool chk(vector<P> S)
{
	for(int i=0;i<4;i++)
		if(crs(S[i],S[(i+1)%4],S[(i+2)%4])*crs(S[i],S[(i+1)%4],S[(i+3)%4])<=eps)return 0;
	return 1;
}
bool can(P a,P b,P c)
{
	vector<P> S;
	if(fabs(crs(ref(a,b),a,c))<=eps||fabs(crs(ref(a,c),a,b))<=eps)return 0;
	S.pb(cet(ref(a,b),a,c)),S.pb(cet(ref(a,c),a,b)),S.pb(ref(b,S[1])),S.pb(ref(c,S[0]));
	bool f=chk(S);
	if(f){puts("YES");for(int i=0;i<4;i++)printf("%.9lf %.9lf%c",S[i].x,S[i].y,i==3?'\n':' ');}
	return f;
}
int main()
{
	int _;scanf("%d",&_);
	while(_--)
	{
		P a,b,c;a.get(),b.get(),c.get();
		if(can(a,b,c))continue;
		if(can(b,c,a))continue;
		if(can(c,a,b))continue;
		printf("NO\n\n");
	}
	return 0;
}