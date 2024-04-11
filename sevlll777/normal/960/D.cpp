#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>
#include <cmath>

#define pb push_back
#define int long long
using namespace std;


signed main() {
    const int C = 61;
    vector<int> levs(C);
    vector<int> po2;
    for (int i = 0; i < C; i++) {
        po2.pb(pow(2, i));
    }
    int Q;
    cin >> Q;
    for (int u = 0; u < Q; u++) {
        int t, x, k;
        cin >> t;
        if (t == 1) {
            cin >> x >> k;
            int lev = floor(log2(x));
            levs[lev] += k;
            levs[lev] %= po2[lev];
        } else if (t == 3) {
            cin >> x;
            int lev = floor(log2(x)) + 1;
            x += levs[lev - 1];
            while (lev--) {
                int gg = ((po2[lev] + x - levs[lev]) % (po2[lev]) + po2[lev]);
                cout << ((po2[lev] + x - levs[lev]) % (po2[lev]) + po2[lev]) << ' ';
                x /= 2;
            }
            cout << '\n';
        } else {
            cin >> x >> k;
            int lev = floor(log2(x));
            int zaz = 1;
            while (lev < C) {
                levs[lev] += po2[lev] * 100000 + k * zaz;
                levs[lev] %= po2[lev];
                zaz *= 2;
                lev++;
            }
        }
    }
}