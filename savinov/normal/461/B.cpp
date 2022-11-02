#ifdef LOCAL
#include <iostream>
#include <vector>
#include <algorithm>
#include <cassert>
#include <cstdio>
#include <queue>
#include <cmath>
#include <utility>
#include <ctime>
#include <climits>
#include <numeric>
#else
#include <bits/stdc++.h>
#endif

#define forn(i, n) for(int i = 0; i < (int) n; ++i)
#define ford(i, n) for(int i = (int)(n) - 1; i >= 0; ++i)
#define For(i, st, en) for(int i = (int)st; i <= (int)en; ++i)
#define clr(x) memset(x, 0, sizeof(x))
#define all(x) (x).begin(),(x).end()
#define pb push_back
#define x first
#define y second
#define mp make_pair

using namespace std;

typedef unsigned int uint;
typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
typedef vector<int> VI;
typedef vector<VI> VVI;
typedef pair<int, int> PII;

/**
 * The code starts here.
 */

vector <int> g[100000];

int color[100000];

const int mod = 1000000007;

PII dfs(int v) {
    PII res;
    if (color[v] == 1) {
        res.x = 0;
        res.y = 1;
        for (int to : g[v]) {
            PII w = dfs(to);
            res.y = (long long) res.y * (w.x + w.y) % mod;
        }
    } else {
        res.x = 1;
        res.y = 0;
        long long p[g[v].size() + 2];
        long long q[g[v].size() + 2];
        long long p1[g[v].size() + 2];
        long long p2[g[v].size() + 2];
        for (int i = 0; i < (int)g[v].size(); ++i) {
            int to = g[v][i];
            PII w = dfs(to);
            p[i + 1] = w.x + w.y;
            q[i + 1] = w.y;
            res.x = (long long)res.x * (w.x + w.y) % mod;
        }
        p1[0] = 1;
        for (int i = 1; i <= g[v].size(); ++i) {
            p1[i] = p[i] * p1[i - 1] % mod;
        }
        p2[g[v].size() + 1] = 1;
        for (int i = g[v].size(); i >= 1; --i) {
            p2[i] = p[i] * p2[i + 1] % mod;
        }
        for (int i = 1; i <= g[v].size(); ++i) {
            res.y = (res.y + q[i] * p1[i - 1] % mod * p2[i + 1]) % mod;
        }
    }
    return res;
}

int main()
{
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
#else
    //freopen("additive-class.in", "r", stdin);
    //freopen("additive-class.out", "w", stdout);
#endif
    //freopen("records-and-cycles.in", "r", stdin);
    //freopen("records-and-cycles.out", "w", stdout);

    ios_base::sync_with_stdio(false);

    int n;
    cin >> n;

    for (int i = 1; i < n; ++i) {
        int p;
        cin >> p;
        g[p].push_back(i);
    }

    for (int i = 0; i < n; ++i) {
        cin >> color[i];
    }

    PII res = dfs(0);

    cout << res.y << endl;
    return 0;
}