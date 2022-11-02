// by shik
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <cmath>
#define SZ(x) ((int)(x).size())
#define FOR(it,c) for ( __typeof((c).begin()) it=(c).begin(); it!=(c).end(); it++ )
using namespace std;
const double eps=1e-9;
int sgn( double x ) { return (x>eps)-(x<-eps); }
struct P {
        double x,y;
        P(){}
        P( double _x, double _y ):x(_x),y(_y){}
        double ang() { return atan2(y,x); }
        void rot( double a ) {
            double r=sqrt(x*x+y*y);
            a+=ang();
            x=r*cos(a);
            y=r*sin(a);
        }
};
P operator +( P a, P b ) { return P(a.x+b.x,a.y+b.y); }
P operator -( P a, P b ) { return P(a.x-b.x,a.y-b.y); }
P operator *( double a, P b ) { return P(a*b.x,a*b.y); }
P operator /( P a, double b ) { return P(a.x/b,a.y/b); }
double operator ^( P a, P b ) { return a.x*b.y-b.x*a.y; }
double X( P o, P a, P b ) { return (a-o)^(b-o); }
int dir( P o, P a, P b ) { return sgn(X(o,a,b)); }
struct Ln {
        P p1,p2;
        double ang;
        Ln(){}
        Ln( P _p1, P _p2 ):p1(_p1),p2(_p2),ang((p2-p1).ang()){}
};
bool is_jiao( double a, double b, double c, double d ) { return max(a,b)>=min(c,d) && max(c,d)>=min(a,b); }
bool is_jiao( P a, P b, P c, P d ) {
        if ( !is_jiao(a.x,b.x,c.x,d.x) ) return 0;
        if ( !is_jiao(a.y,b.y,c.y,d.y) ) return 0;
        if ( dir(a,b,c)*dir(a,b,d)>0 ) return 0;
        if ( dir(c,d,a)*dir(c,d,b)>0 ) return 0;
        return 1;
}
bool is_jiao( Ln a, Ln b ) { return is_jiao(a.p1,a.p2,b.p1,b.p2); }
P jiao( Ln a, Ln b ) {
        double u=X(a.p1,a.p2,b.p1);
        double v=X(a.p2,a.p1,b.p2);
        return (v*b.p1+u*b.p2)/(u+v);
}
bool cp_ang( P a, P b ) { return a.ang()<b.ang(); }
int main()
{
    double w,h,a;
    scanf("%lf%lf%lf",&w,&h,&a);
    if ( a==0 || a==180 ) {
        printf("%.12f\n",w*h);
        return 0;
    }
    if ( w==h && a==90 ) {
        printf("%.12f\n",w*h);
        return 0;
    }
    a=acos(-1)*a/180;
    P pa(-w/2,+h/2);
    P pb(+w/2,+h/2);
    P pc(+w/2,-h/2);
    P pd(-w/2,-h/2);
    P qa(pa),qb(pb),qc(pc),qd(pd);
    qa.rot(a); qb.rot(a); qc.rot(a); qd.rot(a);
    Ln pab(pa,pb),pbc(pb,pc),pcd(pc,pd),pda(pd,pa);
    Ln qab(qa,qb),qbc(qb,qc),qcd(qc,qd),qda(qd,qa);
    Ln pl[4]={pab,pbc,pcd,pda};
    Ln ql[4]={qab,qbc,qcd,qda};
    P pt[100];
    int pn=0;
    for ( int i=0; i<4; i++ ) for ( int j=0; j<4; j++ ) if ( is_jiao(pl[i],ql[j]) ) pt[pn++]=jiao(pl[i],ql[j]);
    sort(pt,pt+pn,cp_ang);
    pt[pn]=pt[0];
    double ans=0;
    for ( int i=0; i<pn; i++ ) ans+=(pt[i]^pt[i+1]);
    ans=fabs(ans/2);
    printf("%.12f\n",ans);
    return 0;
}