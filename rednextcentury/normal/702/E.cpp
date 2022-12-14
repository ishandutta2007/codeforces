# include <bits/stdc++.h>
using namespace std;
#define ll long long
ll sum[100003][40];
ll  mn[100003][40];
int f[100003][40];
int n;
ll k;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>k;
    for (int i=1;i<=n;i++)
        cin>>f[i][0],f[i][0]++;
    for (int i=1;i<=n;i++)
        cin>>sum[i][0],mn[i][0]=sum[i][0];
    for (int i=1;i<36;i++)
    {
        for (int j=1;j<=n;j++)
        {
            f[j][i]=f[f[j][i-1]][i-1];
            mn[j][i]=min(mn[j][i-1],mn[f[j][i-1]][i-1]);
            sum[j][i]=sum[j][i-1]+sum[f[j][i-1]][i-1];
        }
    }
    for (int i=1;i<=n;i++)
    {
        ll mini = 1e18;
        ll s = 0;
        int v = i;
        for (ll i=0;i<36;i++)
        {
            if ((1LL<<i)&k)
            {
                mini=min(mini,mn[v][i]);
                s+=sum[v][i];
                v=f[v][i];
            }
        }
        cout<<s<<' '<<mini<<endl;
    }
}