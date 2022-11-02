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

#define MN 100005

struct Edge{
    int u, v;
    int dir; //0 = u >v, 1 = v->u
    int c;
};

int n, m;
Edge ed[MN];
vi e[MN];

int vis[MN];
bool dfs(int cn, int mxv){
    if(vis[cn] == 1) return true;

    vis[cn] = 1;

    F0R(i, e[cn].size()){
        int ce = e[cn][i];

        if(ed[ce].c <= mxv) continue;
        if(ed[ce].u != cn) continue;
        if(vis[ed[ce].v] == 2) continue;
        
        if(dfs(ed[ce].v, mxv)) return true;
    }

    vis[cn] = 2;
    return false;
}

int topo[MN];
int cnt;
void getTopo(int cn, int mxv){
    if(vis[cn]) return;
    vis[cn] = 1;

    F0R(i, e[cn].size()){
        int ce = e[cn][i];

        if(ed[ce].c <= mxv) continue;
        if(ed[ce].u != cn) continue;
        if(vis[ed[ce].v]) continue;

        getTopo(ed[ce].v, mxv);
    }

    topo[cn] = cnt;
    cnt++;
}

/*int backs[MN];
int back(int cn, int mxv){
    if(backs[cn] != 0) return backs[cn];
    F0R(i, e[cn].size()){
        int ce = e[cn][i];

        if(ed[ce].c <= mxv) continue;
        if(ed[ce].u == cn) continue;

        
        backs[cn] = back(ed[ce].u, mxv);
        return backs[cn];
    }

    backs[cn] = cn;
    return cn;
}*/

/*vi bad;
void form(int cn, int mxv){
    if(vis[cn]) return;
    cout << "proc " << cn << "\n";

    F0R(i, e[cn].size()){
        int ce = e[cn][i];
        if(ed[ce].c > mxv && ed[ce].v == cn && !vis[ed[ce].u]){
            form(ed[ce].u, mxv);
            return;
        }
    }

    vis[cn] = 1;

    F0R(i, e[cn].size()){
        int ce = e[cn][i];

        if(ed[ce].c > mxv) continue;

        int other = ed[ce].u+ed[ce].v-cn;
        if(vis[other] == 2) continue;

        if(cn != ed[ce].u){
            bad.pb(ce);
        }

        form(other, mxv);
    }

    F0R(i, e[cn].size()){
        int ce = e[cn][i];

        if(ed[ce].c > mxv && ed[ce].u == cn){
            form(ed[ce].v, mxv);
        }
    }

    vis[cn] = 2;
}*/

vi bad;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m;
    FOR(i, 1, m){
        cin >> ed[i].u >> ed[i].v >> ed[i].c;
        ed[i].dir = 0;
        e[ed[i].u].pb(i);
        e[ed[i].v].pb(i);
    }

    int l = -1;
    int r = INF;
    while(l+1<r){
        int mid = (l+r)/2;

        memset(vis, 0, sizeof vis);

        int ok = true;
        FOR(i, 1, n){
            if(!vis[i]){
                if(dfs(i, mid)){
                    ok = false;
                    break;
                }
            }
        }

        if(ok){
            r = mid;
        } else{
            l = mid;
        }
    }

    //cout << r;
    /*FOR(i, 1, n){
        //cout << "back from " << i << " is " << back(i, r) << "\n";
        int bk = back(i, r);
    }*/

    memset(vis, 0, sizeof vis);
    FOR(i, 1, n){
        if(!vis[i]){
            getTopo(i, r);
        }
    }

    FOR(i, 1, m){
        if(topo[ed[i].u] < topo[ed[i].v]){
            bad.pb(i);
        }
    }

    //form(r);
    /*FOR(i, 1, n){
        if(!vis[i]){
            int bk = back(i, r);

            //cout << "going from " << bk << "\n";

            form(bk, r);
        }
    }

    sort(bad.begin(), bad.end());*/

    /*F0R(i, n){
        cout << topo[i] << " ";
    }
    cout << "\n";*/

    cout << r << " " << bad.size() << "\n";
    F0R(i, bad.size()){
        cout << bad[i] << " ";
    }

    return 0;
}