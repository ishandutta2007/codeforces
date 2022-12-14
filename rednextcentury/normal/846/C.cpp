#include <bits/stdc++.h>
using namespace std;
long long a[1000000];
long long sum[1000000];
long long getSum(int l,int r)
{
    return sum[r-1]-sum[l-1];
}
long long best=-1e18,r1,r2,r3;
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0); cout.tie(0);
    int n;
    cin>>n;
    for (int i=1;i<=n;i++)
    {
        cin>>a[i];
        sum[i]=sum[i-1]+a[i];
    }
    for (int i=1;i<=n;i++)
    {
        long long b1=-1e18,i1;
        long long b2=b1,i3;
        for (int j=i;j>=1;j--)
        {
            long long cur = getSum(1,j)-getSum(j,i);
            if (cur>b1)b1=cur,i1=j-1;
        }
        for (int j=i;j<=n+1;j++)
        {
            long long cur=getSum(i,j)-getSum(j,n+1);
            if (cur>b2)b2=cur,i3=j-1;
        }
        if (b1+b2>best)best=b1+b2,r1=i1,r2=i-1,r3=i3;
    }
    cout<<r1<<' '<<r2<<' '<<r3<<endl;
}