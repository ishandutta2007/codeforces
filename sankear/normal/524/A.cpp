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
#include <queue>
#include <deque>
#include <complex>

using namespace std;

#define pb push_back
#define mp make_pair
#define fs first
#define sc second
#define pbk pop_back
#define sz(s) int((s).size())
#define len(s) int((s).size())
#define all(s) (s).begin(), (s).end()
#define y0 yy0
#define y1 yy1
#define next _next
#define prev _prev
#define link _link
#define hash _hash
#ifdef LOCAL42
#define eprintf(...) fprintf(stderr, __VA_ARGS__)
#else
#define eprintf(...)
#endif
#if ( _WIN32 || _WIN64 || __WIN32__ || __WIN64__ )
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

const int inf = int(1e9);
const double eps = 1e-9;
const double pi = 4 * atan(double(1));
const int M = 1111;

map<int, int> num;
int a[M], b[M], rev_num[M];
bool can[M][M];
vi lst[M];
vi cur;

int main() {
#ifdef LOCAL42
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int m, k;
    cin >> m >> k;
    int ptr = 0;
    for (int i = 0; i < m; ++i) {
        cin >> a[i] >> b[i];
        if (num.find(a[i]) == num.end()) {
            rev_num[ptr] = a[i];
            num[a[i]] = ptr++;
        }
        if (num.find(b[i]) == num.end()) {
            rev_num[ptr] = b[i];
            num[b[i]] = ptr++;
        }
        a[i] = num[a[i]];
        b[i] = num[b[i]];
        can[a[i]][b[i]] = can[b[i]][a[i]] = true;
    }
    for (int i = 0; i < ptr; ++i) {
        int all = 0;
        for (int j = 0; j < ptr; ++j) {
            if (can[i][j]) {
                ++all;
            }
        }
        for (int j = 0; j < ptr; ++j) {
            if (i == j || can[i][j]) {
                continue;
            }
            int cnt = 0;
            for (int z = 0; z < ptr; ++z) {
                if (can[i][z] && can[j][z]) {
                    ++cnt;
                }
            }
            if (cnt * 100 >= k * all) {
                lst[i].pb(j);
            }
        }
    }
    for (auto it : num) {
        cur.clear();
        for (int i = 0; i < sz(lst[it.sc]); ++i) {
            cur.pb(rev_num[lst[it.sc][i]]);
        }
        sort(all(cur));
        printf("%d: %d", it.fs, sz(cur));
        for (int i = 0; i < sz(cur); ++i) {
            printf(" %d", cur[i]);
        }
        puts("");
    }
    return 0;
}