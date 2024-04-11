#include<cmath>
#include<cstdio>
#include<cctype>
#include<cstring>
#include<algorithm>

#define For(i,x,y) for (int i=x;i<y;i++)
#define mp make_pair
#define fir first
#define sec second
using namespace std;

int IN()
{
    int c,f,x;
    while (!isdigit(c=getchar())&&c!='-');c=='-'?(f=1,x=0):(f=0,x=c-'0');
    while (isdigit(c=getchar())) x=(x<<1)+(x<<3)+c-'0';return !f?x:-x;
}

typedef long long LL;
typedef long double Db;

const int N=1000+19,oo=1<<25;
const Db Pi=acos(-1.0);
Db w,h,Ans,L,R,t,__a[N],__d[N];
int n,c,m;

struct Point
{
    Db x,y;
    Point() {}
    Point(Db __x,Db __y) {x=__x,y=__y;}
} P[N];

Db Dist(Point A,Point B) {return sqrt((A.x-B.x)*(A.x-B.x)+(A.y-B.y)*(A.y-B.y));}

pair<Db,int> A[N*4];

void __Add(Db s,Db t,int v) {A[++c]=mp(s,v),A[++c]=mp(t+1e-12,-v);}
void Add(Db s,Db t,int v)
{
    if (s<0) __Add(s+2*Pi,2*Pi,v),s=0;
    if (t>2*Pi) __Add(0,t-2*Pi,v),t=2*Pi;
    __Add(s,t,v);
}
bool Check(int i,Db r)
{
    c=0;
    if (P[i].x<r)   t=acos(P[i].x/r),Add(Pi-t,Pi+t,oo);
    if (P[i].x+r>w) t=acos((w-P[i].x)/r),Add(-t,t,oo);
    if (P[i].y<r)   t=asin(P[i].y/r),Add(Pi+t,2*Pi-t,oo);
    if (P[i].y+r>h) t=asin((h-P[i].y)/r),Add(t,Pi-t,oo);
    For(j,1,m+1) if (0<__d[j]&&__d[j]<2*r)
    {
        Db a=__a[j],b=acos(__d[j]/2.0/r);
        if (a<0) a+=2*Pi;
        Add(a-b,a+b,1);
    }
    sort(A+1,A+c+1);A[++c]=mp(2*Pi,0);
    int tmp=0;
    For(j,1,c+1)
    {
        if (A[j].fir>A[j-1].fir&&tmp<=1) return 1;
        tmp+=A[j].sec;
    }
    return 0;
}

int main()
{
    w=IN(),h=IN(),n=IN();
    For(i,1,n+1) P[i].x=IN(),P[i].y=IN();
    random_shuffle(P+1,P+n+1);
    For(i,1,n+1)
    {
        m=0;
        For(j,1,n+1) if (i!=j)
            m++,__d[m]=Dist(P[i],P[j]),__a[m]=atan2(P[j].y-P[i].y,P[j].x-P[i].x);
        if (!Check(i,L+1e-9)) continue;
        R=2e6;
        while (R-L>1e-9)
        {
            Db Mid=(L+R)/2.0;
            if (Check(i,Mid)) L=Mid;else R=Mid;
        }
    }
    printf("%.15lf\n",double(L));
}