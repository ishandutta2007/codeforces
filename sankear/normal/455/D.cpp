#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <ctime>
#include <cstring>
#include <cassert>
#include <vector>
#include <set>
#include <map>
#include <bitset>
#include <queue>
#include <deque>
#include <stack>
#include <complex>
#include <algorithm>

using namespace std;

#define pb push_back
#define mp make_pair
#define sz(s) int((s).size())
#define fs first
#define sc second
#define next _next
#define prev _prev
#define rank _rank
#define link _link
#define hash _hash
#ifdef _WIN32
#define LLD "%I64d"
#else
#define LLD "%lld"
#endif

typedef long long ll;
typedef unsigned int uint;
typedef unsigned long long ull;
typedef vector<int> vi;
typedef pair<int, int> pii;
typedef complex<double> tc;
typedef long double ld;

const int inf = int(1e9);
const double pi = 4 * atan(double(1.0));
const double eps = 1e-9;
const int N = int(1e5) + 10;
const int K = 333;

int n;
int cnt[N / K + 1][N];
int sz[N / K + 1];
int b[N / K + 1][2 * K + 10];
int a[N];

inline void writeAll() {
    int ptr = 0;
    for (int i = 0; i <= (n - 1) / K; ++i) {
        for (int j = 0; j < sz[i]; ++j) {
            a[ptr++] = b[i][j];
            --cnt[i][b[i][j]];
        }
    }
}

inline void rebuild(bool fl) {
    if (fl) {
        writeAll();
    }
    int i = 0;
    while (i < n) {
        sz[i / K] = 0;
        for (int j = i; j < min(i + K, n); ++j) {
            b[i / K][sz[i / K]++] = a[j];
            ++cnt[i / K][a[j]];
        }
        i += K;
    }
}

inline pii get(int pos) {
    for (int i = 0; ; ++i) {
        if (sz[i] > pos) {
            return mp(i, pos);
        }
        pos -= sz[i];
    }
}

inline void move(int l, int r) {
    pii pl = get(l), pr = get(r);
    if (pl.fs == pr.fs) {
        int el = b[pl.fs][pr.sc];
        for (int i = pr.sc; i > pl.sc; --i) {
            b[pl.fs][i] = b[pl.fs][i - 1];
        }
        b[pl.fs][pl.sc] = el;
        return;
    }
    // in pr
    int el = b[pr.fs][pr.sc];
    --cnt[pr.fs][el];
    for (int i = pr.sc; i < sz[pr.fs]; ++i) {
        b[pr.fs][i] = b[pr.fs][i + 1];
    }
    --sz[pr.fs];
    // in pl
    for (int i = sz[pl.fs]; i > pl.sc; --i) {
        b[pl.fs][i] = b[pl.fs][i - 1];
    }
    b[pl.fs][pl.sc] = el;
    ++cnt[pl.fs][el];
    ++sz[pl.fs];
}

inline int countt(int l, int r, int k) {
    pii pl = get(l), pr = get(r);
    if (pl.fs == pr.fs) {
        int ans = 0;
        for (int i = pl.sc; i <= pr.sc; ++i) {
            if (b[pl.fs][i] == k) {
                ++ans;
            }
        }
        return ans;
    }
    int ans = 0;
    // in pl
    for (int i = pl.sc; i < sz[pl.fs]; ++i) {
        if (b[pl.fs][i] == k) {
            ++ans;
        }
    }
    // between
    for (int i = pl.fs + 1; i < pr.fs; ++i) {
        ans += cnt[i][k];
    }
    // in pr
    for (int i = 0; i <= pr.sc; ++i) {
        if (b[pr.fs][i] == k) {
            ++ans;
        }
    }
    return ans;
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        scanf("%d", &a[i]);
    }
    rebuild(false);
    int m;
    scanf("%d", &m);
    int ans = 0;
    for (int i = 0; i < m; ++i) {
        if ((i + 1) % K == 0) {
            rebuild(true);
        }
        int t, l, r;
        scanf("%d %d %d", &t, &l, &r);
        l = (l - 1 + ans) % n;
        r = (r - 1 + ans) % n;
        if (l > r) {
            swap(l, r);
        }
        if (t == 1) {
            move(l, r);
            continue;
        }
        int k;
        scanf("%d", &k);
        k = (k - 1 + ans) % n + 1;
        ans = countt(l, r, k);
        printf("%d\n", ans);
    }
    return 0;
}