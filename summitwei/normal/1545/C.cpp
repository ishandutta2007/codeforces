#pragma GCC optimize ("O3")
#pragma GCC target ("sse4")

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
typedef unsigned long long ull;
#define INF 0x3f3f3f3f
#define MOD 998244353LL
#define EPS 0.000000000001
#define f first
#define s second
#define pb push_back
#define mp make_pair

#define FOR(i, a, b) for (int i=(a); i<=(signed)(b); i++)
#define F0R(i, a) for (int i=0; i<(signed)(a); i++)
#define RFOR(i, a, b) for (int i=(a); i >= b; i--)

#define MN 1005
int n;
int a[MN][MN];
set<int> poss[MN][MN];
int stat[MN]; //-1 = bad, 1 = necessary. 2 = comp 1, -2 = comp 2
vi ed[MN];

void dfs(int cn){
    for(auto nn : ed[cn]){
        if(stat[nn] == 0){
            stat[nn] = -stat[cn];
            dfs(nn);
        }
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;
    F0R(_, t){
        cin >> n;
        FOR(i, 1, 2*n){
            FOR(j, 1, n){
                cin >> a[i][j];
                poss[j][a[i][j]].insert(i);
            }
        }
        queue<pii> yeets;
        queue<int> deleets;
        FOR(i, 1, n){
            FOR(j, 1, n){
                if(poss[i][j].size() == 1){
                    yeets.push({i,j});
                }
            }
        }
        while(!yeets.empty()){
            pii top = yeets.front();
            yeets.pop();
            int x = *poss[top.f][top.s].begin();
            assert(stat[x] != -1);
            if(stat[x] == 1) continue;
            stat[x] = 1;
            FOR(i, 1, n){
                for(auto u : poss[i][a[x][i]]){
                    if(u != x){
                        deleets.push(u);
                    }
                }
                poss[i][a[x][i]].clear();
            }
            while(!deleets.empty()){
                int cur = deleets.front(); deleets.pop();
                assert(stat[cur] != 1);
                if(stat[cur] == -1) continue;
                stat[cur] = -1;
                FOR(i, 1, n){
                    poss[i][a[cur][i]].erase(cur);
                    if(poss[i][a[cur][i]].size() == 1){
                        yeets.push({i,a[cur][i]});
                    }
                }
            }
        }
        FOR(i, 1, n){
            FOR(j, 1, n){
                assert(poss[i][j].size() == 0 || poss[i][j].size() == 2);
                if(poss[i][j].size() == 2){
                    vi ree;
                    for(auto u : poss[i][j]) ree.pb(u);
                    ed[ree[0]].pb(ree[1]);
                    ed[ree[1]].pb(ree[0]);
                    poss[i][j].clear();
                }
            }
        }
        int cnt = 0;
        FOR(i, 1, 2*n) if(stat[i] == 0){
            stat[i] = 2;
            ++cnt;
            dfs(i);
        }
        int res = 1;
        F0R(i, cnt) res = (res*2)%MOD;
        cout << res << "\n";
        FOR(i, 1, 2*n){
            if(stat[i] == 1 || stat[i] == 2) cout << i << " ";
        }
        cout << "\n";

        FOR(i, 1, 2*n){
            ed[i].clear();
            stat[i] = 0;
        }
    }

    return 0;
}