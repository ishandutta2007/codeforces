#include <bits/stdc++.h>

using namespace std;

const int N = 2e5 + 13;

vector<int> g[N];
int used[N];
int par[N];
vector<int> a;
int t1 = -1;
int t2 = -1;

/*
5 5 1
1 2
2 3
2 4
3 5
4 5

3 3 1
1 2
1 3
2 3

3 3 1
1 2
3 1
2 3

5 6 1
1 2
3 1
2 3
1 4
4 5
5 1
*/

bool dfs(int v, int p) {
    if(used[v] == 2) {
        t1 = v;
        t2 = p;
        return true;
    }
    used[v] = 1;
    par[v] = p;
    a.push_back(v);

    for(int u : g[v]) {
        if((used[u] == 2 || used[u] == 0) && dfs(u, v)) {
//            t1 = u;
//            t2 = v;
            return true;
        }
//        if(used[u] == 2) {
//
//        } else if(used[u] == 0) {
//            par[u] = v;
//            if(dfs)
//        }
    }
    return false;
}

int s;

vector<int> path(int v) {
    vector<int> res;

    while(v != s) {
        res.push_back(v);
        v = par[v];
    }
    res.push_back(s);

    reverse(res.begin(), res.end());

    return res;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, m;
    cin >> n >> m >> s;

    s--;

    for(int i = 0; i < m; i++) {
        int v, u;
        cin >> v >> u;

        v--;
        u--;

        g[v].push_back(u);
    }

    used[s] = 3;

    for(int v : g[s]) {
        if(dfs(v, s)) {
            vector<int> r1 = path(t1);
            vector<int> r2 = path(t2);
            r2.push_back(t1);

            cout << "Possible" << endl;
            cout << r1.size() << endl;
            for(int x : r1)
                cout << x + 1 << ' ';
            cout << endl;

            cout << r2.size() << endl;
            for(int x : r2)
                cout << x + 1 << ' ';
            cout << endl;
            return 0;
        }

        for(int x : a)
            used[x] = 2;
        a.erase(a.begin(), a.end());
    }

    cout << "Impossible" << endl;
}