#include <cstdio>
#include <cstring>
#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    int n,a1,a2,a3,a4,ans=0,x[1000],y[1000];
    cin>>n;
    for (int i=1;i<=n;i++)
      cin>>x[i]>>y[i];
    for (int i=1;i<=n;i++)
    {
        a1=a2=a3=a4=1;
        for (int j=1;j<=n;j++)
        {
            if ((x[j]==x[i])&&(y[j]>y[i])) a1=0;
            if ((x[j]==x[i])&&(y[j]<y[i])) a2=0;
            if ((x[j]>x[i])&&(y[j]==y[i])) a3=0;
            if ((x[j]<x[i])&&(y[j]==y[i])) a4=0;
        }
        if (a1+a2+a3+a4==0) ans++;
    }
    cout<<ans;
    return 0;
}