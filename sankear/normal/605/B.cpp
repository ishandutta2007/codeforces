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
#include <complex>
#include <tuple>
#include <unordered_map>
#include <unordered_set>

using namespace std;

#define pb push_back
#define pbk pop_back
#define mp make_pair
#define mt make_tuple
#define fs first
#define sc second
#define sz(s) ((int) (s).size())
#define len(s) ((int) (s).size())
#define all(x) (x).begin(), (x).end()
#define next hunext
#define prev huprev
#define rank hurank
#define hash huhash
#ifdef LOCAL42
#define eprintf(...) fprintf(stderr, __VA_ARGS__)
#else
#define eprintf(...)
#define cerr if (0) cerr
#endif
#if _WIN32 || __WIN32__ || _WIN64 || __WIN64__
#define LLD "%I64d"
#else
#define LLD "%lld"
#endif

typedef long long ll;
typedef long long llong;
typedef long long int64;
typedef unsigned int uint;
typedef unsigned long long ull;
typedef unsigned long long ullong;
typedef unsigned long long lint;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef long double ld;
typedef long double ldouble;

const int inf = 1e9;
const double eps = 1e-9;
const double pi = 4 * atan(1.0);
const int N = int(1e5) + 100;

set<pii> ptrs;
int ptr[N];
pii e[N];
pair<pii, int> a[N];

inline void fail() {
    puts("-1");
    exit(0);
}

int main() {
#ifdef LOCAL42
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < m; ++i) {
        scanf("%d %d", &a[i].fs.fs, &a[i].fs.sc);
        a[i].fs.sc = 1 - a[i].fs.sc;
        a[i].sc = i;
    }
    sort(a, a + m);
    if (a[0].fs.sc != 0) {
        fail();
    }
    int k = 1;
    for (int i = 0; i < m; ++i) {
        if (a[i].fs.sc == 0) {
            ++k;
            ptr[k] = k + 1;
            ptrs.insert(mp(ptr[k], k));
            e[a[i].sc] = mp(1, k);
            continue;
        }
        assert(k >= 2);
        if (ptrs.begin()->fs <= k) {
            int v = ptrs.begin()->sc;
            ptrs.erase(ptrs.begin());
            e[a[i].sc] = mp(v, ptr[v]++);
            ptrs.insert(mp(ptr[v], v));
        } else {
            fail();
        }
    }
    for (int i = 0; i < m; ++i) {
        printf("%d %d\n", e[i].fs, e[i].sc);
    }
    return 0;
}