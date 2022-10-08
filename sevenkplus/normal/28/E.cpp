#include<cstdio>
#include<cmath>
#include<vector>
#include<algorithm>
using namespace std;
#define pb push_back
const double eps=1e-8;
struct P
{
    double x,y;
    P(){}
    P(double _x,double _y):x(_x),y(_y){}
    P operator + (const P&a) const {return P(x+a.x,y+a.y);}
    P operator - (const P&a) const {return P(x-a.x,y-a.y);}
    P operator * (const double&a) const {return P(x*a,y*a);}
    P operator / (const double&a) const {return P(x/a,y/a);}
    bool operator == (const P&a) const {return (*this-a).abs()<eps;}
    bool operator != (const P&a) const {return !(*this==a);}
    bool operator < (const P&a) const {return x<a.x-eps||fabs(a.x-x)<eps&&y<a.y;}
    double abs(){return sqrt(x*x+y*y);}
    void get(){scanf("%lf%lf",&x,&y);}
    void out(){printf("%.9lf %.9lf\n",x,y);}
};
bool equ(double a,double b){return fabs(a-b)<eps;}
P med(P a,P b,P c)
{
    if(a<b)if(b<c)return b;else if(a<c)return c;else return a;
    else if(a<c)return a;else if(b<c)return c;else return b;
}
P a[10010],u,v,p,S(1e20,1e20);double uz,vz,fz;int n;
void geti(P a,P b,P c,P d,vector<P>&e)
{
    double A=b.y-a.y,B=a.x-b.x,C=A*a.x+B*a.y;
    double D=d.y-c.y,E=c.x-d.x,F=D*c.x+E*c.y;
    if(equ(A*E,B*D))return;
    P p((C*E-F*B)/(A*E-D*B),(C*D-F*A)/(B*D-E*A));
    if(med(a,b,p)!=p||med(c,d,p)!=d&&med(c,d,p)!=p)return;
    e.pb(p);
}
P ff(P a)
{
    double t1=((a.x-p.x)*v.y-(a.y-p.y)*v.x)/(u.x*v.y-u.y*v.x),t3=((a.x-p.x)*u.y-(a.y-p.y)*u.x)/(v.x*u.y-v.y*u.x),t2=(t1*uz-t3*vz)/fz;
    if(t1<-eps||t2<-eps||t3<-eps)return P(1e20,1e20);
    if(t1<0)t1=0;if(t2<0)t2=0;if(t3<0)t3=0;
    return P(t1,t2);
}
int main()
{
    scanf("%d",&n);
    for(int i=0;i<n;i++)a[i].get();
    p.get(),
    u.get(),scanf("%lf",&uz),
    scanf("%lf",&fz),fz=-fz,
    v.get(),scanf("%lf",&vz),vz=-vz;
    if(u.abs()<eps)
        if(v.abs()<eps);else
        {
            vector<P> e;
            for(int i=0;i<n;i++)geti(a[i],a[(i+1)%n],p,p+v,e);
            sort(e.begin(),e.end()),
            e.erase(unique(e.begin(),e.end()),e.end());
            for(int i=0;i<(int)e.size();i++)
                S=min(S,P((e[i]-p).abs()/v.abs()*vz/uz,0));
        }else
        if(v.abs()<eps)
        {
            vector<P> e;
            for(int i=0;i<n;i++)geti(a[i],a[(i+1)%n],p,p+u,e);
            sort(e.begin(),e.end()),
            e.erase(unique(e.begin(),e.end()),e.end());
            for(int i=0;i<(int)e.size();i++)
                S=min(S,P((e[i]-p).abs()/u.abs(),0));
        }else
            if(equ(u.x*v.y,v.x*u.y))
            {
                vector<P> e,f;
                for(int i=0;i<n;i++)geti(a[i],a[(i+1)%n],p,p+u,e);
                for(int i=0;i<n;i++)geti(a[i],a[(i+1)%n],p,p+v,f);
                sort(e.begin(),e.end()),
                e.erase(unique(e.begin(),e.end()),e.end()),
                sort(f.begin(),f.end()),
                f.erase(unique(f.begin(),f.end()),f.end());
                if(u/u.abs()==v/v.abs())
                {
                    for(int i=0;i<(int)e.size();i++)
                        S=min(S,P((e[i]-p).abs()/(u.abs()+v.abs()*uz/vz),0));
                }else
                if((u/uz).abs()>(v/vz).abs()-eps)
                {
                    for(int i=0;i<(int)e.size();i++)
                        S=min(S,P((e[i]-p).abs()/u.abs(),(e[i]-p).abs()/u.abs()*uz/fz));
                }else
                {
                    for(int i=0;i<(int)e.size();i++)
                        S=min(S,P((e[i]-p).abs()/u.abs(),(e[i]-p).abs()/u.abs()*uz/fz));
                    for(int i=0;i<(int)f.size();i++)
                        S=min(S,P((f[i]-p).abs()/(v.abs()*uz/vz-u.abs()),0));
                }
            }else
            {
                vector<P> e;
                for(int i=0;i<n;i++)
                    geti(a[i],a[(i+1)%n],p,p+u,e),
                    geti(a[i],a[(i+1)%n],p,p+u+v*uz/vz,e),
                    e.pb(a[i]);
                sort(e.begin(),e.end()),
                e.erase(unique(e.begin(),e.end()),e.end());
                for(int i=0;i<(int)e.size();i++)S=min(S,ff(e[i]));
            }
    if(S.x>1e10)puts("-1 -1");else S.out();
    return 0;
}