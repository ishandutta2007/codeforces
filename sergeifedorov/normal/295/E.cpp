#include <cstdio>
#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <string>
#include <set>
#include <map>
#include <ctime>
#include <cstring>
#include <cassert>
#include <bitset>
#include <sstream>
#include <queue>

using namespace std;

#define forn(i, n) for(int i = 0; i < (int)(n); i++)
#define ford(i, n) for(int i = (int)(n) - 1; i >= 0; i--)
#define pb push_back
#define mp make_pair
#define fs first
#define sc second
#define last(a) int(a.size() - 1)
#define all(a) a.begin(), a.end()
#define seta(a,x) memset (a, x, sizeof (a))
#define I (int)

typedef long long int64;
typedef pair <int, int> pii;
typedef long double ldb;

const long double eps = 1e-9;
const int inf = (1 << 30) - 1;
const int64 inf64 = ((int64)1 << 62) - 1;
const long double pi = 3.1415926535897932384626433832795;

template <class T> T sqr (T x) {return x * x;}
template <class T> T abs (T x) {return x < 0 ? -x : x;}

const int nmax =  524288;

struct rec {
    int64 s, sl, sr;
    int n;

    void init() {
        n = s = sl = sr = 0;
     }

    rec () {
        init();
    }

    rec(int x) {
        n = 1;
        s = sl = sr = x;
    }

    int64 get() {
        return sl - sr;
    }
};

rec merge(rec a, rec b) {
    rec res;
    res.n = a.n + b.n;
    res.s = a.s + b.s;
    res.sl = a.sl + b.sl + b.s * a.n;
    res.sr = a.sr + b.sr + a.s * b.n;
    return res;
}

int n, m;
vector<int> dx;
int x[nmax], st[nmax];
int p[nmax], d[nmax], l[nmax], r[nmax], tip[nmax];

rec t[nmax * 2];

void update(int v, int l, int r, int x, int c) {
    if (l > x || r < x) return;
    if (l == r) {
        if (c == -1)
            t[v].init();
        else
            t[v] = rec(dx[x-1]);
        return;
    }
    int m = (l + r) / 2;
    update(v * 2, l, m, x, c);
    update(v * 2 + 1, m + 1, r, x, c);
    t[v] = merge(t[v * 2], t[v*2+1]);
}

rec get(int v, int l, int r, int l1, int r1) {
    rec res; res.init();
    if (l > r1 || r < l1) return res;
    if (l1 <= l && r <= r1) 
        return t[v];
    int m = (l + r) / 2;
    return merge(get(v * 2, l, m, l1, r1), get(v * 2 + 1, m + 1, r, l1, r1));
}

int getPos(int x) {
    return lower_bound(all(dx), x) - dx.begin() + 1;
}

int main ()
{
//  freopen("input.txt", "rt", stdin);
//  freopen("output.txt", "wt", stdout);

    cin >> n;
    forn(i, n) {
        scanf("%d", &x[i]);
        st[i] = x[i];
    }
    cin >> m;       
    forn(i, m) {
        scanf("%d", &tip[i]);
        if (tip[i] == 1) {
            scanf("%d %d", &p[i], &d[i]);
            p[i] --;
        } else
            scanf("%d %d", &l[i], &r[i]);
    }

    {
        forn(i, n) dx.pb(x[i]);
        forn(i, m) {
            if (tip[i] == 1) {
                x[p[i]] += d[i];
                dx.pb(x[p[i]]);
            } else {
                dx.pb(l[i]);
                dx.pb(r[i]);
            }
        }
        sort(all(dx));
        dx.erase(unique(all(dx)), dx.end());
    }

    forn(i, n) {
        x[i] = st[i];
        update(1, 1, nmax, getPos(x[i]), 1);
    }

    forn(i, m) {
        if (tip[i] == 1) {
            update(1, 1, nmax, getPos(x[p[i]]), -1);
            x[p[i]] += d[i];
            update(1, 1, nmax, getPos(x[p[i]]), 1);
        } else {
            rec now = get(1, 1, nmax, getPos(l[i]), getPos(r[i]));
            int64 res = now.get();
            cout << res << endl;
        }
    }

    return 0;
}