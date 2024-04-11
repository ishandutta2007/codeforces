#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int sz=3e5+5;

int main()
{
    ll n,l,r;
    cin >> n >> l >> r;
    ll mn=0,mx=0;
    for(ll i=0, j=1; i<l; i++, j<<=1LL) mn+=j;
    mn+=n-l;
    for(ll i=0, j=1; i<r; i++, j<<=1LL) mx+=j;
    mx+=(n-r)*(1LL<<(r-1));
    cout << mn << " " << mx << endl;
}