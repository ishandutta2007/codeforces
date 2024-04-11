#pragma comment(linker, "/STACK:60000000")
#define _CRT_SECURE_NO_WARNINGS

#include <bitset>
#include <cstdio>
#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <string>
#include <set>
#include <map>
#include <ctime>
#include <cstring>
#include <cassert>
#include <sstream>
#include <iomanip>
#include <complex>
#include <queue>
#include <functional>

using namespace std;

#define forn(i, n) for(int i = 0; i < (int)(n); i++)
#define ford(i, n) for(int i = (int)(n) - 1; i >= 0; i--)
#define pb push_back
#define mp make_pair
#define fs first
#define sc second
#define last(a) int(a.size() - 1)
#define all(a) a.begin(), a.end()
#define seta(a,x) memset (a, x, sizeof (a))
#define I (int)
#define next NEXTHUI
#define prev PREVHUI
#define y1 Y1HUI

typedef long long int64;
typedef pair <int, int> pii;
typedef long double ldb;

const long double eps = 1e-9;
const int inf = (1 << 30) - 1;
const int64 inf64 = ((int64)1 << 62) - 1;
const long double pi = 3.1415926535897932384626433832795;
const string task = "";

template <class T> T sqr (T x) {return x * x;}

int n, m;
int a[100500];
int last[100500];
char ans[100500];
int x[100500], y[100500];

void solve() {
    scanf("%d%d", &n, &m);
    forn(i, m) {
        scanf("%d", &a[i]);
        ans[i] = 'N';
        last[i] = -1;
    }
    forn(i, n - 1) {
        scanf("%d%d", &x[i], &y[i]);
        x[i]--;
        if (x[i] >= 0) last[x[i]] = i;
    }

    int s = 0;
    bool first = 1;
    forn(i, n - 1) {
        if (first && y[i] == 1) {
            first = 0;
            int mn = inf;
            forn(j, m)
                if (a[j] <= s && last[j] < i) {
                    ans[j] = 'Y';
                    mn = min(mn, a[j]);
                }
            s -= mn;
        }
        if (x[i] != -1) {
            a[x[i]]--;
        } else {
            s++;
        }
       
    }
    cerr << s << endl;
    forn(i, m)
        if (a[i] <= s) ans[i] = 'Y';

    forn(i, m) {
        printf("%c", ans[i]);
    }
    printf("\n");
}

int main () {
//  freopen ((task + ".in").data(), "r", stdin);
//  freopen ((task + ".out").data(), "w", stdout);
//  freopen ("input.txt", "r", stdin);
//  freopen ("output.txt", "w", stdout);
    int tt;
    scanf("%d", &tt);
    forn(ii, tt) solve();
    return 0;
}