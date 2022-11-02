#include<cmath>
#include<cstdio>
#include<algorithm>

#define pi acos(-1.0)
#define sqr(x) ((x)*(x))

using namespace std;

int n,px,py;
double R,r,nowl,nowr,now,cos1,cos2,P,S,x[100010],y[100010];

int main()
{
    scanf("%d%d%d",&n,&px,&py);
    for(int i=1;i<=n;i++)
    {
        scanf("%lf%lf",&x[i],&y[i]);
        R=max(R,sqrt(sqr(x[i]-px)+sqr(y[i]-py)));
    }
    x[n+1]=x[1],y[n+1]=y[1];
    r=100000000000000.0;
    for(int i=1;i<=n;i++)
    {
        nowl=sqrt(sqr(x[i]-px)+sqr(y[i]-py));
        nowr=sqrt(sqr(x[i+1]-px)+sqr(y[i+1]-py));
        r=min(r,nowl);
        r=min(r,nowr);
        now=sqrt(sqr(x[i]-x[i+1])+sqr(y[i]-y[i+1]));
        cos1=(sqr(nowl)+sqr(now)-sqr(nowr))/(2*nowl*now);
        cos2=(sqr(nowr)+sqr(now)-sqr(nowl))/(2*nowr*now);
        if(cos1<=0||cos2<=0)continue;
        P=(nowl+nowr+now)/2.;
        S=sqrt(P*(P-now)*(P-nowl)*(P-nowr));
        r=min(r,S*2/now);
    }
    printf("%.20lf",pi*(sqr(R)-sqr(r)));
}