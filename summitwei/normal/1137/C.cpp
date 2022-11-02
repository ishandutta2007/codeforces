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
#define INF 1000000000
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
#define MD 55
int n, m, d;
vi e[MN];
vi re[MN];
bool stat[MN][MD];
int lst[MN]; //last cc that touched on in this one

int cur;

int status[MN][MD]; //0 = unvisited, 1 = in, 2 = left
stack<pii> o;
stack<pii> st1;
/*void dfs1(int cn, int tim){
    if(vis[cn][tim]) return;

    vis[cn][tim] = true;
    F0R(i, e[cn].size()){
        int nn = e[cn][i];

        dfs1(nn, (tim+1)%d);
    }
    o.push(mp(cn, tim));
}*/
void dfs1(int cn, int tim){
    st1.push(mp(cn, tim));
    while(!st1.empty()){
        pii top = st1.top();
        st1.pop();
        if(status[top.f][top.s] == 2){
            continue;
        }
        if(status[top.f][top.s] == 1){
            o.push(top);
            status[top.f][top.s] = 2;
        } else{
            status[top.f][top.s] = 1;
            st1.push(top);
            F0R(i, e[top.f].size()){
                int nn = e[top.f][i];

                if(status[nn][(top.s+1)%d] == 0){
                    st1.push(mp(nn, (top.s+1)%d));
                }
            }
        }
    }
}
int scc[MN][MD];
int sz[MN*MD];
stack<pii> st2;
/*void dfs2(int cn, int tim, int ccc){
    if(scc[cn][tim] != 0) return;

    scc[cn][tim] = ccc;
    if(stat[cn][tim] && lst[cn] != ccc){
        sz[ccc]++;
        lst[cn] = ccc;
    }
    F0R(i, re[cn].size()){
        int nn = re[cn][i];

        dfs2(nn, (tim+d*2-1)%d, ccc);
    }
}*/
void dfs2(int cn, int tim, int ccc){
    st2.push(mp(cn, tim));

    while(!st2.empty()){
        pii top = st2.top();
        st2.pop();
        if(scc[top.f][top.s] != 0){
            continue;
        }
        scc[top.f][top.s] = ccc;
        if(stat[top.f][top.s] && lst[top.f] != ccc){
            sz[ccc]++;
            lst[top.f] = ccc;
        }
        F0R(i, re[top.f].size()){
            int nn = re[top.f][i];

            if(scc[nn][(top.s+d-1)%d] == 0){
                st2.push(mp(nn, (top.s+d-1)%d));
            }
        }
    }
}
void getcc(){
    while(!o.empty()){
        pii top = o.top();
        o.pop();
        if(scc[top.f][top.s] == 0){
            cur++;
            //cout << "hi " << top.f << " " << top.s << " " << cur << "\n";
            dfs2(top.f, top.s, cur);
        }
    }
}

int vis2[MN*MD];
int dp[MN*MD];
vi ne[MN*MD];
int dfs3(int cn){
    if(cn >= MN*MD){
        cout << "REE\n";
        exit(0);
    }

    if(dp[cn] != -1) return dp[cn];
    //cout << "doing " << cn << "\n";

    if(vis2[cn]){
        cout << "REE\n";
        exit(0);
    }

    vis2[cn] = true;

    int mx = 0;
    F0R(i, ne[cn].size()){
        int nn = ne[cn][i];

        mx = max(mx, dfs3(nn));
    }

    dp[cn] = sz[cn]+mx;
    return dp[cn];
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    memset(dp, -1, sizeof dp);

    cin >> n >> m >> d;
    F0R(_, m){
        int u, v;
        cin >> u >> v;

        e[u].pb(v);
        re[v].pb(u);
    }
    FOR(i, 1, n){
        /*string s;
        cin >> s;
        F0R(j, d){
            stat[i][j] = s[j]-'0';
        }*/
        F0R(j, d){
            char c;
            cin >> c;
            stat[i][j] = (c=='1');
        }
    }

    FOR(i, 1, n){
        F0R(j, d){
            if(status[i][j] == 0){
                dfs1(i, j);
            }
        }
    }

    getcc();

    /*FOR(i, 1, n){
        F0R(j, d){
            cout << scc[i][j] << " ";
        }
        cout << "\n";
    }

    FOR(i, 1, cur){
        cout << sz[i] << "\n";
    }*/

    FOR(cn, 1, n){
        F0R(i, e[cn].size()){
            int nn = e[cn][i];
            F0R(j, d){
                int u = scc[cn][j];
                int v = scc[nn][(j+1)%d];
                if(u != v){
                    ne[u].pb(v);
                    //cout << "edge from " << u << " " << v << "\n";
                }
            }
        }
    }

    cout << dfs3(scc[1][0]) << "\n";
    
    return 0;
}