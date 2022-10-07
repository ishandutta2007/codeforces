#include<bits/stdc++.h>
using namespace std;
main()
{
    double n,v1,v2,l,k,x;
    cin>>n>>l>>v1>>v2>>k;
    n=(int)(n+k-1)/(int)k;
x=(l)/(1+2*(n-1)*v1/(v1+v2));
printf("%.8f",x/v2+(l-x)/v1);
}