#include <algorithm>
#include <chrono>
#include <cmath>
#include <ctime>
#include <iomanip>
#include <iostream>
#include <iterator>
#include <map>
#include <queue>
#include <random>
#include <set>
#include <stack>
#include <string>
#include <utility>
#include <vector>
#include <cassert>
#include <assert.h>

//#pragma GCC optimize("O3")

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

const ll MOD = 1000000007;
const ld EPS = 1e-11;
const ll INFL = 2e18;
const int INF = 1e9 + 7;
const ld PI = acos(-1);
const ld E = exp(1);

mt19937 rnd((unsigned)chrono::steady_clock::now().time_since_epoch().count());

vector<int> l, r;
vector<vector<int>> ch;

vector<ll> maxatma, maxatmi;

void root(int cv, int cr) {
    vector<int> nch;
    for (int cch : ch[cv]) {
        if (cch != cr) {
            nch.push_back(cch);
            root(cch, cv);
        }
    }
    ch[cv] = nch;
}

void dfsm(int cv) {
    for (int cch : ch[cv]) {
        dfsm(cch);
    }

    maxatma[cv] = 0;
    maxatmi[cv] = 0;
    for (int cch : ch[cv]) {
        maxatma[cv] += max(maxatma[cch] + abs(r[cv] - r[cch]), maxatmi[cch] + abs(r[cv] - l[cch]));
        maxatmi[cv] += max(maxatma[cch] + abs(l[cv] - r[cch]), maxatmi[cch] + abs(l[cv] - l[cch]));
    }
}

void solve() {
    int n;
    cin >> n;
    l.resize(n);
    r.resize(n);
    ch.assign(n, {});
    for (int i = 0; i < n; ++i) {
        cin >> l[i] >> r[i];
    }
    for (int i = 0; i < n - 1; ++i) {
        int u, v;
        cin >> u >> v;
        --u;
        --v;
        ch[u].push_back(v);
        ch[v].push_back(u);
    }

    root(0, -1);

    maxatma.assign(n, 0);
    maxatmi.assign(n, 0);

    dfsm(0);

    cout << max(maxatma[0], maxatmi[0]) << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    //    freopen("input.txt", "r", stdin);
    //    freopen("output.txt", "w", stdout);

    int t;
    cin >> t;
    for (int i = 0; i < t; ++i) {
        solve();
    }

    return 0;
}