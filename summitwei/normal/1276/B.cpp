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
#define MOD 1000000007
#define EPSILON 0.00001
#define f first
#define s secondc
#define pb push_back
#define mp make_pair

#define FOR(i, a, b) for (int i=(a); i<=(signed)(b); i++)
#define F0R(i, a) for (int i=0; i<(signed)(a); i++)
#define RFOR(i, a, b) for (int i=(a); i >= b; i--)

#define MN 200005
int t;
int n, m, a, b;
vi e[MN];
bool vis[MN][2];
int cnt[2];

void dfs(int cn, int val){
    //cout << "vis " << cn << " " << val << "\n";
    if(vis[cn][val]) return;
    if((val == 1 && cn == a) || (val == 0 && cn == b)) return;
    vis[cn][val] = true;
    cnt[val]++;
    for(auto nn : e[cn]){
        dfs(nn, val);
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> t;
    F0R(_, t){
        cin >> n >> m >> a >> b;
        F0R(_, m){
            int u, v;
            cin >> u >> v;
            e[u].pb(v);
            e[v].pb(u);
        }

        dfs(a, 0);
        dfs(b, 1);
        //cout << cnt[0] << " " << cnt[1] << "\n";
        cout << 1LL*(n-cnt[0]-1)*(n-cnt[1]-1) << "\n";

        FOR(i, 1, n){
            e[i].clear();
            vis[i][0] = false;
            vis[i][1] = false;
        }
        cnt[0] = 0; cnt[1] = 0;
    }
    
    return 0;
}