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

#define MN 100005
int n, a, b, da, db;
vi e[MN];

pii dfs(int cn, int p){
    int fn = cn, d = 0;
    F0R(i, e[cn].size()){
        int nn = e[cn][i];
        if(nn == p) continue;

        pii res = dfs(nn, cn);
        if(res.s > d){
            fn = res.f;
            d = res.s;
        }
    }
    return mp(fn, d+1);
}
int diam(){
    pii x=dfs(1, 0);
    pii y=dfs(x.f, 0);
    return y.s;
}
int d[MN];
void dfs2(int cn, int p){
    for(auto nn : e[cn]) if(nn != p){
        d[nn] = d[cn]+1;
        dfs2(nn, cn);
    }
}
int dist(int x, int y){
    dfs2(x, 0);
    return d[y];
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;
    F0R(_, t){
        cin >> n >> a >> b >> da >> db;
        F0R(_, n-1){
            int u, v;
            cin >> u >> v;
            e[u].pb(v);
            e[v].pb(u);
        }

        int x = diam()-1;
        da = min(da, x);
        db = min(db, x);
        //cout << "diam " << x << "\n";
        
        if(da*2 >= db){
            cout << "Alice\n";
        } else if(da*2 >= x){
            cout << "Alice\n";
        } else if(dist(a, b) <= da){
            cout << "Alice\n";
        } else{
            cout << "Bob\n";
        }

        FOR(i, 1, n){
            e[i].clear();
            d[i] = 0;
        }
    }

    return 0;
}