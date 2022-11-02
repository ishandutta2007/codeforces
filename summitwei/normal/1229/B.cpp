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
#define ML 20
int n;
ll x[MN];
vi e[MN];
ll sm;

ll gcd(ll a, ll b){
    if(b == 0) return a;
    return gcd(b, a%b);
}

void dfs(int cn, int p, map<ll, int> par){
    map<ll, int> ans;
    ans[x[cn]]++;
    for(auto u : par){
        ans[gcd(u.f, x[cn])] += u.s;
    }
    for(auto u : ans){
        sm += u.f*u.s;
        sm %= MOD;
    }
    for(auto nn : e[cn]) if(nn != p){
        dfs(nn, cn, ans);
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> n;
    FOR(i, 1, n) cin >> x[i];
    F0R(_, n-1){
        int u, v;
        cin >> u >> v;
        e[u].pb(v);
        e[v].pb(u);
    }

    dfs(1, 0, {});
    cout << sm << "\n";

    return 0;
}