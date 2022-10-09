#include <iostream>
#include <algorithm>
#include <cstdio>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <ctime>

using namespace std;

#define forn(i, n) for (int i = 0; i < (int)(n); ++i)
#define pb push_back
#define mp make_pair
#define fs first
#define sc second

vector<int> g[300100];
vector<int> s[300100];
set<int> ok;
int M[300100];

void dfs(int v, int p = -1) {
    vector<int> ncols, pr, cur = s[v];
    if (p != -1) {
        pr = s[p];
    }
    int i = 0, j = 0;
    while (i < int(pr.size()) || j < int(cur.size())) {
        if (i < int(pr.size()) && j < int(cur.size()) &&
                                         pr[i] == cur[j]) {
            ++i;
            ++j;
            continue;
        }
        if (j == int(cur.size()) ||
                    (i < int(pr.size()) && j < int(cur.size()) &&
                                                    pr[i] < cur[j])) {
            ok.insert(M[pr[i]]);
            ++i;
        } else {
            ncols.pb(cur[j]);
            ++j;
        }
    }
    forn (i, ncols.size()) {
        M[ncols[i]] = *ok.begin();
        ok.erase(ok.begin());
    }
    forn (i, g[v].size()) {
        int to = g[v][i];
        if (to == p) {
            continue;
        }
        dfs(to, v);
    }
    forn (i, ncols.size()) {
        ok.insert(M[ncols[i]]);
    }
    i = j = 0;
    while (i < int(pr.size()) || j < int(cur.size())) {
        if (i < int(pr.size()) && j < int(cur.size()) &&
                                         pr[i] == cur[j]) {
            ++i;
            ++j;
            continue;
        }
        if (j == int(cur.size()) ||
                    (i < int(pr.size()) && j < int(cur.size()) &&
                                                    pr[i] < cur[j])) {
            ok.erase(M[pr[i]]);
            ++i;
        } else {
            ++j;
        }
    }
}

int main() {
    int n, m, ans = 0;
    scanf("%d%d", &n, &m);
    forn (i, n) {
        int sz;
        scanf("%d", &sz);
        ans = max(ans, sz);
        forn (j, sz) {
            int x;
            scanf("%d", &x);
            s[i].pb(x - 1);
        }
        sort(s[i].begin(), s[i].end());
    }
    forn (i, n - 1) {
        int a, b;
        scanf("%d%d", &a, &b);
        --a;
        --b;
        g[a].pb(b);
        g[b].pb(a);
    }
    forn (i, ans) {
        ok.insert(i + 1);
    }
    dfs(0);
    if (ans == 0) {
        ans = 1;
    }
    forn (i, m) {
        M[i] = M[i] ? M[i] : 1;
    }
    printf("%d\n", ans);
    forn (i, m) {
        printf("%d ", M[i]);
    }
    printf("\n");
    return 0;
}