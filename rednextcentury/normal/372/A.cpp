#include<bits/stdc++.h>
#define ll long long
using namespace std;
int a[1000000];
int n;
bool check(int mid)
{
    int r=mid+1;
    for (int i=1;i<=mid;i++)
    {
        while(r<=n && a[i]*2>a[r])
            r++;
        if (r>n)return 0;
        r++;
    }
    return 1;
}
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>n;
    for (int i=1;i<=n;i++)
        cin>>a[i];
    sort(a+1,a+n+1);
    int l=1,r=n/2;
    int ans=0;
    while(l<=r)
    {
        int mid=(l+r)/2;
        if (check(mid))ans=mid,l=mid+1;
        else r=mid-1;
    }
    cout<<n-ans<<endl;
}