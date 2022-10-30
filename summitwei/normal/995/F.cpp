#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
typedef vector<pair<int, int> > vpii;
typedef pair<int, int> pii;
typedef long long ll;
typedef pair<ll, ll> pll;
typedef pair<double, double> pdd;
#define INF 1000000000
#define MOD 1000000007LL
#define EPSILON 0.00001
#define f first
#define s second
#define pb push_back
#define mp make_pair

#define FOR(i, a, b) for (int i=(a); i<=(signed)(b); i++)
#define F0R(i, a) for (int i=0; i<(signed)(a); i++)
#define RFOR(i, a, b) for (int i=(a); i >= b; i--)

#define MN 3005
int n; ll d;
int p[MN];
vi e[MN];
ll dp[MN][MN];
pii ans[MN];

void dfs(int cn){
    FOR(i, 1, n) dp[cn][i] = 1;
    for(auto nn : e[cn]){
        dfs(nn);
        FOR(i, 1, n){
            dp[cn][i] = (dp[cn][i]*dp[nn][i]) % MOD;
        }
    }
    FOR(i, 1, n){
        dp[cn][i] = (dp[cn][i]+dp[cn][i-1])%MOD;
    }
}

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

ll interp(ll x){
    ll sm = 0;
    FOR(i, 0, n){
        ll num = 1, denom = 1;
        FOR(j, 0, n){
            if(i == j) continue;
            num = (num*(x-ans[j].f+MOD))%MOD;
            denom = (denom*(ans[i].f-ans[j].f+MOD))%MOD;
        }
        ll res = (modDiv(num, denom) * ans[i].s)%MOD;
        sm = (sm+res)%MOD;
    }
    return sm;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    cin >> n >> d;
    FOR(i, 2, n){
        cin >> p[i];
        e[p[i]].pb(i);
    }
    
    dfs(1);
    
    /*FOR(i, 1, n){
        FOR(j, 1, n){
            cout << dp[i][j] << " ";
        }
        cout << "\n";
    }*/
    FOR(i, 0, n){
        ans[i] = {i, dp[1][i]};
    }
    
    cout << interp(d) << "\n";

    return 0;
}