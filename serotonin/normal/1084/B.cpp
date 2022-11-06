#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll ara[4321];

int main() {
    ll n,s;
    cin >> n >> s;
    ll total=0,mx=1e15;
    for(ll i=0; i<n; i++) {
        cin >> ara[i];
        total+=ara[i];
        mx=min(mx,ara[i]);
    }

    if(total<s) printf("-1\n");
    else {
        ll rem=0;
        for(ll i=0; i<n; i++) rem+=ara[i]-mx;
        if(rem<s) {
            mx-=(s-rem)/n;
            if((s-rem)%n) mx--;
        }
        printf("%lld\n", mx);
    }
}