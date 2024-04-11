#include <algorithm>
#include <cassert>
#include <cstdlib>
#include <complex>
#include <cstring>
#include <memory>
#include <string>
#include <vector>
#include <cstdio>
#include <ctime>
#include <set>
#include <iostream>

using namespace std;

#define fs first
#define sc second
#define forn(i, n) for (int i = 0; i < (int)(n); ++i)
#define pb push_back
#define mp make_pair

typedef long long ll;

const int mod = 1000000007;

vector<pair<int, int> > g[300100];
int ans[300100];
int s[300100];
int d[300100];
bool used[300100];

void dfs(int v) {
    used[v] = true;
    s[v] = d[v] > 0;
    forn (i, g[v].size()) {
        int to = g[v][i].fs;
        if (used[to]) {
            continue;
        }
        dfs(to);
        s[v] += s[to];
        if (s[to] % 2) {
            ans[g[v][i].sc]++;
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    int n, m;
    cin >> n >> m;
    bool was = false;
    int sum = 0;
    forn (i, n) {
        cin >> d[i];
        if (d[i] == -1) {
            was = true;
        }
        sum += d[i] > 0;
    }
    if (!was && sum % 2) {
        cout << -1 << endl;
        return 0;
    }
    if (sum % 2) {
        forn (i, n) {
            if (d[i] == -1) {
                d[i] = 1;
                break;
            }
        }
    }
    forn (i, m) {
        int a, b;
        cin >> a >> b;
        --a;
        --b;
        g[a].pb(mp(b, i));
        g[b].pb(mp(a, i));
    }
    dfs(0);
    int res = 0;
    forn (i, m) {
        if (ans[i] % 2) {
            res++;
        }
    }
    cout << res << endl;
    forn (i, m) {
        if (ans[i] % 2) {
            cout << i + 1 << endl;
        }
    }
    return 0;
}