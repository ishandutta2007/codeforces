#include<cstdio>
#include<cmath>
#include<algorithm>
using namespace std;
int a,b,l;
double f(double p){return (p*a+sqrt(l*l-p*p)*b-p*sqrt(l*l-p*p))/l;}
int main()
{
    scanf("%d%d%d",&a,&b,&l);
    if(a>b)swap(a,b);
    if(l<=a){printf("%d\n",l);return 0;}
    if(l<=b){printf("%d\n",a);return 0;}
    double l1=0,l2=l,m1,m2;
    for(int _=300;_--;)
    {
        m1=(l1*2+l2)/3,
        m2=(l1+l2*2)/3;
        if(f(m1)>f(m2))l1=m1;else l2=m2;
    }
    if(f(l1)<1e-8)puts("My poor head =(");
    else printf("%.9lf\n",f(l1));
    return 0;
}