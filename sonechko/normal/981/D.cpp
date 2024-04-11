#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ff first
#define ss second
#define mp make_pair
#define pb push_back

const int N = 50 + 11;

ll a[N];
bool dp[N][N];

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n,k;
    cin>>n>>k;
    for (int i=1; i<=n; i++)
        cin>>a[i];
    ll res=0;
    for (int d=62; d>=0; d--)
    {
        ll xx=1;
        for (int j=1; j<=d; j++)
            xx*=2ll;
        for (int j=0; j<=n; j++)
        for (int p=0; p<=k; p++)
        dp[j][p]=0;
        dp[0][0]=1;
        for (int j=1; j<=n; j++)
        for (int p=1; p<=k; p++)
        {
            ll ss=0;
            for (int l=j; l>=1; l--)
            {
                ss+=a[l];
                if ((ss&(res+xx))==res+xx&&dp[l-1][p-1]) dp[j][p]=1;
            }
        }
        if (dp[n][k]) res+=xx;
    }
    cout<<res<<endl;
}