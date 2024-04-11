#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, q, s[100000];
    cin >> n;
    for (int i=0; i<n; i++) {
        int a;
        cin >> a;
        if (i == 0)
            s[i] = a;
        else
            s[i] = s[i-1] + a;
    }

    cin >> q;
    for (int i=0; i<q; i++) {
        int l, r;
        cin >> l >> r;
        if (l == 1)
            cout << s[r-1] / 10 << endl;
        else
            cout << (s[r-1] - s[l-2]) / 10 << endl;
    }

    return 0;
}