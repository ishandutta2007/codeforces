/**
 * BE CAREFUL!! I have define int li sometimes
 */

//#define _GLIBCXX_DEBUG

#include <stdio.h>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>
#include <deque>
#include <cmath>
#include <ctime>
#include <stack>
#include <set>
#include <bitset>
#include <map>
#include <cassert>
#include <memory.h>
#include <limits>
#include <numeric>

using namespace std;

#define mp make_pair
#define pb push_back
#define all(a) a.begin(), a.end()

typedef long long li;
typedef long double ld;
typedef vector<int> vi;
//typedef pair<int, int> pi;

void solve();

void prec();


#define FILENAME "souvenir"

int main() {
    string s = FILENAME;
#ifdef DEBUG
    freopen("/Users/RiaD/Contests/Contests/input", "r", stdin);
    //freopen("/Users/RiaD/Contests/Contests/output", "w", stdout);
    //cout<<FILENAME<<endl;
    //assert (s != "change me please");
    clock_t start = clock();
#else
    //freopen(FILENAME ".in", "r", stdin);
    //freopen(FILENAME ".out", "w", stdout);
#endif
    cout.sync_with_stdio(0);
    cout.precision(20);
    cout << fixed;
    //prec();
    int tests = 1;
    //cin >> tests;

    while (tests--) {
        solve();
    }
#ifdef DEBUG
    //cerr<<"\n\n"<<(clock() - start) / 1.0 / CLOCKS_PER_SEC<<"\n\n\n";
#endif
    return 0;
}

//#define int li
int n;


vector < vector<int> > g;
vector<vector<int>> g2;
const int INF = 1000000000; //  ""

bool go(int v, int p, int d, int start) {
    if(g[start][v] != d)
        return false;
    for(int to: g2[v]) {
        if(to == p)
            continue;
        if(!go(to, v, d + g[v][to], start))
            return false;
    }
    return true;
}

void solve() {
    cin >> n;
    g2.resize(n);
    g.assign(n, vector<int>(n, 0));
    for(int i = 0; i < n; ++i) {
        for(int j = 0; j < n; ++j) {
            cin >> g[i][j];
            if(i != j && g[i][j] == 0) {
                cout << "NO";
                return;
            }
        }
        if(g[i][i] != 0) {

            cout << "NO";
            return;
        }
    }
    for(int i = 0; i < n; ++i) {
        for(int j = 0; j < n; ++j) {
            if(g[i][j] != g[j][i]) {
                cout << "NO";
                return;
            }
        }
    }


    vector<bool> used(n);
    vector<int> min_e(n, INF), sel_e(n, -1);
    min_e[0] = 0;
    for (int i = 0; i < n; ++i) {
        int v = -1;
        for (int j = 0; j < n; ++j)
            if (!used[j] && (v == -1 || min_e[j] < min_e[v]))
                v = j;

        used[v] = true;
        if (sel_e[v] != -1) {
            g2[v].push_back(sel_e[v]);
            g2[sel_e[v]].push_back(v);
        }

        for (int to = 0; to < n; ++to)
            if (g[v][to] < min_e[to]) {
                min_e[to] = g[v][to];
                sel_e[to] = v;
            }
    }


    for(int i = 0; i < n; ++i) {
        if(!go(i, -1, 0, i)) {
            cout << "NO";
            return;
        }
    }

    cout << "YES";
}