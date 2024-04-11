#include "bits/stdc++.h"

#define int long long
#define forn(i, n) for (int i = 0; i < (int)(n); i++)

using namespace std;

int32_t main() {
    ios_base::sync_with_stdio(0);
    int n;
    cin >> n;
    map<string, int> m;
    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        if (m[s] == 0) {
            cout << "OK" << endl;
            m[s]++;
            continue;
        }
        cout << s << m[s] << endl;
        m[s]++;
    }
}