
# include <iostream>
# include <string>
# include <algorithm>
# include <map>
#include<stdio.h>
#define EPS 1e-9
using namespace std;
int a[100000];
int mx[100000];
int main()
{
    int n,m;
    cin>>n>>m;
    for (int i=0;i<n;i++)
        cin>>a[i];
    mx[n-1]=a[n-1];
    for (int i=n-2;i>=0;i--)
    {
        mx[i]=max(mx[i+1],a[i]);
    }
    int ans=m;
    for (int i=0;i<n-1;i++)
    {
        ans=max(ans,m%a[i] + (m/a[i])*mx[i+1]);
    }
    cout<<ans<<endl;
}