#include<bits/stdc++.h>
#define ll long long
using namespace std;
const ll MN = 3e5 + 9;
vector<ll> v[MN];
ll A[MN], B[MN], C[MN];
ll mod = 998244353;
void dfs(ll x, ll p){
    ll bm = 1;
    A[x] = 1;
    B[x] = 1;
    C[x] = 1;
    for(ll y : v[x]){
        if(y == p) continue;
        dfs(y, x);
        B[x] = B[x] * (A[y] + B[y] + A[y] + B[y] + C[y]) % mod;
        A[x] = A[x] * (B[y] + B[y] + A[y]) % mod;
        C[x] = C[x] * (A[y] + B[y] )% mod;
    }
    A[x] = (A[x] - C[x] + mod) % mod;

}
//C[
main(){
    ios::sync_with_stdio();
    cin.tie(0);
    ll n;
    cin >> n;
    for(ll i = 1; i < n; i++){
        ll a, b;
        cin >> a >> b;
        v[a].push_back(b);
        v[b].push_back(a);
    }
    dfs(1,0);
    cout << (A[1] + B[1] - 1 + mod)%mod << endl;
}
/*
A[x] =
*/