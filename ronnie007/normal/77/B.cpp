#include <iostream>
#include <stdio.h>
using namespace std;

int main()
    {
    long long t,a,b;
    long long i;
    double probability;
    double area,totalarea;

    scanf("%I64d",&t);

    for (i=1;i<=t;i++)
        {
        scanf("%I64d %I64d",&a,&b);

        if (b==0)
            {
            printf("1.000000000\n");
            continue;
            }
        if (a==0)
            {
            printf("0.500000000\n");
            continue;
            }


        probability=0.5;

        if ((double)a/4.0<=(double)b)area=((double)a/4.0 )*(double)a;
        else area=((double)a+((double)a-4.0*(double)b))*(double)b;

        area=area/2.0;


        totalarea=(double)a*(double)b;

        probability=probability+(area/totalarea)*0.5;

        printf("%.9f\n",probability);
        }
    return 0;
    }