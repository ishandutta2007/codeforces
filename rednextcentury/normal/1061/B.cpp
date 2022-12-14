#include<bits/stdc++.h>
using namespace std;
int a[1000000];
map<int,int> mp;
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n,m;
    cin>>n>>m;
    long long ret=0;
    long long sum=0;
    int ok=0;
    for (int i=0;i<n;i++)
    {
        cin>>a[i],ret+=(a[i]>0),sum+=a[i];
    }
    sort(a,a+n);
    for (int i=n-1;i>=0;i--)
    {
        if (i+1<n && a[i]>=a[i+1])a[i]=a[i+1]-1;
        if (a[i]<=0)break;
        if (++mp[a[i]]==1)ok++;
    }
    ret=ret+a[n-1]-ok;
    cout<<sum-ret<<endl;
}