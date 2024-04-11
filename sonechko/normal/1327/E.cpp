#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define ff first
#define ss second
#define mp make_pair
#define pb push_back

const int N = 2e5 + 11;
const ll MOD = 998244353;


ll st[N];

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n;
    cin>>n;
    st[0]=1;
    for (int i=1; i<=n; i++)
        st[i]=(st[i-1]*10ll)%MOD;
    for (int k=1; k<=n; k++)
    {
        if (n==k) cout<<10<<" "; else
        {
            ll ans=0;
            ans=(ans+10ll*9ll*st[n-k-1]*2ll)%MOD;
            ll p=n-k-1;
            if (p>0)
                ans=(ans+10ll*9ll*9ll*p*st[n-k-2])%MOD;
            cout<<ans<<" ";
        }
    }
}
/**



.....Xxxx
**/