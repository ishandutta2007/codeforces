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
#define MOD 1000000009LL
#define EPSILON 0.00001
#define f first
#define s second
#define pb push_back
#define mp make_pair
 
#define FOR(i, a, b) for (ll i=(a); i<=(signed)(b); i++)
#define F0R(i, a) for (ll i=0; i<(signed)(a); i++)
#define RFOR(i, a, b) for (int i=(a); i >= b; i--)

#define MN 200005
int n;
vi e[MN];
int sz[MN];
vi del;
bool yeeted[MN];

void dfs2(int cn, int p){
    del.pb(cn);
    yeeted[cn] = true;
    for(auto nn : e[cn]) if(nn != p){
        if(!yeeted[nn]) dfs2(nn, cn);
    }
}
void dfs(int cn, int p){
    int cnt = 0;
    bool he = false;
    for(auto nn : e[cn]) if(nn != p){
        dfs(nn, cn);
        if(!yeeted[nn]) ++cnt;
    }
    if(p != 0) ++cnt;
    if(cnt % 2 == 0){
        dfs2(cn, p);
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> n;
    FOR(i, 1, n){
        int p;
        cin >> p;
        if(p == 0) continue;
        e[p].pb(i);
        e[i].pb(p);
    }

    if(n % 2 == 0){
        cout << "NO\n";
        return 0;
    }

    cout << "YES\n";
    dfs(1, 0);
    for(auto u : del) cout << u << "\n";

    return 0;
}