#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define ff first
#define ss second
#define mp make_pair
#define pb push_back

const int N = 1e6 + 11;



int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n,m;
    cin>>n>>m;
    ll ans=0;
    for (int l=0; l<m; l++)
    for (int r=0; r<m; r++)
    if ((l*l+r*r)%m==0)
    {
        ll x=n/m;
        if (n%m>=l&&l!=0) x++;
        ll y=n/m;
        if (n%m>=r&&r!=0) y++;
        //cout<<l<<" "<<r<<" "<<x<<" "<<y<<endl;
        ans+=x*1ll*y;
    }
    cout<<ans<<endl;
}