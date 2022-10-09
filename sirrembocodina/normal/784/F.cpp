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

int mod = 1000000007;

int a[10100000];
    
int main() {
    ios::sync_with_stdio(false);
    int n;
    cin >> n;
    forn (i, n) {
        cin >> a[i];
    }
    forn (i, 3) {
        forn (j, (1 << 30)) {
            a[i] ^= j;
        }
    }
    sort(a, a + n);
    forn (i, n) {
//        if (!i || a[i] != a[i - 1])
            cout << a[i];
            if (i < n - 1) cout << ' ';
    }
    cout << endl;
    return 0;
}