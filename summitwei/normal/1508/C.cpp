#pragma GCC optimize ("O3")
#pragma GCC target ("sse4")

#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
typedef vector<vector<int> > vvi;
typedef vector<pair<int, int> > vpii;
typedef pair<int, int> pii;
typedef long long ll;
typedef long double ld;
typedef pair<ll, ll> pll;
typedef vector<pll> vpll;
typedef pair<double, double> pdd;
typedef vector<ll> vll;
#define INF 0x3f3f3f3f
#define INFLL 10000000000000LL
#define MOD 1000000007LL
#define EPS 0.000000000001
#define f first
#define s second
#define pb push_back
#define mp make_pair

#define FOR(i, a, b) for (int i=(a); i<=(signed)(b); i++)
#define F0R(i, a) for (int i=0; i<(signed)(a); i++)
#define RFOR(i, a, b) for (int i=(a); i >= b; i--)

#define MN 200005 //check limits you incompetent ree
int n, m;
vpll e[MN];
set<int> alive;
pll d[MN]; //weight, node
bool vis[MN];
ll xv;
int dep[MN];
pair<ll, pll> ed[MN];

int gd(int cn){
    if(dep[cn] != -1) return dep[cn];
    if(cn == 1) return dep[cn] = 0;
    return dep[cn] = gd(d[cn].s)+1;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;
    F0R(i, m){
        int u,v; ll w;
        cin >> u >> v >> w;
        e[u].pb({v,w});
        e[v].pb({u,w});
        xv ^= w;
        ed[i] = {w,{u,v}};
    }
    FOR(i, 1, n) sort(e[i].begin(), e[i].end());
    FOR(i,2,n){ alive.insert(i); d[i].f = INFLL; }
    priority_queue<pll> hmm;
    hmm.push({0,1});
    int zcnt = 0;
    ll tweight = 0;
    while(!hmm.empty()){
        pll top = hmm.top(); hmm.pop();
        int cn = top.s; ll cw = top.f;
        if(vis[cn]) continue;
        vis[cn] = true;
        if(alive.count(cn)) alive.erase(cn);
        tweight += d[cn].f;
        int x = 0;
        for(set<int>::iterator u = alive.begin(); u != alive.end();){
            //cout << "at " << *u << "\n";
            while(x != e[cn].size() && e[cn][x].f < *u) ++x;
            if(x != e[cn].size() && e[cn][x].f == *u){
                if(e[cn][x].s < d[*u].f){
                    hmm.push({-e[cn][x].s, *u});
                    d[*u] = {e[cn][x].s, cn};
                }
                ++u;
            } else{
                hmm.push({0, *u});
                d[*u] = {0, cn};
                ++zcnt;
                u = alive.erase(u);
            }
        }
    }
    //cout << tweight << " " << zcnt << "\n";
    if(1LL*m + zcnt != 1LL*n*(n-1)/2){ //unused 0-edge
        cout << tweight << "\n";

        return 0;
    }
    memset(dep, -1, sizeof dep);
    FOR(i, 1, n) gd(i);
    //n bounded by 700 now
    sort(ed, ed+m);
    ll extra = INFLL;
    bool fd = false;
    F0R(i, m){
        int u = ed[i].s.f, v = ed[i].s.s;
        //cout << "x " << u << " " << v << "\n";
        if(dep[u] < dep[v]) swap(u,v);
        if(d[u].s == v) continue;
        while(dep[u] > dep[v]){
            if(d[u].f == 0){ fd = true; extra = ed[i].f; break; }
            u = d[u].s;
        }
        if(fd) break;
        while(u != v){
            if(d[u].f == 0 || d[v].f == 0){ fd = true; extra = ed[i].f; break; }
            u = d[u].s; v = d[v].s;
        }
        if(fd) break;
    }
    extra = min(extra, xv);
    cout << tweight + extra << "\n";

    return 0;
}