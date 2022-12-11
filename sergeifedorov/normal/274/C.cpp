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
#define x first
#define y second
#define last(a) int(a.size() - 1)
#define all(a) a.begin(), a.end()
#define seta(a,x) memset (a, x, sizeof (a))
#define I (int)

typedef long long int64;
typedef double ldb;
typedef pair <ldb, ldb> pii;

const long double eps = 1e-9;
const int inf = (1 << 30) - 1;
const int64 inf64 = ((int64)1 << 62) - 1;
const long double pi = 3.1415926535897932384626433832795;

template <class T> T sqr (T x) {return x * x;}
template <class T> T abs (T x) {return x < 0 ? -x : x;}

const int nmax = 110;

int n;
pii p[nmax];
vector<int> g[nmax];
int used[nmax];

pii operator + (pii a, pii b) {
    return pii(a.x + b.x, a.y + b.y);
}

pii operator - (pii a, pii b) {
    return pii(a.x - b.x, a.y - b.y);
}

pii operator * (pii a, double b) {
    return pii(a.x * b, a.y * b);
}

pii operator / (pii a, double b) {
    return pii(a.x / b, a.y / b);
}


struct line {
    ldb a, b, c;
    line () {};
    line (pii v, pii u) {
        a = u.y - v.y;
        b = v.x - u.x;
        c = - v.x * a - v.y * b;
    }
};

ldb side(line l, pii v) {
    return l.a * v.x + l.b * v.y + l.c;
}

ldb dist(pii a, pii b) {
    return sqrt(sqr(a.x - b.x) + sqr(a.y - b.y));
}

inline double det(double a, double b, double c, double d) {
    return a * d - b * c;
}

bool cross(line l1, line l2, pii &res) {
    double o = det(l1.a, l1.b, l2.a, l2.b);
    double ox = det(-l1.c, l1.b, -l2.c, l2.b);
    double oy = det(l1.a, -l1.c, l2.a, -l2.c);
    if (fabs(o) < eps) return 0;
    res = mp(ox / o, oy / o);
    return 1;
}

line getb(pii a, pii b) {
    pii m = (a + b) / 2;
    pii e = a - m;
    swap(e.x, e.y);
    e.x *= -1;
    return line(m, m + e);
}

ldb smul(pii a, pii b) {
    return a.x * b.x + a.y * b.y;
}

pii get(pii a, pii b, pii c) {
    if (smul(b - a, c - a) < eps) return a;
    if (smul(a - b, c - b) < eps) return a;
    if (smul(b - c, a - c) < eps) return a;
    line l1 = getb(a, b);
    line l2 = getb(a, c);
    pii res = a;
    if (cross(l1, l2, res)) return res;
    else return a;
}

double res;

void update(pii now, double cur) {
    if (cur < res) return;
    forn(l, n) 
        if (dist(now, p[l]) < cur - eps) return;
    res = max(res, cur);
}

void no() {
    puts("-1");
    exit(0);
}

bool dfs(int v, int pr) {
    used[v] = 1;
    forn(i, g[v].size()) {
        if (used[g[v][i]] == 1 && g[v][i] != pr)
            return 1;
        if (!used[g[v][i]] && dfs(g[v][i], v))
            return 1;
    }
    used[v] = 2;
    return 0;
}

bool check(double res) {
    memset(used, 0, sizeof used);
    forn(i, n) {
        g[i].clear();
        forn(j, n)
            if (dist(p[i], p[j]) < res * 2 && i != j) {
                g[i].pb(j);
            }
    }
    forn(i, n)
        if (used[i] == 0)
            if (dfs(i, -1)) return 1;
    return 0;
}

void go(int v) {
    used[v] = 1;
    forn(i, g[v].size())
        if (!used[g[v][i]])
            go(g[v][i]);
}

ldb vmul(pii a, pii b) {
    return a.x * b.y - a.y * b.x;
}

bool go(int v, int u, double l, int sz) {
    forn(i, n) {
        g[i].clear();
        if (vmul(p[u] - p[v], p[i] - p[v]) * sz < -eps) continue;
        forn(j, n) {
            if (vmul(p[u] - p[v], p[j] - p[v]) * sz < -eps) continue;
            if (dist(p[i], p[j]) < 2 * l)
                g[i].pb(j);
        }
    }
    memset(used, 0, sizeof used);
    go(v);
    if (!used[u]) return 0;
    return 1;
} 

int main ()
{
//  freopen("input.txt", "rt", stdin);
//  freopen("output.txt", "wt", stdout);

    cin >> n;
    forn(i, n)
        cin >> p[i].x >> p[i].y;

/*  n = 100;
    forn(i, n) {
        p[i].x = rand();
        p[i].y = rand();
    }*/

    {
        if (n <= 2) no();
        line l(p[0], p[1]);
        bool done = 1;
        forn(i, n)
            if (side(l, p[i]) > eps)
                done = 0;
        if (done) no();
    }
    res = -1;
    forn(i, n)
        forn(j, i) {
            pii now = (p[i] + p[j]) * 0.5;
            double cur = 1e9;
            forn(q, n)
                cur = min(cur, dist(now, p[q]));
            if (go(i, j, cur - (1e-4), -1) && go(i, j, cur - (1e-4), 1))
                update(now, dist(p[i], now));
        } 
    forn(i, n)
        forn(j, i)
            forn(k, j) {
                pii now = get(p[i], p[j], p[k]);
                double cur = dist(now, p[i]);
                if (cur < res) continue;
                update(now, cur);
            }
    if (!check(res - 1e-3))
        no();
    printf("%0.9lf\n", res);

    return 0;
}