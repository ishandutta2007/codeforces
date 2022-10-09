#include "bits/stdc++.h"

#define int long long
#define forn(i, n) for (int i = 0; i < (int)(n); ++i)
#define sqr(x) (x) * (x)

using namespace std;

vector<int> a, b, c;

int ans(int i, int j, int k) {
    return sqr(a[i] - b[j]) + sqr(a[i] - c[k]) + sqr(b[j] - c[k]);
}

int32_t main() {
    ios_base::sync_with_stdio(0);
    int t;
    cin >> t;
    forn (q, t) {
        int na, nb, nc;
        cin >> na >> nb >> nc;
        a.resize(na);
        b.resize(nb);
        c.resize(nc);
        forn (i, na) {
            cin >> a[i];
        }
        forn (i, nb) {
            cin >> b[i];
        }
        forn (i, nc) {
            cin >> c[i];
        }
        sort(a.begin(), a.end());
        sort(b.begin(), b.end());
        sort(c.begin(), c.end());
        int i = 0, j = 0, k = 0;
        int best = 4e18;
        while (i < na && j < nb && k < nc) {
            //cerr <<a[i] << ' ' << b[j] << " " << c[k] << endl;
            best = min(best, ans(i, j, k));
            if (min(b[j], c[k]) <= a[i] && a[i] <= max(b[j], c[k])) {
                if (i + 1 < na && ans(i, j, k) >= ans(i + 1, j, k)) {
                    i++;
                    continue;
                }
            }
            if (min(a[i], c[k]) <= b[j] && b[j] <= max(a[i], c[k])) {
                if (j + 1 < nb && ans(i, j, k) >= ans(i, j + 1, k)) {
                    j++;
                    continue;
                }
            } 
            if (min(a[i], b[j]) <= c[k] && c[k] <= max(a[i], b[j])) {
                if (k + 1 < nc && ans(i, j, k) >= ans(i, j, k + 1)) {
                    k++;
                    continue;
                }
            }
            if (a[i] <= min(b[j], c[k])) {
                i++;
            } else if (b[j] <= min(a[i], c[k])) {
                j++;
            } else {
                k++;
            }
        }
        cout << best << endl;
    }
}