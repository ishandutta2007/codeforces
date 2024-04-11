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

#define MN 300005
#define BAD 289182
int n, m;
vi e[MN];

int dist[MN];
int prv[MN]; //for tracing back
queue<int> q;
int bfs(int node, int type=0){
    int md = 0;

    q.push(node);
    while(!q.empty()){
        int cn = q.front();
        q.pop();
        if(type == 1 && cn == 1) continue;
        
        F0R(i, e[cn].size()){
            int nn = e[cn][i];
            if(dist[nn] != -1) continue;
            dist[nn] = dist[cn]+1;
            md = max(md, dist[nn]);
            prv[nn] = cn;
            q.push(nn);
        }
    }

    return md;
}

int ccc;
int cc[MN];
int szcc[MN];
void dfs(int cn){
    cc[cn] = ccc;
    szcc[ccc]++;

    F0R(i, e[cn].size()){
        int nn = e[cn][i];

        if(cc[nn] != 0 || nn == 1) continue;

        dfs(nn);
    }
}

vi ans;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    memset(dist, -1, sizeof dist);

    cin >> n >> m;

    F0R(i, m){
        int u, v;
        cin >> u >> v;
        e[u].pb(v);
        e[v].pb(u);
    }

    dist[1] = 0;
    int md = bfs(1);

    if(dist[n] <= 4 && dist[n] != -1){
        cout << dist[n] << "\n";
        int cur = n;
        while(cur != 0){
            ans.pb(cur);
            cur = prv[cur];
        }

        reverse(ans.begin(), ans.end());
        F0R(i, dist[n]+1){
            cout << ans[i] << " ";
        }
        return 0;
    } else if(md >= 2){
        int dt = 0;
        FOR(i, 1, n){
            if(dist[i] == 2){
                dt = i;
                break;
            }
        }

        cout << "4\n1 " << prv[dt] << " " << dt << " 1 " << n << "\n";
        return 0;
    }

    ccc = 1;
    F0R(i, e[1].size()){
        int cn = e[1][i];
        if(cc[cn] == 0){
            dfs(cn);
            ccc++;
        }
        if(e[cn].size() != szcc[cn]){
            //if(m == BAD) cout << "YAY\n";
            //we're already done lmao
            memset(dist, -1, sizeof dist);
            memset(prv, 0, sizeof prv);

            dist[cn] = 0;
            bfs(cn, 1);
            FOR(j, 1, n){
                if(dist[j] == 2 && cc[j] == cc[cn] && prv[j] != 1){
                    cout << "5\n1 " << cn << " " << prv[j] << " " << j << " " << cn << " " << n << "\n";
                    return 0;
                }
            }
        }
    }

    cout << "-1\n";
    return 0;
}