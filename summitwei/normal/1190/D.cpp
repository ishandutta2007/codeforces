#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
typedef vector<pair<int, int> > vpii;
typedef pair<int, int> pii;
typedef long long ll;
typedef pair<ll, ll> pll;
typedef pair<double, double> pdd;
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

#define MN 200005
int n;
pii a[MN];
map<int, vi> b;

ll tree[MN*4];
void upd(int node, int a, int b, int i, int j, ll val){
    if(a > b || a > j || b < i) return;

    if(a == b){
        tree[node] = tree[node] + val;
        return;
    }
 
    upd(node*2, a, (a+b)/2, i, j, val);
    upd(node*2+1, 1+(a+b)/2, b, i, j, val);
    tree[node] = tree[node*2]+tree[node*2+1];
}
ll que(int node, int a, int b, int i, int j){
    if(a > b || a > j || b < i || j < i) return 0;
 
    if(a >= i && b <= j) return tree[node];
 
    int q1 = que(node*2, a, (a+b)/2, i, j);
    int q2 = que(node*2+1, 1+(a+b)/2, b, i, j);
 
    return q1+q2;
}

set<int> in;

ll c2(ll x){
    return 1LL*x*(x-1)/2;
}

map<int, int> cx, cy;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> n;
    F0R(i, n){
        cin >> a[i].f >> a[i].s;
        cx[a[i].f] = 0; cy[a[i].s] = 0;
    }
    int co = 0;
    for(auto& u : cx) u.s = ++co;
    co = 0;
    for(auto& u : cy) u.s = ++co;

    F0R(i, n){
        a[i].f = cx[a[i].f];
        a[i].s = cy[a[i].s];

        //cout << a[i].f << " " << a[i].s << "\n";

        b[-a[i].s].pb(a[i].f);
    }

    ll sm = 0;

    ll sz = cx.size();
    for(auto u : b){
        ll tot = 0;

        sort(u.s.begin(), u.s.end());

        ll ree = que(1, 1, sz, 1, u.s[0]-1);
        tot += c2(ree+1);
        ree = que(1, 1, sz, u.s[u.s.size()-1]+1, sz);
        tot += c2(ree+1);
        F0R(i, u.s.size()-1){
            ree = que(1, 1, sz, u.s[i]+1, u.s[i+1]-1);
            //cout << "ree " << ree << "\n";
            tot += c2(ree+1);
        }
        F0R(i, u.s.size()){
            if(!in.count(u.s[i])){
                upd(1, 1, sz, u.s[i], u.s[i], 1);
                in.insert(u.s[i]);
            }
        }

        ll yay = c2(in.size()+1) - tot;
        sm += yay;
        //cout << u.f << " " << yay << "\n";
    }

    cout << sm << "\n";

    return 0;
}