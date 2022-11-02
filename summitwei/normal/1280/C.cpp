#pragma GCC optimize ("O3")
#pragma GCC target ("sse4")

#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
typedef vector<long long> vll;
typedef vector<pair<int, int> > vpii;
typedef pair<int, int> pii;
typedef long long ll;
typedef pair<ll, ll> pll;
typedef pair<double, double> pdd;
#define INF 0x3f3f3f3f
#define MOD 1000000007
#define EPSILON 0.00001
#define f first
#define s second
#define pb push_back
#define mp make_pair

#define FOR(i, a, b) for (int i=(a); i<=(signed)(b); i++)
#define F0R(i, a) for (int i=0; i<(signed)(a); i++)
#define RFOR(i, a, b) for (int i=(a); i >= b; i--)

#define MN 200005
int t;
int k;
vpii e[MN];

ll g, b;

int dfs(int cn, int p, int cd){
    int sm = 1;
    for(auto u : e[cn]){
        int nn = u.f, d = u.s;
        if(nn == p) continue;

        sm += dfs(nn, cn, d);
    }
    if(cn == 1) return 0;

    if(sm % 2 == 1) g += cd;
    int o = 2*k-sm;
    b += 1LL*min(o, sm)*cd;
    return sm;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> t;
    F0R(_, t){
        cin >> k;
        F0R(_, 2*k-1){
            int a, b, ti;
            cin >> a >> b >> ti;
            e[a].pb({b, ti});
            e[b].pb({a, ti});
        }
        dfs(1, 0, 0);
        cout << g << " " << b << "\n";

        FOR(i, 1, 2*k){
            e[i].clear();
        }
        g = 0; b = 0;
    }

    return 0;
}