#include <algorithm>
#include <bitset>
#include <chrono>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <ctime>
#include <iomanip>
#include <iostream>
#include <iterator>
#include <map>
#include <queue>
#include <random>
#include <set>
#include <stack>
#include <stdio.h>
#include <string>
#include <unordered_map>
#include <utility>
#include <vector>
#include <cassert>
#include <assert.h>

//#pragma comment(linker, "/STACK:134217728")

//#pragma GCC optimize("O3")

using namespace std;

typedef int64_t ll;
typedef uint64_t ull;
typedef long double ld;

const ll MOD = 998244353;
const ld EPS = 1e-11;
const ld INFLD = 1e20;
const ll INFL = 2e18;
const int INF = 2e9 + 7;
const ld PI = acos(-1);
const ld E = exp(1);

//mt19937 rnd((unsigned)chrono::steady_clock::now().time_since_epoch().count());
mt19937 rnd(123876);

int n;
vector<vector<int>> ch[2]; //0, 1
vector<ll> p[2], pp[2]; //0, 1, 01, 10

void Construct(int v, int root) {
    for (int t = 0; t < 2; ++t) {
        for (int i = 0; i < ch[t][v].size(); ++i) {
            //case of root
            if (ch[t][v][i] == root) {
                swap(ch[t][v][i], ch[t][v].back());
                ch[t][v].pop_back();
                --i;
                continue;
            }

            //constructing the child and updating values
            int nv = ch[t][v][i];
            Construct(nv, v);
            p[t][v] += p[t][nv] + 1;
            pp[t][v] += pp[t][nv];
            pp[t][v] += p[t ^ 1][nv];
        }
    }
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);

    cin >> n;
    for (int i = 0; i < 2; ++i) {
        ch[i].resize(n);
        p[i].assign(n, 0);
        pp[i].assign(n, 0);
    }
    for (int i = 0; i < n - 1; ++i) {
        int u, v, t;
        cin >> u >> v >> t;
        --u;
        --v;
        ch[t][u].push_back(v);
        ch[t][v].push_back(u);
    }

    Construct(0, 0);

    ll ans{ 0 };
    for (int v = 0; v < n; ++v) {
        //cout << v << ":";
        ans += p[0][v] * p[1][v]; //paths, that swap colour at v
        for (int t = 0; t < 2; ++t) {
            //cout << " " << p[t][v] << " " << pp[t][v];
            ans += p[t][v] * 2; //monotone paths to v
            ans += pp[t][v]; //two-coloured paths to v
            ans += p[t][v] * p[t][v]; //all monotone paths through v
            for (int u : ch[t][v]) {
                ans -= (p[t][u] + 1) * (p[t][u] + 1); //excluding squares from the last argument
            }
            ans += pp[t][v] * p[t][v]; //two-coloured paths through v, that doesn't swap colours here
            for (int u : ch[t][v]) {
                ans -= (pp[t][u] + p[t ^ 1][u]) * (p[t][u] + 1); //excluding collisions from the last argument
            }
        }
        //cout << "\n";
    }

    cout << ans << "\n";

    return 0;
}