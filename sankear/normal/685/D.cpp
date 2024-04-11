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

const int inf = 1e9;
const double eps = 1e-9;
const double pi = 4 * atan(1.0);
const int N = int(1e5) + 2;
const int K = 303;

vector<tuple<int, int, int> > events;
pii p[N];
int all_ys[N], last_x[N * K], val[N * K];
ll ans[N];

int main() {
    //cerr << (sizeof(p) + sizeof(all_ys) + sizeof(ans) + sizeof(last_x) + sizeof(val)) / 1024 / 1024 << endl;
#ifdef LOCAL42
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int n, k;
    cin >> n >> k;
    for (int i = 0; i < n; ++i) {
        scanf("%d %d", &p[i].sc, &p[i].fs);
        all_ys[i] = p[i].fs;
    }
    sort(all_ys, all_ys + n);
    sort(p, p + n);
    int last_y = -2e9, ptr = 0, sz = 0;
    for (int i = 0; i < n; ++i) {
        for (int y = max(last_y + 1, all_ys[i] - k + 1); y <= all_ys[i]; ++y) {
            if (ptr < n) {
                assert(p[ptr].fs - k + 1 >= y);
            }
            while (ptr < n && p[ptr].fs - k + 1 == y) {
                events.pb(mt(p[ptr].sc - k + 1, sz, 1));
                events.pb(mt(p[ptr].sc + 1, sz, -1));
                ++ptr;
            }
            ++sz;
        }
        last_y = all_ys[i];
    }
    assert(ptr == n);
    sort(all(events));
    for (tuple<int, int, int> e : events) {
        int x, y, add;
        tie(x, y, add) = e;
        for (int j = 0; j < k; ++j) {
            if (val[y + j] > 0) {
                ans[val[y + j]] += x - last_x[y + j];
            }
            val[y + j] += add;
            last_x[y + j] = x;
        }
    }
    for (int i = 1; i <= n; ++i) {
        printf("%lld ", ans[i]);
    }
    puts("");
    return 0;
}