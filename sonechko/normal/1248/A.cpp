#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define ff first
#define ss second
#define mp make_pair
#define pb push_back

const int N = 4e5 + 11;
const int MOD = 1e9 + 7;



int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int t;
    cin>>t;
    while (t--)
    {
        int n;
        cin>>n;
        ll k0=0,k1=0;
        for (int i=1; i<=n; i++)
        {
            int l;
            cin>>l;
            if (l%2==0) k0++; else k1++;
        }
        ll ans=0;
        int m;
        cin>>m;
        for (int i=1; i<=m; i++)
        {
            int l;
            cin>>l;
            if (l%2==0) ans+=k0; else ans+=k1;
        }
        cout<<ans<<"\n";
    }
}
/**
**/