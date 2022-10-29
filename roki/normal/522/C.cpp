#define _USE_MATH_DEFINES

#include <iostream>
#include <cstdio>
#include <vector>
#include <cmath>
#include <list>
#include <iomanip>
#include <stack>
#include <map>
#include <set>
#include <queue>
#include <string>
#include <algorithm>
#include <cstring>
#include <cstdlib>
#include <cassert>
#include <cstring>
#include <ctime>

#define all(a) a.begin(),a.end()
#define pb push_back
#define mp make_pair
#define forn(i,n) for(int i = 0; i < int(n); ++i)
#define sz(a) int(a.size())

using namespace std;

typedef long long li;
typedef long double ld;

typedef pair<int,int> pt;
#define ft first
#define sc second

const int N = 300 * 1000 + 5;

int m, k, a[N], t[N], r[N], cnt[N][2];
bool ans[N], was;

bool read() {
    if (scanf("%d %d", &m, &k) != 2) 
        return false;

    forn(i, k + 1) {
        ans[i] = false; 
        forn(t, 2)
            cnt[i][t] = 0;
    }

    forn(i, k)
        scanf("%d", &a[i + 1]);

    was = false;

    forn(i, m - 1) {
        scanf("%d %d", &t[i], &r[i]);

        was |= r[i] == 1;
        cnt[ t[i] ][was]++;
    }

    return true;
}

const int INF = 1e9;

void solve() {
    int mint;

    if (was) {
        mint = INF;
        for (int i = 1; i <= k; ++i) {
            if (cnt[i][0] + cnt[0][0] >= a[i] && cnt[i][1] == 0) {
                mint = min(mint, a[i] - cnt[i][0]);
                ans[i] = true;
            }
        }
        assert(mint < INF / 2);
    } else
        mint = 0;

    for (int i = 1; i <= k; ++i) {
        if (cnt[i][0] + cnt[i][1] + cnt[0][0] + cnt[0][1] - mint >= a[i])
            ans[i] = true;

        printf("%c", ans[i] ? 'Y' : 'N');
    }

    puts("");
}

int main() {
#ifdef _DEBUG
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
#endif

    int T;
    scanf("%d", &T);

    while (read())
        solve();
    
    return 0;
}