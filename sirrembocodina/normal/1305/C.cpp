#include "bits/stdc++.h"

//#define int long long
#define forn(i, n) for (int i = 0; i < (int)(n); ++i)

using namespace std;

short int mult[1010][1010];

int32_t main() {
    //ios_base::sync_with_stdio(0);
    int n, m;
    scanf("%d%d", &n, &m);
    //n = 200000;
    //m = 997;
    forn (i, m) {
        forn (j, m) {
            mult[i][j] = i * j % m;
        }
    }
    vector<int> a(n);
    vector<short int> b(m, 1);
    int ans = 1;
    forn (i, n) {
        //a[i] = rand();
        scanf("%d", &a[i]);
    }
    sort(a.begin(), a.end());
    forn (i, n) {
        int x = a[i] % m;
        ans *= b[x];
        ans %= m;
        x = (m - x) % m;
        forn (j, m - x) {
            b[j] = mult[b[j]][j + x];
        }
        x -= m;
        for (int j = -x; j < m; ++j) {
            b[j] = mult[b[j]][j + x];
        }
    }
    cout << ans << endl;
    //cout << clock() * 1.0 / CLOCKS_PER_SEC << endl;
}