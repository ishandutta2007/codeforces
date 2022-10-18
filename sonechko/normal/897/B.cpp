#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define ff first
#define ll long long
#define ss second
const ll N = 1e6 + 11;



int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n,k;
    cin>>n>>k;
    ll ans=0;
    for (int i=1; i<=n; i++)
    {
        ll xx=i;
        int p=i;
        while (p>0)
        {
            xx*=10;
            xx+=1LL*(p%10);
            p/=10;
        }
        ans=(ans+xx)%k;
    }
    cout<<ans<<endl;
}