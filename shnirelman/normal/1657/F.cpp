#include <bits/stdc++.h>

#define f first
#define s second

using namespace std;
using li = long long;
using ld = long double;
using pii = pair<int, int>;

const int INF = 1e9 + 13;
const li INF64 = 1e18 + 13;
//const int M = 1e9 + 7;
const int M = 998244353;
const int N = 3e6 + 13;
const int LOGN = 30;
const int A = 26;

/*

*/

namespace sat2 {
    vector<int> g[N * 4], r[N * 4];
    bool used[N * 4];
    vector<int> ts;
    int cmp[N * 4];


    void add(int x, int y) {
        g[x ^ 1].push_back(y);
        r[y].push_back(x ^ 1);

        g[y ^ 1].push_back(x);
        r[x].push_back(y ^ 1);
    }

    void dfs1(int v) {
        used[v] = true;

        for(int u : g[v]) {
            if(!used[u]) {
                dfs1(u);
            }
        }

        ts.push_back(v);
    }

    void dfs2(int v, int cl) {
        cmp[v] = cl;

        for(int u : r[v]) {
            if(cmp[u] == -1) {
                dfs2(u, cl);
            }
        }
    }

    bool res[N * 4];

    bool solve(int n) {
        for(int i = 0; i < n * 2; i++) {
            cmp[i] = -1;
        }

//        cout << "-----------------2-SAT------------" << endl;
//        for(int v = 0; v < n * 2; v++) {
//            cout << "g[" << v << "] = ";
//            for(int u : g[v]) {
//                cout << u << ' ';
//            }
//            cout << endl;
//        }

        for(int i = 0; i < n * 2; i++) {
            if(!used[i]) {
//                cout << "start dfs1 " << i << endl;
                dfs1(i);
            }
        }

        int cur = 1;

        reverse(ts.begin(), ts.end());

        for(int v : ts) {
            if(cmp[v] == -1) {
//                cout << "start dfs2 " << v << endl;
                dfs2(v, cur++);
            }
        }

//        cout << "cmp : ";
//        for(int i = 0; i < n * 2; i++)
//            cout << cmp[i] << ' ';
//        cout << endl;

        for(int i = 0; i < n; i++) {
            if(cmp[i * 2] == cmp[i * 2 + 1])
                return false;
            else res[i] = (cmp[i * 2] < cmp[i * 2 + 1]);
        }
        return true;
    }

};

vector<int> g[N];
int par[N];
int tin[N], tout[N];
int T = 1;

void dfs(int v) {
    tin[v] = T++;

    for(int u : g[v]) {
        if(u != par[v]) {
            par[u] = v;
            dfs(u);
        }
    }

    tout[v] = T++;
}

bool is_anc(int anc, int v) {
    return (tin[anc] <= tin[v] && tout[v] <= tout[anc]);
}

set<char> st[N];
bool can[N][A];
pii qr[N];
string s[N];
int resc[N][2];

vector<int> path[N];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, q;
    cin >> n >> q;

    for(int i = 0; i < n - 1; i++) {
        int v, u;
        cin >> v >> u;

        v--;
        u--;

        g[v].push_back(u);
        g[u].push_back(v);
    }

    dfs(0);

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < A; j++) {
            can[i][j] = true;
        }
//        st[i].insert(char())
    }

    for(int i = 0; i < q; i++) {
        int v, u;
        cin >> v >> u >> s[i];

        v--;
        u--;

        qr[i] = {v, u};

        vector<int> path1, path2;
        while(!is_anc(v, u)) {
            path1.push_back(v);
            v = par[v];
        }
        path1.push_back(v);

        while(!is_anc(u, v)) {
            path2.push_back(u);
            u = par[u];
        }

        reverse(path2.begin(), path2.end());

        path[i] = path1;

        for(int x : path2)
            path[i].push_back(x);

//        cout << "path " << i << " : ";
//        for(int x : path[i])
//            cout << x << ' ';
//        cout << endl;

        for(int j = 0; j < path[i].size(); j++) {
            int x = path[i][j];
            for(int c = 0; c < A; c++) {
                can[x][c] &= (s[i][j] == char(c + 'a') || s[i][s[i].size() - j - 1] == char(c + 'a'));
            }
        }
    }

    for(int i = 0; i < n; i++) {
        resc[i][0] = resc[i][1] = -1;
        for(int j = 0; j < A; j++) {
            if(can[i][j]) {
                if(resc[i][0] == -1)
                    resc[i][0] = j;
                else if(resc[i][1] == -1)
                    resc[i][1] = j;
            }
        }

        if(resc[i][0] == -1) {
            cout << "NO" << endl;
            return 0;
        }

        if(resc[i][1] == -1)
            resc[i][1] = resc[i][0];
    }

//    for(int i = 0; i < n; i++) {
//        cout << i << ' ' << char(resc[i][0] + 'a') << char(resc[i][1] + 'a') << endl;
//    }

    for(int i = 0; i < q; i++) {
        for(int j = 0; j < path[i].size(); j++) {
            int x = path[i][j];
            int cx[2] = {s[i][j] - 'a', s[i][s[i].size() - j - 1] - 'a'};

//            cout << "x = " << x << "  cx = { " << cx[0] << ' ' << cx[1] << "} " << endl;

            for(int ix = 0; ix < 2; ix++) {
                for(int iq = 0; iq < 2; iq++) {
//                    cout << "try pre add " << " query : " << i << "  vertex " << x << " resc[x][ix] = " << resc[x][ix] << " cx[iq] = " << cx[iq] << endl;
                    if(resc[x][ix] != cx[iq]) {
//                        cout << "pre add " << " query : " << i << "  vertex " << x << " resc[x][ix] = " << resc[x][ix] << " cx[iq] = " << cx[iq] << endl;
//                        cout << "ix = " << ix << "   iq = " << iq << endl;
                        sat2::add(2 * x + (ix ^ 1), 2 * n + 2 * i + (iq ^ 1));
                    }
                }
            }
        }
    }

    if(sat2::solve(n + q)) {
        cout << "YES" << endl;
        for(int i = 0; i < n; i++) {
            cout << char(resc[i][sat2::res[i]] + 'a');
        }
        cout << endl;
    } else {
        cout << "NO" << endl;
    }
}