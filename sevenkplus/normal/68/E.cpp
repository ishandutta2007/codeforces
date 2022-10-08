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
    double abs(){return sqrt(x*x+y*y);}
    P operator + (const P&a) const {return P(x+a.x,y+a.y);}
    P operator - (const P&a) const {return P(x-a.x,y-a.y);}
    P operator * (const double&a) const {return P(x*a,y*a);}
    P operator / (const double&a) const {return P(x/a,y/a);}
    bool operator < (const P&a) const {return x<a.x-eps||fabs(x-a.x)<eps&&y<a.y;}
    bool operator == (const P&a) const {return (*this-a).abs()<eps;}
    P rot(){return P(y,-x);}
    void get(){scanf("%lf%lf",&x,&y);}
};
struct T
{
    P a[3];double b[3];
    void get()
    {
        for(int i=0;i<3;i++)a[i].get();
        for(int i=0;i<3;i++)b[i]=(a[i]-a[(i+1)%3]).abs();
    }
}a[4];
bool equ(double a,double b){return fabs(a-b)<eps;}
bool tri(double a,double b,double c){return a+b>c-eps&&b+c>a-eps&&c+a>b-eps;}
void geti(P a,P b,double la,double lb,vector<P>&e)
{
    double d=(a-b).abs();
    if(!tri(la,lb,d))return;
    if(la+lb<d+eps)e.pb(a+(b-a)*la/d);else
    {
        double co=(d*d+la*la-lb*lb)/(2*d*la),si=sqrt(max(0.0,1.0-co*co));
        e.pb(a+(b-a)*la*co/d+(b-a).rot()*la*si/d),
        e.pb(a+(b-a)*la*co/d-(b-a).rot()*la*si/d);
    }
    sort(e.begin(),e.end()),
    e.erase(unique(e.begin(),e.end()),e.end());
}
int S=9;
void ff(vector<P> a,vector<T> b)
{
    S=min(S,(int)a.size()+(int)b.size()*2);
    if((int)a.size()>=S)return;
    if(b.empty()){S=min(S,(int)a.size());return;}
    for(int i=0;i<(int)a.size();i++)
        for(int j=i+1;j<(int)a.size();j++)
        {
            double d=(a[i]-a[j]).abs();
            for(int k=0;k<(int)b.size();k++)
            {
                vector<P> e;
                for(int l=0;l<3;l++)
                    if(equ(b[k].b[l],d))
                        geti(a[i],a[j],b[k].b[(l+1)%3],b[k].b[(l+2)%3],e),
                        geti(a[i],a[j],b[k].b[(l+2)%3],b[k].b[(l+1)%3],e);
                for(int l=0;l<(int)e.size();l++)
                {
                    vector<P> a0=a;a0.pb(e[l]);
                    sort(a0.begin(),a0.end()),
                    a0.erase(unique(a0.begin(),a0.end()),a0.end());
                    vector<T> b0=b;b0.erase(b0.begin()+k);
                    ff(a0,b0);
                }
            }
        }
}
int main()
{
    for(int i=0;i<4;i++)a[i].get();
    for(int k=0;k<81;k++)
    {
        double e[4];
        for(int i=0,j=k;i<4;j/=3,i++)e[i]=a[i].b[j%3];
        if(e[0]+e[1]+e[2]+e[3]>2* *max_element(e,e+4)-eps)S=min(S,8);
    }
    for(int i=0;i<4;i++)
    {
        vector<P> a0;
        for(int j=0;j<3;j++)a0.pb(a[i].a[j]);
        sort(a0.begin(),a0.end()),
        a0.erase(unique(a0.begin(),a0.end()),a0.end());
        vector<T> b0;
        for(int j=0;j<4;j++)if(i!=j)b0.pb(a[j]);
        ff(a0,b0);
    }
    for(int i=0;i<4;i++)
    {
        vector<int> p;
        for(int j=0;j<4;j++)if(j!=i)p.pb(j);
        for(int k=0;k<27;k++)
        {
            vector<P> a0;
            vector<double> l;
            for(int i=0,j=k;i<3;j/=3,i++)l.pb(a[p[i]].b[j%3]);
            vector<P> e;
            a0.pb(P(0,0)),a0.pb(P(0,l[0]));geti(P(0,0),P(0,l[0]),l[2],l[1],e);
            if(e.empty())continue;a0.pb(e[0]);
            for(int o=0;o<64;o++)
            {
                vector<P> a1=a0;
                for(int i=0,j=k;i<3;j/=3,i++)
                {
                    e.clear();
                    if((o>>i*2)&1)geti(a0[i],a0[(i+1)%3],a[p[i]].b[(j%3+1)%3],a[p[i]].b[(j%3+2)%3],e);
                    else geti(a0[i],a0[(i+1)%3],a[p[i]].b[(j%3+2)%3],a[p[i]].b[(j%3+1)%3],e);
                    if(e.empty())goto end;
                    if((int)e.size()==1)a1.pb(e[0]);else
                    if(((o>>i*2)&3)/2)a1.pb(e[0]);else a1.pb(e[1]);
                }
                sort(a1.begin(),a1.end()),
                a1.erase(unique(a1.begin(),a1.end()),a1.end());
                ff(a1,vector<T>(1,a[i]));
                end:;
            }
        }
    }
    for(int w=0;w<81;w++)
        for(int i=0;i<4;i++)
            for(int j=i+1;j<4;j++)
            {
                if(!equ(a[i].b[w%3],a[j].b[w/3%3]))continue;
                vector<P> e,f;
                geti(P(0,0),P(0,a[i].b[w%3]),a[i].b[(w%3+1)%3],a[i].b[(w%3+2)%3],e),
                geti(P(0,0),P(0,a[i].b[w%3]),a[i].b[(w%3+2)%3],a[i].b[(w%3+1)%3],e),
                geti(P(0,0),P(0,a[j].b[w/3%3]),a[j].b[(w/3%3+1)%3],a[j].b[(w/3%3+2)%3],f),
                geti(P(0,0),P(0,a[j].b[w/3%3]),a[j].b[(w/3%3+2)%3],a[j].b[(w/3%3+1)%3],f);
                vector<double> d;
                for(int i=0;i<(int)e.size();i++)
                    for(int j=0;j<(int)f.size();j++)
                        d.pb((e[i]-f[j]).abs());
                sort(d.begin(),d.end()),
                d.erase(unique(d.begin(),d.end(),equ),d.end());
                for(int k=0;k<4;k++)if(k!=i&&k!=j)
                    for(int l=k+1;l<4;l++)if(l!=i&&l!=j)
                    {
                        if(tri(a[k].b[w/9%3],a[l].b[w/27%3],a[i].b[w%3]-eps))S=min(S,7);
                        if(equ(a[k].b[w/9%3],a[l].b[w/27%3]))
                        {
                            e.clear(),f.clear();
                            geti(P(0,0),P(0,a[k].b[w/9%3]),a[k].b[(w/9%3+1)%3],a[k].b[(w/9%3+2)%3],e),
                            geti(P(0,0),P(0,a[k].b[w/9%3]),a[k].b[(w/9%3+2)%3],a[k].b[(w/9%3+1)%3],e),
                            geti(P(0,0),P(0,a[l].b[w/27%3]),a[l].b[(w/27%3+1)%3],a[l].b[(w/27%3+2)%3],f),
                            geti(P(0,0),P(0,a[l].b[w/27%3]),a[l].b[(w/27%3+2)%3],a[l].b[(w/27%3+1)%3],f);
                            for(int k=0;k<(int)e.size();k++)
                                for(int l=0;l<(int)f.size();l++)
                                    for(int w=0;w<(int)d.size();w++)
                                        if(equ((e[k]-f[l]).abs(),d[w]))S=min(S,6);
                        }
                    }
            }
    printf("%d\n",S);
    return 0;
}