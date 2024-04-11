#include <bits/stdc++.h>
using namespace std;
long long dp[60];
int a[60];
int b[60];
int main()
{
    dp[0]=1;
    dp[1]=1;
    dp[2]=2;
    for (int i=3;i<=50;i++)
    {
        for (int j=i-2;j>=0;j--)
                dp[i]+=dp[j];
        dp[i]++;
    }
    long long n,k;
    cin>>n>>k;
    int cur=n-1;
    for (int i=1;i<=n;i++)
    {
        if (dp[cur]>=k)
        {
            a[i]=0;
            cur--;
        }
        else
        {
            a[i]=1;
            a[i+1]=0;
            i++;
            k-=dp[cur];
            cur-=2;
        }
    }
    for (int i=1;i<=n;i++)
        b[i]=i;
    for (int i=1;i<=n;i++)
        if (a[i])
            swap(b[i],b[i+1]);
    for (int i=1;i<=n;i++)
        cout<<b[i]<<' ';
    cout<<endl;
}