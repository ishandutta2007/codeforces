#define _USE_MATH_DEFINES
#pragma comment(linker, "/STACK:167772016")

#include <cstdio>
#include <iostream>
#include <string>
#include <cstring>
#include <cstdlib>
#include <iomanip>
#include <vector>
#include <queue>
#include <map>
#include <set>
#include <stack>
#include <bitset>
#include <algorithm>
#include <ctime>
#include <cassert>
#include <cmath>

using namespace std;

#define forn(i, n) for (int i = 0; i < int(n); ++i)
#define pb push_back
#define mp make_pair
#define all(a) a.begin(),a.end()

typedef long long li;
typedef long double ld;

typedef pair<int, int> pt;
#define ft first
#define sc second
#define x first
#define y second

const int INF = 1e9 + 6;
const li INF64 = 1e18;
const ld EPS = 1e-9;

#define sqr(n) ((n) * (n))

int n;
const int N = 500;
int a[N];

bool read() {
    if (!(cin >> n))
        return false;
    forn (i, 2 * n - 1)
        cin >> a[i];
    return true;
}

bool used[300][300];

void solve() {
    
    int m = n;
    n = 2 * n - 1;

    forn (i, n)
        if (a[i] == 0)
            m = max(1, m - 1);

    int neg = 0;
    forn (i, n)
        neg += a[i] < 0;
    int pos = 0;
    forn (i, n)
        pos += a[i] > 0;

    queue<pt> q;
    q.push(mp(neg, pos));

    used[neg][pos] = true;

    while(!q.empty()) {
        pt v = q.front();
        q.pop();
        forn (i, m + 1) {
            int j = m - i;
            if (v.ft - i + j >= 0 && v.sc + i - j >= 0)
            if (!used[v.ft - i + j][v.sc + i - j]) {
                used[v.ft - i + j][v.sc + i - j] = true;
                q.push(mp(v.ft - i + j, v.sc + i - j));
            }
        }
    }

    forn (i, n)
        a[i] = abs(a[i]);

    sort(a, a + n);

    int ans = 0;

    forn (i, 300)
        forn (j, 300) {
            if (!used[i][j])
                continue;
            for (int x = i; x < n; ++x)
                ans += a[x];
            forn (x, i)
                ans -= a[x];
            cout << ans << endl;
            return;
    }
}

int main() {
    
#ifdef _DEBUG
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
#endif

    while(read())
        solve();

    return 0;
}