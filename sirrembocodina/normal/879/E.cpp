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

int a[50100][12];
//int num[50100];
//set<pair<int, int> >::iterator wh[50100];
set<pair<int, unsigned short int> > s[12];
set<pair<int, unsigned short int> > S;
int p[50100];
int sz[50100];

int pr(int v) {
    if (v == p[v]) {
        return v;
    }
    p[v] = pr(p[v]);
    return p[v];
}

void unite(int x, int y) {
    x = pr(x);
    y = pr(y);
    if (x == y) {
        return;
    }
    if (sz[x] < sz[y]) {
        swap(x, y);
    }
    sz[x] += sz[y];
    p[y] = x;
}

void add_edge(int i, int j) {
//    swap(i, j);
    i = pr(i);
    j = pr(j);
    if (a[i][0] <= a[j][0]) {
        return;
    }
    set<pair<int, unsigned short int> >::iterator it1 = S.find(mp(a[j][0], j));
    set<pair<int, unsigned short int> >::iterator it2 = S.find(mp(a[i][0], i));
//    cerr << j << " " << i << endl;
    vector<int> path;
    for (; it1 != it2; it1++) {
        path.pb(it1->sc);
    }
//    for (auto x: S) {
//        cerr << (x.sc) << "_";
//    }
//    cerr << endl;
    forn (k, path.size()) {
        int cur = path[k];
        unite(cur, i);
        S.erase(S.find(mp(a[cur][0], cur)));
    }
    S.erase(S.find(mp(a[i][0], i)));
    i = pr(i);
    S.insert(mp(a[i][0], i));
//    for (auto x: S) {
//        cerr << (x.sc) << "_";
//    }
//    cerr << "!";
//    cerr << "!";
}

int main() {
    ios::sync_with_stdio(false);
    int n, k;
    cin >> n >> k;
    forn (i, n) {
        forn (j, k) {
            cin >> a[i][j];
            a[i][j] *= -1;
        }
        p[i] = i;
        sz[i] = 1;
    }
/*    vector<pair<int, unsigned short int> > b;
    forn (i, n) {
        b.pb(mp(a[i][0], i));
    }
    sort(b.begin(), b.end());
    forn (i, n) {
        num[b[i].sc] = i;
    }*/
    forn (i, n) {
        S.insert(mp(a[i][0], i));
//        wh[i] = S.find(mp(a[i][0], i));
        forn (j, k) {
            int x = a[i][j];
            if (!i) {
                s[j].insert(mp(x, i));
                continue;
            }
            set<pair<int, unsigned short int> >::iterator it2 = s[j].lower_bound(mp(x, 0));
            set<pair<int, unsigned short int> >::iterator it1 = it2;
            if (it1 == s[j].begin()) {
                it1 = s[j].end();
            } else {
                --it1;
            }
//            cerr << "@";
            if (it1 != s[j].end()) {
                add_edge(it1->sc, i);
            }
//            cerr << "@";
            if (it2 != s[j].end()) {
                add_edge(i, it2->sc);
            }
//            cerr << "@";
            s[j].insert(mp(x, i));
        }
//        cerr << "%";
//        cout << p[p[S.begin()->sc]] << "_" << endl;
        cout << sz[pr(S.begin()->sc)] << endl;
//        cerr << "%";
    }
    return 0;
}