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
#define MOD 1000000007LL
#define EPSILON 0.00001
#define f first
#define s second
#define pb push_back
#define mp make_pair

#define FOR(i, a, b) for (ll i=(a); i<=(signed)(b); i++)
#define F0R(i, a) for (ll i=0; i<(signed)(a); i++)
#define RFOR(i, a, b) for (ll i=(a); i >= b; i--)

#define MN 1005
int n;
vi e[MN];
int deg[MN];
pair<pii, int> ed[MN];
vector<pair<pii, int> > ad;

int gl(int cn, int p){
    if(deg[cn] == 1) return cn;
    if(e[cn][0] != p) return gl(e[cn][0], cn);
    else return gl(e[cn][1], cn);
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> n;
    if(n == 2){
        int u, v, w;
        cin >> u >> v >> w;
        cout << "YES\n1\n";
        cout << u << " " << v << " " << w << "\n";
        return 0;
    }
    F0R(i, n-1){
        int u, v, w;
        cin >> u >> v >> w;
        ed[i] = {{u, v}, w};
        e[u].pb(v); e[v].pb(u);
        deg[u]++; deg[v]++;
    }
    FOR(i, 1, n){
        if(deg[i] == 2){
            cout << "NO\n";
            return 0;
        }
    }
    F0R(i, n-1){
        int u = ed[i].f.f, v=ed[i].f.s;
        if(deg[u] > deg[v]) swap(u, v);
        int ch = ed[i].s/2;
        
        if(deg[u] == 1){
            vi ok;
            for(auto nn : e[v]) if(nn != u){
                ok.pb(gl(nn, v));
            }
            int x = ok[0], y = ok[1];
            ad.pb({{u, x}, ch});
            ad.pb({{u, y}, ch});
            ad.pb({{x, y}, -ch});
        } else{
            vi ok1;
            for(auto nn : e[u]) if(nn != v){
                ok1.pb(gl(nn, u));
            }
            vi ok2;
            for(auto nn : e[v]) if(nn != u){
                ok2.pb(gl(nn, v));
            }
            int w = ok1[0], x = ok1[1], y = ok2[0], z = ok2[1];
            ad.pb({{w, y}, ch});
            ad.pb({{x, z}, ch});
            ad.pb({{w, x}, -ch});
            ad.pb({{y, z}, -ch});
        }
    }
    cout << "YES\n" << ad.size() << "\n";
    for(auto u : ad) cout << u.f.f << " " << u.f.s << " " << u.s << "\n";
    
    return 0;
}