#include <bits/stdc++.h>

#define f first
#define s second
//#define int li

using namespace std;
using li = long long;
using ld = long double;
using pii = pair<int, int>;

const int INF = 1e9 + 13;
const int N = 1e5 + 13;
const int M = 6;
const int A = 21;
const int LOGN = 20;
const int B = 3;//300;

/*
*/

vector<int> g[N], r[N];
int deg[N];
bool res[N][2];
int p[N][2];
bool used[N];
int ord[N];
int cur = 0;

void dfs(int v) {
    used[v] = true;
    for(auto u : g[v])
        if(!used[u])
            dfs(u);

    ord[v] = cur++;
}

signed main() {
//    ios::sync_with_stdio(0);
//    cin.tie(0);

    int n, m;
    cin >> n >> m;

    queue<pii> q;
    for(int i = 0; i < n; i++) {
        cin >> deg[i];

//        cout << "deg " << deg[i] << endl;
//        cout << "deg0 ---------- " << deg[0] << endl;

        for(int j = 0; j < deg[i]; j++) {
            int u;
            cin >> u;

            u--;

            g[i].push_back(u);
            r[u].push_back(i);
        }
//cout << "deg0 ---------- " << deg[0] << endl;
        if(deg[i] == 0) {
            res[i][1] = true;
            q.push({i, 1});
        }
//        cout << "deg0 ---------- " << deg[0] << endl;
    }

//    cout << deg[0] << endl;

    int s;
    cin >> s;

    s--;

    bool draw = false;
    dfs(s);

    for(int i = 0; i < n; i++) {
        if(used[i]) {
            for(auto u : g[i])
                if(ord[u] > ord[i])
                    draw = true;
        }
    }

//    for(int i = 0; i < n; i++)
//        cout << deg[i] << ' ';
//    cout << endl;



    while(!q.empty()) {
        int v = q.front().f;
        int x = q.front().s;
        q.pop();

//        cout << v << endl;

        for(auto u : r[v]) {
            if(!res[u][x ^ 1]) {
                res[u][x ^ 1] = true;
                p[u][x ^ 1] = v;
                q.push({u, x ^ 1});
            }
        }
    }

    if(res[s][0]) {
        cout << "Win" << endl;
        int x = 0;
        while(!g[s].empty()) {
            cout << s + 1 << ' ';
            s = p[s][x];
            x ^= 1;
        }
        cout << s + 1 << endl;
    } else
        cout << (!draw ? "Lose" : "Draw") << endl;

}