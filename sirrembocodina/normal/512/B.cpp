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

int n;
pair<int, int> l[310];
int b[310], d[1024];

int main() {
    scanf("%d", &n);
    forn (i, n) {
        scanf("%d", &l[i].fs);
    }
    forn (i, n) {
        scanf("%d", &l[i].sc);
    }
    sort(l, l + n);
    int ans = 1000000000;
    forn (i, n) {
        vector<int> p;
        int a = l[i].fs;
        //cerr << a << endl;
        for (int j = 2; j * j <= a; ++j) {
            if (a % j) {
                continue;
            }
            while (a % j == 0) {
                a /= j;
            }
            p.pb(j);
        }
        if (a > 1) {
            p.pb(a);
        }
        int m = p.size();
//        forn (j, m) {
//            cerr << p[j] << " ";
//        }
//        cerr << endl;
        forn (j, i) {
            b[j] = 0;
            forn (k, m) {
                if (l[j].fs % p[k]) {
                    b[j] |= 1 << k;
                }
            }
        }
        forn (mask, 1 << m) {
            d[mask] = 1000000000;
        }
        d[0] = 0;
        forn (j, i) {
            forn (mask, 1 << m) {
                d[mask | b[j]] = min(d[mask | b[j]], d[mask] + l[j].sc);
            }
        }
        //cerr << d[(1 << m) - 1] + l[i].sc << endl;
        ans = min(ans, d[(1 << m) - 1] + l[i].sc);
    }
    if (ans < 1000000000) {
       printf("%d\n", ans);
    } else {
       printf("-1\n");
    }
    return 0;
}