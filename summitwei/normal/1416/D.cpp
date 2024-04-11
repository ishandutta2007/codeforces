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
typedef pair<double, double> pdd;
typedef vector<ll> vll;
#define INF 0x3f3f3f3f
#define MOD 1000000007LL
#define EPS 0.00001
#define f first
#define s second
#define pb push_back
#define mp make_pair

#define FOR(i, a, b) for (int i=(a); i<=(signed)(b); i++)
#define F0R(i, a) for (int i=0; i<(signed)(a); i++)
#define RFOR(i, a, b) for (int i=(a); i >= b; i--)

#define MN 500005 //check limits you incompetent ree
int n, m, q;
int v[MN];
int inv[MN];
bool used[MN];
pii e[MN];
bool ded[MN];

pii qs[MN];

stack<pii> ree;
set<int> in[MN];
set<int> vals[MN];
int dsu[MN];
int sz[MN];
int fd(int x){
    if(dsu[x] == x) return x;
    return fd(dsu[x]);
}
bool jn(int x, int y){
    x = fd(x), y = fd(y);
    if(x == y){ ree.push({-1, -1}); return false; }
    if(sz[x] < sz[y]) swap(x, y);
    ree.push({x, y});
    dsu[y] = x;
    sz[x] += sz[y];
    for(auto u : in[y]) in[x].insert(u);
    for(auto u : vals[y]) vals[x].insert(u);
    return true;
}
void und(int x, int y){ //x took y
    dsu[y] = y;
    sz[x] -= sz[y];
    for(auto u : in[y]){
        if(used[u]){
            vals[y].erase(v[u]);
        } else{
            vals[x].erase(v[u]);
        }
        in[x].erase(u);
    }
}


int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m >> q;
    FOR(i, 1, n){
        cin >> v[i];
        inv[v[i]] = i;
    }
    FOR(i, 1, m){
        cin >> e[i].f >> e[i].s;
    }
    FOR(i, 1, q){
        cin >> qs[i].f >> qs[i].s;
        if(qs[i].f == 2){
            ded[qs[i].s] = true;
        }
    }
    FOR(i, 1, n){
        dsu[i] = i;
        sz[i] = 1;
        in[i].insert(i);
        vals[i].insert(v[i]);
    }
    FOR(i, 1, m){
        if(!ded[i]){
            jn(e[i].f, e[i].s);
            //cout << "merging " << e[i].f << " " << e[i].s << "\n";
        }
    }
    RFOR(i, q, 1){
        if(qs[i].f == 2){
            jn(e[qs[i].s].f, e[qs[i].s].s);
        }
    }
    FOR(i, 1, q){
        if(qs[i].f == 1){
            int x = fd(qs[i].s);
            if(vals[x].empty()){
                cout << "0\n";
            } else{
                int val = *vals[x].rbegin();
                int loc = inv[val];
                used[loc] = true;
                vals[x].erase(val);
                //cout << "from " << loc << ", ";
                cout << val << "\n";
            }
        } else{
            pii tp = ree.top(); ree.pop();
            //cout << "undoing " << tp.f << " " << tp.s << "\n";
            if(tp.f == -1) continue;
            und(tp.f, tp.s);
        }
    }

    return 0;
}