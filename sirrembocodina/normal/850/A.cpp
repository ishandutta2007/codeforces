#include <iostream>
#include <algorithm>
#include <cstdio>
#include <vector>
#include <string>
#include <set>
#include <map>

using namespace std;

#define forn(i, n) for (int i = 0; i < (int)(n); ++i)
#define pb push_back
#define mp make_pair
#define fs first
#define sc second

typedef long long ll;

int mod = 1000000007;

long long x[1010][5];

bool good(int i, int j, int k) {
    long long res = 0;
    forn (q, 5) {
        res += (x[j][q] - x[i][q]) * (x[k][q] - x[i][q]);
    }
    return res <= 0;
}

int main() {
    ios::sync_with_stdio(false);
    int n;
    cin >> n;
    if (n > 100) {
        cout << 0 << endl;
        return 0;
    }
    forn (i, n) {
        forn (j, 5) {
            cin >> x[i][j];
        }
    }
    vector<int> ans;
    forn (i, n) {
        bool ok = good;
        forn (j, n) {
            if (j == i) {
                continue;
            }
            forn (k, j) {
                if (k == i) {
                    continue;
                }
                if (!good(i, j, k)) {
                    ok = false;
                }
            }
        }
        if (ok) {
            ans.pb(i + 1);
        }
    }
    cout << ans.size() << endl;
    forn (i, ans.size()) {
        cout << ans[i] << endl;
    }
    return 0;
}