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
#define INF 10000000000000000LL
#define MOD 1000000007
#define EPSILON 0.00001
#define f first
#define s second
#define pb push_back
#define mp make_pair

#define FOR(i, a, b) for (int i=(a); i<=(signed)(b); i++)
#define F0R(i, a) for (int i=0; i<(signed)(a); i++)
#define RFOR(i, a, b) for (int i=(a); i >= b; i--)

#define MN 500005
int n;
vi e[MN];
ll sz[MN];
ll bst[MN];
ll hue[MN];

vector<pll> vals; //sz, hue

ll tot;

ll c2(ll x){
    return x*(x-1) / 2;
}

struct line {
    long long m, c;
    long long eval(long long x) { return m * x + c; }
    long double intersectX(line l) { return (long double) (c - l.c) / (l.m - m); }
};

void dfs(int cn, int p){
    sz[cn] = 1;
    F0R(i, e[cn].size()){
        int nn = e[cn][i];
        if(nn == p) continue;
        dfs(nn, cn);

        sz[cn] += sz[nn];
    }

    ll mn = c2(sz[cn]);

    vals.clear();

    F0R(i, e[cn].size()){
        int nn = e[cn][i];
        if(nn == p) continue;

        ll val = bst[nn] + c2(sz[cn]-sz[nn]);
        mn = min(mn, val);
        
        vals.pb(mp(sz[nn], hue[nn]));
        //ll hue = sz[nn]*(-2*n+sz[nn]+1) + 2*bst[nn]; //DON'T FORGET TO DIVIDE BY TWO

        ll ca = bst[nn] + c2(n - sz[nn]);
        tot = min(tot, ca);
    }
    sort(vals.begin(), vals.end(), greater<pll>());

    deque<line> dq;
    dq.push_front({0, INF});
    F0R(i, vals.size()){
        while (dq.size() >= 2 && dq.back().eval(vals[i].f) >= dq[dq.size() - 2].eval(vals[i].f))
            dq.pop_back();
        
        ll ca = dq.back().eval(vals[i].f) + vals[i].s;
        tot = min(tot, ca+c2(n));
        line cur;
        cur.m = vals[i].f;
        cur.c = vals[i].s;

        while(dq.size() >= 2 && cur.intersectX(dq[0]) <= dq[0].intersectX(dq[1])){
            dq.pop_front();
        }

        dq.push_front(cur);
    }

    bst[cn] = mn;
    hue[cn] = (sz[cn]*(-2*n+sz[cn]+1) + 2*bst[cn])/2; //DON'T FORGET TO DIVIDE BY TWO
    //cout << "bst at " << cn << " " << bst[cn] << "\n";
    //cout << "hue at " << cn << " " << hue[cn] << "\n";
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    tot = INF;

    cin >> n;
    F0R(_, n-1){
        int u, v;
        cin >> u >> v;
        e[u].pb(v);
        e[v].pb(u);
    }

    dfs(1, 0);

    ll ans = c2(n)*2 - tot;
    cout << ans << "\n";

    //cout << tot << "\n";

    return 0;
}