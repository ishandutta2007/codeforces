#include <algorithm>
#include <cstdio>
#include <iostream>
#include <cstring>
#include <cmath>
#include <vector>
#include <string>
#include <map>
#include <deque>
#include <queue>
#include <stack>
#include <cassert>

using namespace std;

#define forn(i,n) for (int i = 0; i < int(n); ++i)
#define ford(i,n) for (int i = int(n) - 1; i >= 0; --i)
#define pb push_back
#define mp make_pair
#define fs first
#define sc second
#define sqr(a) ((a) * (a))
#define all(a) a.begin(), a.end()

typedef long double ld;
typedef long long ll;
typedef unsigned long long ull;
typedef unsigned int ui;
typedef unsigned char uc;

const ld pi = 3.1415926535897932384626433832795l;

const ll mod = 1000000007;

int main() {
    int n, m;
    cin >> n >> m;
    int ld = 0, lh = 1, ans = 0;
    int d, h;
    forn (i, m) {
        cin >> d >> h;
        if (i == 0) {
            ans = h + d - 1;
            ld = d;
            lh = h;
            continue;
        }
        if (abs(h - lh) > d - ld) {
            cout << "IMPOSSIBLE\n";
            return 0;
        }
        ans = max(ans, max(h, lh) + (d - ld - abs(h - lh)) / 2);
        ld = d;
        lh = h;
    }
    ans = max(ans, h + n - ld);
    cout << ans << endl;
    return 0;
}