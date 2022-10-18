#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define ll long long
const int N = 2e5 + 11;

ll n,k;

bool good(ll r)
{
    ll p=0;
    while (1==1)
    {
        p+=r;
        r/=k;
        if (r==0) break;
    }
    if (p>=n) return true;
    return false;
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin>>n>>k;
    ll l=1,r=n;
    while (r-l>1)
    {
        ll mid=(l+r)/2;
        if (good(mid)) r=mid; else l=mid;
    }
    if (good(l)) cout<<l; else cout<<r;
}