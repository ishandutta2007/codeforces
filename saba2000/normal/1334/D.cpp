#include<bits/stdc++.h>
#define ll long long
using namespace std;
void solve(ll n, ll l, ll r){
    while(l < 2*(n-1) && l <= r){
        if(l&1) cout << 1 <<" ";
        else cout<<l/2+1<<" ";
        l++;
    }
    l -= 2*(n-1) - 1;
    r -= 2*(n-1) - 1;
    for(int i = 2; i <= n - 1; i++){
        if(l == 1) cout<<n<<" ", l++;
        while(l <= 2 * (n - i) && l <= r){
            if(l & 1) cout << i + l/2 << " ";
            else cout<<i<<" ";
            l++;
        }
        l -= 2*(n-i);
        r -= 2*(n-i);
        if(l > r || r < 1) return;
    }
    if(l > r) return;
    if(l == 1) cout<<n<<" ";
    if(r == 2) cout<<1<<" ";
}

main(){
    ll t;
    cin >> t;
    while(t--){
        ll n, l, r;
        cin >> n >> l >> r;
        solve(n, l, r);

    }
}