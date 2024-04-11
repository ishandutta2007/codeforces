#include <bits/stdc++.h>

using namespace std;

#define int int64_t
#define forn(i, n) for (int i = 0; i < (int)(n); i++)

vector<int> get(int i, int j) {
    cout << "and " << i + 1 << " " << j + 1 << endl;
    int x;
    cin >> x;
    int y;
    cout << "or " << i + 1 << " " << j + 1 << endl;
    cin >> y;
    vector<int> res(30);
    for (int i = 0; i < 30; i++) {
        if (x & (1 << i)) {
            res[i]++;
        }
        if (y & (1 << i)) {
            res[i]++;
        }
    }
    return res;
}

int32_t main() {
    ios_base::sync_with_stdio(0);
    int n, k;
    cin >> n >> k;
    k--;
    vector<int> a(n);
    vector<int> x = get(0, 1), y = get(1, 2), z = get(0, 2);
    for (int i = 0; i < 30; i++) {
        if (x[i] == 0) {
            if (y[i] == 1) {
                a[2] |= 1 << i;
            }
        } else if (x[i] == 2) {
            a[0] |= 1 << i;
            a[1] |= 1 << i;
            if (y[i] == 2) {
                a[2] |= 1 << i;
            }
        } else if (y[i] == 0) {
            a[0] |= 1 << i;
        } else if (y[i] == 2) {
            a[1] |= 1 << i;
            a[2] |= 1 << i;
        } else if (z[i] == 0) {
            a[1] |= 1 << i;
        } else {
            a[0] |= 1 << i;
            a[2] |= 1 << i;
        }
    }
    for (int i = 3; i < n; i++) {
        x = get(0, i);
        for (int j = 0; j < 30; j++) {
            if (a[0] & (1 << j)) {
                x[j]--;
            }
            if (x[j]) {
                a[i] |= 1 << j;
            }
        }
    }
    sort(a.begin(), a.end());
    /*forn (i, n) {
        cerr << a[i] << endl;
    }*/
    cout << "finish " << a[k] << endl;
    return 0;
}