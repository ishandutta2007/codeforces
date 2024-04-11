#include<bits/stdc++.h>
using namespace std;
int a[1000000];
int main()
{
    int n;
    cin>>n;
    int mx=0;
    for (int i=0;i<n;i++)
        cin>>a[i];
    mx=a[n-1]-a[n-2];
    int mn=100000000;
    for (int i=1;i<n-1;i++)
    {
        mx=max(mx,a[i]-a[i-1]);
        mn=min(mn,a[i+1]-a[i-1]);
    }
    cout<<max(mx,mn)<<endl;
}