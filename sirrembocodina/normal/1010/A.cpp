#include <iostream>
#include <map>
#include <vector>
#include <bits/stdc++.h>
#include <algorithm>

using namespace std;

#define forn(i, n) for (int i = 0; i < (int)(n); ++i)

#define pb push_back

int a[100100];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    double m;
    cin >> n >> m;
    double M = m;
    forn (i, n) {
        cin >> a[i * 2];
    }
    cin >> a[2 * n - 1];
    forn (i, n - 1) {
        cin >> a[i * 2 + 1];
    }
    n *= 2;
    for (int i = n - 1; i >= 0; --i) {
        if (a[i] == 1) {
            cout << -1 << endl;
            return 0;
        }
        m += m / (a[i] - 1);
    }
    cout.precision(10);
    cout << fixed << m - M << endl;
}