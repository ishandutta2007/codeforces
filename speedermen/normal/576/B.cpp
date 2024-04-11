#include <bits/stdc++.h>

using namespace std;

int const MaxN = 100010;
int const MOD = 1000000007;

int who[MaxN], n, perm[MaxN];
bool used[MaxN];
vector < int > temp;
vector < pair < int, int > > edges;

int get(int v) {
    if(v == who[v]) {
        return v;
    }
    return who[v] = get(who[v]);
}

void solver() {
    int countEdges = n * (n - 1) / 2;
    int mat[11][11] = {};
    vector < pair < int, int > > allEdges;
    for (int i = 1; i <= n; ++i) {
        for (int j = i + 1; j <= n; ++j) {
            allEdges.push_back(make_pair(i, j));
        }
    }
    for (int mask = 0; mask < 1 << countEdges; ++mask) {
        vector < pair < int, int > > tempEdges;
        for (int i = 0; i < countEdges; ++i) {
            if (mask & (1 << i)) {
                tempEdges.push_back(allEdges[i]);
            }
        }
        if (tempEdges.size() != n - 1) {
            continue;
        }
        for (int i = 1; i <= n; ++i) {
            who[i] = i;
        }
        bool ok = true;
        for (int i = 0; i < (int)tempEdges.size(); ++i) {
            int x = tempEdges[i].first, y = tempEdges[i].second;
            int px = get(x), py = get(y);
            if (px == py) {
                ok = false;
            } else {
                who[px] = py;
            }
        }
        if (ok == true) {
            memset(mat, 0, sizeof(mat));
            for (int i = 0; i < (int)tempEdges.size(); ++i) {
                int x = tempEdges[i].first, y = tempEdges[i].second;
                mat[x][y] = mat[y][x] = 1;
            }
            for (int i = 0; i < (int)tempEdges.size(); ++i) {
                int x = tempEdges[i].first, y = tempEdges[i].second;
                if(mat[perm[x]][perm[y]] == 0) {
                    ok = false;
                }
            }
        }
        if (ok == true) {
            cout << "YES" << '\n';
            for (int i = 0; i < tempEdges.size(); ++i) {
                cout << tempEdges[i].first << ' ' << tempEdges[i].second << '\n';
            }
            cout.flush();
        }
    }
    cout << "NO" << '\n';
    cout.flush();
}

int main() {
 //   ios :: sync_with_stdio(false);
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> perm[i];
    }
//    solver();
    for (int i = 1; i <= n; ++i) {
        if (perm[i] == i) {
            cout << "YES" << '\n';
            for (int j = 1; j <= n; ++j) {
                if (j != i) {
                    cout << i << ' ' << j << '\n';
                }
            }
            exit(0);
        }
    }
    int need = n - 1;
    for (int i = 1; i <= n; ++i) {
        if (used[i] != false) {
            continue;
        }
        vector < int > now;
        int j = i;
        while (!used[j]) {
            used[j] = 1;
            now.push_back(j);
            j = perm[j];
        }
        if (now.size() == 2 && !edges.size()) {
            edges.push_back(make_pair(i, perm[i]));
            continue;
        }
        if (now.size() > 2 && now.size() % 2 == 1) {
            cout << "NO\n";
            exit(0);
        }
        for (int i = 0; i < (int)now.size(); ++i) {
            temp.push_back(now[i]);
        }
    }
    if(!edges.size()) {
        cout << "NO\n";
        exit(0);
    }
    int p[2] = {edges[0].first, edges[0].second};
    for (int i = 0; i < (int)temp.size(); ++i) {
        edges.push_back(make_pair(p[i % 2], temp[i]));
    }
    cout << "YES\n";
    for (int i = 0; i < (int)edges.size(); ++i) {
        cout << edges[i].first << ' ' << edges[i].second << '\n';
    }
//    while(true);
    return 0;
}