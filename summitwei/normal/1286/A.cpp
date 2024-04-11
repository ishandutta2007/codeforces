#pragma GCC optimize ("O3")
#pragma GCC target ("sse4")

#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
typedef vector<long long> vll;
typedef vector<pair<int, int> > vpii;
typedef pair<int, int> pii;
typedef long long ll;
typedef pair<ll, ll> pll;
typedef pair<double, double> pdd;
#define INF 0x3f3f3f3f
#define MOD 1000000007
#define EPSILON 0.00001
#define f first
#define s second
#define pb push_back
#define mp make_pair

#define FOR(i, a, b) for (int i=(a); i<=(signed)(b); i++)
#define F0R(i, a) for (int i=0; i<(signed)(a); i++)
#define RFOR(i, a, b) for (int i=(a); i >= b; i--)

#define MN 105
int n;
int p[MN];

int dp[MN][MN][MN][2];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> n;
    int no = (n+1)/2, ne = n/2;
    FOR(i, 1, n){
        cin >> p[i];
        if(p[i] != 0 && p[i] % 2 == 0) --ne;
        else if(p[i] != 0) --no;
    }
    //cout << ne << " " << no << "\n";
    memset(dp, 0x3f, sizeof dp);
    dp[0][ne][no][0] = 0;
    dp[0][ne][no][1] = 0;
    FOR(i, 1, n){
        FOR(j, 0, ne){
            FOR(k, 0, no){
                if(p[i] != 0){
                    if(p[i] % 2 == 0){
                        dp[i][j][k][0] = min(dp[i-1][j][k][0], dp[i-1][j][k][1]+1);
                    } else{
                        dp[i][j][k][1] = min(dp[i-1][j][k][1], dp[i-1][j][k][0]+1);
                    }
                } else{
                    dp[i][j][k][0] = min(dp[i-1][j+1][k][0], dp[i-1][j+1][k][1]+1);
                    dp[i][j][k][1] = min(dp[i-1][j][k+1][1], dp[i-1][j][k+1][0]+1);
                }
            }
        }
    }
    cout << min(dp[n][0][0][0], dp[n][0][0][1]) << "\n";

    /*F0R(i, 6){
        F0R(j, 6){
            F0R(k, 6){
                cout << dp[i][j][k][0] << " " << dp[i][j][k][1] << "  ";
            }
            cout << "\n";
        }
        cout << "\n";
    }*/

    return 0;
}