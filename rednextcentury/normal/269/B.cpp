# include <iostream>
# include <algorithm>
# include <vector>
using namespace std;
struct plant
{
    long double x;
    int v;
};
bool operator<(plant a,plant b)
{
    if (a.v==b.v)
        return a.x<b.x;
    else
        return a.v<b.v;
}
plant a[1000000];
int dp[10000];
int main()
{
    int n,m;
    cin>>n>>m;
    for (int i=0;i<n;i++)
        cin>>a[i].v>>a[i].x;
    int ans=0;
    sort(a,a+n);
    for (int i=0;i<n;i++)
    {
        dp[i]=1;
        for (int j=i-1;j>=0;j--)
            if (a[i].x>a[j].x)
                dp[i]=max(dp[i],dp[j]+1);
        ans=max(ans,dp[i]);
    }
    cout<<n-ans<<endl;
}