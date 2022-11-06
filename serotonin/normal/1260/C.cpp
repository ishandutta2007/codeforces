#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll sz=3e5+5;

int main()
{
    int t;
    cin >> t;
    while(t--) {
        ll r,b,k;
        cin >> r >> b >> k;
        if(r<b) swap(r,b);

        ll g=__gcd(r,b);
        if(g==b) g=0;
        ll x=(r-g-1)/b;
        if(g) x++;
        if(x>=k) puts("REBEL");
        else puts("OBEY");
    }
}