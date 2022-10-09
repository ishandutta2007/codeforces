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

int mod = 1000000007;

int n;
vector<int> g[5010];
int p[5010], c[5010], d[5010];
vector<ll> dp[5010];
int sz[5010];

void v_merge(vector<int> &a, vector<int> &b, vector<int> &c) {
    c.clear();
    a.pb(2000000000);
    b.pb(2000000000);
    int i = 0, j = 0;
    while (i < int(a.size()) - 1 || j < int(b.size()) - 1) {
//        cerr << a[i] << " " << b[j] << endl;
        if (a[i] < b[j]) {
            c.pb(a[i++]);
        } else {
            c.pb(b[j++]);
        }
    }
    a.pop_back();
    b.pop_back();
}

vector<int> dfs(int v) {
    vector<int> a;
    a.pb(c[v]);
    forn (i, g[v].size()) {
        int to = g[v][i];
        vector<int> b = dfs(to), na;
        v_merge(a, b, na);
        a = na;
    }
    sz[v] = a.size();
    dp[v].assign(sz[v] + 1, 2000000000000000000ll);
    dp[v][0] = 0;
    dp[v][1] = c[v] - d[v];
    int cursz = 1;
    forn (i, g[v].size()) {
        int to = g[v][i];
        vector<ll> nval(cursz + sz[to] + 1, 2000000000000000000ll);
        forn (j, sz[to] + 1) {
            if (!j) {
                continue;
            }
            forn (k, cursz + 1) {
                if (!k || dp[v][k] == 2000000000000000000ll) {
                    continue;
                }
                nval[j + k] = min(nval[j + k], dp[v][k] + dp[to][j]);
            }
        }
        cursz += sz[to];
        forn (j, cursz + 1) {
            dp[v][j] = min(dp[v][j], nval[j]);
        }
    }
    ll sum = 0;
    forn (i, sz[v] + 1) {
        dp[v][i] = min(dp[v][i], sum);
        if (i < sz[v]) {
            sum += a[i];
        }
    }
    return a;
}

int main() {
    ll b;
    cin >> n >> b;
    forn (i, n) {
        cin >> c[i] >> d[i];
        if (i) {
            cin >> p[i];
//            p[i] = i;
            --p[i];
            g[p[i]].pb(i);
        }
    }
    dfs(0);
    int mx = 0;
    forn (i, n + 1) {
        if (dp[0][i] <= b) {
            mx = i;
        }
    }
    cout << mx << endl;
    return 0;
}