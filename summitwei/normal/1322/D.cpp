#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
typedef vector<pair<int, int> > vpii;
typedef pair<int, int> pii;
typedef long long ll;
typedef pair<ll, ll> pll;
typedef pair<double, double> pdd;
typedef vector<ll> vll;
#define INF 0x3f3f3f3f
#define MOD 1000000007LL
#define EPSILON 0.00001
#define f first
#define s second
#define pb push_back
#define mp make_pair
 
#define FOR(i, a, b) for (ll i=(a); i<=(signed)(b); i++)
#define F0R(i, a) for (ll i=0; i<(signed)(a); i++)
#define RFOR(i, a, b) for (int i=(a); i >= b; i--)
 
#define MN 2005
#define ML 13
int n, m;
int a[MN];
int s[MN];
int c[MN*2];
int dp[MN][5+(1<<ML)];
int mdp[MN];
int sm[MN*2];
 
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
 
    cin >> n >> m;
    FOR(i, 1, n){
        cin >> a[i];
    }
    FOR(i, 1, n){
        cin >> s[i];
    }
    FOR(i, 1, n+m){
        cin >> c[i];
        sm[i] = sm[i-1]+c[i];
    }
 
    memset(dp, -0x3f, sizeof dp);
    int bst = 0;
 
    RFOR(i, n, 1){
        //dp assumes use but check others with no carryover
        /*dp[i][0] = 0;
        dp[i][1] = c[a[i]]-s[i];*/
        int bon = c[a[i]]-s[i];
        F0R(k, ML){
            int loc = a[i]-k;
            if(loc <= 0) continue;
            RFOR(j, (1<<ML)-1, 0){
                if(dp[loc][j] <= -INF/2) continue;
                //use or no
                int ns = j>>k;
                int nw = ++ns;
 
                //calc bonus
                int zs = __builtin_ctz(nw);
                int eb = sm[a[i]+zs]-sm[a[i]];
 
                //update dp
                dp[a[i]][nw] = max(dp[a[i]][nw], dp[loc][j]+bon+eb);
                mdp[a[i]] = max(mdp[a[i]], dp[a[i]][nw]);
            }
        }
        dp[a[i]][0] = max(dp[a[i]][0], 0);
        dp[a[i]][1] = max(dp[a[i]][1], bon); mdp[a[i]] = max(mdp[a[i]], bon);
        if(a[i]-ML >= 0){
            FOR(j, 0, a[i]-ML){
                dp[a[i]][1] = max(dp[a[i]][1], mdp[j]+bon);
                mdp[a[i]] = max(mdp[a[i]], dp[a[i]][1]);
            }
        }
 
        /*FOR(j, 1, m){
            F0R(k, (1<<ML)){
                if(dp[j][k] >= -100000){
                    cout << i << " " << j << " " << k << " " << dp[j][k] << "\n";
                }
            }
        }*/
    }
    int ans = 0;
    FOR(i, 1, m) ans = max(ans, mdp[i]);
 
    cout << ans << "\n";
 
    return 0;
}