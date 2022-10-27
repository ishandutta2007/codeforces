#include<iostream>
#include<cstdio>
#include<stdio.h>
#include<cstring>
#include<string.h>
#include<cmath>
#include<math.h>
using namespace std;
double quickmod(double a,int b)
{
    double ans=0;
    while(b)
    {
        if(b&1)
        {
            ans = ans*a;
            b--;
        }
        b/=2;
        a = a*a;
    }
    return ans;
}
int main()
{
    double m,n;cin>>m>>n;
    double res=m;
    for(int i=1;i<=m-1;i++)
    {
        res -= pow((i/m),n);
    }
    printf("%.5lf\n",res);
    return 0;
}