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

#define FOR(i, a, b) for (int i=(a); i<=(signed)(b); i++)
#define F0R(i, a) for (int i=0; i<(signed)(a); i++)
#define RFOR(i, a, b) for (int i=(a); i >= b; i--)

#define MN 500005
int n, m;
vi e[MN];
pii t[MN];
int ctr[MN];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> m;
    FOR(i, 1, m){
        int u, v;
        cin >> u >> v;
        e[u].pb(v); e[v].pb(u);
    }
    FOR(i, 1, n){ cin >> t[i].f; t[i].s = i;}
    sort(t+1, t+n+1);
    FOR(i, 1, n){
        int x = t[i].s, k=t[i].f;
        if(ctr[x] != k-1){
            cout << "-1\n";
            return 0;
        }
        for(auto u : e[x]){
            if(ctr[u] == k-1) ctr[u] = k;
        }
    }
    FOR(i, 1, n) cout << t[i].s << " ";


    return 0;
}