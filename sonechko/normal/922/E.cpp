#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define ss second
#define ff first
#define ll long long
#define ld long double
#define endl "\n"
#define mp make_pair

const ll N = 2e5 + 11;

ll use[N],c[N],cost[N];

ll dp[1005][10005];

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ll n,w,b,x;
    cin>>n>>w>>b>>x;
    for (ll i=0; i<=n; i++)
    for (ll j=0; j<=10001; j++)
    dp[i][j]=-1;
    dp[0][0]=w;
    for (ll i=1; i<=n; i++)
    {
        cin>>c[i];
    }
    ll res=0;
    for (ll i=1; i<=n; i++)
    {
        cin>>cost[i];
        for (ll p=0; p<=10000; p++)
        {
            ll f=dp[i-1][p];
            if (f>=0)
            {
                for (ll xy=0; xy<=c[i]; xy++)
                {
                    ll ch=min(w+p*b,f+x);
                    if (ch>=xy*cost[i])
                    {
                        ch-=xy*cost[i];
                        dp[i][p+xy]=max(dp[i][p+xy],ch);
                        res=max(res,p+xy);
                    }
                }
            }
        }
    }
    cout<<res<<endl;
}