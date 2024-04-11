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
#define MOD 1000000007LL
#define EPSILON 0.00001
#define f first
#define s second
#define pb push_back
#define mp make_pair

#define FOR(i, a, b) for (int i=(a); i<=(signed)(b); i++)
#define F0R(i, a) for (int i=0; i<(signed)(a); i++)
#define RFOR(i, a, b) for (int i=(a); i >= b; i--)

#define MN 400005
int n, m, q;
int qs[MN];
vi e[MN];
int vis[MN];
void dfs(int cn){
    vis[cn] = true;
    for(auto nn : e[cn]) if(!vis[nn]) dfs(nn);
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> m >> q;
    F0R(_, q){
        int r, c;
        cin >> r >> c;
        e[r].pb(n+c);
        e[n+c].pb(r);
    }
    int cnt = 0;
    FOR(i, 1, n+m){
        if(!vis[i]){
            ++cnt;
            dfs(i);
        }
    }
    cout << cnt-1 << "\n";

    return 0;
}