#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<cstdlib>
#include<queue>
#include<map>
using namespace std;
int n,h;
double m,t;
int main()
    {
    while(scanf("%lf%d%d",&m,&n,&h)==3)
        {
        double e=0;
        double I=0;
        double r=1.0;
        for(int i=1;i<=n;i++)
            {
            scanf("%lf",&t);
            if(i==h)
            I=t;
            e+=t;
            }
        e=e-1;
        m--;
        I=I-1;
        if(e<m*1.0)
            {
            printf("-1.0\n");
            continue;
            }

        if(e-I<m*1.0)
            {
            printf("1.0\n");
            continue;
            }

        for(int i=0;i<m;i++)
            {
         r=r*(e-I-i)/(e-i);
         //printf("%lf\n",(e-I-i)/(e-i));
            }
        printf("%.10lf\n",1-r);
        }


    return 0;
    }