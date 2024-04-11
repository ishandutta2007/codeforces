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
#define MOD 998244353
#define EPSILON 0.00001
#define f first
#define s second
#define pb push_back
#define mp make_pair

#define FOR(i, a, b) for (int i=(a); i<=(signed)(b); i++)
#define F0R(i, a) for (int i=0; i<(signed)(a); i++)
#define RFOR(i, a, b) for (int i=(a); i >= b; i--)

#define MN 505
int n, m;
int c[MN];
int inv[MN];

ll dp[MN][MN];
ll dp2[MN][MN];

//2 = when right side has been decided
ll calc2(int a, int b, int ml);

ll calc(int a, int b){
    if(a > b) return 1;
    if(dp[a][b] != -1) return dp[a][b];
    if(a >= b){
        dp[a][b] = 1;
        return 1;
    }

    int mn = n+1;
    int ml = a;
    FOR(i, a, b){
        mn = min(mn, c[i]);
        if(mn == c[i]) ml = i;
    }
    // cout << "for " << a << " " << b << " ml is " << ml << "\n";
    ll res = 0;
    FOR(i, ml, b){
        ll amt = (calc2(a, i, ml)*calc(i+1, b))%MOD;
        res = (res+amt)%MOD;
    }
    // res += calc2(a, b, ml);
    // res %= MOD;

    dp[a][b] = res;
    //cout << "dp " << a << " " << b << " " << res << "\n";
    return res;
}
ll calc2(int a, int b, int ml){
    if(dp2[a][b] != -1) return dp2[a][b];
    if(a >= b){
        dp2[a][b] = 1;
        return 1;
    }

    ll res = 0;
    FOR(i, a, ml-1){
        ll amt = (calc(a, i)*((calc(i+1, ml-1)*calc(ml+1, b))%MOD))%MOD;
        res = (res+amt)%MOD;
    }
    res += ((calc(a, ml-1)*calc(ml+1, b))%MOD);
    res %= MOD;

    dp2[a][b] = res;
    //cout << "dp2 " << a << " " << b << " " << res << "\n";
    return res;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    cin >> n >> m;
    F0R(i, n){
        cin >> c[i];
        inv[c[i]] = i;
    }

    memset(dp, -1, sizeof(dp));
    memset(dp2, -1, sizeof(dp2));
    
    cout << calc(0, n-1) << "\n";

    return 0;
}