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


struct side {
    vector<pair<int, pii> > have;
    vector<pair<int, int> > res;
    vector<pair<int, vector<pii> > > e;
    int n, len;
    bool rv;

    void add(int x, int l, int r) {
        if (l > r) swap(l, r);
        have.pb(mp(x, mp(l, r)));   
    }

    void check(vector<pii> &e, int x, int ll, int rs) {
//      cerr << ll << " " << rs << endl;
        if ((ll ^ rs) > ll) return;
        int w = (ll ^ rs);
//      cerr << w << endl;
//      forn(i, e.size())
//          cerr << e[i].fs << " " << e[i].sc << endl;
        int st = 0;
        int fin = 0;
        int now = 0;
        forn(i, e.size()) {
            if (e[i].sc - e[i].fs + now < w) {
                now += e[i].sc - e[i].fs;
                continue;
            }
            fin = e[i].fs + w - now;
            puts("FIRST");
            if (rv) {
                printf("%d %d %d %d", x, fin, x, len);
            } else {
                printf("%d %d %d %d", fin, x, len, x);
            }
            exit(0);
        }
        exit(1);
    }

    void find(int rs) {
        int cnt = n - res.size();
        if (cnt > 0) { // > 0
            int w = 1, pos = 0;
            while (pos < res.size() && res[pos].fs == w) {
                pos ++;
                w ++;
            }
            vector<pii> q;
            q.pb(mp(0, len));
            check(q, w, len, rs);
        }
        forn(i, e.size()) {
            check(e[i].sc, res[i].fs, res[i].sc, rs);
        }
    }

    void recalc() {
        sort(all(have));
        forn(i, have.size()) {
            int now = have[i].sc.fs, pos = have[i].sc.sc;
            int j = i + 1;
            vector<pii> e1;
            e1.pb(mp(0, have[i].sc.fs));
            while (j < have.size() && have[j].fs == have[i].fs) {
                int w = have[j].sc.fs;
                if (w <= pos) {
                    pos = max(pos, have[j].sc.sc);
                } else {
                    now += w - pos;
                    e1.pb(mp(pos, w));
                    pos = have[j].sc.sc;
                }
                j ++;
            }
            now += len - pos;
            e1.pb(mp(pos, len));
            e.pb(mp(have[i].fs, e1));
            res.pb(mp(have[i].fs, now));
//          cerr << have[i].fs << " " << now << endl;
            i = j - 1;
        }
    }

    int getNim() {
//      forn(i, res.size())
//          cerr << res[i].sc << " ";
//      cerr << endl;
        int nim = 0;
        int cnt = n - res.size();
//      cerr << cnt << endl;
        if (cnt & 1)
            nim ^= len;
        forn(i, res.size())
            nim ^= res[i].sc;
        return nim;
    }
};

side a, b;
int n,m, k;

int main ()
{
//  freopen("input.txt", "rt", stdin);
//  freopen("output.txt", "wt", stdout);
    
    cin >> n >> m >> k;
    a.n = n - 1; a.len = m; a.rv = 1;
    b.n = m - 1; b.len = n; b.rv = 0;
    forn(i, k) {
        int x1, y1, x2, y2;
        scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
        if (x1 == x2)
            a.add(x1, y1, y2);
        else
            b.add(y1, x1, x2);
    }

    a.recalc();
    b.recalc();
    int res = a.getNim() ^ b.getNim();
    cerr << res << endl;
    
    if (res == 0) {
        puts("SECOND");
        exit(0);
    }
    a.find(res);
    b.find(res);
    puts("SECOND");

    return 0;
}