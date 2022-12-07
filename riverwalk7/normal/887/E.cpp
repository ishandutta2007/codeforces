#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
#define eps 1e-10
#define MN 100005
#define INF 1e12
#define ll long long
#define ld long double
using namespace std;
struct vec
{
	int x,y;
	friend vec operator-(const vec& a,const vec& b) {return (vec){a.x-b.x,a.y-b.y};}
	friend ll  operator/(const vec& a,const vec& b) {return 1LL*a.x*b.y-1LL*a.y*b.x;}
}s,e,a[MN];
struct meg{ld l,r;}itv[2][MN];
ld zx,zy,zr,A,B,C,L,R,mdx,mdy,mdr,mdd,d1x,d1y,d1r,d2x,d2y,d2r;
int r[MN],tp[2];
bool fg;
int n;

inline int read()
{
	int n=0,f=1; char c=getchar();
	while (c<'0' || c>'9') {if(c=='-')f=-1; c=getchar();}
	while (c>='0' && c<='9') {n=n*10+c-'0'; c=getchar();}
	return n*f;
}

inline void revs(vec& a) {swap(a.x,a.y); a.y=-a.y;}
inline void dcxs(vec& a) {a.y=-a.y;}
inline ll sqr(int x) {return 1LL*x*x;}
inline ld dqr(ld x) {return x*x;}
bool cmp(const meg& a,const meg& b) {return a.l<b.l || fabs(a.l-b.l)<eps && a.r<b.r;}
ld solve(bool g)
{
	sort(itv[g]+1,itv[g]+tp[g]+1,cmp);
	ld lim=zr;
	for (register int i=1;i<=tp[g];++i)
	{
		if (itv[g][i].l>=lim) return lim;
		lim=max(lim,itv[g][i].r);
	}
	return lim;
}

int main()
{
	register int i,j;
	s.x=read(); s.y=read(); e.x=read(); e.y=read();
	n=read();
	for (i=1;i<=n;++i)
		a[i].x=read(),a[i].y=read(),r[i]=read();
	if (s.y==e.y) for (revs(s),revs(e),i=1;i<=n;++i) revs(a[i]);
	if (s.x> e.x) swap(s,e);
	if (s.y< e.y) for (dcxs(s),dcxs(e),i=1;i<=n;++i) dcxs(a[i]);
	zx=(ld)(s.x+e.x)/2; zy=(ld)(s.y+e.y)/2; zr=sqrt(sqr(e.x-s.x)+sqr(e.y-s.y))/2;
	A=2*(e.x-s.x); B=2*(e.y-s.y); C=sqr(s.x)+sqr(s.y)-sqr(e.x)-sqr(e.y);
//	printf("%d %d %d %d\n",s.x,s.y,e.x,e.y);
//	printf("%.5lf %.5lf %.5lf\n",(double)A,(double)B,(double)C);
	for (i=1;i<=n;++i)
	{
		fg=((e-s)/(a[i]-s))>0;
		L=-INF; R=INF;
		for (j=1;j<=500;++j)
		{
			ld mdx=(L+R)/2;
			mdy=-(A*mdx+C)/B;
			mdr=sqrt(dqr(mdx-s.x)+dqr(mdy-s.y));
			mdd=sqrt(dqr(mdx-a[i].x)+dqr(mdy-a[i].y));
			if ((mdr+r[i]<mdd)^fg) R=mdx; else L=mdx;
		}
		d1x=L; d1y=-(A*d1x+C)/B; d1r=sqrt(dqr(d1x-s.x)+dqr(d1y-s.y));
//		printf("1l=%.5lf,r=%.5lf\n",(double)L,(double)d1r);
		L=-INF; R=INF;
		for (j=1;j<=500;++j)
		{
			ld mdx=(L+R)/2;
			mdy=-(A*mdx+C)/B;
			mdr=sqrt(dqr(mdx-s.x)+dqr(mdy-s.y));
			mdd=sqrt(dqr(mdx-a[i].x)+dqr(mdy-a[i].y));
			if ((mdr-r[i]<mdd)^fg) R=mdx; else L=mdx;
		}
		d2x=L; d2y=-(A*d2x+C)/B; d2r=sqrt(dqr(d2x-s.x)+dqr(d2y-s.y));
//		printf("2l=%.5lf,r=%.5lf\n",(double)L,(double)d2r);
		if ((d1x<zx)^(d2x<zx))
			itv[d1x<zx][++tp[d1x<zx]]=(meg){zr-eps,d1r},
			itv[d2x<zx][++tp[d2x<zx]]=(meg){zr-eps,d2r};
		else itv[d1x<zx][++tp[d1x<zx]]=(meg){min(d1r,d2r),max(d1r,d2r)};
//			itv[i].l=zr-eps; itv[i].r=max(d1r,d2r);
	}
//	itv[n+1]=(meg){-eps,zr};
//	for (i=1;i<=tp[0];++i) printf("%.5lf %.5lf\n",(double)itv[0][i].l,(double)itv[0][i].r);
//	puts("");	
//	for (i=1;i<=tp[1];++i) printf("%.5lf %.5lf\n",(double)itv[1][i].l,(double)itv[1][i].r);
	printf("%.10lf\n",(double)min(solve(0),solve(1)));
}