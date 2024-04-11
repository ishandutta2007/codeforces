#include <bits/stdc++.h>
using namespace std;

#define N 200200

int n, a[N], b[N];

int main() {
    cin >> n;
    for (int i = 0; i < n; i ++) cin >> a[i];
    int ad = 0;
    for (int i = 0; i < n; i ++) {
        if (a[i] & 1) ad ++;
        b[i] = a[i] >> 1;
    }
    int sum = 0;
    for (int i = 0; i < n; i ++) sum -= b[i];
    if (sum <= ad) {
        for (int i = 0; i < n && sum; i ++) {
            if (a[i] & 1) sum --, b[i] ++;
        }
        for (int i = 0; i < n; i ++) cout << b[i] << endl;
    }

    return 0;
}