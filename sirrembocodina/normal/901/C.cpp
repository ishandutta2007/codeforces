#include <iostream>
#include <algorithm>
#include <cstdio>
#include <vector>
#include <string>
#include <cstring>
#include <map>
#include <set>
#include <ctime>

using namespace std;

#define forn(i, n) for (int i = 0; i < (int)(n); ++i)
#define pb push_back
#define mp make_pair
#define fs first
#define sc second

typedef long long ll;
typedef long double ld;

int mod = 1000000007;

vector<int> g[300100];
int col[300100];
bool used[300100];

int dfs(int v, int p = -1) {
    used[v] = true;
    bool end = false;
    forn (i, g[v].size()) {
        int to = g[v][i];
        if (to == p) {
            continue;
        }
//        cerr << v << " " << to << endl;
        if (used[to]) {
            col[v] = to;
            continue;
        }
        int res = dfs(to, v);
        if (res != -1) {
            col[v] = res;
        }
        if (res == v) {
            end = true;
        }
    }
    if (end) {
        col[v] = v;
    }
    return col[v] == v ? -1 : col[v];
}

int last[300100];
int fst[300100];
int a[300100];
long long s[300100];
vector<pair<int, int> > q[300100];
long long ans[300100];

int main() {
    ios::sync_with_stdio(false);
    int n = 300000, m = 300000;
    cin >> n >> m;
    forn (i, m) {
        int a, b;
        cin >> a >> b;
        --a;
        --b;
//        a = i % 3;
//        b = (i + 1) % 3;
        g[a].pb(b);
        g[b].pb(a);
    }
    forn (i, n) {
        col[i] = -1;
    }
    forn (i, n) {
        if (!used[i]) {
            dfs(i);
        }
    }
//    forn (i, n) {
//        cerr << col[i] << " ";
//    }
//    cerr << endl;
    forn (i, n) {
        if (col[i] != -1) {
            last[col[i]] = i;
        }
    }
    for (int i = n - 1; i >= 0; --i) {
        if (col[i] != -1) {
            fst[col[i]] = i;
        }
    }
    int r = n;
    for (int i = n - 1; i >= 0; --i) {
        if (col[i] != -1 && i == fst[col[i]]) {
            r = min(r, last[col[i]]);
        }
        a[i] = r;
    }
//    forn (i, n) {
//        cerr << a[i] << " ";
//    }
//    cerr << endl;
    s[0] = 0;
    forn (i, n) {
        s[i + 1] = s[i] + a[i];
    }
    int k;
    cin >> k;
    forn (i, k) {
        int x, y;
        cin >> x >> y;
        --x;
        ans[i] -= y * (long long)(y - 1) / 2 - x * (long long)(x - 1) / 2;
        q[y].pb(mp(x, i));
    }
    int j = n;
    for (int i = n; i > 0; --i) {
        while (j && a[j - 1] >= i) {
            --j;
        }
        forn (t, q[i].size()) {
            int ind = q[i][t].sc;
            int l = q[i][t].fs;
            if (l >= j) {
                ans[ind] += (long long)(i - l) * i;
            } else {
                ans[ind] += (long long)(i - j) * i + s[j] - s[l];
            }
        }
    }
    forn (i, k) {
        cout << ans[i] << endl;
    }
    return 0;
}