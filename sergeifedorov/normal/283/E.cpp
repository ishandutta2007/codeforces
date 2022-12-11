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

const int nmax = 1 << 17;

int n, k;
int a[nmax];
int t[nmax * 2][2];
int upd[nmax * 2];
vector<pair<int, pii> > e;

void push(int v) {
    if (!upd[v] || v > nmax) return;
    upd[v] = 0;
    upd[v*2] ^= 1;
    upd[v*2+1] ^= 1;
    swap(t[v*2][0], t[v*2][1]);
    swap(t[v*2+1][0], t[v*2+1][1]);
}

void build(int v, int l, int r) {
    t[v][0] = r - l + 1;
    t[v][1] = 0;
    if (r == l) return;
    int m = (l + r) / 2;
    build(v * 2, l, m);
    build(v * 2 + 1, m + 1, r);
}

void update(int v, int l, int r, int l1, int r1) {
    push(v);
    if (l > r1 || r < l1) return;
    if (l1 <= l && r <= r1) {
        swap(t[v][0], t[v][1]);
        upd[v] = 1;
        return;
    }
    int m = (l + r) / 2;
    update(v * 2, l, m, l1, r1);
    update(v * 2 + 1, m + 1, r, l1, r1);
    forn(i, 2)
        t[v][i] = t[v*2][i] + t[v*2+1][i];
}

int get(int v, int l, int r, int l1, int r1, int c) {
    push(v);
    if (l > r1 || r < l1) return 0;
    if (l1 <= l && r <= r1) return t[v][c];
    int m = (l + r) / 2;
    return get(v * 2, l, m, l1, r1, c) + get(v * 2 + 1, m + 1, r, l1, r1, c);
}

int main ()
{
//  freopen("input.txt", "rt", stdin);
//  freopen("output.txt", "wt", stdout);

    cin >> n >> k;
    forn(i, n)
        scanf("%d", &a[i]); 
    sort(a, a + n);
    forn(i, k) {
        int l, r;
        scanf("%d %d", &l, &r);
        l = lower_bound(a, a + n, l) - a + 1;
        r = lower_bound(a, a + n, r + 1) - a;
        e.pb(mp(l, mp(l, r)));
        e.pb(mp(r+1, mp(l, r)));
    }
    sort(all(e));
    int p = 0;

    int64 res = 1ll * n * (n - 1) * (n - 2) / 6;

    build(1, 1, nmax);

    forn(i, n) {
        while (p < e.size() && e[p].fs <= i + 1) {
            update(1, 1, nmax, e[p].sc.fs, e[p].sc.sc);
            p ++;
        }
        int64 now = get(1, 1, nmax, 1, i, 0) + get(1, 1, nmax, i + 2, n, 1);
        res = res - now * (now - 1) / 2;
    }
    cout << res << endl;


    return 0;
}