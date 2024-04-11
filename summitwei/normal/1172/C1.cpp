#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
typedef vector<pair<int, int> > vpii;
typedef pair<int, int> pii;
typedef long long ll;
typedef long double ld;
typedef pair<ll, ll> pll;
typedef pair<double, double> pdd;
#define INF 1000000000
#define MOD 998244353LL
#define EPSILON 0.00001
#define f first
#define s second
#define pb push_back
#define mp make_pair

#define FOR(i, a, b) for (int i=(a); i<=(signed)(b); i++)
#define F0R(i, a) for (int i=0; i<(signed)(a); i++)
#define RFOR(i, a, b) for (int i=(a); i >= b; i--)

#define MN 55
int n, m;
int a[MN];
int w[MN];
ll dp[MN][MN];
ll pl, mn, tt;


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

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> m;
    FOR(i, 1, n){
        cin >> a[i];
    }
    FOR(i, 1, n){
        cin >> w[i];
        if(a[i]) pl += w[i];
        else mn += w[i];
        tt += w[i];
    }

    FOR(i, 1, n){
        memset(dp, 0, sizeof dp);
        dp[0][0] = w[i];
        ll sm = 0;
        FOR(j, 0, m){
            FOR(k, 0, m){
                if(j == 0 && k == 0) continue;
                if(j+k > m) continue;

                if(a[i]){
                    if(j != 0){
                        ll num = (dp[j-1][k]*(dp[j-1][k]+1))%MOD;
                        ll den = tt+j-1-k;
                        ll res = modDiv(num, den);
                        dp[j][k] = (dp[j][k]+res)%MOD;

                        ll prob = pl+j-1-dp[j-1][k];
                        prob = (prob+MOD)%MOD;
                        num = (dp[j-1][k]*prob)%MOD;
                        den = tt+j-1-k;
                        res = modDiv(num, den);
                        dp[j][k] = (dp[j][k]+res)%MOD;
                    }
                    if(k != 0){
                        ll prob = mn-k+1;
                        if(prob <= 0) continue;
                        ll num = (dp[j][k-1]*prob)%MOD;
                        ll den = tt+j-k+1;
                        ll res = modDiv(num, den);
                        dp[j][k] = (dp[j][k]+res)%MOD;
                    }
                } else{
                    if(j != 0){
                        ll prob = pl+j-1;
                        ll num = (dp[j-1][k]*prob)%MOD;
                        ll den = tt+j-1-k;
                        ll res = modDiv(num, den);
                        dp[j][k] = (dp[j][k]+res)%MOD;
                    }
                    if(k != 0){
                        ll prob, num, den, res;

                        prob = dp[j][k-1];
                        num = ((dp[j][k-1]-1)*prob)%MOD;
                        den = tt+j-k+1;
                        res = modDiv(num, den);
                        dp[j][k] = (dp[j][k]+res)%MOD;


                        prob = mn-k+1-dp[j][k-1];
                        prob = (prob+MOD)%MOD;
                        num = (dp[j][k-1]*prob)%MOD;
                        den = tt+j-k+1;
                        res = modDiv(num, den);
                        dp[j][k] = (dp[j][k]+res)%MOD;
                    }
                }
                //cout << i << " " << j << " " << k << " " << dp[j][k] << "\n";
                if(j+k==m) sm = (sm+dp[j][k])%MOD;
            }
        }

        cout << sm << "\n";
    }
    
    return 0;
}