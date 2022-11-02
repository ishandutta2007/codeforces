#pragma GCC optimize ("O3")
#pragma GCC target ("sse4")

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
#define MOD 1000000007LL
#define EPS 0.00001
#define f first
#define s second
#define pb push_back
#define mp make_pair

#define FOR(i, a, b) for (int i=(a); i<=(signed)(b); i++)
#define F0R(i, a) for (int i=0; i<(signed)(a); i++)
#define RFOR(i, a, b) for (int i=(a); i >= b; i--)

#define MN 100005 //check limits you incompetent ree
int r, n;
int t[MN], x[MN], y[MN];
int dp[MN];
int dpmx[MN];

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    memset(dp, -0x3f, sizeof dp);
    memset(dpmx, -0x3f, sizeof dpmx);

    cin >> r >> n;
    FOR(i, 1, n) cin >> t[i] >> x[i] >> y[i];
    x[0] = y[0] = 1;
    dp[0] = dpmx[0] = 0;
    FOR(i, 1, n){
        RFOR(j, i-1, 0){
            if(t[i]-t[j] >= 2*r){
                dp[i] = max(dp[i], dpmx[j]+1);
                break;
            }
            if(t[i]-t[j] >= abs(x[i]-x[j])+abs(y[i]-y[j])){
                //cout << "trans " << i << " " << j << "\n";
                dp[i] = max(dp[i], dp[j]+1);
            }
        }
        dpmx[i] = max(dp[i], dpmx[i-1]);
    }
    cout << dpmx[n] << "\n";
    //FOR(i, 1, n) cout << dp[i] << " ";

    return 0;
}