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
#define MOD 1000000007LL
#define EPSILON 0.00001
#define f first
#define s second
#define pb push_back
#define mp make_pair

#define FOR(i, a, b) for (int i=(a); i<=(signed)(b); i++)
#define F0R(i, a) for (int i=0; i<(signed)(a); i++)
#define RFOR(i, a, b) for (int i=(a); i >= b; i--)

#define MN 55
int n;
vi e[MN];
double dp[MN][MN];
int sz[MN];
double tmp[MN]; //including parent edge
double tmp2[MN];
double ch[MN][MN];

void dfs(int cn, int p){
    sz[cn] = 1;
    dp[cn][0] = 1.0;
    for(auto nn : e[cn]) if(nn != p){
        dfs(nn, cn);
        //sz[cn] += sz[nn];
        memset(tmp, 0, sizeof tmp);
        F0R(i, sz[nn]+1){ //number yeeted
            F0R(j, sz[nn]){ //location of cut
                if(j >= i){
                    tmp[i] += dp[nn][j] / (sz[nn]*2);
                } else{
                    tmp[i] += dp[nn][i-1] / sz[nn];
                }
            }
        }
        /*cout << "calc up of " << nn << "\n";
        F0R(i, sz[nn]+1){
            cout << tmp[i] << " ";
        }
        cout << "\n";

        cout << sz[cn]-1 << " " << sz[nn] << "\n";*/

        memset(tmp2, 0, sizeof tmp);
        int nw = sz[cn]+sz[nn];
        F0R(i, sz[cn]){
            F0R(j, sz[nn]+1){
                //cout << i << " " << j << " " << nw-1 << " " << i+j << "\n";
                double ree = (ch[sz[cn]-1][i])*(ch[sz[nn]][j])/(ch[nw-1][i+j]);
                //cout << dp[cn][i] << " " << tmp[j] << " " << ree << "\n";
                tmp2[i+j] += dp[cn][i]*tmp[j]*ree;
            }
        }
        memcpy(dp[cn], tmp2, sizeof tmp2);
        sz[cn] += sz[nn];
        /*cout << "after merging:\n";
        F0R(i, sz[cn]) cout << dp[cn][i] << " ";
        cout << "\n";*/
    }
    /*cout << "for " << cn << ":\n";
    F0R(i, sz[cn]){
        cout << dp[cn][i] << " ";
    }
    cout << "\n";*/
}

int main(){
    //ios_base::sync_with_stdio(false);
    //cin.tie(0);

    cin >> n;

    ch[0][0] = 1;
    FOR(i, 1, n){
        ch[i][0] = 1;
        FOR(j, 1, i){
            ch[i][j] = ch[i-1][j]+ch[i-1][j-1];
        }
    }

    F0R(_, n-1){
        int u, v;
        cin >> u >> v;
        e[u].pb(v);
        e[v].pb(u);
    }
    FOR(i, 1, n){
        memset(dp, 0, sizeof dp);
        dfs(i, 0);
        cout << fixed << setprecision(9) << dp[i][0] << "\n";
    }
    
    return 0;
}