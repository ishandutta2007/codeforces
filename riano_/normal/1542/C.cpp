#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define rep(i,n) for(int (i)=0;(i)<(n);(i)++)
#define Pr pair<ll,ll>
#define Tp tuple<ll,ll,ll>
using Graph = vector<vector<int>>;

ll mod = 1000000007;


// 
ll gcd(ll x,ll y){
    ll r=1;
    if(x<=y) swap(x,y);
    if(y==0) r=0;
    while(r>0){
        r=x%y;
        x=y;
        y=r;
    }
    return x;
}

// 
// "gcd"
ll lcm(ll x,ll y){
    ll a = gcd(x,y);
    return (x/a)*y;
}

int main() {
    ll T; cin >> T;
    rep(ii,T){
        
        ll N; cin >> N; ll ans = N;
        ll t = 1; ll s = 1;
        while(t<=N){
            ans += (N/t)%mod;
            s++; t = lcm(t,s);
        }
        ans %= mod;
        cout << ans << endl;
    }
    //cout << ans << endl;
}