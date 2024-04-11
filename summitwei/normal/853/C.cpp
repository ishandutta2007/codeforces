#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
typedef vector<pair<int, int> > vpii;
typedef pair<int, int> pii;
typedef long long ll;
typedef pair<ll, ll> pll;
typedef pair<double, double> pdd;
typedef vector<ll> vll;
#define INF 0x3f3f3f3f3f3f3f3fLL
#define MOD 998244353LL
#define EPSILON 0.00001
#define f first
#define s second
#define pb push_back
#define mp make_pair
 
#define FOR(i, a, b) for (ll i=(a); i<=(signed)(b); i++)
#define F0R(i, a) for (ll i=0; i<(signed)(a); i++)
#define RFOR(i, a, b) for (int i=(a); i >= b; i--)

#define MN 200005
int n, q;
int p[MN];

vi tree[4*MN];
void build(int node, int a, int b){
    if(a == b){
        tree[node].pb(p[a]);
        return;
    }

    build(node*2, a, (a+b)/2);
    build(node*2+1, 1+(a+b)/2, b);
    int i=0, j=0;
    while(i < tree[node*2].size() || j < tree[node*2+1].size()){
        if(i == tree[node*2].size()){
            tree[node].pb(tree[node*2+1][j]);
            ++j;
        } else if(j == tree[node*2+1].size()){
            tree[node].pb(tree[node*2][i]);
            ++i;
        } else if(tree[node*2][i] < tree[node*2+1][j]){
            tree[node].pb(tree[node*2][i]);
            ++i;
        } else{
            tree[node].pb(tree[node*2+1][j]);
            ++j;
        }
    }
    /*cout << node << " " << a << " " << b << "\n";
    for(auto u : tree[node]) cout << u << " ";
    cout << "\n";*/
}
int que(int node, int a, int b, int i, int j, int q, bool up){ //true gets q -> n
    if(a > j || b < i || a > b) return 0;

    if(i <= a && b <= j){
        if(!up){
            int ans = lower_bound(tree[node].begin(), tree[node].end(), q) - tree[node].begin();
            //cout << a << " " << b << " " << q << " down found " << ans << "\n";
            return ans;
        } else{
            int ans = tree[node].end()-upper_bound(tree[node].begin(), tree[node].end(), q);
            //cout << a << " " << b << " " << q << " up found " << ans << "\n";
            return ans;
        }
    }

    int q1 = que(node*2, a, (a+b)/2, i, j, q, up);
    int q2 = que(node*2+1, 1+(a+b)/2, b, i, j, q, up);
    return q1+q2;
}

ll c2(ll x){
    //cout << "doing " << x << "\n";
    return x*(x-1)/2;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> q;
    FOR(i, 1, n) cin >> p[i];
    build(1, 1, n);
    F0R(i, q){
        //cin >> qs[i].f.f >> qs[i].s.f >> qs[i].f.f >> qs[i].s.s;

        int u, d, l, r;
        cin >> l >> d >> r >> u;
        ll cur = c2(l-1)+c2(d-1)+c2(n-r)+c2(n-u);
        //cout << cur << "\n";
        cur -= c2(que(1, 1, n, 1, l-1, d, false));
        cur -= c2(que(1, 1, n, 1, l-1, u, true));
        cur -= c2(que(1, 1, n, r+1, n, d, false));
        cur -= c2(que(1, 1, n, r+1, n, u, true));

        cout << c2(n)-cur << "\n";
    }


    return 0;
}