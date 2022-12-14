#include <bits/stdc++.h>
using namespace std;
multiset<long long> s;
long long dp[1000000];
long long a[1000000];
int main()
{
    int n,c;
    cin>>n>>c;
    long long sum=0;
    for (int i=1;i<=n;i++)
    {
        cin>>a[i];
        sum+=a[i];
        s.insert(a[i]);
        if (i>c)
        {
            s.erase(s.find(a[i-c]));
            sum-=a[i-c];
        }
        dp[i]=dp[i-1]+a[i];
        if (i>=c)
        {
            dp[i]=min(dp[i],dp[i-c]+sum-*s.begin());
        }
    }
    cout<<dp[n]<<endl;
}