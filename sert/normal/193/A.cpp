#include <bits/stdc++.h>

using namespace std;

const int N = 3431;

vector <int> es[N];
int up[N], tin[N];
int n, tme, x, y, m;
int kl;
char a[N][N];

void dfs(int v, int p) {
    int ch = 0;
    up[v] = tin[v] = ++tme;
    for (int i = 0; i < es[v].size(); i++) {
        if (es[v][i] == p) continue;
        if (tin[es[v][i]])
            up[v] = min(up[v], tin[es[v][i]]);
        else {
            ch++;
            dfs(es[v][i], v);
            up[v] = min(up[v], up[es[v][i]]);
            if (up[es[v][i]] >= tin[v] && v != y * m + x) {
                cout << "1\n";
                exit(0);
            }
        }
    }
    if (v == y * m + x && ch > 1) {
        cout << "1\n";
        exit(0);
    }
}

int main()
{
    //freopen("a.in", "r", stdin);
    //freopen("a.out", "w", stdout);

    cin >> n >> m;
    for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++) {
        cin >> a[i][j];
        if (a[i][j] == '#') {
            x = j;
            y = i;
            kl++;
        }
    }

    if (kl < 3) {
        cout << "-1\n";
        return 0;
    }

    int v;

    for (int i = 1; i < n; i++)
        for (int j = 0; j < m; j++) {
            if (a[i][j] == '.') continue;
            v = i * m + j;
            if (a[i - 1][j] == '#') {
                es[v].push_back(v - m);
                es[v - m].push_back(v);
            }
        }

    for (int i = 0; i < n; i++)
    for (int j = 1; j < m; j++) {
        if (a[i][j] == '.') continue;
        v = i * m + j;
        if (a[i][j - 1] == '#') {
            es[v].push_back(v - 1);
            es[v - 1].push_back(v);
        }
    }

    dfs(y * m + x, -1);

    cout << "2\n";

    return 0;

}