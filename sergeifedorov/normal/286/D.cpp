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
typedef pair <int64, int64> pii;
typedef long double ldb;

const long double eps = 1e-9;
const int inf = (1 << 30) - 1;
const int64 inf64 = ((int64)1 << 62) - 1;
const long double pi = 3.1415926535897932384626433832795;

template <class T> T sqr (T x) {return x * x;}
template <class T> T abs (T x) {return x < 0 ? -x : x;}

const int nmax = 200100;

int l[nmax], r[nmax], t[nmax];
int n, m;
multiset<int> h;
vector<pii> e;

void pre_calc() {
    vector<pii> now;
    forn(i, m) {
        now.pb(mp(l[i], -t[i]));    
        now.pb(mp(r[i], t[i]));
    }
    sort(all(now));
    m = 0;
    forn(i, now.size() - 1) {
        if (now[i].sc < 0)
            h.insert(-now[i].sc);
        else
            h.erase(h.find(now[i].sc));
        if (now[i+1].fs > now[i].fs && h.size() > 0) {
            l[m] = now[i].fs;
            r[m] = now[i+1].fs;
            t[m] = *h.begin();
            m ++;
        }
    }
    forn(i, m)
        e.pb(mp(t[i] - r[i], t[i] - l[i]));
    sort(all(e));
}

multiset<pii> buf;

int main ()
{
//  freopen("input.txt", "rt", stdin);
//  freopen("output.txt", "wt", stdout);

    cin >> n >> m;
    forn(i, m) {
        scanf("%d %d %d", &l[i], &r[i], &t[i]);
        t[i] ++;
    }
    pre_calc();
    int64 p2, sum, s, q;
    p2 = sum = s = 0;
    forn(i, n) {
        scanf("%I64d", &q);
        q ++;
        while (p2 < e.size() && e[p2].fs <= q) {
            s += e[p2].fs;
            buf.insert(mp(e[p2].sc, e[p2].fs));
            p2 ++;
        }
        while (buf.size() > 0 && buf.begin()->fs <= q) {
            s -= buf.begin()->sc;
            sum += buf.begin()->fs - buf.begin()->sc;
            buf.erase(buf.begin());
        }
        int64 res = sum + q * buf.size() - s;
        printf("%I64d\n", res);
    }

    return 0;
}