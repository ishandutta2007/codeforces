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
#define ML 18
int n;
pii p[MN];
vi ch[MN];
pii dp[MN][ML];
int d[MN];

void dfs(int cn){
    for(auto nn : ch[cn]){
        d[nn] = d[cn]+1;
        dfs(nn);
    }
}

void prepro(){
    FOR(i, 1, n){
        dp[i][0] = p[i];
        //cout << i << " " << dp[i][0].f << " " << dp[i][0].s << "\n";
    }
    FOR(i, 1, ML-1){
        FOR(j, 1, n){
            dp[j][i].f = dp[dp[j][i-1].f][i-1].f;
            dp[j][i].s = dp[j][i-1].s | dp[dp[j][i-1].f][i-1].s;
        }
    }
}

pair<int, pii> lca(int a, int b){ //lca, bitmask
    /*cout << "doing " << a << " " << b << "\n";
    cout << "w/ depths " << d[a] << " " << d[b] << "\n";*/
    bool swp = false;
    if(d[b] < d[a]){
        swap(a, b);
        swp = true;
    }
    int bm1 = 0, bm2 = 0;
    int dif = d[b]-d[a];
    RFOR(i, ML-1, 0){
        if(dif >= (1<<i)){
            dif -= (1<<i);
            bm2 |= dp[b][i].s;
            b = dp[b][i].f;
            //cout << "jumped " << i << " now at " << b << " with bm2 " << bm2 << "\n";
        }
    }
    if(a == b){
        if(swp) return {a, {bm2, 0}};
        else return {a, {0, bm2}};
    }
    
    //cout << "p2 with " << a << " " << b << "\n";
    RFOR(i, ML-1, 0){
        if(dp[a][i].f != dp[b][i].f){
            bm1 |= dp[a][i].s; bm2 |= dp[b][i].s;
            a=dp[a][i].f; b=dp[b][i].f;
        }
    }
    bm1 |= p[a].s; bm2 |= p[b].s;
    a = p[a].f; b = p[b].f;
    if(a != b || a == 0) return {-1, {3, 3}};
    //cout << "now w/ " << a << " " << b << "\n";
    if(swp) return {a, {bm2, bm1}};
    else return {a, {bm1, bm2}};
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    cin >> n;
    FOR(i, 1, n){
        cin >> p[i].f >> p[i].s;
        ++p[i].s;
        if(p[i].f == -1) p[i].f = 0;
        ch[p[i].f].pb(i);
    }
    
    FOR(i, 1, n){
        if(p[i].f == 0){
            d[i] = 0;
            dfs(i);
        }
    }
    prepro();
    
    int q;
    cin >> q;
    F0R(_, q){
        int t, u, v;
        cin >> t >> u >> v;
        pair<int, pii> res = lca(u, v);
        //cout << res.f << " " << res.s.f << " " << res.s.s << "\n";
        if(t == 1){
            if(u != v && res.f == u && res.s.s == 1){
                cout << "YES\n";
            } else{
                cout << "NO\n";
            }
        } else{
            if(res.f != v && !(res.s.f&2) && !(res.s.s&1)){
                cout << "YES\n";
            } else{
                cout << "NO\n";
            }
        }
    }

    return 0;
}