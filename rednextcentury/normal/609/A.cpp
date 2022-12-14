# include<bits/stdc++.h>
using namespace std;
long long a[1000000],dp[1000000];
int main()
{
    int n,m;
    cin>>n>>m;
    for (int i=0;i<n;i++)
        cin>>a[i];
    sort(a,a+n);
    int ans=0;
    for (int i=n-1;i>=0;i--)
    {
        m-=a[i];
        ans++;
        if (m<=0)
            break;
    }
    cout<<ans<<endl;
}