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
#define MOD 1000000007
#define EPSILON 0.00001
#define f first
#define s second
#define pb push_back
#define mp make_pair
 
#define FOR(i, a, b) for (int i=(a); i<=(signed)(b); i++)
#define F0R(i, a) for (int i=0; i<(signed)(a); i++)
#define RFOR(i, a, b) for (int i=(a); i >= b; i--)
 
#define MN 100005
int n, m;
vi e[MN];
vi in[MN];
int q;
ll ans;

ll calc(int x){
    return 1LL*(e[x].size()-in[x].size())*(in[x].size());
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> m;
    F0R(_, m){
        int a, b;
        cin >> a >> b;
        e[a].pb(b);
        e[b].pb(a);
        if(a > b) swap(a, b);
        in[a].pb(b);
    }
    FOR(i, 1, n){
        ans += calc(i);
    }
    cin >> q;
    F0R(_, q){
        cout << ans << "\n";
        int u;
        cin >> u;
        ans -= calc(u);
        for(auto v : in[u]){
            ans -= calc(v);
            in[v].pb(u);
            ans += calc(v);
        }
        in[u].clear();
    }
    cout << ans << "\n";

    return 0;
}