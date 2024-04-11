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

#define MN 1005
int n, m;
char grd[MN][MN];
vi e[2*MN];
vi rev[2*MN];
vi eq[2*MN];

int topoloc[2*MN];
int topo[2*MN];
int cnt;

int vis[2*MN];
bool dfs(int cn){
    //cout << "vis " << cn << "\n";
    if(vis[cn] == 1) return true;

    vis[cn] = 1;

    F0R(i, e[cn].size()){
        int nn = e[cn][i];
        if(vis[nn] == 2) continue;

        if(dfs(nn)) return true;
    }
    F0R(i, eq[cn].size()){
        int nn = eq[cn][i];
        if(vis[nn] != 0) continue;
        
        if(dfs(nn)) return true;
    }

    vis[cn] = 2;
    topoloc[cn] = cnt;
    topo[cnt] = cn;
    cnt--;

    return false;
}

bool vis2[2*MN];
int val[2*MN];
int locate(int cn, int cmn){
    //cout << "locating " << cn << "\n";
    if(val[cn] != 0) return val[cn];
    //if(vis2[cn]) return 0;

    vis2[cn] = true;

    int loc = cmn;

    F0R(i, rev[cn].size()){
        int nn = rev[cn][i];
        
        loc = max(loc, locate(nn, 1)+1);
    }
    F0R(i, eq[cn].size()){
        int nn = eq[cn][i];

        if(vis2[nn]) continue;

        loc = max(loc, locate(nn, loc));
    }

    val[cn] = loc;
    return loc;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m;
    FOR(i, 1, n){
        FOR(j, 1, m){
            char c;
            cin >> c;
            if(c == '>'){
                e[n+j].pb(i);
                rev[i].pb(n+j);
            } else if(c == '<'){
                e[i].pb(n+j);
                rev[n+j].pb(i);
            } else if(c == '='){
                eq[i].pb(n+j);
                eq[n+j].pb(i);
            }

            grd[i][j] = c;
        }
    }

    cnt = n+m;

    FOR(i, 1, n+m){
        if(vis[i] == 0){
            if(dfs(i)){
                cout << "No\n";
                return 0;
            }
        }
    }

    FOR(i, 1, n+m){
        int cn = topo[i];
        /*int mn = 0;
        F0R(j, rev[cn].size()){
            int nn = rev[cn][j];
            mn = max(mn, val[nn]);
        }
        F0R(j, eq[cn].size()){
            int nn = eq[cn][j];
            if(topoloc[nn] < topoloc[cn]){
                //cout << "hi " << topo[i] << "\n";
                mn = max(mn, val[nn]-1);
            }
        }
        val[cn] = mn+1;*/
        locate(cn, 1);
    }

    /*FOR(i, 1, n+m){
        cout << topo[i] << " " << val[i] << "\n";
    }*/

    FOR(i, 1, n){
        FOR(j, 1, m){
            char c = grd[i][j];
            if(c == '=' && val[i] != val[n+j]){
                cout << "No\n";
                return 0;
            } else if(c != '=' && val[i] == val[n+j]){
                cout << "No\n";
                return 0;
            }
        }
    }

    cout << "Yes\n";
    FOR(i, 1, n){
        cout << val[i] << " ";
    }
    cout << "\n";
    FOR(i, 1, m){
        cout << val[n+i] << " ";
    }
    cout << "\n";

    return 0;
}