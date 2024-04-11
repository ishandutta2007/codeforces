#pragma GCC optimize ("O3")
#pragma GCC target ("sse4")

#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
typedef vector<pair<int, int> > vpii;
typedef pair<int, int> pii;
typedef long long ll;
typedef pair<ll, ll> pll;
typedef pair<double, double> pdd;
#define INF 1000000000000LL
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
int n;
ll c[MN];
vi e[MN];

ll atot[MN];
ll amax[MN];
ll asec[MN];
ll athr[MN];

int stat[MN][2]; //1 = must use, 0 = tie, -1 = never use

ll cost[MN][2]; //0 = done, 1 = not done
void dfs(int cn, int p){
    //cost[cn] = c[cn]; //for now

    if(e[cn].size() == 1 && cn != 1){
        cost[cn][0] = c[cn];
        cost[cn][1] = 0;

        stat[cn][0] = 1;
        stat[cn][1] = -1;
        return;
    }

    ll totch = 0;
    ll maxc = -INF;
    ll secc = -INF;
    ll thrc = -INF;

    F0R(i, e[cn].size()){
        int nn = e[cn][i];
        if(nn == p) continue;
        
        dfs(nn, cn);
        totch += cost[nn][0];
        ll sv = cost[nn][0] - cost[nn][1];
        //maxc = max(maxc, cost[nn][0]-cost[nn][1]);
        if(sv > maxc){
            thrc = secc;
            secc = maxc;
            maxc = sv;
        } else if(sv > secc){
            thrc = secc;
            secc = sv;
        } else if(sv > thrc){
            thrc = sv;
        }
    }

    //cout << "for node " << cn << ", totch is " << totch << " and maxc is " << maxc << " and sec is " << secc << "\n";

    atot[cn] = totch;
    amax[cn] = maxc;
    asec[cn] = secc;
    athr[cn] = thrc;

    cost[cn][0] = min(totch, totch+c[cn]-maxc);
    if(c[cn] < maxc){
        stat[cn][0] = 1;
    } else if(c[cn] > maxc){
        stat[cn][0] = -1;
    }
    /*cost[cn][1] = min(totch-maxc, totch+c[cn]-maxc-secc);
    if(c[cn] < secc){
        stat[cn][1] = 1;
    } else if(c[cn] > secc){
        stat[cn][1] = -1;
    }*/
    cost[cn][1] = totch-maxc;
    stat[cn][1] = -1;
}

bool cu[MN];
bool vis[MN][2];
void rec(int cn, int p, int val){
    if(vis[cn][val]) return;
    vis[cn][val] = true;

    //cout << "stat at " << cn << " " << val << " is " << stat[cn][val] << "\n";

    if(stat[cn][val] != 1 && val == 0){ //there exists a sol w/o this
        F0R(i, e[cn].size()){
            int nn = e[cn][i];
            if(nn == p) continue;

            rec(nn, cn, 0);
        }
    } else if(stat[cn][val] != 1 && val == 1){
        F0R(i, e[cn].size()){
            int nn = e[cn][i];
            if(nn == p) continue;

            ll sv = cost[nn][0]-cost[nn][1];

            if(amax[cn] == sv){
                rec(nn, cn, 1);
            }
            if(amax[cn] != sv || asec[cn] == sv){
                rec(nn, cn, 0);
            }
        }
    }

    if(stat[cn][val] != -1 && val == 0){
        cu[cn] = true;
        F0R(i, e[cn].size()){
            int nn = e[cn][i];
            if(nn == p) continue;

            ll sv = cost[nn][0]-cost[nn][1];

            if(amax[cn] == sv){
                rec(nn, cn, 1);
            }
            if(amax[cn] != sv || asec[cn] == sv){
                rec(nn, cn, 0);
            }
        }
    } else if(stat[cn][val] != -1 && val == 1){
        cu[cn] = true;
        F0R(i, e[cn].size()){
            int nn = e[cn][i];
            if(nn == p) continue;

            ll sv = cost[nn][0]-cost[nn][1];

            if(amax[cn] == sv || asec[cn] == sv){
                rec(nn, cn, 1);
            }
            if((amax[cn] != sv && asec[cn] != sv) || athr[cn] == sv){
                rec(nn, cn, 0);
            }
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> n;
    FOR(i, 1, n){
        cin >> c[i];
    }
    F0R(_, n-1){
        int u, v;
        cin >> u >> v;
        e[u].pb(v);
        e[v].pb(u);
    }

    dfs(1, 0);

    /*cout << cost[1][0] << "\n";
    FOR(i, 1, n){
        cout << cost[i][0] << " " << cost[i][1] << "\n";
    }*/

    rec(1, 0, 0);

    int cnt = 0;
    FOR(i, 1, n){
        if(cu[i]) cnt++;
    }

    cout << cost[1][0] << " " << cnt << "\n";
    FOR(i, 1, n){
        if(cu[i]) cout << i << " ";
    }
    
    return 0;
}