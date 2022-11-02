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
#define MOD 1000000007LL
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
ll v[MN];
vi e[MN];
pii sz[MN];
int d[MN];

void dfs(int cn, int p){ //odds, evens
    sz[cn].f = 1;
    for(auto nn : e[cn]) if(nn != p){
        d[nn] = d[cn]+1;
        dfs(nn, cn);
        sz[cn].f += sz[nn].s;
        sz[cn].s += sz[nn].f;
    }
    //cout << "sizes " << cn << " " << sz[cn].f << " " << sz[cn].s << "\n";
}

ll sm;
void dfs2(int cn, int p){
    vpii hmph;
    for(auto nn : e[cn]) if(nn != p){
        dfs2(nn, cn);
        hmph.pb({sz[nn].s, sz[nn].f});
    }
    if(p != 0){
        if(d[cn]%2 == 0){
            hmph.pb({sz[1].f-sz[cn].f, sz[1].s-sz[cn].s});
        } else{
            hmph.pb({sz[1].s-sz[cn].f, sz[1].f-sz[cn].s});
        }
    }
    ll del = 1; ll tot = 1; ll od = 1;
    //cout << "doing " << cn << "\n";
    for(auto u : hmph){
        //cout << u.f << " " << u.s << "\n";
        del = del + (u.f-u.s)*tot;
        del = (del+MOD)%MOD;
        del = del + od*(u.f+u.s);
        del = (del+MOD)%MOD;
        tot = tot+u.f+u.s;
        od = od+u.f-u.s;
    }
    //cout << cn << " " << del << "\n";
    sm = (sm+del*v[cn])%MOD;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    cin >> n;
    FOR(i, 1, n){
        cin >> v[i];
        v[i] = (v[i]+MOD)%MOD;
    }
    F0R(_, n-1){
        int x, y;
        cin >> x >> y;
        e[x].pb(y);
        e[y].pb(x);
    }

    dfs(1, 0);
    dfs2(1, 0);

    cout << sm << "\n";

    return 0;
}