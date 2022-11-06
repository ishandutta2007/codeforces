#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int sz=3e5+5;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);

    int t;
    cin >> t;
    while(t--) {
        ll a,b;
        cin >> a >> b;
        if(a<b) swap(a,b);
        ll x=a-b;
        ll y=sqrt(x);
        for(ll i=y; ; i++) {
            ll n=i;
            ll z=n*(n+1)/2;

            if(z<x || (z-x)&1) continue;
            cout << i << endl;
            break;
        }
    }
}