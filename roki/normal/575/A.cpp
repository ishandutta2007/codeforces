#include <iostream>
#include <fstream>
#include <sstream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cassert>
#include <ctime>
#include <cstring>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <deque>
#include <list>
#include <stack>
#include <bitset>
#include <algorithm>
#include <iomanip>

#include<bits/stdc++.h>

using namespace std;

#define forn(i,n) for (int i = 0; i < int(n); i++)
#define ford(i,n) for (int i = int(n) - 1; i >= 0; i--)
#define fore(i,l,r) for (int i = int(l); i <= int(r); i++)
#define all(a) a.begin(), a.end()
#define sz(a) int(a.size())
#define mp make_pair
#define pb push_back
#define ft first
#define sc second
#define x first
#define y second

template<typename X> inline X abs(const X& a) { return a < 0 ? -a : a; }
template<typename X> inline X sqr(const X& a) { return a * a; }

typedef long long li;
typedef long double ld;
typedef pair<li, int> pt;

const int INF = int(1e9);
const li INF64 = li(1e18);
const ld EPS = 1e-9;
const ld PI = acosl(ld(-1));

const int N = 50000 + 5;
int a[N];
li k, MOD;
int n;
int m;
pt p[N];

inline bool read()
{
    cin >> k >> MOD;
    cin >> n;
    forn (i, n)
        cin >> a[i];
    cin >> m;
    forn (i, m)
        cin >> p[i].ft >> p[i].sc;
    return true;
}

struct matrix {
    li a[4];
};

matrix create(int a = 0, int b = 0, int c = 0, int d = 0) {
    matrix res;
    res.a[0] = a, res.a[1] = b, res.a[2] = c, res.a[3] = d;
    return res;
}

int to[N][61];
matrix r[N][61];

matrix mul(matrix &a, matrix &b) {
    matrix c = a;
    forn (i, 2)
        forn (j, 2) { 
            li t = 0;
            forn (k, 2)
                t += li(a.a[i * 2 + k]) * li(b.a[k * 2 + j]);
            c.a[i * 2 + j] = t % MOD;
        }
    return c;
}

void go(int &pos, li len, matrix &cur) {
    forn (i, 61)
        if (len & (1LL << i)) {
            cur = mul(cur, r[pos][i]);
            pos = to[pos][i];
        }
}

li naive() {
    vector<int> c(k + 1);
    forn (i, k + 1)
        c[i] = a[i % n];
    forn (i, m)
        if (p[i].ft <= sz(c))
            c[p[i].ft] = p[i].sc;

    forn (i, sz(c))
        cerr << c[i] << ' ';
    cerr << endl;
            
    li A = 1, B = 0;
    forn (i, k - 1) {
        int x = i + 1, y = i;
        int ca = c[x], cb = c[y];
        li na = (li(A) * ca + li(B) * cb) % MOD; 
        B = A;
        A = na;
    }
    return A;
}

bool bad(li pos) {
    int x = lower_bound(p, p + m, mp(pos, -1)) - p;
    if (x == m || p[x].ft != pos)
        return false;
    return true;
}

int getval(li pos) {
    int x = lower_bound(p, p + m, mp(pos, -1)) - p;
    if (x == m || p[x].ft != pos)
        return a[pos % n];
    return p[x].sc;
}

inline void solve()
{
    if (k == 0) {
        cout << 0 << endl;
        return;
    }
    if (k == 1) {
        cout << 1 % MOD << endl;
        return;
    }
    
    forn (i, n) {
        r[i][0] = create(a[(i - 1 + n) % n], 1, a[(i - 2 + n) % n]);
        to[i][0] = (i + 1) % n;
    }
    for (int it = 1; it < 61; ++it) {
        forn (i, n) {
            r[i][it] = mul(r[i][it - 1], r[to[i][it - 1]][it - 1]);
            to[i][it] = to[ to[i][it - 1] ][it - 1];
        }
    }
    
    //li right = naive();
    
    sort(p, p + m);
    
    int pos = 2 % n;
    li it = 0;
    k--;
    matrix cur = create(1, 0, 0, 1);

    while (k) {
        while(k && (bad(it) || bad(it + 1))) {
            k--;
            pos = (pos + 1) % n;
            matrix tmp = create(getval(it + 1), 1, getval(it));
            it++;
            cur = mul(cur, tmp);            
        }
        if (k) {
            int x = lower_bound(p, p + m, mp(it, 0)) - p;
            li  len = x == m ? INF64 : p[x].ft - it - 1;
            li need = min(len, k);
            go(pos, need, cur);
            it += need;
            k -= need;
        }
    }
        
    cout << cur.a[0] << endl;
}

int main()
{
#ifdef SU2_PROJ
    assert(freopen("input.txt", "r", stdin));
    assert(freopen("output.txt", "w", stdout));
#endif

    cout << setprecision(25) << fixed;
    cerr << setprecision(10) << fixed;

    srand(int(time(NULL)));

    assert(read());
    solve();

#ifdef SU2_PROJ
    cerr << "TIME: " << clock() << endl;
#endif

    return 0;
}