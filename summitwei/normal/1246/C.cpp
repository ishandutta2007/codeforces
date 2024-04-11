#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
typedef vector<pair<int, int> > vpii;
typedef pair<int, int> pii;
typedef long long ll;
typedef pair<ll, ll> pll;
typedef pair<double, double> pdd;
#define INF 1000000000
#define MOD 1000000007LL
#define EPSILON 0.00001
#define f first
#define s second
#define pb push_back
#define mp make_pair

#define FOR(i, a, b) for (int i=(a); i<=(signed)(b); i++)
#define F0R(i, a) for (int i=0; i<(signed)(a); i++)
#define RFOR(i, a, b) for (int i=(a); i >= b; i--)

#define MN 2005
int n, m;
char gr[MN][MN];
vi rcks[MN][2]; //horiz, vert
ll dp[MN][MN][2]; //prev R, prev D
ll sm[MN][MN][2]; //sums left, sums up


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    cin >> n >> m;
    FOR(i, 1, n){
        FOR(j, 1, m){
            cin >> gr[i][j];
            if(gr[i][j] == 'R'){
                rcks[i][0].pb(j);
                rcks[j][1].pb(i);
            }
        }
    }
    if(n == 1 && m == 1){
        cout << "1\n";
        return 0;
    }
    FOR(i, 1, n){
        FOR(j, 1, m){
            if(i == j && j == 1){
                dp[i][j][0] = dp[i][j][1] = 1;
                sm[i][j][0] = sm[i][j][1] = 1;
                continue;
            }
            int amtRt = m-j;
            int loc = rcks[i][0].size()-1-amtRt;
            int bd;
            if(loc < 0){
                bd = 1;
            } else{
                bd = rcks[i][0][loc];
            }
            dp[i][j][0] = (sm[i][j-1][1]-sm[i][bd-1][1]+MOD)%MOD;

            int amtDn = n-i;
            int loc2 = rcks[j][1].size()-1-amtDn;
            int bd2;
            if(loc2 < 0){
                bd2 = 1;
            } else{
                bd2 = rcks[j][1][loc2];
            }
            dp[i][j][1] = (sm[i-1][j][0]-sm[bd2-1][j][0]+MOD)%MOD;

            sm[i][j][0] = (sm[i-1][j][0]+dp[i][j][0])%MOD;
            sm[i][j][1] = (sm[i][j-1][1]+dp[i][j][1])%MOD;
            //cout << i << " " << j << " " << dp[i][j][0] << " " << dp[i][j][1] << " " << sm[i][j][0] << " " << sm[i][j][1] << " " << bd << " " << bd2 << "\n";
        }
    }
    cout << (dp[n][m][0]+dp[n][m][1])%MOD << "\n";

    return 0;
}