#include "bits/stdc++.h"
 
#define int long long
#define forn(i, n) for (int i = 0; i < (int)(n); ++i)
 
using namespace std;
 
vector<vector<pair<int, int>>> g;

int32_t main() {
    ios_base::sync_with_stdio(0);
    int n;
    cin >> n;
    cout << 3 * n + 4 << endl;
    int x = 0, y = 0;
    forn (i, n + 2) {
        cout << x << " " << y << endl;
        x++; y++;
    }
    x = 1; y = 0;
    forn (i, n + 1) {
        cout << x << " " << y << endl;
        x++; y++;
    }
    x = 0; y = 1;
    forn (i, n + 1) {
        cout << x << " " << y << endl;
        x++; y++;
    }
}