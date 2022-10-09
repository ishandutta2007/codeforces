#include "bits/stdc++.h"

#define int long long
#define forn(i, n) for (int i = 0; i < (int)(n); i++)

using namespace std;

int32_t main() {
    ios_base::sync_with_stdio(0);
    int n;
    cin >> n;
    string cur = "blue";
    bool lock = false;
    forn (i, n) {
        string s;
        cin >> s;
        if (s == "lock") {
            lock = true;
        } else if (s == "unlock") {
            lock = false;
        } else if (!lock) {
            cur = s;
        }
    }
    cout << cur << endl;
}