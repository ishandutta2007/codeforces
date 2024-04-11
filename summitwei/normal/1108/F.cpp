#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
typedef vector<pair<int, int> > vpii;
typedef pair<int, int> pii;
typedef long long ll;
typedef pair<ll, ll> pll;
#define INF 1000000000
#define MOD 1000000007
#define EPSILON 0.00001
#define f first
#define s second
#define pb push_back
#define mp make_pair

#define FOR(i, a, b) for (int i=(a); i<=(b); i++)
#define F0R(i, a) for (int i=0; i<(signed)(a); i++)
#define RFOR(i, a, b) for (int i=(a); i >= b; i--)

#define MN 200005
int n, m;

struct Edge{
    int u, v;
    int w;
};

Edge e[MN];
vpii es[MN];
int compress(){
    map<int, int> cm;
    F0R(i, m){
        cm[e[i].w] = 0;
    }
    int co = 0;
    for(auto& u : cm){
        u.s = ++co;
    }
    F0R(i, m){
        e[i].w = cm[e[i].w];
        es[e[i].w].pb(mp(e[i].u, e[i].v));
    }
    return co;
}

int dsu[MN];
int sz[MN];
int find(int x){
    if(x == dsu[x]) return x;
    dsu[x] = find(dsu[x]);
    return dsu[x];
}
bool same(int x, int y){
    return find(x)==find(y);
}
bool unite(int x, int y){
    x = find(x);
    y = find(y);
    if(x == y) return false;

    if(sz[x] < sz[y]) swap(x, y);

    dsu[y] = x;
    sz[x] += sz[y];
    return true;
}

int main(){
    //ios_base::sync_with_stdio(false);
    //cin.tie(NULL);

    cin >> n >> m;
    iota(dsu, dsu+n+1, 0);
    F0R(i, m){
        cin >> e[i].u >> e[i].v >> e[i].w;
    }
    int amt = compress();

    //cout << amt << "\n";

    int cnt = 0;
    FOR(i, 1, amt){
        //cout << "on " << i << "\n";
        F0R(j, es[i].size()){
            int u = es[i][j].f, v = es[i][j].s;
            if(!same(u, v)){
                //cout << u << " " << v << " diff\n";
                cnt++;
            }
        }
        F0R(j, es[i].size()){
            int u = es[i][j].f, v = es[i][j].s;
            if(unite(u, v)){
                //cout << u << " " << v << " united\n";
                cnt--;
            }
        }
    }

    cout << cnt << "\n";
    return 0;
}