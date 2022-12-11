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

const int nmax = 600;
const int emax = 10100;

int n, m, nm, k;
int a[emax], b[emax], id[emax], us[emax];
int p[nmax];
int cnt;

int get(int x) {
    if (p[x] == x) return x;
    return p[x] = get(p[x]);
}

void add(int x, int y) {
    x = get(x);
    y = get(y);
    if (x == y) return;
    cnt --;
    if (rand() & 1)
        p[x] = y;
    else
        p[y] = x;
}

void init() {
    cnt = n;
    forn(i, n)
        p[i] = i;
}

void solve() {
    int l, r;
    scanf("%d %d", &l, &r);
    l --; r--;
    init();
    forn(j, nm)
        if (id[j] < l || id[j] > r)
            add(a[j], b[j]);
    printf("%d\n", cnt);
}

int main ()
{
//  freopen("input.txt", "rt", stdin);
//  freopen("output.txt", "wt", stdout);

    cin >> n >> m;
    forn(i, m) {
        scanf("%d %d", &a[i], &b[i]);   
        a[i] --; b[i] --;
    }

    memset(us, 0, sizeof us);
    init();
    forn(i, m) {
        if (get(a[i]) != get(b[i])) 
            us[i] = 1;
        add(a[i], b[i]);
    }
    init();
    ford(i, m) {
        if (get(a[i]) != get(b[i])) 
            us[i] = 1;
        add(a[i], b[i]);
    }
    nm = 0;
    forn(i, m) {
        if (us[i]) {
            a[nm] = a[i];
            b[nm] = b[i];
            id[nm] = i;
            nm ++;
        }
    }
    cin >> k;
    forn(i, k)
        solve();

        

    return 0;
}