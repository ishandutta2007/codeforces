#pragma comment(linker, "/STACK:100000000")
#define _CRT_SECURE_NO_DEPRECATE

#include<set>
#include<map>
#include<algorithm>
#include<cstdio>
#include<string>
#include<cstring>
#include<bitset>
#include<cmath>
#include<complex>
#include<ctime>
#include<iostream>
#include<sstream>
#include<vector>

#define next nexthui
#define prev prevhui
#define pb push_back
#define mp make_pair
#define forn(i,n) for (int i = 0; i < (int)(n); i++)
#define ford(i,n) for (int i = (int)(n)-1; i >= 0; i--)
#define fs first
#define sc second
#define all(x) x.begin(), x.end()
#define sqr(x) ((x)*(x))
#define last(x) ((int)x.size()-1)

using namespace std;

typedef long long int64;
typedef long double ldb;
typedef pair<int, int> pii;

const int INF = (1 << 30) - 1;
const int64 INF64 = (1LL << 62) - 1;
const ldb EPS = 1e-9;

const int NMAX = 1100000;

int p[NMAX];

int get(int v) {
    if (v == p[v])
        return v;

    return p[v] = get(p[v]);
}

void unite(int x, int y) {
    x = get(x);
    y = get(y);

    if (x == y)
        return;

    if ((x ^ y) & 1)
        swap(x, y);

    p[x] = y;
}

int main() {
    int n, m;
    scanf("%d%d", &n, &m);

    set<int> r;
    forn(i, n - 1)
        r.insert(i);
    forn(i, n)
        p[i] = i;

    forn(i, m) {
        int tp, x, y;
        scanf("%d%d%d", &tp, &x, &y);

        x--;
        y--;

        if (tp == 2) {
            while (true) {
                set<int>::iterator it = r.lower_bound(x);
                if (it == r.end() || *it >= y)
                    break;

                int v = *it;
                r.erase(it);

                unite(v, v + 1);
            }
        }
        else if (tp == 1) {
            unite(x, y);
        }
        else {
            bool ans = get(x) == get(y);

            puts(ans ? "YES" : "NO");
        }
    }
}