#include <iostream>
#include <iomanip>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <cassert>
#include <string>
#include <set>
#include <map>
#include <random>
#include <bitset>
#include <string>
#include <unordered_set>
#include <unordered_map>
#include <deque>
#include <queue>
#define rep(i, n) for (int i = 0; i < (n); i++)
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()

using namespace std;
using ll = long long;
using ul = unsigned long long;
using ld = long double;

const int N = 2001;
vector<int> g[N];
int c[N], h[N], p[N], x[N];

void dfs(int v) {
    for (int u : g[v]) {
        h[u] = h[v] + 1;
        dfs(u);
    }
}

int main() {
#ifdef ONPC
    freopen("a.in", "r", stdin);
#endif
    ios_base::sync_with_stdio(0); cin.tie(0);
	int n, r = -1, cc = 1;
    cin >> n;
    rep(i, n) {
        cin >> p[i] >> c[i];
        p[i]--;
        if (p[i] == -1)
            r = i;
        else
            g[p[i]].push_back(i);
    }
    dfs(r);
    rep(i, n) {
        int cv = -1;
        rep(j, n)
            if (c[j] == 0 && (cv == -1 || h[j] < h[cv]))
                cv = j;
        if (cv == -1) {
            cout << "NO";
            return 0;
        }
        x[cv] = cc++;
        while (cv != -1) {
            c[cv]--;
            cv = p[cv];
        }
    }
    cout << "YES\n";
    rep(i, n)
        cout << x[i] << ' ';
}