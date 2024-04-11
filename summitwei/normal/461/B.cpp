#pragma GCC optimize ("O3")
#pragma GCC target ("sse4")
 
#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
typedef vector<pair<int, int> > vpii;
typedef pair<int, int> pii;
typedef long long ll;
typedef pair<ll, ll> pll;
typedef pair<double, double> pdd;
#define INF 1000000000
#define MOD 1000000007
#define EPSILON 0.00001
#define f first
#define s second
#define pb push_back
#define mp make_pair
 
#define FOR(i, a, b) for (int i=(a); i<=(signed)(b); i++)
#define F0R(i, a) for (int i=0; i<(signed)(a); i++)
#define RFOR(i, a, b) for (int i=(a); i >= b; i--)
 
#define MN 100005
pll gcd(ll a, ll b){ //a*first+b*second=gcd
    if(a == 0){
        return mp(0, 1);
    }
 
    pll prev = gcd(b%a, a);
 
    return mp(prev.s-(b/a)*prev.f, prev.f);
} //using ll's just to be safe wrt overflow issues
ll modInv(ll x){ //return x^-1 % MOD
    pll res = gcd(x, MOD);
 
    res.f = (res.f+MOD)%MOD;
 
    //cout << "modinv of " << x << " is " << res.f << "\n";
 
    return res.f;
}
ll modDiv(ll x, ll y){
    return (x*modInv(y))%MOD;
}
 
int n;
int p[MN];
vi ch[MN];
 
int c[MN];
 
ll dp[MN][2];
void dfs(int cn){
    ll prod = 1;
    ll res = 0;
    F0R(i, ch[cn].size()){
        int nn = ch[cn][i];
 
        dfs(nn);
        ll sm = (dp[nn][0]+dp[nn][1])%MOD;
        prod = (prod*sm)%MOD;
        res = (res+modDiv(dp[nn][1], sm))%MOD;
    }
 
    if(c[cn] == 0){
        dp[cn][0] = prod;
        dp[cn][1] = (prod*res)%MOD;
    } else{
        dp[cn][0] = 0;
        dp[cn][1] = prod;
    }
 
    //cout << cn << " " << dp[cn][0] << " " << dp[cn][1] << "\n";
}
 
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
 
    cin >> n;
    FOR(i, 1, n-1){
        cin >> p[i];
        ch[p[i]].pb(i);
    }
    F0R(i, n){
        cin >> c[i];
    }
 
    dfs(0);
    cout << dp[0][1] << "\n";
 
    return 0;
}