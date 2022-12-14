# include<bits/stdc++.h>
using namespace std;
long long a[1000000],dp[1000000];
int main()
{
    int n;
    cin>>n;
    int sum=0;
    for (int i=1;i<=n;i++)
        cin>>a[i],sum+=a[i];
    sort(a+1,a+n+1);
    int v=sum/n;
    int x=sum%n;
    x=n-x;
    int ans=0;
    for (int i=1;i<=n;i++)
    {
        if (i==x+1)
            v++;
        ans+=max(0LL,v-a[i]);
    }
    cout<<ans<<endl;
}