#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
typedef vector<pair<int, int> > vpii;
typedef pair<int, int> pii;
typedef long long ll;
typedef pair<ll, ll> pll;
typedef pair<double, double> pdd;
typedef vector<ll> vll;
#define INF 1000000000000LL
#define MOD 1000000007LL
#define EPSILON 0.00001
#define f first
#define s second
#define pb push_back
#define mp make_pair
 
#define FOR(i, a, b) for (ll i=(a); i<=(signed)(b); i++)
#define F0R(i, a) for (ll i=0; i<(signed)(a); i++)
#define RFOR(i, a, b) for (int i=(a); i >= b; i--)
 
#define MN 200005
#define MM 1000000
int n, m, p;
pii wea[MN];
//pii arm[MN];
map<int, int> arm;
pair<pii, int> mon[MN];
 
ll tree[MM*4];
ll lazy[MM*4];
void build(int node, int a, int b){
    tree[node] = -INF;
    if(a == b) return;
    build(node*2, a, (a+b)/2);
    build(node*2+1, 1+(a+b)/2, b);
}
void upd(int node, int a, int b, int i, int j, ll val){
    if(lazy[node] != 0){
        tree[node] = tree[node] + lazy[node];
        if(tree[node] < -INF) tree[node] = -INF;
        if(a != b){
            lazy[node*2] = (lazy[node*2]+lazy[node]);
            lazy[node*2+1] = (lazy[node*2+1]+lazy[node]);
        }
        lazy[node] = 0;
    }
 
    if(a > b || a > j || b < i || j < i) return;
 
    if(i <= a && b <= j){
        tree[node] = tree[node] + val;
        if(tree[node] < -INF) tree[node] = -INF;
        if(a != b){
            lazy[node*2] = (lazy[node*2]+val);
            lazy[node*2+1] = (lazy[node*2+1]+val);
        }
        return;
    }
 
    upd(node*2, a, (a+b)/2, i, j, val);
    upd(node*2+1, 1+(a+b)/2, b, i, j, val);
    tree[node] = max(tree[node*2], tree[node*2+1]);
}
ll que(int node, int a, int b, int i, int j){
    if(lazy[node] != 0){
        tree[node] = tree[node] + lazy[node];
        if(a != b){
            lazy[node*2] = (lazy[node*2]+lazy[node]);
            lazy[node*2+1] = (lazy[node*2+1]+lazy[node]);
        }
        lazy[node] = 0;
    }
    if(a > b || a > j || b < i) return 0;
 
    if(a >= i && b <= j) return tree[node];
 
    ll q1 = que(node*2, a, (a+b)/2, i, j);
    ll q2 = que(node*2+1, 1+(a+b)/2, b, i, j);
 
    return max(q1, q2);
}
 
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
 
    cin >> n >> m >> p;
    F0R(i, n){
        cin >> wea[i].f >> wea[i].s;
    }
    F0R(i, m){
        //cin >> arm[i].f >> arm[i].s;
        int b, cb;
        cin >> b >> cb;
        if(arm.count(b)){
            arm[b] = min(arm[b], cb);
        } else{
            arm[b] = cb;
        }
    }
    F0R(i, p){
        cin >> mon[i].f.f >> mon[i].f.s >> mon[i].s;
    }
    sort(wea, wea+n);
    sort(mon, mon+p);
    //memset(tree, -0x3f, sizeof tree);
    build(1, 1, MM);
    //cout << "mx is " << que(1, 1, MM, 1, MM) << "\n";
    for(auto u : arm){
        //cout << "inc " << 
        upd(1, 1, MM, u.f, u.f, INF-u.s);
    }
    //cout << "mx is " << que(1, 1, MM, 1, MM) << "\n";
    int cw = 0, cm = 0;
    ll mx = -INF;
    FOR(i, 1, MM){
        while(wea[cw].f == i){
            ll val = que(1, 1, MM, 1, MM);
            ll tot = val-wea[cw].s;
            mx = max(mx, tot);
            //cout << wea[cw].f << " " << wea[cw].s << " " << val << " " << tot << "\n";
            ++cw;
        }
        while(mon[cm].f.f == i){
            //cout << "upd " << mon[cm].f.s-1 << " " << mon[cm].s << "\n";
            upd(1, 1, MM, mon[cm].f.s+1, MM, mon[cm].s);
            ++cm;
        }
    }
    cout << mx << "\n";
 
    return 0;
}