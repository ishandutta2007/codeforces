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

#define MN 2005
int n;
int a, b;
int p[MN];
vi e[MN];
int x[MN];
int q[MN];
vi f[MN];
int y[MN];
int cst[MN][MN][2];

void dfs1(int cn, int st, int fr, int cd, int cu){
    if(cn > MN){
        int nn = cn-MN;
        cst[st][nn][0] = cd-1;
        return;
    }
    if(cn == 1){
        cst[0][st][0] = cu;
    }
    if(cn != 1 && fr != -1){
        dfs1(p[cn], st, cn, cd, cu+1);
    }
    for(auto nn : e[cn]){
        if(nn != fr){
            dfs1(nn, st, -1, cd+1, 0);
        }
    }
}
void dfs2(int cn, int st, int fr, int cd, int cu){
    if(cn > MN){
        int nn = cn-MN;
        cst[st][nn][1] = cd-1;
        return;
    }
    if(cn == 1){
        cst[0][st][1] = cu;
    }
    if(cn != 1 && fr != -1){
        dfs2(q[cn], st, cn, cd, cu+1);
    }
    for(auto nn : f[cn]){
        if(nn != fr){
            dfs2(nn, st, -1, cd+1, 0);
        }
    }
}
int dp[MN][MN];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> n;
    cin >> a;
    FOR(i, 2, a){
        cin >> p[i];
        e[p[i]].pb(i);
    }
    FOR(i, 1, n){
        cin >> x[i];
        e[x[i]].pb(i+MN);
    }
    cin >> b;
    FOR(i, 2, b){
        cin >> q[i];
        f[q[i]].pb(i);
    }
    FOR(i, 1, n){
        cin >> y[i];
        f[y[i]].pb(i+MN);
    }
    
    FOR(i, 1, n){
        dfs1(x[i], i, i+MN, 0, 0);
        dfs2(y[i], i, i+MN, 0, 0);
    }

    /*FOR(i, 1, n){
        FOR(j, 1, n){
            cout << cst[i][j][0] << " ";
        }
        cout << "\n";
        cout << cst[0][i][0] << " ";
    }*/
    memset(dp, 0x3f, sizeof dp);
    dp[1][0] = cst[0][1][0];
    dp[0][1] = cst[0][1][1];
    FOR(i, 0, n){
        FOR(j, 0, n){
            if(i == j) continue;
            if(i > j+1){
                dp[i][j] = dp[i-1][j]+cst[i-1][i][0];
            } else if(j > i+1){
                dp[i][j] = dp[i][j-1]+cst[j-1][j][1];
            } else if(i == j+1){
                FOR(k, 0, i-1){
                    dp[i][j] = min(dp[i][j], dp[k][j]+cst[k][i][0]);
                }
            } else if(j == i+1){
                FOR(k, 0, j-1){
                    dp[i][j] = min(dp[i][j], dp[i][k]+cst[k][j][1]);
                }
            }
        }
    }
    int mn = INF;
    FOR(i, 0, n-1){
        mn = min(mn, min(dp[i][n], dp[n][i]));
    }

    int tot = a-1+b-1;
    /*cout << "\n";
    FOR(i, 0, n){
        FOR(j, 0, n){
            cout << dp[i][j] << " ";
        }
        cout << "\n";
    }
    cout << mn << " " << tot << "\n";*/
    cout << tot-mn << "\n";
    
    return 0;
}