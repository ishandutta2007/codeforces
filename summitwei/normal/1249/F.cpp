#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
typedef vector<vector<int> > vvi;
typedef vector<pair<int, int> > vpii;
typedef pair<int, int> pii;
typedef long long ll;
typedef long double ld;
typedef pair<ll, ll> pll;
typedef pair<double, double> pdd;
typedef vector<ll> vll;
#define INF 0x3f3f3f3f
#define MOD 998244353LL
#define EPS 0.00001
#define f first
#define s second
#define pb push_back
#define mp make_pair

#define FOR(i, a, b) for (int i=(a); i<=(signed)(b); i++)
#define F0R(i, a) for (int i=0; i<(signed)(a); i++)
#define RFOR(i, a, b) for (int i=(a); i >= b; i--)

#define MN 205
int n, k;
int a[MN];
vi e[MN];
int dp[MN][MN]; //closest node from bottom, >k -> k
//treat each individual node as closest?
int bruh[MN];
void dfs(int cn, int p){
    for(auto nn : e[cn]) if(nn != p) dfs(nn, cn);
    dp[cn][0] = a[cn];
    for(auto nn : e[cn]) if(nn != p){
        memset(bruh, 0, sizeof bruh);
        FOR(i, 1, k){
            bruh[i] = dp[nn][i-1];
            if(i == k) bruh[i] = max(bruh[i], dp[nn][i]);
            for(auto nn2 : e[cn]) if(nn2 != p){
                if(nn2 == nn) continue;
                int mx = 0;
                FOR(j, i, k){
                    if(i+j<=k) continue; //OBO?
                    //if(j == k) bruh[i] += max(dp[nn2][j-1], dp[nn2][j]);
                    //else bruh[i] += dp[nn2][j-1];
                    mx = max(mx, dp[nn2][j-1]);
                }
                mx = max(mx, dp[nn2][k]);
                bruh[i] += mx;
            }
        }
        dp[cn][0] += dp[nn][k];
        FOR(i, 1, k){
            //cout << nn << " " << i << " " << bruh[i] << "\n";
            dp[cn][i] = max(dp[cn][i], bruh[i]);
        }
    }
    /*cout << cn << ": ";
    F0R(i, k+1){
        cout << dp[cn][i] << " ";
    }
    cout << "\n";*/
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> k;
    FOR(i, 1, n) cin >> a[i];
    F0R(_, n-1){
        int u, v;
        cin >> u >> v;
        e[u].pb(v);
        e[v].pb(u);
    }
    dfs(1, 0);
    int ans = 0;
    FOR(i, 0, k){
        ans = max(ans, dp[1][i]);
    }
    cout << ans << "\n";
    
    return 0;
}