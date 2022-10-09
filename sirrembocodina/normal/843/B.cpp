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

typedef long long ll;

const int mod = 1000000007;
const int q_sz = 1000;

vector<int> q;
bool was[50100];

int main() {
    ios::sync_with_stdio(false);
    int n, st, x;
    cin >> n >> st >> x;
    --st;
    forn (i, min(q_sz, n)) {
        int x = (ll(rand()) * rand() + rand()) % (n - i);
        forn (j, n) {
            if (was[j]) {
                continue;
            }
            if (x == 0) {
                was[j] = true;
                q.pb(j);
                break;
            }
            --x;
        }
    }
    vector<pair<int, pair<int, int> > > a;
    forn (i, q.size()) {
        cout << "? " << q[i] + 1 << endl;
        cout.flush();
        int X, Y;
        cin >> X >> Y;
        a.pb(mp(X, mp(q[i], Y - 1)));
    }
    sort(a.begin(), a.end());
    int mx = -1, nxt = st, ans = -1;
    forn (i, a.size()) {
        if (a[i].fs < x) {
            mx = a[i].sc.fs;
            nxt = a[i].sc.sc;
            ans = a[i].fs;
        }
    }
    forn (i, 1999 - a.size()) {
        if (nxt == -2) {
            break;
        }
        cout << "? " << nxt + 1 << endl;
        cout.flush();
        int X, Y;
        cin >> X >> Y;
        if (X >= x) {
            cout << "! " << X << endl;
            cout.flush();
            return 0;
        }
        nxt = Y - 1;
    }
    cout << "! -1" << endl;
    cout.flush();
    return 0;
}