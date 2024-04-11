#define __GLIBCXX_DEBUG

#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <vector>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <queue>
#include <ctime>
#include <cassert>
#include <complex>
#include <string>
#include <cstring>
#include <random>
#include <queue>
#include <bitset>

#define pb push_back
// #define int long long
#define dbl long double
#define str string
using namespace std;
const int M = 1e9 + 7;
int n;
int subtree_size[100009];
char level[100009];
bitset<100009> used;
vector<vector<int>> gr;

void get_sizes(int v, int p) {
    subtree_size[v] = 1;
    for (auto u : gr[v]) {
        if (u != p && !used[u]) {
            get_sizes(u, v);
            subtree_size[v] += subtree_size[u];
        }
    }
}

int centroid(int v, int p, int n) {
    for (auto u : gr[v]) {
        if (subtree_size[u] > n / 2 && u != p && !used[u]) {
            return centroid(u, v, n);
        }
    }
    return v;
}

void solve(int v, int lvl) {
    get_sizes(v, -1);
    used[v] = true;
    level[v] = (char) 'A' + lvl;
    for (auto u : gr[v]) {
        if (!used[u]) {
            solve(centroid(u, v, subtree_size[u]), lvl+1);
        }
    }
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >> n;
    gr.resize(n);
    for (int i = 0; i < n - 1; i++) {
        int a, b;
        cin >> a >> b;
        a--; b--;
        gr[a].pb(b);
        gr[b].pb(a);
    }
    get_sizes(0, -1);
    int c = centroid(0, -1, n);
    solve(c, 0);
    for (int x = 0; x < n; x++) {
        char lol = level[x];
        cout << lol << ' ';
    }

}