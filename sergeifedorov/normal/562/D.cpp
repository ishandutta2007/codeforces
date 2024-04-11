#ifdef blabla
#define _GLIBCXX_DEBUG
#endif

#include <cstdio>
#include <cstdlib>
#include <iostream>

#include <vector>
#include <string>
#include <cstring>
#include <map>
#include <set>
#include <queue>
#include <bitset>
#include <algorithm>
#include <cmath>

using namespace std;

#define forn(i, n) for (int i = 0; i < (int)(n); i ++)
#define ford(i, n) for (int i = (int)(n) - 1; i >= 0; i--)
#define pb push_back
#define mp make_pair
#define fs first
#define sc second
#define all(a) a.begin(), a.end()
#define sqr(a) ((a)*(a))

const int NMAX = 1000000;

int Root(int c[NMAX], int v) {
    return c[v] == v ? v : (c[v] = Root(c, c[v]));
}

bool Join(int c[NMAX], int v, int u) {
    v = Root(c, v);
    u = Root(c, u);
    if (v == u)
        return false;
    if (rand() & 1)
        swap(v, u);
    c[v] = u;
    return true;
}

int c[NMAX], r[NMAX], n, m;

void Init(int x[NMAX]) {
    forn(i, NMAX)
        x[i] = i;
}

int main() {
#ifdef blabla
    freopen("input.txt", "rt", stdin);
//  freopen("output.txt", "wt", stdout);
#endif

    cin >> n >> m;

    Init(c);
    Init(r);

    forn(i, m) {
        int t, x, y;
        scanf("%d %d %d", &t, &x, &y);
        x--, y--;
        if (t == 1) {
            Join(c, x, y);
            continue;
        }
        if (t == 2) {
            int j = x;
            while(true) {
                int nj = Root(r, j) + 1;
                if (nj > y)
                    break;
                r[nj - 1] = nj;
                Join(c, nj - 1, nj);
                j = nj;
            }
            continue;
        }
        x = Root(c, x);
        y = Root(c, y);
        if (x == y)
            puts("YES");
        else
            puts("NO");

    }

    return 0;
}