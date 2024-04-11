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

typedef long double ld;

long double p[1010], np[1010];
int q[1010];
int ans[1010];

int main() {
    ios::sync_with_stdio(false);
    int n, m;
    cin >> n >> m;
    forn (i, m) {
        cin >> q[i];
    }
    p[0] = 1;
    forn (i, 7500) {
        np[0] = 0;
        forn (j, n) {
            np[j + 1] = p[j] * ld(n - j) / ld(n) + 
                        p[j + 1] * ld(j + 1) / ld(n);
        }
        forn (j, n + 1) {
            p[j] = np[j];
        }
        forn (j, m) {
            if (ans[j]) {
                continue;
            }
            if (p[n] * 2000 >= q[j]) {
                ans[j] = i + 1;
            }
        }
    }
    forn (i, m) {
        cout << ans[i] << endl;
    }
    return 0;
}