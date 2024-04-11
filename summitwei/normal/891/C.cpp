#pragma GCC optimize ("O3")
#pragma GCC target ("sse4")

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

#define MN 500005
int n, m;
pair<pii, pii> ed[MN];
bool comp1(pair<pii, pii> a, pair<pii, pii> b){
    if(a.s.f != b.s.f) return a.s.f < b.s.f;
    return a.s.s < b.s.s;
}
bool comp2(pair<pii, pii> a, pair<pii, pii> b){
    return a.s.s < b.s.s;
}

int q;
vi qs[MN];

stack<pii> ree;

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
    return true;
}
void und(int x, int y){ //x took y
    dsu[y] = y;
    sz[x] -= sz[y];
}

bool rip[MN];
map<int, vi> bruh[MN];
vpii eds[MN];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> m;
    FOR(i, 1, m){
        cin >> ed[i].f.f >> ed[i].f.s >> ed[i].s.f;
        ed[i].s.s = i;
        eds[ed[i].s.f].pb({ed[i].f.f, ed[i].f.s});
    }

    FOR(i, 1, n){
        dsu[i] = i;
        sz[i] = i;
    }

    FOR(i, 1, n){ dsu[i] = i; sz[i] = 1; }

    cin >> q;
    F0R(i, q){
        int k;
        cin >> k;
        FOR(j, 1, k){
            int x;
            cin >> x;
            bruh[ed[x].s.f][i].pb(x);
        }
    }

    FOR(w, 1, 5e5){
        for(auto qt : bruh[w]){
            for(auto u : qt.s){
                if(!jn(ed[u].f.f, ed[u].f.s)) rip[qt.f] = true;
            }
            F0R(_, qt.s.size()){
                pii tp = ree.top(); ree.pop();
                if(tp.f == -1) continue;
                und(tp.f, tp.s);
            }
        }
        for(auto u : eds[w]){
            jn(u.f, u.s);
        }
    }
    F0R(i, q){
        if(rip[i]) cout << "NO\n";
        else cout << "YES\n";
    }
    
    return 0;
}