#include <algorithm>
#include <cassert>
#include <cstdlib>
#include <complex>
#include <cstring>
#include <memory>
#include <string>
#include <vector>
#include <cstdio>
#include <ctime>
#include <set>
#include <iostream>

using namespace std;

#define fs first
#define sc second
#define forn(i, n) for (int i = 0; i < (int)(n); ++i)
#define pb push_back
#define mp make_pair

typedef unsigned int uint;

const int mod = 1000000007;

int a[200100], b[200100], p[200100];
set<pair<int, int> > s[3];

int main() {
    ios::sync_with_stdio(false);
    int n;
    cin >> n;
    forn (i, n) {
        cin >> p[i];
    }
    forn (i, n) {
        cin >> a[i];
        --a[i];
    }
    forn (i, n) {
        cin >> b[i];
        --b[i];
    }
    forn (i, n) {
        s[a[i]].insert(mp(p[i], i));
        s[b[i]].insert(mp(p[i], i));
    }
    int m;
    cin >> m;
    forn (i, m) {
        int c;
        cin >> c;
        --c;
        if (s[c].size() == 0) {
            cout << -1 << " ";
            continue;
        }
        int id = s[c].begin()->sc;
        s[a[id]].erase(mp(p[id], id));
        s[b[id]].erase(mp(p[id], id));
        cout << p[id] << " ";
    }
    cout << endl;
    return 0;
}