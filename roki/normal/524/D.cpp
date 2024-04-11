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

const int N = 20 * 1000 + 5;

int n, M, T, l[N], u[N], rsz;

int cnt[N];

bool read() {
    if (!(cin >> n >> M >> T)) {
        return false;
    }

    forn(i, n) {
        int h, m, s;
        scanf("%d:%d:%d", &h, &m, &s);
        l[i] = h * 60 * 60 + m * 60 + s;
    }
    return true;
}

void solve() {
    rsz = 0;
    int lft = 0;
    int usrs = 0;
    bool any = false;

    forn(i, n) {
        while (l[lft] + T - 1 < l[i]) {
            cnt[ u[lft] ]--;
            if (cnt[ u[lft] ] == 0)
                usrs--;
            ++lft;
        }

        if (usrs == M) {
            u[i] = u[i - 1];
        } else {
            u[i] = rsz++;
            usrs++;
        }

        cnt[ u[i] ]++;

        if (usrs == M)
            any = true;
    }

    if (!any) {
        puts("No solution");
        return;
    }

    printf("%d\n", rsz);

    forn(i, n)
        printf("%d\n", u[i] + 1);
}

int main() {

#ifdef _DEBUG
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
#else

#ifdef TASK_NAME
    freopen(TASK_NAME ".in", "r", stdin);
    freopen(TASK_NAME ".out", "w", stdout);
#endif

#endif

    while (read())
        solve();
    
    return 0;
}