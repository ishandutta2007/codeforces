#include <iostream>
#include <algorithm>
#include <cstdio>
#include <vector>
#include <string>
#include <cstring>
#include <map>
#include <set>
#include <ctime>

using namespace std;

#define forn(i, n) for (int i = 0; i < (int)(n); ++i)
#define pb push_back
#define mp make_pair
#define fs first
#define sc second

typedef long long ll;
typedef long double ld;

int mod = 1000000007;

vector<pair<pair<int, int>, pair<int, int> > > e;
int E[500100][3];
int p[500100];
int sz[500100];
bool ok[500100];
vector<pair<int, int> > c_p;
vector<pair<int, int> > c_sz;
map<int, vector<pair<int, int> > > M;

int pr(int v) {
    if (v == p[v]) {
        return v;
    }
    c_p.pb(mp(v, p[v]));
    return p[v] = pr(p[v]);
}

void unite(int a, int b) {
    a = pr(a);
    b = pr(b);
    if (a == b) {
        return;
    }
    if (sz[a] < sz[b]) {
        swap(a, b);
    }
    c_p.pb(mp(b, p[b]));
    p[b] = a;
    c_sz.pb(mp(a, sz[a]));
    sz[a] += sz[b];
}

int main() {
    ios::sync_with_stdio(false);
    int n, m;
    cin >> n >> m;
    forn (i, n) {
        p[i] = i;
        sz[i] = 1;
    }
    forn (i, m) {
        int a, b, c;
        cin >> a >> b >> c;
        --a;
        --b;
        E[i][0] = a;
        E[i][1] = b;
        E[i][2] = c;
        e.pb(mp(mp(c, e.size()), mp(a, b)));
    }
    int q;
    cin >> q;
    forn (Q, q) {
        ok[Q] = true;
        int k;
        cin >> k;
        forn (i, k) {
            int x;
            cin >> x;
            --x;
            M[E[x][2]].pb(mp(Q, x));
        }
    }
    sort(e.begin(), e.end());
    forn (i, m) {
        if (i && e[i].fs.fs == e[i - 1].fs.fs) {
            unite(e[i].sc.fs, e[i].sc.sc);
            continue;
        }
        vector<pair<int, int> > &q = M[e[i].fs.fs];
        forn (j, q.size()) {
            if (j && q[j].fs == q[j - 1].fs) {
                continue;
            }
            int p_sz = c_p.size();
            int sz_sz = c_sz.size();
            for (int k = j; k < q.size(); ++k) {
                if (q[k].fs != q[j].fs) {
                    break;
                }
                int a = E[q[k].sc][0], b = E[q[k].sc][1];
                if (pr(a) == pr(b)) {
                    ok[q[k].fs] = false;
                }
                unite(a, b);
            }
            while (c_p.size() > p_sz) {
                p[c_p.back().fs] = c_p.back().sc;
                c_p.pop_back();
            }
            while (c_sz.size() > sz_sz) {
                sz[c_sz.back().fs] = c_sz.back().sc;
                c_sz.pop_back();
            }
        }
        unite(e[i].sc.fs, e[i].sc.sc);
    }
    forn (i, q) {
        cout << (ok[i] ? "YES\n" : "NO\n");
    }
    return 0;
}