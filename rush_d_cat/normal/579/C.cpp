#include<iostream>
#include<stdio.h>
#include<cstdio>
using namespace std;
typedef __int64 ll;
int main()
{
    int a,b;cin>>a>>b;
    if(a<b)
    {
        cout<<-1<<endl;
    }
    else
    {
        int tmp1 = a+b;
        int k1 = tmp1/(2*b);
        double res1 = ( (double)tmp1/k1 )/2;

        int tmp2 = a-b;
        int k2 = tmp2/(2*b);
        double res2 = ( (double)tmp2/k2 )/2;
        double res = min(res1,res2);
        printf("%.10lf\n",res);
    }
    return 0;
}