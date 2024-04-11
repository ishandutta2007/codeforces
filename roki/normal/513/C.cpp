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
typedef double ld;

typedef pair<int,int> pt;
#define ft first
#define sc second

const int INF = int(1e9) + 6;
const li INF64 = li(1e18);
const ld EPS = 1e-9;

#define sqr(n) ((n) * (n))

const int N = 5;
int n;
int l[N], r[N];

bool read() {
    cin >> n;
    forn (i, n)
        cin >> l[i] >> r[i];
    return true;
}

ld f(ld x) {
    return min(1.0, max(0.0, x));
}

int ff(int x)
{
    int res = 1;
    for (int i = 1; i <= x; ++i)
        res *= i;
    return res;
}

void solve() {

    ld ans = 0;

    ld sum = 0;

    forn (mask, 1 << n) {
        
        if (mask == 0)
            continue;

        int cnt = 0;

        int cl = -INF, cr = INF;
        forn (j, n)
            if (mask & (1 << j))
                cnt++, cl = max(cl, l[j]), cr = min(cr, r[j]);

        for (int i = cl; i <= cr; ++i) {
            ld p = 1;
            forn (j, n)
                if (mask & (1 << j))
                    p *= 1.0 / (r[j] - l[j] + 1);

            forn (j, n) {
                if (mask & (1 << j))
                    continue;
                ld cp = p * f((r[j] - i) / (r[j] - l[j] + 1.0));
                forn (k, n) {
                    if (mask & (1 << k))
                        continue;
                    if (k == j)
                        continue;
                    cp *= f((i - l[k]) / (r[k] - l[k] + 1.0));
                }
                ans += cp * i;
                sum += cp;
            }

            if (cnt > 1) {
                ld cp = p;
                forn (k, n) {
                    if (mask & (1 << k))
                        continue;
                    cp *= f((i - l[k]) / (r[k] - l[k] + 1.0));
                }
                ans += cp * i;
                sum += cp;
            }

        }
    }

    cout << fixed << setprecision(10) << ans << endl;
}

int main() {

#ifdef _DEBUG
    freopen("input.txt", "r", stdin);
//  freopen("output.txt", "w", stdout);
#endif

    read();
    solve();

    return 0;
}