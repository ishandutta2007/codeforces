#include<bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    int n, q;
    cin >> n >> q;
    vector<int> lis;
    for (int i = 1; i < 7001; ++i) {
        bool f = true;
        for (int j = 2; j * j <= i; ++j) {
            if (i % (j * j) == 0) {
                f = false;
                break;
            }
        }
        if (f) lis.push_back(i);
    }
    vector<bitset<7001>> bs(7001);
    vector<bitset<7001>> mask(7001);
    for (int i = 1; i < 7001; ++i) {
        for (int j = 1; j * j <= i; ++j) {
            if (i % j == 0) {
                bs[i][j] = 1;
                bs[i][i / j] =  1;
            }
        }
        for (int j : lis) {
            if (i * j > 7000) break;
            mask[i][i * j] = 1;
        }
    }
    // cout << mask[1].count() << "\n";
    vector<bitset<7001>> a(n);
    for (int _ = 0; _ < q; ++_) {
        int t, i;
        cin >> t >> i;
        --i;
        if (t == 1) {
            int v;
            cin >> v;
            a[i] = bs[v];
        }
        else if (t == 2) {
            int j, k;
            cin >> j >> k;
            --j;
            --k;
            a[i] = a[j] ^ a[k];
        }
        else if (t == 3) {
            int j, k;
            cin >> j >> k;
            --j;
            --k;
            a[i] = a[j] & a[k];
        }
        else {
            int v;
            cin >> v;
            cout << (a[i] & mask[v]).count() % 2;
        }
    }
    cout << "\n";
    return 0;
}