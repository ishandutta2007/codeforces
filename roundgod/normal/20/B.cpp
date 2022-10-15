#include<bits/stdc++.h>
#define MAXN 1000005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
double A,B,C;
int main()
{
    scanf("%lf%lf%lf",&A,&B,&C);
    if(A==0)
    {
        if(B==0&&C==0) puts("-1");
        else if(B==0) puts("0");
        else
        {
            puts("1");
            double x=-C/B;
            printf("%.10f\n",x);
        }
        return 0;
    }
    ll delta=1LL*(int)B*(int)B-4LL*(int)A*(int)C;
    if(delta<0) puts("0");
    else if(delta==0)
    {
        puts("1");
        double x=-B/(2*A);
        printf("%.10f\n",x);
    }
    else
    {
        puts("2");
        double x1=(-B-sqrt(delta))/(2*A),x2=(-B+sqrt(delta))/(2*A);
        if(x1>x2) swap(x1,x2);
        printf("%.10f\n%.10f\n",x1,x2);
    }
    return 0;
}