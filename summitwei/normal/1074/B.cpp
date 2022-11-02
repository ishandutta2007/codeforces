#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
typedef vector<pair<int, int>> vpii;
typedef pair<int, int> pii;
typedef long long ll;
typedef pair<ll, ll> pll;
#define INF 1000000000
#define MOD 1000000007
#define EPSILON 0.00001
#define MAX_N 1005
#define fi first
#define se second

#define FOR(i, a, b) for (int i=(a); i<=(b); i++)
#define F0R(i, a) for (ll i=0; i<(a); i++)
#define RFOR(i, a, b) for (int i=(a); i >= b; i--)

int query(int num, int type){
    if(type == 0){
        cout << "A " << num << "\n";
        cout.flush();
    } else if(type == 1){
        cout << "B " << num << "\n";
        cout.flush();
    } else if(type == 2){
        cout << "C " << num << "\n";
        cout.flush();
        return 0;
    } else{
        cout << "C -1\n";
        cout.flush();
        return 0;
    }

    int resp;
    cin >> resp;
    
    if(resp == -1) exit(0);
    return resp;
}

int t;
int n;
vi edges[MAX_N];
int k1, k2;
set<int> me;
set<int> lc;

bool visited[MAX_N];
int dfs(int currNode){
    visited[currNode] = true;

    F0R(i, edges[currNode].size()){
        int newNode = edges[currNode][i];
        if(visited[newNode]) continue;

        if(me.count(newNode) == 1) return newNode;

        int recurse = dfs(newNode);
        if(recurse != -1) return recurse;
    }

    return -1;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> t;
    F0R(asdf, t){
        cin >> n;
        FOR(i, 1, n){
            edges[i].clear();
        }
        me.clear();
        lc.clear();
        F0R(i, n-1){
            int u, v;
            cin >> u >> v;
            edges[u].push_back(v);
            edges[v].push_back(u);
        }

        cin >> k1;
        F0R(i, k1){
            int x;
            cin >> x;
            me.insert(x);
        }
        cin >> k2;
        F0R(i, k2){
            int x;
            cin >> x;
            lc.insert(x);
        }

        int resp = query(*lc.begin(), 1);

        if(me.count(resp) == 1){
            query(resp, 2);
            continue;
        }

        memset(visited, false, sizeof visited);
        int nearest = dfs(resp);

        resp = query(nearest, 0);
        if(lc.count(resp) == 1){
            query(nearest, 2);
        } else{
            query(nearest, 3);
        }
    }

    return 0;
}