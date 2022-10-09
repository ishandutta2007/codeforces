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

vector<pair<pair<int, int>, int> > a[500000];
vector<pair<pair<int, int>, int> > b[500000];
int x[100100], y[100100];

int main() {
    ios::sync_with_stdio(false);
    cout.flush();
    int n, w, h;
    cin >> n >> w >> h;
    forn (i, n) {
        int g, p, t;
        cin >> g >> p >> t;
        if (g == 1) {
            x[i] = p;
            y[i] = h;
        } else {
            x[i] = w;
            y[i] = p;
        }
        a[p - t + 100000].pb(mp(mp(g, g == 1 ? -p : p), i));
        b[p - t + 100000].pb(mp(mp(-g, g == 1 ? -p : p), i));
    }
    vector<int> ans(n);
    forn (i, 500000) {
        sort(a[i].begin(), a[i].end());
        sort(b[i].begin(), b[i].end());
        forn (j, a[i].size()) {
            ans[a[i][j].sc] = b[i][j].sc;
        }
    }
    forn (i, n) {
        cout << x[ans[i]] << " " << y[ans[i]] << endl;
    }
    return 0;
}