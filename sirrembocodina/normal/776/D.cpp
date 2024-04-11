#include <iostream>
#include <algorithm>
#include <cstdio>
#include <vector>
#include <string>

using namespace std;

#define forn(i, n) for (int i = 0; i < (int)(n); ++i)
#define pb push_back
#define mp make_pair
#define fs first
#define sc second

typedef long double ld;

int n, m;
bool r[100100];
vector<int> gr[100100];
vector<pair<int, int> > g[100100];
int col[100100];

void dfs(int v, int c = 1) {
//    cerr << v << " " << c << endl;
    col[v] = c;
    forn (i, g[v].size()) {
        int to = g[v][i].fs;
        int id = g[v][i].sc;
//        cerr << to << " " << id << " " << r[id] << endl;
        if (col[to]) {
            if ((col[to] == 1) ^ (c == 1) ^ r[id]) {
                cout << "NO\n";
                exit(0);
            }
            continue;
        }
        dfs(to, r[id] ? 3 - c : c);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin >> m >> n;
    forn (i, m) {
        int x;
        cin >> x;
        r[i] = !x;
    }
    forn (i, n) {
        int k;
        cin >> k;
        forn (j, k) {
            int x;
            cin >> x;
            --x;
            gr[x].push_back(i);
        }
    }
    forn (i, m) {
        g[gr[i][0]].push_back(mp(gr[i][1], i));
        g[gr[i][1]].push_back(mp(gr[i][0], i));
    }
    forn (i, n) {
        if (!col[i]) {
            dfs(i);
        }
    }
    cout << "YES\n";
    return 0;
}