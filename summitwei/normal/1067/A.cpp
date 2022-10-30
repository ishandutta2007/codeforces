#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
typedef vector<pair<int, int> > vpii;
typedef pair<int, int> pii;
typedef long long ll;
typedef long double ld;
typedef pair<ll, ll> pll;
typedef pair<double, double> pdd;
#define INF 1000000000000LL
#define MOD 998244353LL
#define EPSILON 0.00001
#define f first
#define s second
#define pb push_back
#define mp make_pair

#define FOR(i, a, b) for (int i=(a); i<=(signed)(b); i++)
#define F0R(i, a) for (int i=0; i<(signed)(a); i++)
#define RFOR(i, a, b) for (int i=(a); i >= b; i--)

#define MN 100005
#define MM 205
int n, m;
int a[MN];
ll dp[MN][MM][2]; //not sat, sat

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> n;
    m = 200;
    FOR(i, 1, n){
        cin >> a[i];
    }
    if(a[1] == -1){
        FOR(j, 1, m){
            dp[1][j][0] = 1;
        }
    } else{
        dp[1][a[1]][0] = 1;
    }
    FOR(i, 2, n){
        ll sm = 0;
        FOR(j, 1, m){
            dp[i][j][0] = sm;
            sm += (dp[i-1][j][0]+dp[i-1][j][1]);
            sm %= MOD;
        }
        ll sm2 = 0;
        RFOR(j, m, 1){
            sm2 += dp[i-1][j][1];
            sm2 %= MOD;
            dp[i][j][1] = (sm2+dp[i-1][j][0])%MOD;
        }
        if(a[i] != -1){
            FOR(j, 1, m){
                if(j != a[i]){
                    dp[i][j][0] = dp[i][j][1] = 0;
                }
            }
        }
    }

    /*FOR(i, 1, n){
        FOR(j, 1, m){
            cout << dp[i][j][0] << " ";
        }
        cout << "\n";
    }
    FOR(i, 1, n){
        FOR(j, 1, m){
            cout << dp[i][j][1] << " ";
        }
        cout << "\n";
    }*/

    ll ans = 0;
    FOR(i, 1, m){
        ans += dp[n][i][1];
        ans %= MOD;
    }
    cout << ans << "\n";

    return 0;
}