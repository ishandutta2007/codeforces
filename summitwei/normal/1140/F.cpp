#pragma GCC optimize ("O3")
#pragma GCC target ("sse4")

#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
typedef vector<pair<int, int> > vpii;
typedef pair<int, int> pii;
typedef long long ll;
typedef pair<ll, ll> pll;
typedef pair<double, double> pdd;
#define INF 1000000000
#define MOD 998244353
#define EPSILON 0.00001
#define f first
#define s second
#define pb push_back
#define mp make_pair

#define FOR(i, a, b) for (int i=(a); i<=(signed)(b); i++)
#define F0R(i, a) for (int i=0; i<(signed)(a); i++)
#define RFOR(i, a, b) for (int i=(a); i >= b; i--)

#define MN 300005
#define MXX 300000
int q;
int dsu[2*MN];
pll sz[2*MN]; //sz of x-co, sz of y-co
ll ans;

int tim; //store time for td.s

stack<pii> ps[2*MN]; //previous sizes
stack<pair<pii, int> > td; //to delete

vpii tree[4*MN]; //stores all updates needed

ll finans[MN];

map<pii, int> pastim; //for beginning half of problem

int find(int x){
    if(dsu[x] == x) return x;
    return find(dsu[x]);
}
void mer(int x, int y, int ct){
    x = find(x);
    y = find(y);
    if(x == y) return;

    if(sz[x].f+sz[x].s < sz[y].f+sz[y].s) swap(x, y);
    ps[x].push(sz[x]);
    ps[y].push(sz[y]);
    ans -= (sz[x].f*sz[x].s);
    ans -= (sz[y].f*sz[y].s);

    dsu[y] = x;
    sz[x].f += sz[y].f;
    sz[x].s += sz[y].s;
    ans += (sz[x].f*sz[x].s);
    td.push(mp(mp(x, y), ct)); //pop td during bs
}
void del(int x, int y){
    dsu[y] = y;
    ans -= (sz[x].f*sz[x].s);
    
    if(ps[x].empty() || ps[y].empty()){
        cout << "REE\n";
    }
    pii top = ps[x].top();
    ps[x].pop();
    sz[x] = top;
    ans += (sz[x].f*sz[x].s);

    top = ps[y].top();
    ps[y].pop();
    sz[y] = top;
    ans += (sz[y].f*sz[y].s);
}

void add(int node, int l, int r, int i, int j, pii val){
    if(l > j || r < i || l > r || j < i) return;

    if(i <= l && r <= j){
        tree[node].pb(val);
        return;
    }

    add(node*2, l, (l+r)/2, i, j, val);
    add(node*2+1, 1+(l+r)/2, r, i, j, val);
}
void check(int node, int l, int r){
    if(l > r) return;
    //cout << "on " << node << " " << l << " " << r << "\n";
    tim++;
    int ct = tim;

    F0R(i, tree[node].size()){
        pii cur = tree[node][i];
        mer(cur.f, cur.s, ct);
    }

    if(l == r){
        finans[l] = ans;
        //cout << "ans at " << l << " is " << ans << "\n";
    } else{
        check(node*2, l, (l+r)/2);
        check(node*2+1, (l+r)/2+1, r);
    }

    while(!td.empty() && td.top().s == ct){
        pair<pii, int> top = td.top();
        td.pop();

        del(top.f.f, top.f.s);
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    FOR(i, 1, MXX){
        dsu[i] = i;
        sz[i] = mp(1, 0);
    }
    FOR(i, MXX+1, 2*MXX){
        dsu[i] = i;
        sz[i] = mp(0, 1);
    }

    cin >> q;
    FOR(i, 1, q){
        pii cur;
        //int x, y;
        //cin >> x >> y;
        cin >> cur.f >> cur.s;
        cur.s += MXX;
    
        if(pastim.count(cur) == 0 || pastim[cur] == 0){
            pastim[cur] = i;
            //cout << "adding " << cur.f << " " << cur.s << " " << i << "\n";
        } else{
            int lt = pastim[cur];
            //cout << "adding " << lt << " " << i << " " << cur.f << " " << cur.s-MXX << "\n";
            add(1, 1, q+1, lt, i-1, cur);
            pastim[cur] = 0;
        }
    }
    for(auto u : pastim){
        if(u.s != 0){
            int lt = u.s;
            pii cur = u.f;
            //cout << "adding " << lt << " " << q+1 << " " << cur.f << " " << cur.s-MXX << "\n";
            add(1, 1, q+1, lt, q+1, cur);
        }
    }

    //cout << "am i alive?\n";

    check(1, 1, q+1);

    FOR(i, 1, q){
        cout << finans[i] << " ";
    }
    
    return 0;
}