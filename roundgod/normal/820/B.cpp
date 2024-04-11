#include<bits/stdc++.h>
#define INF 1000000
using namespace std;
int n;
double a;
double check(double x,double y)
{
    return x>y?x:y;
}
int main()
{
    scanf("%d %lf",&n,&a);
    double ang=0;
    double ans=INF;
    int t=INF;
    for(int i=n;i>=3;i--)
    {
        ang=(double)(n+1-i)*180/n;
        if(check(a-ang,ang-a)<ans)
        {
            ans=check(a-ang,ang-a);
            t=i;
        }
    }
    printf("1 2 %d\n",t);
    return 0;
}