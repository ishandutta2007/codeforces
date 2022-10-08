#include<cstdio>
#include<cmath>
#include<algorithm>
using namespace std;
const double eps=1e-9;
struct P
{
    double x,y;
    P(){}
    P(double _x,double _y):x(_x),y(_y){}
    P operator + (const P&a) const {return P(x+a.x,y+a.y);}
    P operator - (const P&a) const {return P(x-a.x,y-a.y);}
    P operator * (const double&a) const {return P(x*a,y*a);}
    P operator / (const double&a) const {return P(x/a,y/a);}
    bool operator < (const P&a) const {return x<a.x-eps||fabs(x-a.x)<eps&&y<a.y-eps;}
    bool operator == (const P&a) const {return (*this-a).abs()<eps;}
    bool operator != (const P&a) const {return !(*this==a);}
    double abs(){return sqrt(x*x+y*y);}
    void get(){scanf("%lf%lf",&x,&y);}
    void out(){printf("%.9lf %.9lf\n",x,y);}
};
bool equ(double a,double b){return fabs(a-b)<eps;}
const P nul(1e10,1e10);
struct L
{
    P x,y;
    L(){}
    L(P _x,P _y):x(_x),y(_y){}
    void get(){x.get(),y.get();}
    void out(){x.out(),y.out(),puts("");}
};
P med(P a,P b,P c)
{
    if(a<b)if(b<c)return b;else if(a<c)return c;else return a;
    else if(a<c)return a;else if(b<c)return c;else return b;
}
P geti(L a,L b)
{
    double A=a.y.y-a.x.y,B=a.x.x-a.y.x,C=A*a.x.x+B*a.x.y;
    double D=b.y.y-b.x.y,E=b.x.x-b.y.x,F=D*b.x.x+E*b.x.y;
    if(equ(A*E,B*D))return nul;
    P p((C*E-F*B)/(A*E-D*B),(C*D-F*A)/(B*D-E*A));
    if(med(a.x,p,a.y)!=p||med(b.x,p,b.y)!=p)return nul;
    return p;
}
P geti2(L a,L b)
{
    double A=a.y.y-a.x.y,B=a.x.x-a.y.x,C=A*a.x.x+B*a.x.y;
    double D=b.y.y-b.x.y,E=b.x.x-b.y.x,F=D*b.x.x+E*b.x.y;
    if(fabs(A*b.x.x+B*b.x.y+C)<eps&&med(a.x,b.x,a.y)==b.x)return b.x;
    if(fabs(A*b.y.x+B*b.y.y+C)<eps&&med(a.x,b.y,a.y)==b.y)return b.y;
    if(equ(A*E,B*D))return nul;
    P p((C*E-F*B)/(A*E-D*B),(C*D-F*A)/(B*D-E*A));
    if(med(a.x,p,a.y)!=p||med(b.x,p,b.y)!=p)return nul;
    return p;
}
P getr(L a,P b)
{
    double A=a.y.y-a.x.y,B=a.x.x-a.y.x,C=A*a.x.x+B*a.x.y;
    double D=a.x.x-a.y.x,E=a.x.y-a.y.y,F=D*b.x+E*b.y;
    P p((C*E-F*B)/(A*E-D*B),(C*D-F*A)/(B*D-E*A));
    return p*2-b;
}
P u,v;L n,m;
int main()
{
    u.get(),v.get(),n.get(),m.get();
    if(geti2(L(u,v),n)==nul)
    {
        if(geti(L(u,v),m)!=nul)puts("NO");else puts("YES");
        return 0;
    }
    P w=geti(L(u,getr(m,v)),m);
    if(w==nul){puts("NO");return 0;}
    if(geti2(L(u,w),n)==nul&&geti2(L(v,w),n)==nul)puts("YES");else puts("NO");
    return 0;
}