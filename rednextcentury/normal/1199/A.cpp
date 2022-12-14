#include<bits/stdc++.h>
using namespace std;
int a[1000000];
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n,x,y;
    cin>>n>>x>>y;
    for (int i=0;i<n;i++)
        cin>>a[i];
    for (int i=0;i<n;i++)
    {
        bool ok=1;
        for (int j=i-1;j>=max(0,i-x);j--)ok&=a[j]>a[i];
        for (int j=i+1;j<=min(i+y,n-1);j++)ok&=a[j]>a[i];
        if (ok)return cout<<i+1<<endl,0;
    }
}