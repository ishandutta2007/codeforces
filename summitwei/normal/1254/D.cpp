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
typedef vector<pll> vpll;
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

#define MN 150005
#define BAD 149332
int n, q;
bool ree;

int par[MN];
vi e[MN];
int sz[MN];

pii prof[MN];

bool comp(int a, int b){
    return sz[a] < sz[b];
}

void dfs(int node){
    //cout << "in " << node << "\n";
    sz[node] = 1;
    F0R(i, e[node].size()){
        int newNode = e[node][i];
        if(newNode == par[node]) continue;

        par[newNode] = node;
        dfs(newNode);
        sz[node] += sz[newNode];
    }

    sort(e[node].begin(), e[node].end(), comp);
}

unordered_map<int, pii> bounds[MN];
int curr;
int dfsOrder[MN];
int segStart[MN];
int segLoc[MN];
void dfs2(int node){
    //cout << "in " << node << "\n";
    segStart[node] = INF;
    F0R(i, e[node].size()){
        int newNode = e[node][i];
        if(newNode == par[node]) continue;

        dfs2(newNode);
        segStart[node] = min(segStart[node], segStart[newNode]);
        
        if(!bounds[node].count(sz[newNode])){
            bounds[node][sz[newNode]] = {segStart[newNode], segLoc[newNode]};
        } else{
            bounds[node][sz[newNode]].s = segLoc[newNode];
        }
    }

    dfsOrder[curr] = node;
    segLoc[node] = curr;
    segStart[node] = min(segStart[node], curr);

    curr++;
}

ll bit[MN*2];
void upd(int k, ll val){
    while(k <= n){
        bit[k] = (bit[k]+val)%MOD;
        bit[k] = (bit[k]+MOD)%MOD;
        k += (k&-k);
    }
}
ll que(int k){
    ll sm = 0;
    while(k >= 1){
        sm = (sm+bit[k])%MOD;
        k -= (k&-k);
    }
    return sm;
}

/*ll tree[MN*4];
ll lazy[MN*4];
void update(int node, int a, int b, int i, int j, ll val){
    if(lazy[node] != 0){
        if(a == b){
            tree[node] = (tree[node]+lazy[node])%MOD;
        } else{
            lazy[node*2] = (lazy[node*2]+lazy[node])%MOD;
            lazy[node*2+1] = (lazy[node*2+1]+lazy[node])%MOD;
        }
        lazy[node] = 0;
    }
    if(a > b || a > j || b < i) return;
    if(i <= a && b <= j){
        if(a == b){
            tree[node] = (tree[node]+val)%MOD;
        } else{
            lazy[node*2] = (lazy[node*2]+val)%MOD;
            lazy[node*2+1] = (lazy[node*2+1]+val)%MOD;
        }
        return;
    }

    update(node*2, a, (a+b)/2, i, j, val);
    update(node*2+1, 1+(a+b)/2, b, i, j, val);
}
ll query(int node, int a, int b, int i, int j){
    if(lazy[node] != 0){
        if(a == b){
            tree[node] = (tree[node]+lazy[node])%MOD;
        } else{
            lazy[node*2] = (lazy[node*2]+lazy[node])%MOD;
            lazy[node*2+1] = (lazy[node*2+1]+lazy[node])%MOD;
        }
        lazy[node] = 0;
    }
    if(a > b || a > j || b < i) return 0;

    if(a >= i && b <= j) return tree[node];

    ll q1 = query(node*2, a, (a+b)/2, i, j);
    ll q2 = query(node*2+1, 1+(a+b)/2, b, i, j);

    return q1 + q2;
}*/

pll gcd(ll a, ll b){ //a*first+b*second=gcd
    if(a == 0){
        return mp(0, 1);
    }

    pll prev = gcd(b%a, a);

    return mp(prev.s-(b/a)*prev.f, prev.f);
} //using ll's just to be safe wrt overflow issues

ll modInv(ll x){ //return x^-1 % MOD
    pll res = gcd(x, MOD);

    res.f = (res.f+MOD)%MOD;

    //cout << "modinv of " << x << " is " << res.f << "\n";

    return res.f;
}

ll modDiv(ll x, ll y){
    return (x*modInv(y))%MOD;
}

map<int, ll> chs;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> q;
    //if(n == BAD) ree = true;
    F0R(_, n-1){
        int u, v;
        cin >> u >> v;
        e[u].pb(v);
        e[v].pb(u);
    }

    curr = 1;
    dfs(1);
    dfs2(1);

    ll ninv = modInv(n);

    /*FOR(i, 1, n){
        cout << dfsOrder[i] << " ";
    }
    cout << "\n";*/

    if(ree){
        int mx = 0;
        FOR(i, 1, n){
            mx = max(mx, (int)bounds[i].size());
        }
        cout << mx << "\n";
        return 0;
    }
    F0R(_, q){
        int c;
        cin >> c;
        if(c == 1){
            int v; ll d;
            cin >> v >> d;
            chs[v] += d;
            chs[v] %= MOD;
        } else{
            int cv;
            cin >> cv;
            for(auto u : chs){
                int v = u.f; ll d = u.s;
                ll tot = sz[v];
                for(auto u : bounds[v]){
                    ll csz = u.f;
                    int l = u.s.f, r = u.s.s;
                    ll ch = ((d*(n-csz)%MOD)*ninv)%MOD;
                    //cout << l << " " << r << " " << ch << "\n";
                    //update(1, 1, n, l, r, ch);
                    upd(l, ch);
                    upd(r+1, -ch);
                }
                ll och = ((d*(tot)%MOD)*ninv)%MOD;
                //cout << "1 " << n << " " << och << "\n";
                //update(1, 1, n, 1, n, och);
                upd(1, och);
                //cout << segStart[v] << " " << segLoc[v] << " " << MOD-och << "\n";
                //update(1, 1, n, segStart[v], segLoc[v], MOD-och);
                upd(segStart[v], MOD-och);
                upd(segLoc[v]+1, och);
                //cout << segLoc[v] << " " << segLoc[v] << " " << d << "\n";
                //update(1, 1, n, segLoc[v], segLoc[v], d);
                upd(segLoc[v], d);
                upd(segLoc[v]+1, -d);
            }
            cout << que(segLoc[cv]) << "\n";
            chs.clear();
        }
        
        /*if(c == 1){
            int v; ll d;
            cin >> v >> d;
            ll tot = sz[v];
            for(auto u : bounds[v]){
                ll csz = u.f;
                int l = u.s.f, r = u.s.s;
                ll ch = ((d*(n-csz)%MOD)*ninv)%MOD;
                //cout << l << " " << r << " " << ch << "\n";
                //update(1, 1, n, l, r, ch);
                upd(l, ch);
                upd(r+1, -ch);
            }
            ll och = ((d*(tot)%MOD)*ninv)%MOD;
            //cout << "1 " << n << " " << och << "\n";
            //update(1, 1, n, 1, n, och);
            upd(1, och);
            //cout << segStart[v] << " " << segLoc[v] << " " << MOD-och << "\n";
            //update(1, 1, n, segStart[v], segLoc[v], MOD-och);
            upd(segStart[v], MOD-och);
            upd(segLoc[v]+1, och);
            //cout << segLoc[v] << " " << segLoc[v] << " " << d << "\n";
            //update(1, 1, n, segLoc[v], segLoc[v], d);
            upd(segLoc[v], d);
            upd(segLoc[v]+1, -d);
        } else{
            int v;
            cin >> v;
            //cout << query(1, 1, n, segLoc[v], segLoc[v]) << "\n";
            cout << que(segLoc[v]) << "\n";
        }*/
    }

    return 0;
}