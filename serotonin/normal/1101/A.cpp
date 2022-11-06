#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll sz=5e5+5;

int main()
{
    ll n,m,i,j,k,x,y,q;
    cin >> q;
    while(q--) {
        ll l,r,d;
        cin >> l >> r >> d;
        if(l<=d && d<=r) {
            x=r/d;
            printf("%lld\n", (x+1)*d);
        }
        else printf("%lld\n", d);
    }
}