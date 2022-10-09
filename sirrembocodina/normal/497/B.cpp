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

int a[100100], b[100100];
pair<int, int> ans[100100];

int main() {
    int n;
    scanf("%d", &n);
    forn (i, n) {
        if (i) {
            a[i] = a[i - 1];
            b[i] = b[i - 1];
        }
        int x;
        scanf("%d", &x);
        if (x == 1) {
            ++a[i];
        } else {
            ++b[i];
        }
    }
    int sz = 0;
    for (int x = 1; x <= n; ++x) {
        int y1 = 0, y2 = 0, cur = -1, cura = 0, curb = 0;
        bool ok = true;
        while (cur < n - 1) {
            int c1 = lower_bound(a, a + n, cura + x) - a;
            int c2 = lower_bound(b, b + n, curb + x) - b;
            ok = true;
            if (c1 < c2) {
                ++y1;
                cur = c1;
                if (y1 <= y2) {
                    ok = false;
                }
            } else {
                ++y2;
                cur = c2;
                if (y2 <= y1) {
                    ok = false;
                }
            }
            cura = a[cur];
            curb = b[cur];
        }
        if (cur == n - 1 && ok) {
            ans[sz++] = mp(max(y1, y2), x);
        }
    }
    printf("%d\n", sz);
    sort(ans, ans + sz);
    forn (i, sz) {
        printf("%d %d\n", ans[i].fs, ans[i].sc);
    }
    return 0;
}