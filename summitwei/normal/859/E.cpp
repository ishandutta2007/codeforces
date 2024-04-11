#pragma GCC target ("avx2")
#pragma GCC optimization ("O3")
#pragma GCC optimization ("unroll-loops")

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

#define MN 400005
int n;
int a[MN];
vi rev[MN];
int vis[MN];
int t;
int dfs(int cn){
    int sz=1;
    vis[cn] = 1;
    for(auto nn : rev[cn]) if(!vis[nn]) sz += dfs(nn);
    return sz;
}
int dfs2(int cn){
    if(vis[cn])
        return t-vis[cn]+1;
    vis[cn] = ++t;
    //cout << cn << " " << vis[cn] << "\n";
    int res = dfs2(a[cn]);
    dfs(cn);
    return res;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    //functional graph!
    //given a cycle, those guys HAVE to stay the same or all move
    //so answer is just product of cycle lengths? lmao
    //wait alone things are terrible tho
    //every tree either ends in a cycle or a void. if cycle, answer for tree is cycle length. if void, answer is number of nodes
    cin >> n;
    FOR(i, 1, n){
        int x, y;
        cin >> x >> y;
        a[x] = y;
        rev[y].pb(x);
    }
    ll ans = 1;
    FOR(i, 1, 2*n){
        if(a[i] == 0){
            //cout << "found at " << i << "\n";
            ans = (ans*dfs(i))%MOD;
        }
    }
    //cout << ans << "\n";
    FOR(i, 1, 2*n){
        if(!vis[i]){
            //cout << "checking " << i << "\n";
            ans = (ans*min(2, dfs2(i)))%MOD;
        }
    }
    cout << ans << "\n";

    return 0;
}