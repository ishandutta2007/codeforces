# include<iostream>
# include<iomanip>
#include <cstdio>
# include <algorithm>
using namespace std;
int mn[1000000];
int a[1000000];
int now;
int binsearch(int s,int e)
{
    int ans=-1;
    while(s<=e)
    {
        int mid=(s+e)/2;
        if (mn[mid]<now)
        {
            ans=mid;
            s=mid+1;
        }
        else
            e=mid-1;
    }
    return ans;
}
int main()
{
    int n;
    cin>>n;
    for (int i=1;i<=n;i++)
        cin>>a[i];
    mn[n]=a[n];
    for (int i=n-1;i>=1;i--)
        mn[i]=min(mn[i+1],a[i]);
    for (int i=1;i<=n;i++)
    {
        now=a[i];
        int x=binsearch(i+1,n);
        if (x==-1)
            cout<<x<<" ";
        else
            cout<<x-i-1<<" ";
    }
    cout<<endl;
}