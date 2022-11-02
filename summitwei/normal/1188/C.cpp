#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
typedef vector<vector<int> > vvi;
typedef vector<pair<int, int> > vpii;
typedef pair<int, int> pii;
typedef long long ll;
typedef pair<ll, ll> pll;
typedef pair<double, double> pdd;
typedef vector<ll> vll;
#define INF 0x3f3f3f3f
#define MOD 998244353LL
#define EPSILON 0.00001
#define f first
#define s second
#define pb push_back
#define mp make_pair

#define FOR(i, a, b) for (ll i=(a); i<=(signed)(b); i++)
#define F0R(i, a) for (ll i=0; i<(signed)(a); i++)
#define RFOR(i, a, b) for (ll i=(a); i >= b; i--)

#define MN 1005
int n, k;
int a[MN];
ll dp[2][MN];
ll calc(ll x){
    //cout << "doing " << x << "\n";
    memset(dp, 0, sizeof dp);
    dp[0][0] = 1;
    FOR(j, 1, k){
        F0R(i, n+1) dp[j%2][i] = 0;
        int l = 0;
        ll sm = 0;
        FOR(r, 1, n){
            while(a[r]-a[l] >= x){
                sm = (sm+dp[(j+1)%2][l])%MOD;
                ++l;
            }
            //cout << r << " " << a[r] << " has " << sm << "\n";
            dp[j%2][r] = sm;
        }
        //FOR(i, 1, n) cout << dp[j%2][i] << " ";
        //cout << "\n";
    }
    ll ans = 0;
    FOR(i, 1, n){
        ans = (ans+dp[k%2][i])%MOD;
    }
    return ans;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> k;
    FOR(i, 1, n) cin >> a[i];
    sort(a+1, a+1+n);
    a[0] = -INF;
    //FOR(i, 0, n) cout << a[i] << " ";
    //cout << "\n";
    ll ans = 0;
    FOR(x, 1, 100000/(k-1)){
        ll amt = calc(x);
        ans = (ans+amt)%MOD;
    }

    cout << ans << "\n";
    
    return 0;
}