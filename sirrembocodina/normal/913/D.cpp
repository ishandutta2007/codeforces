#include <iostream>
#include <algorithm>
#include <cstdio>
#include <vector>
#include <string>
#include <set>
#include <map>

using namespace std;

#define forn(i, n) for (ll i = 0; i < (ll)(n); ++i)
#define pb push_back
#define mp make_pair
#define fs first
#define sc second

typedef long long ll;

ll mod = 1000000007;

vector<pair<int, int> > t[200100];

int main() {
    ios::sync_with_stdio(false);
    int n, x;
    cin >> n >> x;
    forn (i, n) {
        int a, b;
        cin >> a >> b;
        t[a].pb(mp(b, i));
    }
    int l = 1, r = n + 1;
    while (r - l > 1) {
        int m = (l + r) / 2;
        vector<int> y;
        for (int i = m; i <= n; ++i) {
            forn (j, t[i].size()) {
                y.pb(t[i][j].fs);
            }
        }
        sort(y.begin(), y.end());
        int sum = 0;
        int res = 0;
        forn (i, y.size()) {
            sum += y[i];
            if (sum > x) {
                break;
            }
            ++res;
        }
        if (res >= m) {
            l = m;
        } else {
            r = m;
        }
    }
    vector<pair<int, int> > y;
    for (int i = l; i <= n; ++i) {
        forn (j, t[i].size()) {
            y.pb(t[i][j]);
        }
    }
    sort(y.begin(), y.end());
    int sum = 0;
    int res = 0;
    forn (i, y.size()) {
        sum += y[i].fs;
        if (sum > x) {
            break;
        }
        ++res;
    }
    res = min(res, l);
    cout << res << "\n" << res << endl;
    forn (i, res) {
        cout << y[i].sc + 1 << " ";
    }
    cout << endl;
    return 0;
}