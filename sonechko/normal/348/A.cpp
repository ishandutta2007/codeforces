#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define ll long long
const int N = 1e5 + 11;
ll a[N],n;
bool good(ll l)
{
    ll kol=0;
    for (int i=1; i<=n; i++)
        kol+=l-a[i];
    if (kol>=l) return true;
    return false;
}

int main()
{
    cin>>n;
    for (int i=1; i<=n; i++)
        cin>>a[i];
    sort(a+1,a+n+1);
    ll l=a[n],r=1e13;
    while (r-l>1)
    {
        ll mid=(l+r)/2;
        if (good(mid)) r=mid; else l=mid;
    }
    if (good(l)) cout<<l<<endl; else cout<<r<<endl;
}