#include <bits/stdc++.h>

#define f first
#define s second
//#define int li

using namespace std;
using li = long long;
using ld = long double;
using pii = pair<int, int>;

const int INF = 1e9 + 13;
const li INF64 = 1e18 + 13;
const int M = 1e9 + 7;
//const int M = 998244353;
const int N = 100 + 13;
const int LOGN = 30;

bool b[N][N][N];
//vector<int> d[N][N];
bool fl = false;

void calc(int n, int v, int par, vector<vector<int>>& g, vector<bool>& used) {
    used[v] = true;
//    cout << "calc " << v << ' ' << par << endl;
    for(int i = 0; i < n; i++) {
//        cout << "   b " << i << ' ' << b[v][par][i] << endl;
        if(b[v][par][i]) {
            g[v].push_back(i);
            if(i != par) {
                if(used[i]) {
                    fl = true;
                    return;
                } else {
                    calc(n, i, v, g, used);
                    if(fl)
                        return;
                }
            }
        }
    }
}

/*
1
3
001 000
000


*/

void solve() {
    int n;
    cin >> n;

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n - i - 1; j++) {
            string s;
            cin >> s;

            for(int k = 0; k < n; k++) {
                b[k][i][i + j + 1] = b[k][i + j + 1][i] = s[k] - '0';
//                if(s[k] == '1') {
//                    cout << "-------- " << k << ' ' << i << ' ' << i + j + 1 << endl;
//                }
            }
        }
    }

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            b[i][j][j] = true;
        }
    }

    vector<bool> used(n, false);
    for(int x = 1; x < n; x++) {
        if(used[x])
            continue;

//        cout << "-----------------x = " << x << "----------- " << endl;

        vector<vector<int>> g(n);
        for(int i = 1; i < n; i++) {
            if(b[0][x][i] || x == i) {
                g[0].push_back(i);
                used[i] = true;
            }
        }

        fl = false;
        vector<bool> used2(n, false);
        used2[0] = true;
        for(int i : g[0]) {
            if(!used2[i])
                calc(n, i, 0, g, used2);
            else
                fl = true;

            if(fl)
                break;
        }
        if(fl)
            continue;

        int cnt = 0;
        for(int i = 0; i < n; i++) {
            cnt += g[i].size();
        }

        if(cnt != 2 * (n - 1))
            continue;

        for(int root = 0; root < n; root++) {
            //bfs
            vector<int> d(n, INF);
            d[root] = 0;
            queue<int> q;
            q.push(root);

            while(!q.empty()) {
                int v = q.front();
                q.pop();

                for(int u : g[v]) {
                    if(d[u] == INF) {
                        d[u] = d[v] + 1;
                        q.push(u);
                    }
                }
            }

//            cout << "d[" << root << "] : ";
//            for(int x : d)
//                cout << x << ' ';
//            cout << endl;
//
//            cout << "b[" << root << "] : ";
//            for(int i = 0; i < n; i++) {
//                for(int j = 0; j < n; j++)
//                    cout << "(" << i << ", " << j << ") = " << b[root][i][j] << " | ";
//            }
//            cout << endl;

            for(int i = 0; i < n && !fl; i++) /*if(i != root)*/ {
                for(int j = 0; j < n; j++) /*if(i != j && j != root) */{
                    if((d[i] == d[j]) != b[root][i][j]) {
                        fl = true;
                        break;
                    }
                }
            }

            if(fl)
                break;
        }

        if(!fl) {
            cout << "YES" << endl;
            for(int i = 0; i < n; i++) {
                for(int j : g[i])
                    if(j > i)
                        cout << i + 1 << ' ' << j + 1 << endl;
            }


            return;
        }
    }

    cout << "NO" << endl;
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t = 1;
    cin >> t;

    while(t--)
        solve();
}