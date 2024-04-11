#include<bits/stdc++.h>
using namespace std;
void solveL(long long xl,long long yl,long long xr,long long yr,long long xs,long long ys);
int ask(long long x,long long y)
{
	int t;
	cout<<x<<' '<<y<<endl;
	cin>>t;
	if(t==0)exit(0);
	return t;
}
void solveX(long long y,long long xl,long long xr)
{
	long long xm=(xl+xr)/2;
	int t=ask(xm,y);
	if(t==1)solveX(y,xm,xr);
	else solveX(y,xl,xm);
}
void solveY(long long x,long long yl,long long yr)
{
	long long ym=(yl+yr)/2;
	int t=ask(x,ym);
	if(t==2)solveY(x,ym,yr);
	else solveY(x,yl,ym);
}
const long double p=0.4;
void solverect(long long xl,long long yl,long long xr,long long yr)
{
//	cerr<<"solverect"<<' '<<xl<<' '<<xr<<' '<<yl<<' '<<yr<<endl;
	long long xm=max((long long)(xl+(xr-xl)*p),xl+1),ym=max((long long)(yl+(yr-yl)*p),yl+1);
	if(xl==xr-2)solveY(xl+1,yl,yr);
	else if(yl==yr-2)solveX(yl+1,xl,xr);
	else
	{
		int t=ask(xm,ym);
		if(t==1)solverect(xm,yl,xr,yr);
		else if(t==2)solverect(xl,ym,xr,yr);
		else solveL(xl,yl,xr,yr,xm,ym);
	}
}
void solveL(long long xl,long long yl,long long xr,long long yr,long long xs,long long ys)
{
	if(xl>xs-2)return solverect(xl,yl,xr,ys);
	if(yl>ys-2)return solverect(xl,yl,xs,yr);
	if(ys-yl>(xs-xl)*2)
	{
		long long ym=(yl+ys)/2;
		int t=ask(xs,ym);
		if(t==1)solverect(xs,yl,xr,ys);
		else if(t==2)solveL(xl,ym,xr,yr,xs,ys);
		else solveL(xl,yl,xr,yr,xs,ym);
	}
	else if(xs-xl>(ys-yl)*2)
	{
		long long xm=(xl+xs)/2;
		int t=ask(xm,ys);
		if(t==1)solveL(xm,yl,xr,yr,xs,ys);
		else if(t==2)solverect(xl,ys,xs,yr);
		else solveL(xl,yl,xr,yr,xm,ys);
	}
	else
	{
		long long ym=(yl+ys+1)/2;
		long long xm=(xl+xs+1)/2;
		int t=ask(xm,ym);
		if(t==1)solveL(xm,yl,xr,yr,xs,ys);
		else if(t==2)solveL(xl,ym,xr,yr,xs,ys);
		else solveL(xl,yl,xr,yr,xm,ym);
	}
}
int main()
{
	ios_base::sync_with_stdio(false);
	long long n;
	cin>>n;
	solverect(0,0,n+1,n+1);
	return 0;
}