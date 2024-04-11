#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
typedef vector<pair<int, int> > vpii;
typedef pair<int, int> pii;
typedef long long ll;
typedef pair<ll, ll> pll;
#define INF 1000000000
#define MOD 1000000007
#define EPSILON 0.00001
#define f first
#define s second
#define pb push_back
#define mp make_pair

#define FOR(i, a, b) for (int i=(a); i<=(b); i++)
#define F0R(i, a) for (int i=0; i<(signed)(a); i++)
#define RFOR(i, a, b) for (int i=(a); i >= b; i--)

#define MN 200005
int n, m;
vi e[MN];

int cbcc;
set<int> nbcc[MN]; //nodes in a bcc
vpii bcc[MN];

int par[MN];
int d[MN];
int l[MN];
bool vis[MN];
int tim;
stack<pii> stk;
void dfs(int cn){
    l[cn]=d[cn]=++tim;
    vis[cn] = true;

    int nch = 0;
    F0R(i, e[cn].size()){
        int nn = e[cn][i];

        if(vis[nn]){
            if(nn == par[cn]) continue;
            l[cn] = min(l[cn], d[nn]);
            if(d[nn] < d[cn]) stk.push(mp(cn, nn));
        } else{
            nch++;
            stk.push(mp(cn, nn));
            par[nn] = cn;
            dfs(nn);

            l[cn] = min(l[cn], l[nn]);

            if(par[cn] == 0 && nch > 1){
                while(stk.top() != mp(cn, nn)){
                    bcc[cbcc].pb(stk.top());
                    stk.pop();
                }
                bcc[cbcc].pb(stk.top());
                stk.pop();
                cbcc++;
            }
            if(par[cn] != 0 && l[nn] >= d[cn]){
                while(stk.top() != mp(cn, nn)){
                    bcc[cbcc].pb(stk.top());
                    stk.pop();
                }
                bcc[cbcc].pb(stk.top());
                stk.pop();
                cbcc++;
            }
        }
    }
}
void getbcc(){
    FOR(i, 1, n){
        if(!vis[i]){
            dfs(i);
        }
    }
    while(!stk.empty()){
        bcc[cbcc].pb(stk.top());
        stk.pop();
    }
    cbcc++;
}

int used[MN]; //0 = unused, 1 = used but not in cycle, 2 = in cycle
stack<int> cur;
vi cycle;
bool fc(int cn, int par){
    if(vis[cn]){
        while(cur.top() != cn){
            cycle.pb(cur.top());
            used[cur.top()] = 2;
            cur.pop();
        }
        used[cur.top()] = 2;
        cycle.pb(cur.top());
        return true;
    }

    vis[cn] = true;
    cur.push(cn);
    F0R(i, e[cn].size()){
        int nn = e[cn][i];
        if(used[nn] == 0 || nn == par) continue;

        if(fc(nn, cn)) return true;
    }

    cur.pop();
    return false;
}
vi othpth;
bool fp(int cn, int par, int orig){
    if(cn == orig) return false;

    if(used[cn] == 2){
        othpth.pb(cn);
        while(!cur.empty()){
            othpth.pb(cur.top());
            cur.pop();
        }
        othpth.pb(orig);
        return true;
    }

    vis[cn] = true;
    cur.push(cn);
    F0R(i, e[cn].size()){
        int nn = e[cn][i];
        if(used[nn] == 0 || vis[nn]) continue;

        if(fp(nn, cn, orig)) return true;
    }

    cur.pop();
    return false;
}

vi paths[3];
void gtp(){
    int st = othpth[0], end = othpth[othpth.size()-1];
    //cout << "third path is: ";
    F0R(i, othpth.size()){
        paths[0].pb(othpth[i]);
        //cout << othpth[i] << " ";
    }
    //cout << "\n";

    int stind = find(cycle.begin(), cycle.end(), st)-cycle.begin();
    int endind = find(cycle.begin(), cycle.end(), end)-cycle.begin();

    //cout << stind << " " << endind << "\n";

    if(stind < endind){
        FOR(i, stind, endind){
            paths[1].pb(cycle[i]);
        }
        RFOR(i, stind, 0){
            paths[2].pb(cycle[i]);
        }
        RFOR(i, cycle.size()-1, endind){
            paths[2].pb(cycle[i]);
        }
    } else{
        RFOR(i, stind, endind){
            paths[1].pb(cycle[i]);
        }
        FOR(i, stind, cycle.size()-1){
            paths[2].pb(cycle[i]);
        }
        FOR(i, 0, endind){
            paths[2].pb(cycle[i]);
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m;
    F0R(i, m){
        int u, v;
        cin >> u >> v;
        e[u].pb(v);
        e[v].pb(u);
    }

    getbcc();

    //cout << "there are " << cbcc << " bccs\n";

    int sol = -1;
    F0R(i, cbcc){
        //cout << "bcc " << i << "\n";
        F0R(j, bcc[i].size()){
            nbcc[i].insert(bcc[i][j].f);
            nbcc[i].insert(bcc[i][j].s);
            //cout << bcc[i][j].f << " " << bcc[i][j].s << "\n";
        }

        if(nbcc[i].size() < bcc[i].size()){
            sol = i;
            break;
        }
    }
    
    if(sol == -1){
        cout << "NO\n";
        return 0;
    }
    cout << "YES" << "\n";

    for(auto u : nbcc[sol]){
        used[u] = 1;
    }
    memset(vis, false, sizeof vis);

    fc(*nbcc[sol].begin(), -1);

    memset(vis, false, sizeof vis);
    while(!cur.empty()) cur.pop();

    /*F0R(i, cycle.size()){
        cout << cycle[i] << " ";
    }
    cout << "\n\n";*/

    //cout << "cycle is: ";
    bool done = false;
    F0R(i, cycle.size()){
        //cout << cycle[i] << " ";
        int cn = cycle[i];
        F0R(j, e[cn].size()){
            int nn = e[cn][j];
            if(used[nn] == 1){
                fp(nn, cn, cn);
                done = true;
                break;
            } else if(used[nn] == 2 && (nn != cycle[(i+1)%cycle.size()] && nn != cycle[(i+cycle.size()-1)%cycle.size()])){
                //cout << "hmm\n";
                othpth.pb(nn);
                othpth.pb(cn);
                done = true;
                break;
            }
        }
        if(done) break;
    }

    gtp();

    F0R(i, 3){
        cout << paths[i].size() << " ";
        F0R(j, paths[i].size()){
            cout << paths[i][j] << " ";
        }
        cout << "\n";
    }

    return 0;
}