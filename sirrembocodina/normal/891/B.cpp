#include <algorithm>
#include <cassert>
#include <cstdlib>
#include <complex>
#include <cstring>
#include <memory>
#include <string>
#include <vector>
#include <cstdio>
#include <ctime>
#include <set>
#include <iostream>

using namespace std;

#define fs first
#define sc second
#define forn(i, n) for (int i = 0; i < (int)(n); ++i)
#define pb push_back
#define mp make_pair

typedef long long ll;

const int mod = 1000000007;

int a[30];

int main() {
    ios::sync_with_stdio(false);
    int n;
    cin >> n;
    forn (i, n) {
        cin >> a[i];
        forn (j, i) {
            if (a[j] == a[i]) {
                cout << -1 << endl;
                return 0;
            }
        }
    }
    int mx = 0;
    forn (i, n) {
        mx = max(mx, a[i]);
    }
    forn (i, n) {
        int res = -1;
        forn (j, n) {
            if (a[j] >= a[i]) {
                continue;
            }
            res = max(res, a[j]);
        }
        if (res == -1) {
            res = mx;
        }
        cout << res << " ";
    }
    cout << endl;
    return 0;
}