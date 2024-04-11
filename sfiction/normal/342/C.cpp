#include <cstdio>
const double sqr3=1.7320508075689;
int main()
{
    int a,b;
    int r,h;
    double t,tr;
    scanf("%d%d",&r,&h);
    h<<=1;
    r<<=1;
    a=((h+(r>>1))/r)<<1;
    t=h;
    tr=r/2;
    t=t+(2-sqr3)*tr;
    t/=2*tr;
    b=t;
    b=b*2+1;
    printf("%d",a>b?a:b);
    return 0;
}