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
int n;
vi e[MN];

ll dp[MN][2][2]; //first = whether used (on/off), second = whether alone (no/yes)
void dfs(int cn, int p){
    ll nou = 1, use = 1; //w/o restrictions; subtract at end
    //ll noal = 1, ual = 1;
    ll al = 1;
    for(auto nn : e[cn]) if(nn != p){
        dfs(nn, cn);
        //use top and split
        /*use = use*(dp[nn][0][0]+dp[nn][1][0]);
        ual = ual*(dp[nn][0][0]+dp[nn][1][0]);
        use %= MOD; ual %= MOD;*/
        ll spl = (dp[nn][0][0]+dp[nn][1][0]+dp[nn][1][1])%MOD;

        //don't use top, split
        /*nou = nou*(dp[nn][0][0]+dp[nn][1][0]);
        noal = noal*(dp[nn][0][0]+dp[nn][1][0]);
        nou %= MOD; noal %= MOD;*/

        //use top, don't split
        /*use = use*(dp[nn][1][0]+dp[nn][1][1]);
        use %= MOD;*/
        ll uno = (dp[nn][1][0]+dp[nn][1][1])%MOD;

        //don't use top, don't split
        /*nou = nou*(dp[nn][0][0]+dp[nn][0][1]+dp[nn][1][0]+dp[nn][1][1]);
        nou %= MOD;*/
        ll nouno = (dp[nn][0][0]+dp[nn][0][1]+dp[nn][1][0]+dp[nn][1][1])%MOD;

        use = (use*(spl+uno))%MOD;
        nou = (nou*(spl+nouno))%MOD;
        al = (al*spl)%MOD;
    }
    dp[cn][0][0] = (use-al+MOD)%MOD;
    dp[cn][1][0] = (nou-al+MOD)%MOD;
    dp[cn][0][1] = al;
    dp[cn][1][1] = al;
    //cout << cn << " " << dp[cn][0][0] << " " << dp[cn][1][0] << " " << dp[cn][0][1] << " " << dp[cn][1][1] << "\n";
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> n;
    F0R(_, n-1){
        int u, v;
        cin >> u >> v;
        e[u].pb(v);
        e[v].pb(u);
    }
    dfs(1, 0);
    cout << (dp[1][0][0]+dp[1][1][0]+dp[1][1][1]+MOD-1)%MOD << "\n";
    
    return 0;
}