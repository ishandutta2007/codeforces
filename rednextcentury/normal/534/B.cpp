# include <iostream>
# include <vector>
# include <cstring>
#include <stdio.h>
#include <set>
#include <algorithm>
using namespace std;
int a[10000];
int main()
{
    int v1,v2,t,d;
    cin>>v1>>v2>>t>>d;
    a[1]=v1;
    a[t]=v2;
    int sum=a[1]+a[t];
    for (int i=2;i<t;i++)
    {
        a[i]=min(a[i-1]+d,a[t]+(t-i)*d);
        sum+=a[i];
    }
    cout<<sum<<endl;
}