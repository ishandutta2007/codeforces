#include<bits/stdc++.h>
using namespace std;
#define ff first
#define ss second
#define ll long long
#define mp make_pair
#define pb push_back

const int N = 1e5 + 11;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ll n;
    cin>>n;
    n*=2;
    for (ll j=1; j<=100000; j++)
    {
        ll m=n-j*(j+1);
        if (m<0) break;
        ll l=1,r=100000;
        while (r-l>1)
        {
            ll mid=(l+r)/2;
            if (mid*(mid+1)>m) r=mid; else l=mid;
        }
        if (r*(r+1)==m) {cout<<"YES"<<endl; return 0;}
        if (l*(l+1)==m) {cout<<"YES"<<endl; return 0;}
    }
    cout<<"NO"<<endl; return 0;
}