#pragma comment(linker, "/STACK:256000000")

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <ctime>
#include <cstring>
#undef NDEBUG
#include <cassert>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <bitset>
#include <queue>
#include <deque>
#include <unordered_map>
#include <unordered_set>
#include <tuple>

using namespace std;

#define pb push_back
#define mp make_pair
#define mt make_tuple
#define pbk pop_back
#define sz(s) ((int) (s).size())
#define fs first
#define sc second
#define all(x) (x).begin(), (x).end()
#ifdef LOCAL42
#define eprintf(...) fprintf(stderr, __VA_ARGS__)
#else
#define eprintf(...) 42
#endif
#if _WIN32 || __WIN32__ || _WIN64 || __WIN64__
#define LLD "%I64d"
#else
#define LLD "%lld"
#endif
#define prev huprev
#define next hunext
#define link hulink
#define hash huhash
#define rank hurank
#define y0 yy0
#define y1 yy1

typedef long long ll;
typedef unsigned int uint;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<int, int> pii;
typedef vector<int> vi;

const ll inf = 1e18;
const double eps = 1e-9;
const double pi = 4 * atan(1.0);
const int N = int(2e5) + 100;
const int ITERS = 80;

int m;
pii a[N];
vector<pii> group[N];
ll sum_t[N];
int p[N];
double fen_suff[N];

inline ll val(const pii& a, const pii& b) {
    return 1LL * a.fs * b.sc - 1LL * b.fs * a.sc;
}

inline bool cmp(const pii& a, const pii& b) {
    return val(a, b) > 0;
}

inline void add_suff(int cp, double val) {
    int pos = lower_bound(p, p + m, cp) - p;
    assert(pos < m && p[pos] == cp);
    while (pos >= 0) {
        if (val < fen_suff[pos]) {
            fen_suff[pos] = val;
        } else {
            break;
        }
        pos = (pos & (pos + 1)) - 1;
    }
}

inline double get_suff(int cp) {
    int pos = lower_bound(p, p + m, cp) - p;
    assert(pos < m && p[pos] == cp);
    double res = 1e100;
    ++pos;
    while (pos < m) {
        res = min(res, fen_suff[pos]);
        pos = (pos | (pos + 1));
    }
    return res;
}

int main() {
#ifdef LOCAL42
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        scanf("%d", &a[i].fs);
    }
    for (int i = 0; i < n; ++i) {
        scanf("%d", &a[i].sc);
    }
    sort(a, a + n, cmp);
    for (int i = 0; i < n; ++i) {
        p[i] = a[i].fs;
    }
    sort(p, p + n);
    m = unique(p, p + n) - p;
    int i = 0, sz = 0;
    while (i < n) {
        int j = i;
        while (j + 1 < n && val(a[i], a[j + 1]) == 0) {
            ++j;
        }
        for (int z = i; z <= j; ++z) {
            group[sz].pb(a[z]);
        }
        sort(all(group[sz]));
        ++sz;
        i = j + 1;
    }
    for (int i = 0; i < sz; ++i) {
        if (i > 0) {
            sum_t[i] += sum_t[i - 1];
        }
        for (pii p : group[i]) {
            sum_t[i] += p.sc;
        }
    }
    double l = 0, r = 1;
    for (int it = 0; it < ITERS; ++it) {
        double mid = (l + r) / 2;
        for (int i = 0; i < m; ++i) {
            fen_suff[i] = 1e100;
        }
        bool fl = false;
        for (int i = sz - 1; i >= 0 && !fl; --i) {
            int ptr = sz(group[i]) - 1;
            for (int j = sz(group[i]) - 1; j >= 0; --j) {
                while (group[i][ptr].fs > group[i][j].fs) {
                    add_suff(group[i][ptr].fs, group[i][ptr].fs * (1.0 - mid * sum_t[i] / sum_t[sz - 1]));
                    --ptr;
                }
                if (group[i][j].fs * (1.0 - mid * ((i > 0 ? sum_t[i - 1] : 0) + group[i][j].sc) / sum_t[sz - 1]) > get_suff(group[i][j].fs)) {
                    fl = true;
                    break;
                }
            }
            while (ptr >= 0) {
                add_suff(group[i][ptr].fs, group[i][ptr].fs * (1.0 - mid * sum_t[i] / sum_t[sz - 1]));
                --ptr;
            }
        }
        if (fl) {
            r = mid;
            continue;
        }
        for (int i = 0; i < m; ++i) {
            fen_suff[i] = 1e100;
        }
        for (int i = 0; i < sz && !fl; ++i) {
            int ptr = sz(group[i]) - 1;
            for (int j = sz(group[i]) - 1; j >= 0; --j) {
                while (group[i][ptr].fs > group[i][j].fs) {
                    add_suff(group[i][ptr].fs, group[i][ptr].fs * (1.0 - mid * sum_t[i] / sum_t[sz - 1]));
                    --ptr;
                }
                if (group[i][j].fs * (1.0 - mid * ((i > 0 ? sum_t[i - 1] : 0) + group[i][j].sc) / sum_t[sz - 1]) > get_suff(group[i][j].fs)) {
                    fl = true;
                    break;
                }
            }
            while (ptr >= 0) {
                add_suff(group[i][ptr].fs, group[i][ptr].fs * (1.0 - mid * sum_t[i] / sum_t[sz - 1]));
                --ptr;
            }
        }
        if (fl) {
            r = mid;
        } else {
            l = mid;
        }
    }
    printf("%.18lf\n", (l + r) / 2);
    return 0;
}