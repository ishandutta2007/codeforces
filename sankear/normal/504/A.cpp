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
#define all(s) (s).begin(), (s).end()
#if ( _WIN32 || __WIN32__ || _WIN64 || __WIN64__ )
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
const double eps = 1e-4;
const double pi = 4 * atan(double(1));
const int N = (1 << 17);

int deg[N], s[N], q[N];
vector<pii> ans;

int main() {
#ifdef LOCAL42
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#else
    
#endif
    int n;
    scanf("%d", &n);
    int l = 0, r = 0;
    for (int i = 0; i < n; ++i) {
        scanf("%d %d", &deg[i], &s[i]);
        if (deg[i] == 1) {
            q[r++] = i;
        }
    }
    while (l < r) {
        int v = q[l++];
        if (deg[v] != 1) {
            assert(deg[v] == 0);
            continue;
        }
        ans.pb(mp(v, s[v]));
        s[s[v]] ^= v;
        --deg[s[v]];
        if (deg[s[v]] == 1) {
            q[r++] = s[v];
        }
    }
    printf("%d\n", sz(ans));
    for (int i = 0; i < sz(ans); ++i) {
        printf("%d %d\n", ans[i].fs, ans[i].sc);
    }
    return 0;
}