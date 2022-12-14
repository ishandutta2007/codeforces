#include <bits/stdc++.h>
using namespace std;
long long n,m;
long long bs(long long l,long long r)
{
    long long ans=r;
    while(l<=r)
    {
        long long mid=(l+r)/2;
        if (n-mid*(mid+1)/2<=m)
            ans=mid,r=mid-1;
        else
            l=mid+1;
    }
    return ans;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>m;
    if (n<=m)
        cout<<n<<endl;
    else
        cout<<m+bs(1,3000000000)<<endl;
}