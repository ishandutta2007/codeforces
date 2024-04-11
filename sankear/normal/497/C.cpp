#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <ctime>
#include <cstring>
#include <cassert>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <bitset>
#include <stack>
#include <queue>
#include <deque>
#include <complex>

using namespace std;

#define pb push_back
#define mp make_pair
#define sz(s) int((s).size())
#define len(s) int((s).size())
#define all(s) (s).begin(), (s).end()
#ifdef _WIN32
#define LLD "%I64d"
#else
#define LLD "%lld"
#endif
#ifdef LOCAL42
#define eprintf(...) fprintf(stderr, __VA_ARGS__)
#else
#define eprintf(...) 42
#endif
#define y0 yy0
#define y1 yy1
#define next _next
#define prev _prev
#define rank _rank
#define link _link
#define hash _hash
#define fs first
#define sc second

typedef long long ll;
typedef long long llong;
typedef long long int64;
typedef unsigned int uint;
typedef long double ld;
typedef unsigned long long ull;
typedef unsigned long long ullong;
typedef unsigned long long lint;
typedef pair<int, int> pii;
typedef vector<int> vi;

const int inf = int(1e9);
const double eps = 1e-9;
const double pi = 4 * atan(double(1));
const int N = int(1e5) + 100;

struct event {
    
    int x, num, t;
    
    event() {}
    
    event(int x, int num, int t) {
        this->x = x;
        this->num = num;
        this->t = t;
    }
    
};

bool operator < (const event &a, const event &b) {
    return mp(a.x, a.t) < mp(b.x, b.t);
}

event e[4 * N];
int b[N], d[N], k[N], ans[N];
set<pii> s;

int main() {
#ifdef LOCAL42
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#else
    
#endif
    int n;
    scanf("%d", &n);
    int sz = 0;
    for (int i = 0; i < n; ++i) {
        int a;
        scanf("%d %d", &a, &b[i]);
        e[sz++] = event(a, i, -1);
    }
    int m;
    scanf("%d", &m);
    for (int i = 0; i < m; ++i) {
        int c;
        scanf("%d %d %d", &c, &d[i], &k[i]);
        e[sz++] = event(c, i, -2);
        e[sz++] = event(d[i], i, 2);
    }
    sort(e, e + sz);
    for (int i = 0; i < sz; ++i) {
        if (e[i].t == -2) {
            s.insert(mp(d[e[i].num], e[i].num));
            continue;
        }
        if (e[i].t == -1) {
            set<pii>::iterator it = s.lower_bound(mp(b[e[i].num], -inf));
            if (it == s.end()) {
                puts("NO");
                return 0;
            }
            int num = it->sc;
            --k[num];
            if (k[num] == 0) {
                s.erase(it);
            }
            ans[e[i].num] = num;
            continue;
        }
        if (e[i].t == 2) {
            s.erase(mp(d[e[i].num], e[i].num));
            continue;
        }
        assert(false);
    }
    puts("YES");
    for (int i = 0; i < n; ++i) {
        printf("%d ", ans[i] + 1);
    }
    puts("");
    return 0;
}