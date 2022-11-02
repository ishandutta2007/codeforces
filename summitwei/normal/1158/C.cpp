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
#define INF 0x3f3f3f3f
#define MOD 1000000007
#define EPSILON 0.00001
#define f first
#define s second
#define pb push_back
#define mp make_pair

#define FOR(i, a, b) for (int i=(a); i<=(signed)(b); i++)
#define F0R(i, a) for (int i=0; i<(signed)(a); i++)
#define RFOR(i, a, b) for (int i=(a); i >= b; i--)

#define MN 500005
int t;
int n;
int nxt[MN];
priority_queue<pii, vpii> pq; //first, second. first large

int cur;
int topo[MN];
int vis[MN];
vi e[MN];
int ans[MN];

bool dfs(int cn){
    //cout << "dfs on " << cn << "\n";
    if(vis[cn] == 1) return false;
    if(vis[cn] == 2) return true;
    if(cn == n+1) return true;
    vis[cn] = 1;

    //cout << "loop starting\n";
    F0R(i, e[cn].size()){
        int nn = e[cn][i];
        if(!dfs(nn)) return false;
    }

    //cout << cn << "done\n";
    cur++;
    topo[cur] = cn;
    vis[cn] = 2;
    return true;
}

bool getTopo(){
    FOR(i, 1, n){
        if(!dfs(i)) return false;
    }
    return true;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    memset(topo, -1, sizeof topo);

    cin >> t;
    F0R(_, t){
        cin >> n;
        FOR(i, 1, n){
            cin >> nxt[i];
        }

        FOR(i, 1, n){
            while(!pq.empty() && pq.top().s <= i) pq.pop();
            if(!pq.empty()){
                e[i].pb(pq.top().f);
                //cout << "ae " << i << " " << pq.top().f << "\n";
            }
            if(nxt[i] == -1) continue;
            e[i].pb(nxt[i]);
            //cout << "ae " << i << " " << nxt[i] << "\n";
            pq.push(mp(i, nxt[i]));
        }

        if(!getTopo()){
            cout << "-1\n";
        } else{
            FOR(i, 1, n){
                ans[topo[n+1-i]] = i;
            }
            FOR(i, 1, n){
                cout << ans[i] << " ";
            }
            cout << "\n";
        }

        cur = 0;
        FOR(i, 1, n){
            nxt[i] = 0;
            topo[i] = -1;
            vis[i] = 0;
            ans[i] = 0;
            e[i].clear();
        }
        while(!pq.empty()) pq.pop();
    }
    
    return 0;
}