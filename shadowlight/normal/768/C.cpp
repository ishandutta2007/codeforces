#include <bits/stdc++.h>

using namespace std;

const int MAXN = 3 * 1e3;

int main() {
    int n, k, x;
    cin >> n >> k >> x;
    vector <int> a(MAXN, 0);
    for (int i = 0; i < n; i++) {
        int z;
        cin >> z;
        a[z]++;
    }
    for (int i = 0; i < k; i++) {
        vector <int> b(MAXN, 0);
        bool fl = 0;
        for (int j = 0; j < MAXN; j++) {
            if (a[j] % 2) {
                if (fl) {
                    b[j ^ x] += a[j] / 2;
                    b[j] += a[j] / 2 + 1;
                } else {
                    b[j ^ x] += a[j] / 2 + 1;
                    b[j] += a[j] / 2;
                }
                fl ^= 1;
            } else {
                b[j ^ x] += a[j] / 2;
                b[j] += a[j] / 2;
            }
        }
        a = b;
    }
    for (int i = MAXN - 1; i >= 0; i--) {
        if (a[i]) {
            cout << i << " ";
            break;
        }
    }
    for (int i = 0; i < MAXN; i++) {
        if (a[i]) {
            cout << i << " ";
            break;
        }
    }
}