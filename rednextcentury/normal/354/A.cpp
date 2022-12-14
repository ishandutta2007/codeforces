#include<bits/stdc++.h>
using namespace std;
int a[1000000];
int sum[1000000];
int main()
{
    int n,l,r,ql,qr;
    cin>>n>>l>>r>>ql>>qr;
    for (int i=1;i<=n;i++)
    {
        cin>>a[i];
        sum[i]=sum[i-1]+a[i];
    }
    int ans=sum[n]*r+(n-1)*qr;
    for (int i=1;i<=n;i++)
    {
        int cur=(sum[i]*l)+(sum[n]-sum[i])*r;
        if ((n-i)>i)
            cur+=((n-i)-i-1)*qr;
        else if (i>(n-i))
            cur+=(i-(n-i)-1)*ql;
        ans=min(ans,cur);
    }
    cout<<ans<<endl;
}