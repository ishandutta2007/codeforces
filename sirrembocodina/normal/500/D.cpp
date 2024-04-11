#include <algorithm>
#include <cstdio>
#include <iostream>
#include <cstring>
#include <cmath>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <deque>
#include <queue>
#include <stack>
#include <cassert>

using namespace std;

#define forn(i,n) for (int i = 0; i < int(n); ++i)
#define ford(i,n) for (int i = int(n) - 1; i >= 0; --i)
#define pb push_back
#define mp make_pair
#define fs first
#define sc second
#define sqr(a) ((a) * (a))
#define all(a) a.begin(), a.end()

typedef long double ld;
typedef long long ll;
typedef unsigned long long ull;
typedef unsigned int ui;
typedef unsigned char uc;

const ld pi = 3.1415926535897932384626433832795l;

const ll mod = 1000000007;

vector<int> g[100100];
bool used[100100];
int a[100100], b[100100], c[100100], sz[100100];

void dfs(int v) {
    used[v] = true;
    sz[v] = 1;
    forn (i, g[v].size()) {
        if (!used[g[v][i]]) {
            dfs(g[v][i]);
            sz[v] += sz[g[v][i]];
        }
    }
}

int main() {
    int n;
    scanf("%d", &n);
    forn (i, n - 1) {
        scanf("%d%d%d", &a[i], &b[i], &c[i]);
        --a[i];
        --b[i];
        g[a[i]].pb(b[i]);
        g[b[i]].pb(a[i]);
    }
    dfs(0);
    ld ans = 0.0;
    forn (i, n - 1) {
        if (sz[a[i]] > sz[b[i]]) {
            swap(a[i], b[i]);
        }
        int x = sz[a[i]], y = n - x;
        ans += (1 - (ll(x) * ll(x - 1) * ll(x - 2) + ll(y) * ll(y - 1) * ll(y - 2)) / ld(n) / ld(n - 1) / ld(n - 2)) * c[i];
    }
    int m;
    scanf("%d", &m);
    forn (i, m) {
        int p, q;
        scanf("%d%d", &p, &q);
        --p;
        int x = sz[a[p]], y = n - x;
        ans += (1 - (ll(x) * ll(x - 1) * ll(x - 2) + ll(y) * ll(y - 1) * ll(y - 2)) / ld(n) / ld(n - 1) / ld(n - 2)) * (q - c[p]);
        printf("%lf\n", double(ans * 2.0));
        c[p] = q;
    }
    return 0;
}