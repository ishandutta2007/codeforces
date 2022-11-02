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
#define MS 320
int n, m, x;
//ll dp[MS][MS][MS];
vector<vector<vector<ll> > > dp;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    cin >> n >> m >> x;
    if(n > m){
        cout << "0\n";
        return 0;
    }
    dp.resize(m+1);
    F0R(i, m+1){
        dp[i].resize(n+1);
        F0R(j, n+1){
            dp[i][j].resize(n+1);
        }
    }
    dp[0][0][0] = 1;
    FOR(i, 1, m){
        FOR(j, 0, n){
            FOR(k, 0, j){
                if(i == x){
                    if(j != 0) dp[i][j][k] = (dp[i][j][k]+dp[i-1][j-1][k])%MOD;
                    if(j != 0 && k != 0) dp[i][j][k] = (dp[i][j][k]+dp[i-1][j-1][k-1])%MOD;
                } else{
                    dp[i][j][k] = (dp[i][j][k]+dp[i-1][j][k])%MOD;
                    if(j != 0) dp[i][j][k] = (dp[i][j][k]+dp[i-1][j-1][k])%MOD;
                    if(k != 0) dp[i][j][k] = (dp[i][j][k]+dp[i-1][j][k-1])%MOD;
                    if(j != 0 && k != 0) dp[i][j][k] = (dp[i][j][k]+dp[i-1][j-1][k-1])%MOD;
                }
            }
        }
    }
    ll res = dp[m][n][n];
    FOR(i, 1, n){
        res = (res*i)%MOD;
    }
    
    cout << res << "\n";

    return 0;
}