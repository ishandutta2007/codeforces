#include<cstdio>
#include<cmath>
using namespace std;
int x[3],y[3],r[3];
double tmp[3];
inline double sqr(double a){return a*a;}
double ff(double X,double Y)
{
    for(int i=0;i<3;tmp[i]=sqrt(sqr(X-x[i])+sqr(Y-y[i]))/r[i],i++);
    double s=0;
    for(int i=0;i<3;s+=sqr(tmp[i]-tmp[(i+1)%3]),i++);
    return s;
}
int main()
{
    double X=0,Y=0;
    for(int i=0;i<3;scanf("%d%d%d",x+i,y+i,r+i),X+=x[i],Y+=y[i],i++);
    X/=3,Y/=3;
    double T=ff(X,Y),T1,d=1;
    for(;d>1e-6;)
    {
        T1=ff(X-d,Y);
        if(T1<T)
        {
            T=T1,X-=d;
            continue;
        }
        T1=ff(X+d,Y);
        if(T1<T)
        {
            T=T1,X+=d;
            continue;
        }
        T1=ff(X,Y-d);
        if(T1<T)
        {
            T=T1,Y-=d;
            continue;
        }
        T1=ff(X,Y+d);
        if(T1<T)
        {
            T=T1,Y+=d;
            continue;
        }
        d*=.7;
    }
    if(T<1e-7)
        printf("%.5f %.5f\n",X,Y);
    return 0;
}