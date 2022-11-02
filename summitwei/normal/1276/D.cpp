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
typedef vector<vi> vvi;
#define INF 1000000000
#define MOD 998244353LL
#define EPSILON 0.00001
#define f first
#define s second
#define pb push_back
#define mp make_pair

#define FOR(i, a, b) for (int i=(a); i<=(signed)(b); i++)
#define F0R(i, a) for (int i=0; i<(signed)(a); i++)
#define RFOR(i, a, b) for (int i=(a); i >= b; i--)

#define MN 200005
int n;
vpii e[MN]; //time
int par[MN];
ll dp[MN][4];
//killed parent, parent already dead, parent killed node, dead before parent

bool comp(pii a, pii b){
    return a.s < b.s;
}

void dfs(int cn){
    sort(e[cn].begin(), e[cn].end(), comp);

    F0R(i, e[cn].size()){
        int nn = e[cn][i].f;
        if(nn == par[cn]) continue;
        par[nn] = cn;
        dfs(nn);
    }

    bool seen; ll facts, logic;

    seen = false; facts = 1; logic = 0;
    F0R(i, e[cn].size()){
        int nn = e[cn][i].f;
        if(nn == par[cn]){
            seen = true; continue;
        }
        if(seen){
            logic = (logic * dp[nn][1] + facts * dp[nn][0]) % MOD;
            facts = (facts * (dp[nn][2] + dp[nn][3])) % MOD;
        } else{
            facts = (facts * (dp[nn][2] + dp[nn][3])) % MOD;
        }
    }
    dp[cn][0] = (facts+logic)%MOD;

    seen = false; facts = 1; logic = 0;
    F0R(i, e[cn].size()){
        int nn = e[cn][i].f;
        if(nn == par[cn]){
            seen = true; continue;
        }
        logic = (logic * dp[nn][1] + facts * dp[nn][0]) % MOD;
        facts = (facts * (dp[nn][2] + dp[nn][3])) % MOD;
    }
    dp[cn][1] = (facts+logic)%MOD;

    seen = false; facts = 1; logic = 0;
    F0R(i, e[cn].size()){
        int nn = e[cn][i].f;
        if(nn == par[cn]){
            logic = facts;
            seen = true; continue;
        }
        if(seen){
            logic = (logic * dp[nn][1]) % MOD;
        } else{
            facts = (facts * (dp[nn][2] + dp[nn][3])) % MOD;
        }
    }
    dp[cn][2] = logic;

    seen = false; facts = 1; logic = 0;
    F0R(i, e[cn].size()){
        int nn = e[cn][i].f;
        if(nn == par[cn]){
            seen = true; continue;
        }
        if(seen){
            logic = (logic * dp[nn][1]) % MOD;
        } else{
            logic = (logic * dp[nn][1] + facts * dp[nn][0]) % MOD;
            facts = (facts * (dp[nn][2] + dp[nn][3])) % MOD;
        }
    }
    dp[cn][3] = logic;

    //cout << cn << " " << dp[cn][0] << " " << dp[cn][1] << " " << dp[cn][2] << " " << dp[cn][3] << "\n";
    //cout << cn << " " << alive << " " << kp << " " << pd << " " << pk << " " << db4 << "\n";
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> n;
    F0R(i, n-1){
        int u, v;
        cin >> u >> v;
        e[u].pb({v, i});
        e[v].pb({u, i});
    }

    dfs(1);

    cout << dp[1][1] << "\n";

    return 0;
}