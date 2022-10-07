#include<bits/stdc++.h>
#define ll long long
#define fi first
#define se second
using namespace std;
ll solve(ll n, ll x, ll s){
    if(s == 1) return solve(n, (x - 1), 0);
    if(x == 0) return solve(n, n, 0);
    if(x % 2 == 1) return (x + 1) / 2;
    if(n % 2 == 0) return n/2+solve(n/2,x/2,0);
    return (n+1)/2+solve(n/2,x/2,1);
}
main(){
    ll n,q;
    cin >> n >> q;
    while(q--){
        ll x;
        cin >> x;
        cout << solve(n, x, 0) << endl;
    }

}
/*
1.2.3.4.5  .6.7.8.9
5768

9
*/