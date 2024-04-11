#include<bits/stdc++.h>
using namespace std;

#define ll long long

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int t;
    cin>>t;
    while (t--)
    {
        ll n,m;
        cin>>n>>m;
        ll ans=0;
        ll k=(n/m);
        for (int j=1; j<=9; j++)
        {
            ll t=k/10;
            if (k%10>=j) t++;
            ans+=t*1ll*((m*1ll*j)%10);
        }
        cout<<ans<<"\n";
    }
}


/**
1m % 10   11m % 10
2m % 10   ......
3m % 10
......
9m % 10
0m % 10
**/