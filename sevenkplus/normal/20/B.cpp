#include<cstdio>
#include<cmath>
using namespace std;
typedef long long ll;
ll a,b,c;
int main()
{
    scanf("%I64d%I64d%I64d",&a,&b,&c);
    if(!a)
        if(!b)
            puts(c?"0":"-1");
        else
            printf("1\n%.18lf\n",double(-c)/b);
    else
        if(b*b-4*a*c<0)
            puts("0");
        else
            if(b*b-4*a*c>0)
                if(a>0)
                    printf("2\n%.18lf\n%.18lf\n",(-b-sqrt(b*b-4*a*c))/a/2,(-b+sqrt(b*b-4*a*c))/a/2);
                else
                    printf("2\n%.18lf\n%.18lf\n",(-b+sqrt(b*b-4*a*c))/a/2,(-b-sqrt(b*b-4*a*c))/a/2);
            else
                printf("1\n%.18lf\n",double(-b)/a/2);
    return 0;
}