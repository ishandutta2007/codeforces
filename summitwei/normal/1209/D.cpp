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
#define INF 1000000000
#define MOD 998244353
#define EPSILON 0.00001
#define f first
#define s second
#define pb push_back
#define mp make_pair

#define FOR(i, a, b) for (int i=(a); i<=(signed)(b); i++)
#define F0R(i, a) for (int i=0; i<(signed)(a); i++)
#define RFOR(i, a, b) for (int i=(a); i >= b; i--)

#define MN 100005
int n, k;
vi e[MN];
int vis[MN];

int dfs(int cn){
    if(vis[cn]) return 0;
    vis[cn] = true;
    int cnt = 1;
    F0R(i, e[cn].size()){
        int nn = e[cn][i];
        cnt += dfs(nn);
    }
    return cnt;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> k;
    F0R(_, k){
        int x, y;
        cin >> x >> y;
        e[x].pb(y);
        e[y].pb(x);
    }

    int cnt = 0;

    FOR(i, 1, n){
        if(!vis[i]){
            int sz = dfs(i);
            //cout << sz << "\n";
            cnt += (sz-1);
        }
    }

    cout << max(0, k-cnt) << "\n";
    
    return 0;
}