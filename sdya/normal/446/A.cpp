#include <iostream>
#include <cstdio>
#include <ctime>

using namespace std;

const int maxN = 110000;
int a[maxN], d[maxN], n;

int main() {
    cin >> n;
    for (int i = 0; i < n; ++i) cin >> a[i];
    for (int i = n - 1; i >= 0; --i) {
        d[i] = 1;
        if (i + 1 < n && a[i + 1] > a[i]) d[i] = d[i + 1] + 1;
    }
    int res = 1;
    for (int i = 0; i < n; ++i) {
        int pos = i + d[i] - 1;
        int current = d[i] + 1;
        if (pos + 2 < n && a[pos + 2] > a[pos] + 1) current = d[i] + d[pos + 2] + 1; else if (i == 0 && pos == n - 1) current = d[i];
        res = max(res, current);
    }

    for (int i = 0; i + 2 < n; ++i) {
         if (a[i] + 1 >= a[i + 2]) {
             continue;
         }
         int l = i, r = i + 2;
         while (l != 0 && a[l - 1] < a[l]) --l;
         while (r != n - 1 && a[r + 1] > a[r]) ++r;
         res = max(res, r - l + 1);
         if ((double)(clock()) / CLOCKS_PER_SEC > 0.75) break;
    }
    cout << res << endl;
}