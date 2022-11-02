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
#ifdef _WIN32 || _WIN64
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
const int N = 4040;
const int M = int(2e4) + 100;

struct mystack {
    
    int sz;
    pii val[N];
    int d[N][N];
    
    void init() {
        sz = 0;
        for (int i = 0; i < N; ++i) {
            d[0][i] = 0;
        }
    }
    
    void add(pii cur) {
        val[++sz] = cur;
        for (int i = 0; i < N; ++i) {
            d[sz][i] = d[sz - 1][i];
            if (i > 0) {
                d[sz][i] = max(d[sz][i], d[sz][i - 1]);
            }
            if (i - cur.fs >= 0) {
                d[sz][i] = max(d[sz][i], d[sz - 1][i - cur.fs] + cur.sc);
            }
        }
    }
    
    pii del() {
        return val[sz--];
    }
    
    int get_ans(int can) {
        return d[sz][can];
    }
    
};
          
mystack s1, s2;
pair<pii, int> q[M];
int ans[M];
pair<int, pii> a[N];

inline int get_ans(int can) {
    int ans = 0;
    for (int i = 0; i <= can; ++i) {
        ans = max(ans, s1.get_ans(i) + s2.get_ans(can - i));
    }
    return ans;
}

inline void add(pii cur) {
    s2.add(cur);
}

inline void del() {
    if (s1.sz == 0) {
        while (s2.sz > 0) {
            s1.add(s2.del());
        }
    }
    assert(s1.sz > 0);
    s1.del();
}

int main() {
    cerr << (sizeof(s1) + sizeof(s2)) / 1024 / 1024 << endl;
#ifdef LOCAL42
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#else
    
#endif
    int n, p;
    scanf("%d %d", &n, &p);
    for (int i = 0; i < n; ++i) {
        scanf("%d %d %d", &a[i].sc.fs, &a[i].sc.sc, &a[i].fs);
    }
    sort(a, a + n);
    int m;
    cin >> m;
    for (int i = 0; i < m; ++i) {
        scanf("%d %d", &q[i].fs.fs, &q[i].fs.sc);
        q[i].sc = i;
    }
    sort(q, q + m);
    int l = 0, r = 0;
    s1.init();
    s2.init();
    for (int i = 0; i < m; ++i) {
        while (r < n && a[r].fs <= q[i].fs.fs) {
            add(a[r++].sc);
        }
        while (l < r && a[l].fs + p <= q[i].fs.fs) {
            del();
            ++l;
        }
        ans[q[i].sc] = get_ans(q[i].fs.sc);
    }
    for (int i = 0; i < m; ++i) {
        printf("%d\n", ans[i]);
    }
    return 0;
}