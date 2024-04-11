#include <bits/stdc++.h>

using namespace std;

#define forn(i, n) for (int i = 0; i < (int)(n); ++i)
#define pb push_back
#define mp make_pair
#define fs first
#define sc second

typedef long long ll;

int mod = 1000000007;

int a[110];

int main() {
    ios::sync_with_stdio(0);
    int m, n;
    cin >> m >> n;
    forn (i, n) {
        cout << 1 << endl;
        int x;
        cin >> x;
        if (!x) {
            return 0;
        }
        a[i] = x != 1;
    }
    int l = 1, r = m;
    int i = 0;
    while (true) {
        m = (l + r) / 2;
        cout << m << endl;
        int x;
        cin >> x;
        if (a[i]) {
            x *= -1;
        }
        if (x == 0) {
            return 0;
        }
        if (x == -1) {
            r = m - 1;
        } else {
            l = m + 1;
        }
        i = (i + 1) % n;
    }
    return 0;
}