#include<stdio.h>
#include<math.h>

main()
{
    double x,y,a,b;
    scanf("%lf %lf", &x, &y);
    a=y*log10(x);
    b=x*log10(y);
    if(x==y || fabs(a-b)<= pow(10,-10)) printf("=\n");
    else if(a>b) printf(">\n");
    else if(a<b) printf("<\n");
}