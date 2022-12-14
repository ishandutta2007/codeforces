    #include <iostream>
    #include <bits/stdc++.h>
    #include <math.h>
    #define ll int
    #define mkp make_pair
    #define pb push_back
    #define pf push_front
    #include <string>
    #define I ll i,j;
    #define J ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ll mod=1000000007;
    ll mod2=998244353;
    ll OO=1e18;
    using namespace std;
     
    ll n,m,b;
    ll a[555];
    ll dp[5][1100][1100];
     
    ll david_villa(ll indx,ll bugs,ll lines)
    {
        if (indx==n)
        {
            if (lines==m&&bugs<=b)
                return 1;
            return 0;
        }
        if (lines==m)
        {
            if (bugs<=b)
                return 1;
            return 0;
        }
        if (dp[indx][bugs][lines]+1) return dp[indx][bugs][lines];
        ll r1=0,r2=0;
        r1=david_villa(indx+1,bugs,lines);
        r2=david_villa(indx,bugs+a[indx],lines+1);
        return dp[indx][bugs][lines]=((r1%mod)+(r2%mod))%mod;
    }
     
     
    int main()
    {
        I;J;
        cin >>n>>m>>b>>mod;
        for (i=0; i<n; i++)
            cin >>a[i];
        memset(dp,0,sizeof (dp));
        for (i=0; i<=b; i++)
            for (j=0; j<=n; j++)
                dp[j%2][i][m]=1;
        ll l;
        for (i=n-1; i>=0; i--)
        {
            for (j=m; j>=0; j--)
            {
                for (l=b;l>=0;l--)
                {
                    ll x=0;
                    x=((dp[(i+1)%2][l][j]%mod)+(dp[i%2][l+a[i]][j+1]%mod))%mod;
                    dp[i%2][l][j]=x;
                }
            }
        }
        cout <<dp[0][0][0];
        return 0;
    }