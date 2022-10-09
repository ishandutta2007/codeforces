#include <iostream>
#include <algorithm>
#include <cstdio>
#include <vector>
#include <string>

using namespace std;

#define forn(i, n) for (int i = 0; i < (int)(n); ++i)
#define pb push_back
#define mp make_pair
#define fs first
#define sc second

int a[100100];

int main() {
    ios::sync_with_stdio(false);
    int n;
    cin >> n;
    forn (i, n) {
        cin >> a[i];
        --a[i];
    }
    forn (i, n) {
        if (a[a[i]] != a[i]) {
            cout << "-1\n";
            return 0;
        }
    }
    vector<int> b, c(n, -1);
    forn (i, n) {
        if (a[i] == i) {
            c[i] = b.size();
            b.pb(i);
        }
    }
    cout << b.size() << "\n";
    forn (i, n) {
        cout << c[a[i]] + 1 << " ";
    }
    cout << endl;
    forn (i, b.size()) {
        cout << b[i] + 1 << " ";
    }
    cout << endl;
    return 0;
}