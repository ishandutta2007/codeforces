#include<cstring>
#include<cstdlib>
#include<cstdio>
#include<algorithm>
#include<map>
#include<vector>
#define rep(i,j,k) for(int i=j;i<=k;i++)
#define per(i,j,k) for(int i=j;i>=k;i--)
#define lowbit(x) ((x)&(-(x)))
#define MAXN 310000
using namespace std;
typedef double ld;
int n;
struct jsb
{
       int a,b;
}data[MAXN];
inline bool cmp(const jsb &a,const jsb &b){return a.a>b.a;}
double Pow[MAXN];
struct Info
{
       double al,ar;
       int sum;
       inline Info operator +(const Info &b)const
       {
              Info c;c.al=c.ar=c.sum=0;c.sum=b.sum+sum;
              c.al=al+b.al*Pow[sum];
              c.ar=b.ar+ar*Pow[b.sum];
              return c;
              }
}info[MAXN*4];
void add(int now,int l,int r,int x)
{
     if(l==r)
     {
             info[now].sum=1;
             info[now].al=info[now].ar=0.5*x;
             return;
             }
     int mid=(l+r)>>1;
     if(x<=mid)add(now*2,l,mid,x);
     if(x>mid)add(now*2+1,mid+1,r,x);
     info[now]=info[now*2]+info[now*2+1];
}
Info ask(int now,int l,int r,int x,int y)
{
     if(x<=l&&r<=y)return info[now];
     int mid=(l+r)>>1;Info res;res.sum=0;res.al=res.ar=0;
     if(x<=mid)res=res+ask(now*2,l,mid,x,y);
     if(y>mid)res=res+ask(now*2+1,mid+1,r,x,y);
     return res;
}
int main()
{
    scanf("%d",&n);rep(i,1,n){scanf("%d",&data[i].a);data[i].b=i;}
    sort(data+1,data+1+n,cmp);Pow[0]=1;
    rep(i,1,n)Pow[i]=Pow[i-1]*0.5;
    double res=0;
    rep(i,1,n)
    {
              add(1,1,n,data[i].b);
              double lin,rin;
              Info l,r;
              if(data[i].b>=2)
              l=ask(1,1,n,1,data[i].b-1);
              else {l.sum=l.al=l.ar=0;}
              
              if(data[i].b+1<=n)
              r=ask(1,1,n,data[i].b+1,n);
              else {r.sum=r.al=r.ar=0;}
              l.ar=data[i].b-l.ar;
              r.al=r.al-data[i].b+Pow[r.sum]*(n+1);
              res+=0.5*l.ar*r.al*data[i].a;
              }
    printf("%.8lf\n",res/(1.*n*1.*n));
    return 0;
}