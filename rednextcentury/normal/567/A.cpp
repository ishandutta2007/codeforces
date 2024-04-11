# include <iostream>
# include <algorithm>
# include <ios>
# include <stdio.h>
using namespace std;
int a[1000000];
int mn[1000000];
int mx[1000000];
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int n;
    cin>>n;
    for (int i=0;i<n;i++)
    {
        cin>>a[i];
        mn[i]=2000000001;
        mx[i]=0;
    }
    mn[0]=a[1]-a[0];
    mx[0]=a[n-1]-a[0];
    for (int i=1;i<n-1;i++)
    {
        mn[i]=min(mn[i],min(a[i]-a[i-1],a[i+1]-a[i]));
        mx[i]=max(mx[i],max(a[i]-a[0],a[n-1]-a[i]));
    }
    if (n>1)
    {


    mn[n-1]=a[n-1]-a[n-2];
    mx[n-1]=a[n-1]-a[0];
    }
    for (int i=0;i<n;i++)
    {
        cout<<mn[i]<<" "<<mx[i]<<endl;
    }
}