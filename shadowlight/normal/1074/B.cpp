#include <iostream>
#include <tuple>
#include <sstream>
#include <vector>
#include <cmath>
#include <ctime>
#include <bitset>
#include <cassert>
#include <cstdio>
#include <queue>
#include <set>
#include <map>
#include <fstream>
#include <cstdlib>
#include <string>
#include <cstring>
#include <algorithm>
#include <numeric>
#define ll long long

#define TASKNAME ""

using namespace std;

const int INF = 1e9 + 7;
const int MAXN = 1e6 + 7;
const double EPS = 1e-8;

int n;
vector <vector <int> > gr;
vector <int> pred;
vector <int> ma;

void dfs(int v, int p, int last) {
    if (ma[v]) {
        last = v;
    }
    pred[v] = last;
    for (int u : gr[v]) {
        if (u == p) continue;
        dfs(u, v, last);
    }
}

void solve() {
    gr.clear();
    pred.clear();
    ma.clear();
    cin >> n;
    gr.resize(n);
    pred.resize(n);
    for (int i = 1; i < n; i++) {
        int v, u;
        cin >> v >> u;
        v--, u--;
        gr[v].push_back(u);
        gr[u].push_back(v);
    }
    int sza;
    cin >> sza;
    ma.resize(n, 0);
    int st = -1;
    for (int i = 0; i < sza; i++) {
        cin >> st;
        st--;
        ma[st] = 1;
    }
    dfs(st, -1, -1);
    int szb;
    cin >> szb;
    vector <int> sb(n, 0);
    int stb = 0;
    for (int i = 0; i < szb; i++) {
        int x;
        cin >> x;
        x--;
        sb[x] = 1;
        stb = x + 1;
    }
    cout << "B " << stb << endl;
    int x;
    cin >> x;
    x--;
    if (ma[x]) {
        cout << "C " << x + 1 << endl;
        return;
    }
    cout << "A " << pred[x] + 1 << endl;
    int y;
    cin >> y;
    y--;
    if (sb[y]) {
        cout << "C " << pred[x] + 1 << endl;
    } else {
        cout << "C -1" << endl;
    }
}

int main() {
    #ifdef MY
        //freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);
    #else
        //freopen(TASKNAME".in", "r", stdin);
        //freopen(TASKNAME".out", "w", stdout);
        //ios_base::sync_with_stdio(false);
        //cin.tie(0);
        //cout.tie(0);
    #endif // MY
    int t;
    cin >> t;
    for (int i = 0; i < t; i++) {
        solve();
    }
}