#include <iostream>
#include <algorithm>
#include <cstdio>
#include <vector>
#include <string>
#include <set>

using namespace std;

#define forn(i, n) for (int i = 0; i < (int)(n); ++i)
#define pb push_back
#define mp make_pair
#define fs first
#define sc second

typedef long long ll;

int mod = 1000000007;

int a[110][110];

int main() {
    ios::sync_with_stdio(false);
    int n, m;
    cin >> n >> m;
    forn (i, n) {
        forn (j, m) {
            cin >> a[i][j];
        }
    }
    vector<pair<int, bool> > ans;
    if (n < m) {
        forn (i, n) {
            bool ok = true;
            forn (j, m) {
                if (!a[i][j]) {
                    ok = false;
                }
            }
            if (!ok) {
                continue;
            }
            ans.pb(mp(i, 0));
            forn (j, m) {
                --a[i][j];
            }
            --i;
        }
        forn (j, m) {
            bool ok = true;
            forn (i, n) {
                if (!a[i][j]) {
                    ok = false;
                }
            }
            if (!ok) {
                continue;
            }
            ans.pb(mp(j, 1));
            forn (i, n) {
                --a[i][j];
            }
            --j;
        }
    } else {
        forn (j, m) {
            bool ok = true;
            forn (i, n) {
                if (!a[i][j]) {
                    ok = false;
                }
            }
            if (!ok) {
                continue;
            }
            ans.pb(mp(j, 1));
            forn (i, n) {
                --a[i][j];
            }
            --j;
        }
        forn (i, n) {
            bool ok = true;
            forn (j, m) {
                if (!a[i][j]) {
                    ok = false;
                }
            }
            if (!ok) {
                continue;
            }
            ans.pb(mp(i, 0));
            forn (j, m) {
                --a[i][j];
            }
            --i;
        }
    }
    bool ok = true;
    forn (i, n) {
        forn (j, m) {
            if (a[i][j]) {
                ok = false;
            }
        }
    }
    if (!ok) {
        cout << -1 << endl;
        return 0;
    }
    cout << ans.size() << endl;
    forn (i, ans.size()) {
        if (!ans[i].sc) {
            cout << "row ";
        } else {
            cout << "col ";
        }
        cout << ans[i].fs + 1 << endl;
    }
    return 0;
}