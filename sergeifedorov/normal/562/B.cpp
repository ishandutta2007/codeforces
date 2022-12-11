#ifdef blabla
#define _GLIBCXX_DEBUG
#endif

#include <cstdio>
#include <cstdlib>
#include <iostream>

#include <vector>
#include <string>
#include <cstring>
#include <map>
#include <set>
#include <queue>
#include <bitset>
#include <algorithm>
#include <cmath>

using namespace std;

#define forn(i, n) for (int i = 0; i < (int)(n); i ++)
#define ford(i, n) for (int i = (int)(n) - 1; i >= 0; i--)
#define pb push_back
#define mp make_pair
#define fs first
#define sc second
#define all(a) a.begin(), a.end()
#define sqr(a) ((a)*(a))

const int NMAX = 1000000 + 100;

int n;
int used[NMAX], d[NMAX];

int main() {
#ifdef blabla
    freopen("input.txt", "rt", stdin);
//  freopen("output.txt", "wt", stdout);
#endif

    scanf("%d", &n);
    forn(i, n) {
        int x;
        scanf("%d", &x);
        used[x] = 1;
    }

    for (int x = 1; x < NMAX; ++x) {
        if (used[x]) {
            d[x] = max(d[x], 1);
            for (int xx = 2 * x; xx < NMAX; xx += x) {
                if (used[xx]) {
                    d[xx] = max(d[xx], d[x] + 1);                   
                }
            }
        }
    }

    int ans = *max_element(d, d + NMAX);
    cout << ans << endl;    

    return 0;
}