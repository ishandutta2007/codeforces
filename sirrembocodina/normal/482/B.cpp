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

int a[100100], ans[100100];
pair<int, pair<bool, int> > q[200100];
bool ok[100100];
vector<int> cur;

int main() {
    int n, m;
    scanf("%d %d", &n, &m);
    int sz = 0;
    forn (i, m) {
        int l, r;
        scanf("%d %d %d", &l, &r, &a[i]);
        q[sz++] = mp(l - 1, mp(true, i));
        q[sz++] = mp(r, mp(false, i));
    }
    sort(q, q + sz);
    forn (b, 30) {
        forn (i, m) {
            ok[i] = false;
        }
        int cnt1 = 0, j = 0, p = 1 << b;
        cur.clear();
        forn (i, n + 1) {
            while (j < sz && q[j].fs == i) {
                if (q[j].sc.fs) {
                    if (a[q[j].sc.sc] & p) {
                        ++cnt1;
                    } else {
                        cur.pb(q[j].sc.sc);
                    }
                } else {
                    if (a[q[j].sc.sc] & p) {
                        --cnt1;
                    } else {
                        if (!ok[q[j].sc.sc]) {
                            printf("NO\n");
                            return 0;
                        }
                    }
                }
                ++j;
            }
            if (cnt1) {
                ans[i] |= p;
            } else {
                while(cur.size()) {
                    ok[cur.back()] = true;
                    cur.pop_back();
                }
            }
        }
    }
    printf("YES\n");
    forn (i, n) {
        printf("%d ", ans[i]);
    }
}