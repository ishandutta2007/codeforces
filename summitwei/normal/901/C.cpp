#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
typedef vector<pair<int, int> > vpii;
typedef pair<int, int> pii;
typedef long long ll;
typedef pair<ll, ll> pll;
typedef pair<double, double> pdd;
typedef vector<ll> vll;
#define INF 0x3f3f3f3f
#define MOD 998244353LL //119*2^23+1
#define EPSILON 0.00001
#define f first
#define s second
#define pb push_back
#define mp make_pair
 
#define FOR(i, a, b) for (int i=(a); i<=(signed)(b); i++)
#define F0R(i, a) for (int i=0; i<(signed)(a); i++)
#define RFOR(i, a, b) for (int i=(a); i >= b; i--)

#define MN 300005
int n, m;
vi e[MN];
int d[MN];
int p[MN];
vpii cyc;

void gc(int bt, int tp){
    //cout << "getting " << bt << " " << tp << "\n";
    int mn = bt, mx = bt;
    int cur = bt;
    while(cur != tp){
        //cout << "on " << cur << "\n";
        cur = p[cur];
        mn = min(mn, cur);
        mx = max(mx, cur);
    }
    cyc.pb({mn, mx});
}
void dfs(int cn){
    //cout << "doing " << cn << "\n";
    for(auto nn : e[cn]){
        if(d[nn] == -1){
            d[nn] = d[cn]+1;
            p[nn] = cn;
            dfs(nn);
        } else if(nn != p[cn] && d[nn] < d[cn]){
            gc(cn, nn);
        }
    }
}

ll rb[MN];
ll ps[MN];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> m;
    F0R(_, m){
        int u, v;
        cin >> u >> v;
        e[u].pb(v);
        e[v].pb(u);
    }
    memset(d, -1, sizeof d);
    FOR(i, 1, n){
        if(d[i] == -1){d[i] = 0; dfs(i);}
    }
    //dfs(1);

    //cout << "hmm1\n";

    sort(cyc.begin(), cyc.end());
    /*for(auto u : cyc){
        cout << u.f << " " << u.s << "\n";
    }*/
    rb[n] = n;
    int cur = cyc.size()-1;
    RFOR(i, n-1, 1){
        rb[i] = rb[i+1];
        while(cur >= 0 && cyc[cur].f == i){
            rb[i] = min(rb[i], (ll)cyc[cur].s-1);
            --cur;
        }
    }
    FOR(i, 1, n){
        ps[i] = ps[i-1]+rb[i];
        //cout << rb[i] << " ";
    }
    //cout << "\n";

    //cout << "hmm2\n";

    int q;
    cin >> q;
    F0R(_, q){
        ll l, r;
        cin >> l >> r;
        ll loc = max(l, (ll)(lower_bound(rb, rb+n, r)-rb));
        loc = min(loc, r+1);
        ll sm = ps[loc-1]-ps[l-1]+(r-loc+1)*r;
        ll bad = 1LL*(r-l+1)*(l+r)/2;
        ll ans = sm-bad+(r-l+1);
        cout << ans << "\n";
    }

    return 0;
}