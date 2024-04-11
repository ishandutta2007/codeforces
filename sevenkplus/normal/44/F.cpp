#include<cstdio>
#include<string>
#include<cmath>
#include<vector>
#include<map>
#include<queue>
#include<algorithm>
using namespace std;
#define fi first
#define se second
#define pb push_back
#define mp make_pair
const double eps=1e-8;
typedef pair<int,double> PIF;
struct point
{
    double x,y;
    point(){}
    point(double _x,double _y):x(_x),y(_y){}
    bool operator < (const point&a) const {return x<a.x-eps||fabs(x-a.x)<eps&&y<a.y-eps;}
    bool operator ==(const point&a) const {return fabs(x-a.x)<eps&&fabs(y-a.y)<eps;}
    bool operator !=(const point&a) const {return !(*this==a);}
    void get(){scanf("%lf%lf",&x,&y);}
};
struct line
{
    point x,y;
    line(){}
    line(point _x,point _y):x(_x),y(_y){}
    void get(){x.get(),y.get();}
};
struct node
{
    string c;vector<int> a;double sz;
    node(string _c,double _sz=0):c(_c),sz(_sz){}
    void add(int x){a.pb(x);}
};
point med(point a,point b,point c)
{
    if(a<b)if(b<c)return b;else if(a<c)return c;else return a;
    else if(a<c)return a;else if(b<c)return c;else return b;
}
int getcrs(line a,line b,point&c)
{
    double A=a.y.y-a.x.y,B=a.x.x-a.y.x,C=a.x.x*A+a.x.y*B;
    double D=b.y.y-b.x.y,E=b.x.x-b.y.x,F=b.x.x*D+b.x.y*E;
    if(fabs(A*E-B*D)<eps)return -1;
    c=point((C*E-F*B)/(A*E-D*B),(C*D-F*A)/(B*D-E*A));
    if(med(a.x,a.y,c)!=c||med(b.x,b.y,c)!=c)return -1;
    return 0;
}
bool online(point p,line a)
{
    if(med(a.x,a.y,p)!=p)return 0;
    double A=a.y.y-a.x.y,B=a.x.x-a.y.x,C=a.x.x*A+a.x.y*B;
    return abs(A*p.x+B*p.y-C)<eps;
}
double ang(point a,point b)
{
    double S=atan2(b.y-a.y,b.x-a.x)*180/M_PI;
    if(S<eps)S+=360;
    return S;
}
bool cmpid(const PIF&a,const PIF&b){return a.fi<b.fi;}
bool equid(const PIF&a,const PIF&b){return a.fi==b.fi;}
bool cmpang(const PIF&a,const PIF&b){return a.se<b.se;}
double getsz(vector<point> p)
{
    double S=0;
    for(int i=0;i<(int)p.size();i++)
    {
        int j=(i+1)%(int)p.size();
        S+=p[i].x*p[j].y-p[j].x*p[i].y;
    }
    return -S/2;
}
double crs(point a,point b,point c)
{
    return (b.y-a.y)*(c.x-a.x)-(b.x-a.x)*(c.y-a.y);
}
int inpoly(point p,vector<point> a)
{
    int n=(int)a.size();a.pb(a[0]);
    for(int i=0;i<n;i++)
        if(online(p,line(a[i],a[i+1])))return 0;
    int w=0;
    for(int i=0;i<n;i++)
        if(a[i].y<=p.y&&a[i+1].y>p.y&&crs(a[i],a[i+1],p)<0)++w;else
        if(a[i].y>p.y&&a[i+1].y<=p.y&&crs(a[i],a[i+1],p)>0)--w;
    return w;
}
int w,h,n,m,p;
vector<point> po;
vector<vector<PIF> > pa;
vector<node> gr;
vector<int> bl;
vector<point> fl;
vector<vector<point> > pl;
void bfs(int x,string c)
{
    string d=gr[x].c;
    queue<int> q;vector<bool> v((int)gr.size(),0);
    v[x]=1,q.push(x);
    while(!q.empty())
    {
        int x=q.front();q.pop();
        gr[x].c=c;
        for(int i=0;i<(int)gr[x].a.size();i++)
            if(!v[gr[x].a[i]]&&gr[gr[x].a[i]].c==d)
                q.push(gr[x].a[i]),v[gr[x].a[i]]=1;
    }
}
int main()
{
    scanf("%d%d%d",&w,&h,&n);
    vector<line> l0(n);
    for(int i=0;i<n;i++)l0[i].get();
    for(int i=0;i<n;i++)po.pb(l0[i].x),po.pb(l0[i].y);
    for(int i=0;i<n;i++)
        for(int j=i+1;j<n;j++)
        {
            point p;
            if(getcrs(l0[i],l0[j],p)!=-1)po.pb(p);
        }
    sort(po.begin(),po.end()),
    po.erase(unique(po.begin(),po.end()),po.end());
    m=(int)po.size();
    pa.resize(m);
    for(int i=0;i<n;i++)
    {
        vector<int> vp;
        for(int j=0;j<m;j++)
            if(online(po[j],l0[i]))vp.pb(j);
        for(int j=1;j<(int)vp.size();j++)
            pa[vp[j-1]].pb(mp(vp[j],ang(po[vp[j-1]],po[vp[j]]))),
            pa[vp[j]].pb(mp(vp[j-1],ang(po[vp[j]],po[vp[j-1]])));
    }
    for(int i=0;i<m;i++)
        sort(pa[i].begin(),pa[i].end(),cmpid),
        pa[i].erase(unique(pa[i].begin(),pa[i].end(),equid),pa[i].end()),
        sort(pa[i].begin(),pa[i].end(),cmpang);
    gr.pb(node("white",w*h));
    fl.pb(point(0.0,0.0));
    bl.resize(m,-1);
    for(int i=0;i<m;i++)if(bl[i]==-1)
    {
        queue<int> q;
        q.push(i);
        gr.pb(node("black",0.0));
        bl[i]=++p,fl.pb(po[i]);
        while(!q.empty())
        {
            int x=q.front();q.pop();
            for(int j=0;j<(int)pa[x].size();j++)
                if(bl[pa[x][j].fi]==-1)
                    q.push(pa[x][j].fi),
                    bl[pa[x][j].fi]=p;
        }
    }
    pl.resize(p+1);
    vector<vector<bool> > chk(m);
    for(int i=0;i<m;i++)chk[i].resize((int)pa[i].size(),0);
    for(int i=0;i<m;i++)
        for(int j=0;j<(int)pa[i].size();j++)
        {
            if(chk[i][j])continue;
            vector<point> vp;
            int i0=i,j0=j;
            while(!chk[i0][j0])
            {
                vp.pb(po[i0]);
                chk[i0][j0]=1;
                int i1=pa[i0][j0].fi,j1=-1;
                for(int j=0;j<(int)pa[i1].size();j++)
                    if(pa[i1][j].fi==i0){j1=(j+1)%(int)pa[i1].size();break;}
                i0=i1,j0=j1;
            }
            double sz=getsz(vp);
            if(sz>0)
            {
                pl.pb(vp);
                gr.pb(node("white",sz));
                int r=bl[i];
                gr[r].add((int)gr.size()-1),
                gr[(int)gr.size()-1].add(r);
                gr[r].sz-=sz;
            }
        }
    for(int i=1;i<=p;i++)
    {
        int fa=0;
        for(int j=(int)pl.size()-1;j>p;j--)
            if(inpoly(fl[i],pl[j])){fa=j;break;}
        gr[fa].add(i),gr[i].add(fa),gr[fa].sz+=gr[i].sz,gr[i].sz=0;
    }
    int _;scanf("%d",&_);
    while(_--)
    {
        point x;x.get();string c;char s[100];scanf("%s",s),c=s;
        for(int i=0;i<m;i++)
            for(int j=0;j<(int)pa[i].size();j++)
                if(online(x,line(po[i],po[pa[i][j].fi]))){bfs(bl[i],c);goto end;}
        for(int i=(int)pl.size()-1;i>p;i--)
            if(inpoly(x,pl[i])){bfs(i,c);goto end;}
        bfs(0,c);
        end:;
    }
    map<string,double> S;
    for(int i=0;i<(int)gr.size();i++)
        S[gr[i].c]+=gr[i].sz;
    for(map<string,double>::iterator i=S.begin();i!=S.end();i++)
        printf("%s %.9lf\n",i->first.c_str(),i->second);
    return 0;
}