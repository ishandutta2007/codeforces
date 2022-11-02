#include <cstdio>
#include <vector>
#include <cmath>
#include <set>
#include <map>
#include <algorithm>
#include <cstring>
#include <string>
#include <iostream>
#include <memory.h>
using namespace std;

#define forn(i, n) for (int i = 0; i < (int)(n); i++)
#define foreach(it, a) for (__typeof((a).begin()) it = (a).begin(); it != (a).end(); it++)
#define pb push_back
typedef long long ll;
typedef pair<int, int> pii;
typedef long double ld;

const int di[] = {-1, 0, 1, 0};
const int dj[] = {0, -1, 0, 1};

bool a[1510][1510];
bool u[1510][1510];
char s[1510];
int n, m, si, sj;
int cur[1510 * 5], kc, p2[1510 * 5], p[1510 * 5];
pii u2[1510 * 5];
set<pair<int, pii> > g[1510 * 5];
map<pii,int> mm;
pii coord[1510 * 5];

int getid(int i, int j) {
    pii z(i, j);
    if (mm.find(z) != mm.end()) return mm[z];
    int res = mm.size();
    coord[res] = z;
    p[res] = res;
    return mm[z] = res;
}

void dfs(int i, int j) {
    u[i][j] = true;
    if (i == 0 || j == 0 || i == n-1 || j == m-1 || (i == si && j == sj)) {
        int v = getid(i, j);
        cur[kc++] = v;
    }

    forn(q, 4) {
        int ni = i + di[q];
        int nj = j + dj[q];

        if (ni >= 0 && nj >= 0 && ni < n && nj < m && !a[ni][nj] && !u[ni][nj])
            dfs(ni, nj);
    }
}

int findset(int x) {
    return x == p[x] ? x : p[x] = findset(p[x]);
}


void link(int a, int b) {
    a = findset(a);
    b = findset(b);
    if (a == b) return;

    if (a & 1) p[a] = b;
    else p[b] = a;
}

void go(int i, int j) {
    kc = 0;
    dfs(i, j);

    forn(i, kc-1)
        link(cur[i], cur[i+1]);
}

bool dfs2(int i, pii c) {
    if (u2[i] != pii(-1, -1)) {
        return u2[i] != c;
    }
    u2[i] = c;

    foreach(it, g[i]) {
        int v = it->first;
        pii nc(c.first + it->second.first, c.second + it->second.second);
        if (dfs2(v, nc)) return true;
    }

    return false;
}

int main() {
    scanf("%d %d", &n, &m);
    forn(i, n) {
        scanf("%s", s);
        forn(j, m) {
            a[i][j] = s[j] == '#';
            if (s[j] == 'S') si = i, sj = j;
        }
    }

    forn(i, n)
        forn(j, m)
            if (!u[i][j]) go(i, j);

    set<pii> ss;
    forn(i, n) {
        if (a[i][0] || a[i][m-1]) continue;
        int u = findset(getid(i, 0));
        int v = findset(getid(i, m-1));

            g[u].insert(make_pair(v, pii(0, -1)));
            g[v].insert(make_pair(u, pii(0, 1)));
    }

    forn(j, m) {
        if (a[0][j] || a[n-1][j]) continue;
        int u = findset(getid(0, j));
        int v = findset(getid(n-1, j));

            g[u].insert(make_pair(v, pii(-1, 0)));
            g[v].insert(make_pair(u, pii(1, 0)));
    }

    forn(i, mm.size()) u2[i] = pii(-1, -1);

    if (dfs2(findset(getid(si, sj)), pii(0, 0))) printf("Yes\n");
    else printf("No\n");

    return 0;
}