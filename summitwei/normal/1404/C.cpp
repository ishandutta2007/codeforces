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

#define MN 300005
int n, q;
int a[MN];
pii qs[MN];
vpii qv[MN];

ll tree[4*MN];
ll lazy[4*MN];
void upd(int node, int a, int b, int i, int j, ll val){
    if(lazy[node] != 0){
        tree[node] += lazy[node];
        if(a != b){
            lazy[node*2] += lazy[node];
            lazy[node*2+1] += lazy[node];
        }
        lazy[node] = 0;
    }
    if(a > j || b < i) return;
    if(i <= a && b <= j){
        tree[node] += val;
        if(a != b){
            lazy[node*2] += val;
            lazy[node*2+1] += val;
        }
        return;
    }
    int mid = (a+b)/2;
    upd(node*2, a, mid, i, j, val);
    upd(node*2+1, mid+1, b, i, j, val);
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
    if(a > j || b < i) return INF;
    if(i <= a && b <= j) return tree[node];
    int mid = (a+b)/2;
    ll q1 = que(node*2, a, mid, i, j);
    ll q2 = que(node*2+1, 1+mid, b, i, j);
    return min(q1, q2);
}
int fdmn(int node, int a, int b){
    if(lazy[node] != 0){
        tree[node] += lazy[node];
        if(a != b){
            lazy[node*2] += lazy[node];
            lazy[node*2+1] += lazy[node];
        }
        lazy[node] = 0;
    }
    if(a==b) return a;
    int mid = (a+b)/2;
    if(tree[node] == tree[node*2+1]+lazy[node*2+1]) return fdmn(node*2+1, mid+1, b);
    else return fdmn(node*2, a, mid);
}

int fen[MN*2];
void fupd(int x, int v){
    while(x<=n){
        fen[x] += v;
        x += (x&-x);
    }
}
int fque(int x){
    int sm=0;
    while(x>0){
        sm += fen[x];
        x -= (x&-x);
    }
    return sm;
}
int anss[MN];

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> q;
    FOR(i, 1, n){
        cin >> a[i];
    }
    FOR(i, 1, q){
        cin >> qs[i].f >> qs[i].s;
        qv[qs[i].f].pb({qs[i].s, i});
    }
    //memset(tree, 0x3f, sizeof tree);
    upd(1, 1, n, 1, n, INF);
    RFOR(i, n, 1){
        //if this guy can be deleted immediately, do it, and look for ppl who are 0s
        //can be done w/ range max & dec
        //cout << "proc " << i << "\n";
        if(a[i] == i){
            //cout << i << " deletable instantly\n";
            fupd(i, 1);
            upd(1, 1, n, i+1, n, -1);
            while(tree[1]+lazy[1] == 0){
                int x = fdmn(1, 1, n);
                //cout << "can delete " << x << "\n";
                fupd(x, 1);
                upd(1, 1, n, x, x, INF);
                upd(1, 1, n, x+1, n, -1);
            }
        } else{
            if(a[i] > i){
                a[i] = -INF;
            }
            upd(1, 1, n, i, i, (i-a[i])-INF);
            //cout << i << " " << a[i] << " starts at value of " << que(1, 1, n, i, i) << "\n";
        }
        //FOR(i, 1, n) cout << fen[i] << " ";
        //cout << "\n";
        for(auto u : qv[i-1]){
            int lst = n-u.f;
            int ans = fque(lst);
            anss[u.s] = ans;
        }
    }
    FOR(i, 1, q){
        cout << anss[i] << "\n";
    }

    return 0;
}