# include<bits/stdc++.h>
using namespace std;
long long a[1000000],dp[1000000];
int main()
{
    int n,m;
    cin>>n>>m;
    for (int i=0;i<n;i++)
    {
        int x;
        cin>>x;
        a[x]++;
    }
    int sum=0;
    int ans=0;
    for (int i=1;i<=m;i++)
    {
        ans+=sum*a[i];
        sum+=a[i];
    }
    cout<<ans<<endl;
}