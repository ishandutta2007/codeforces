#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
typedef vector<vector<int> > vvi;
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
int n, m;
pii a[MN];
vi e[MN];
vi re[MN];
int vis[MN];
bool dfs(int cn){
    if(vis[cn] == 2) return false;
    if(vis[cn] == 1) return true;
    vis[cn] = 1;
    for(auto nn : e[cn]) if(dfs(nn)) return true;
    vis[cn] = 2;
    return false;
}
void dfsf(int cn){
    if(vis[cn]&1) return;
    vis[cn] |= 1;
    for(auto nn : e[cn]) dfsf(nn);
}
void dfsb(int cn){
    if(vis[cn]&2) return;
    vis[cn] |= 2;
    for(auto nn : re[cn]) dfsb(nn);
}
int ok[MN];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> m;
    F0R(i, m){
        cin >> a[i].f >> a[i].s;
        e[a[i].f].pb(a[i].s);
        re[a[i].s].pb(a[i].f);
    }
    F0R(i, n){
        if(dfs(i)){
            cout << "-1\n";
            return 0;
        }
    }
    memset(vis, 0, sizeof vis);
    int cnt = 0;
    FOR(cn, 1, n){
        if(vis[cn] == 0){
            ++cnt;
            ok[cn] = true;
        }
        dfsf(cn);
        dfsb(cn);
    }
    cout << cnt << "\n";
    FOR(i, 1, n) cout << (ok[i]?'A':'E');
    cout << "\n";
    
    return 0;
}