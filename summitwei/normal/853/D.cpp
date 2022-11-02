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
#define MOD 998244353LL
#define EPSILON 0.00001
#define f first
#define s second
#define pb push_back
#define mp make_pair
 
#define FOR(i, a, b) for (int i=(a); i<=(signed)(b); i++)
#define F0R(i, a) for (int i=0; i<(signed)(a); i++)
#define RFOR(i, a, b) for (int i=(a); i >= b; i--)

#define MN 300005
#define MK 42
int n;
int a[MN];
int dp[MN][MK];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> n;
    FOR(i, 1, n){
        cin >> a[i];
        a[i] /= 1000;
    }
    memset(dp, 0x3f, sizeof dp);
    dp[0][0] = 0;
    FOR(i, 1, n){
        FOR(k, 1, a[i]*10){
            dp[i][0] = min(dp[i][0], dp[i-1][k]+100*(a[i]*10-k));
        }
        FOR(j, 1, 40){
            if(a[i] == 1){
                if(j != 0) dp[i][j] = min(dp[i][j], dp[i-1][j-1]+1000);
                if(j <= 30) dp[i][j] = min(dp[i][j], dp[i-1][j+10]);
            } else{
                if(j >= 2) dp[i][j] = min(dp[i][j], dp[i-1][j-2]+2000);
                if(j <= 20) dp[i][j] = min(dp[i][j], dp[i-1][j+20]);
            }
        }
    }
    int mn = INF;
    FOR(i, 0, 40) mn = min(mn, dp[n][i]);
    cout << mn << "\n";

    return 0;
}