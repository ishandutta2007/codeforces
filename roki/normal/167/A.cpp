#define _USE_MATH_DEFINES

#include <iostream>
#include <cstdio>
#include <string>
#include <cstring>
#include <iomanip>
#include <vector>
#include <ctime>
#include <queue>
#include <stack>
#include <cassert>
#include <algorithm>
#include <map>
#include <set>
#include <bitset>
#include <cmath>

using namespace std;

#define forn(i,n) for (int i = 0; i < int(n); ++i)
#define pb push_back
#define mp make_pair
#define all(a) a.begin(),a.end()
#define sz(a) int(a.size())

typedef long long li;
typedef long double ld;

typedef pair<int,int> pt;
#define ft first
#define sc second

const int INF = int(1e9);
const li INF64 = li(1e18);

const li mod = 1000000000000000031ll;

int n;
ld a, d;

bool read() {
    return (cin >> n >> a >> d);
}

void solve() {
    ld ans = 0;
    forn (i, n)
    {
        ld st, v;
        cin >> st >> v;
        ld t1 = v / a;
        ld t2 = sqrt(2 * d / a);
        if (t1 < t2)
        {
            ld d1 = a * t1 * t1 / 2;
            ans = max(ans, (d - d1) / v + st + t1);
        }
        else
            ans = max(ans, st + t2);

        cout << fixed << setprecision(10) << ans << endl;
    }
}

int main() {
#ifdef _DEBUG
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
#endif
    
    while (read())
        solve();

    return 0;
}