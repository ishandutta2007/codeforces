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

#define MN 200005
int t;
int n;
int p[MN];
int c[MN];

bool vis[MN];
vi cur;
int chk(int x){ //# of exps
    int m = cur.size();
    vector<bool> ok(x, true);
    F0R(i, m-x){
        if(c[cur[i]] != c[cur[i+x]]){
            ok[i%x] = false;
        }
    }
    F0R(i, x){
        if(ok[i]) return x;
    }
    return INF;
}
int dfs(int cn, int st){
    if(vis[cn] && cn == st){
        /*cout << "doing ";
        for(auto u : cur) cout << u << " ";
        cout << "\n";*/
        int ans = INF;
        int m = cur.size();
        for(int i=1; i*i<=m; ++i){
            if(m % i != 0) continue;
            ans = min(ans, chk(i));
            ans = min(ans, chk(m/i));
        }
        cur.clear();
        return ans;
    }
    vis[cn] = true;
    cur.pb(cn);
    return dfs(p[cn], st);
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> t;
    F0R(_, t){
        cin >> n;
        FOR(i, 1, n) cin >> p[i];
        FOR(i, 1, n) cin >> c[i];
        int ans = INF;
        FOR(i, 1, n) if(!vis[i]) ans = min(ans, dfs(i, i));
        cout << ans << "\n";

        FOR(i, 1, n) vis[i] = false;
    }

    return 0;
}