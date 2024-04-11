#include<cmath>
#include<cstdio>

#define pi acos(-1.0)

using namespace std;

int n,r,v,s,f;
double nowans,dis;

int main()
{
    scanf("%d%d%d",&n,&r,&v);
    for(int i=1;i<=n;i++)
    {
        scanf("%d%d",&s,&f);
        dis=f-s-2*pi*r*(int)((f-s)/(2*pi*r));
        dis/=2;
        nowans=0;
        double L=0,R=2*pi*r;
        for(int cnt=1;cnt<=100;cnt++)
        {
            double mid=(L+R)/2;
            if(mid+r*sin(mid/r)>=dis)R=mid-1e-8,nowans=mid;
            else L=mid+1e-8;
        }
        nowans=2*nowans+2*pi*r*((int)((f-s)/(2*pi*r)));
        printf("%.10lf\n",nowans/v);
    }
}