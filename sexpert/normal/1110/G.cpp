#include <bits/stdc++.h>
using namespace std;

const int MAXN = 5e5 + 5;
int n, deg[MAXN];
vector<int> adj[MAXN];

void finish(string res) {
    cout << res << '\n';
    for(int i = 1; i <= n; i++) {
        deg[i] = 0;
        adj[i].clear();
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int tc;
    cin >> tc;
    while(tc--) {
        cin >> n;
        for(int i = 0; i < n - 1; i++) {
            int u, v;
            cin >> u >> v;
            deg[u]++;
            deg[v]++;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        string s;
        cin >> s;
        if(n < 3) {
            finish("Draw");
            continue;
        }
        if(n == 3) {
            if(s == "WWN" || s == "WNW" || s == "NWW")
                finish("White");
            else
                finish("Draw");
            continue;
        }
        int d3 = 0, whites = 0;
        bool b = true;
        for(int i = 1; i <= n; i++) {
            if(deg[i] >= 4) {
                finish("White");
                b = false;
                break;
            }
            if(s[i - 1] == 'W')
                whites++;
            if(s[i - 1] == 'W' && deg[i] > 1) {
                finish("White");
                b = false;
                break;
            }
            if(deg[i] == 3) {
                d3++;
                int d2 = 0;
                for(auto v : adj[i]) {
                    if(s[v - 1] == 'W') {
                        finish("White");
                        b = false;
                        break;
                    }
                    if(deg[v] > 1)
                        d2++;
                }
                if(!b)
                    break;
                if(d2 > 1) {
                    finish("White");
                    b = false;
                }
                if(!b)
                    break;
            }
        }

        if(!b)
            continue;

        if(d3 == 0) {
            if(whites == 2 && n % 2 == 1)
                finish("White");
            else
                finish("Draw");
            continue;
        }
        if(d3 == 1) {
            if(whites == 1 && n % 2 == 0)
                finish("White");
            else
                finish("Draw");
            continue;
        }
        if(d3 == 2) {
            if(n % 2 == 1)
                finish("White");
            else
                finish("Draw");
            continue;
        }
    }
}