#include <iostream>
#include <algorithm>
#include <cstdio>
#include <vector>
#include <string>
#include <set>
#include <map>

using namespace std;

#define forn(i, n) for (int i = 0; i < (int)(n); ++i)
#define pb push_back
#define mp make_pair
#define fs first
#define sc second

typedef long long ll;

int mod = 1000000007;

int l[100100], e[100100];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, m, nl, ne, v;
    cin >> n >> m >> nl >> ne >> v;
    forn (i, nl) {
        cin >> l[i];
    }
    sort(l, l + nl);
    forn (i, ne) {
        cin >> e[i];
    }
    sort(e, e + ne);
    l[nl] = e[ne] = 2000000000;
    int q;
    cin >> q;
    forn (i, q) {
        int x1, y1, x2, y2;
        cin >> y1 >> x1 >> y2 >> x2;
        if (x1 > x2) {
            swap(x1, x2);
        }
        if (y1 > y2) {
            swap(y1, y2);
        }
        if (y2 == y1) {
            cout << x2 - x1 << endl;
            continue;
        }
        int ans = 2000000000;
        int i1 = lower_bound(l, l + nl, x1) - l;
        if (i1 < nl) {
            ans = min(ans, y2 - y1 + abs(l[i1] -  x1) + abs(l[i1] - x2));
        }
        --i1;
        if (i1 >= 0) {
            ans = min(ans, y2 - y1 + abs(l[i1] -  x1) + abs(l[i1] - x2));
        }
        i1 = lower_bound(e, e + ne, x1) - e;
        if (i1 < ne) {
            ans = min(ans, (y2 - y1 + v - 1) / v + abs(e[i1] -  x1) + abs(e[i1] - x2));
        }
        --i1;
        if (i1 >= 0) {
            ans = min(ans, (y2 - y1 + v - 1) / v + abs(e[i1] -  x1) + abs(e[i1] - x2));
        }
        cout << ans << endl;
    }
    return 0;
}