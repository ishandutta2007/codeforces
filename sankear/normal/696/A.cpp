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

map<ll, ll> add;

inline int len(ll v) {
    int res = 0;
    while (v > 1) {
        ++res;
        v /= 2;
    }
    return res;
}

int main() {
#ifdef LOCAL42
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int q;
    cin >> q;
    for (int i = 0; i < q; ++i) {
        int t;
        scanf("%d", &t);
        if (t == 1) {
            ll u, v;
            int w;
            scanf("%lld %lld %d", &u, &v, &w);
            int lu = len(u), lv = len(v);
            if (lu < lv) {
                swap(u, v);
                swap(lu, lv);
            }
            while (lu > lv) {
                add[u] += w;
                u /= 2;
                --lu;
            }
            while (v != u) {
                add[u] += w;
                add[v] += w;
                u /= 2;
                v /= 2;
            }
        } else {
            assert(t == 2);
            ll u, v;
            scanf("%lld %lld", &u, &v);
            int lu = len(u), lv = len(v);
            if (lu < lv) {
                swap(lu, lv);
                swap(u, v);
            }
            ll res = 0;
            while (lu > lv) {
                res += add[u];
                u /= 2;
                --lu;
            }
            while (u != v) {
                res += add[u];
                res += add[v];
                u /= 2;
                v /= 2;
            }
            printf("%lld\n", res);
        }
    }
    return 0;
}