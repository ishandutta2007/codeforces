#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
typedef vector<pair<int, int> > vpii;
typedef pair<int, int> pii;
typedef long long ll;
typedef pair<ll, ll> pll;
#define INF 1000000000000000LL
#define MOD 1000000007
#define EPSILON 0.00001
#define f first
#define s second
#define pb push_back
#define mp make_pair

#define FOR(i, a, b) for (int i=(a); i<=(b); i++)
#define F0R(i, a) for (int i=0; i<(signed)(a); i++)
#define RFOR(i, a, b) for (int i=(a); i >= b; i--)

#define MN 500005
struct Query{
    int ind;
    int node;
    int l, r;
};
bool comp(Query a, Query b){
    return a.node < b.node;
}

int n, q;

Query qs[MN];
ll ans[MN];

pii p[MN];
vpii ch[MN];

ll d[MN]; //dist to 1
ll cd[MN]; //child dist, but only child dist
int mcv[MN]; //max child val

ll tree[MN*3];
ll lazy[MN*3];

void build(int node, int a, int b){
    if(a == b){
        tree[node] = cd[a];
        return;
    }

    build(node*2, a, (a+b)/2);
    build(node*2+1, 1+(a+b)/2, b);

    tree[node] = min(tree[node*2], tree[node*2+1]);
}
void upd(int node, int a, int b, int i, int j, ll val){
    if(lazy[node] != 0){
        tree[node] += lazy[node];
        if(a != b){
            lazy[node*2] += lazy[node];
            lazy[node*2+1] += lazy[node];
        }
        lazy[node] = 0;
    }

    if(a > j || b < i || a > b || i > j) return;

    if(i <= a && b <= j){
        tree[node] += val;
        if(a != b){
            lazy[node*2] += val;
            lazy[node*2+1] += val;
        }

        return;
    }

    upd(node*2, a, (a+b)/2, i, j, val);
    upd(node*2+1, 1+(a+b)/2, b, i, j, val);

    tree[node] = min(tree[node*2], tree[node*2+1]);
}
ll que(int node, int a, int b, int i, int j){
    if(lazy[node] != 0){
        tree[node] += lazy[node];
        if(a != b){
            lazy[node*2] += lazy[node];
            lazy[node*2+1] += lazy[node];
        }
        lazy[node] = 0;
    }

    if(a > j || b < i || a > b) return INF;
    
    if(i <= a && b <= j) return tree[node];

    ll q1 = que(node*2, a, (a+b)/2, i, j);
    ll q2 = que(node*2+1, 1+(a+b)/2, b, i, j);

    return min(q1, q2);
}

void dfs1(int node){
    mcv[node] = node;
    if(ch[node].size() == 0){
        cd[node] = d[node];
        //cout << "orig dist to " << node << " is " << d[node] << "\n";
        return;
    }

    F0R(i, ch[node].size()){
        int nn = ch[node][i].f;
        d[nn] = d[node]+ch[node][i].s;
        dfs1(nn);
        mcv[node] = mcv[nn];
    }
}

int cur;
void dfs2(int node){
    while(qs[cur].node == node){
        //cout << "doing index " << qs[cur].ind << " on node " << node << "\n";
        ll resp = que(1, 1, n, qs[cur].l, qs[cur].r);
        ans[qs[cur].ind] = resp;
        cur++;
    }

    /*cout << "node " << node << "\n";
    FOR(i, 1, 9){
        cout << tree[i] << " ";
    }
    cout << "\n";
    FOR(i, 1, 9){
        cout << lazy[i] << " ";
    }
    cout << "\n";*/

    F0R(i, ch[node].size()){
        int nn = ch[node][i].f;
        int dist = ch[node][i].s;

        upd(1, 1, n, 1, n, dist);
        upd(1, 1, n, nn, mcv[nn], -dist*2);

        dfs2(nn);

        upd(1, 1, n, 1, n, -dist);
        upd(1, 1, n, nn, mcv[nn], dist*2);
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> q;

    FOR(i, 2, n){
        int cp, w;
        cin >> cp >> w;

        p[i] = mp(cp, w);
        ch[cp].pb(mp(i, w));
    }
    F0R(i, q){
        int v, l, r;
        cin >> v >> l >> r;
        qs[i].ind = i;
        qs[i].node = v;
        qs[i].l = l;
        qs[i].r = r;
    }

    memset(cd, 0x3f, sizeof cd);

    dfs1(1);
    build(1, 1, n);

    /*FOR(i, 5, 9){
        cout << tree[i] << " ";
    }
    cout << "\n";*/

    sort(qs, qs+q, comp);

    dfs2(1);

    F0R(i, q){
        cout << ans[i] << "\n";
    }

    /*FOR(i, 1, n){
        cout << "last one in subtree is " << mcv[i] << "\n";
    }*/

    return 0;
}