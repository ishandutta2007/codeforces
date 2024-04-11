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
const int N = (1 << 15);

ll ans;
int maxv;
int a[N];

void dfs(int v, int need, ll add) {
    if (v >= maxv) {
        return;
    }
    ll cur = need - (a[v * 2] + add);
    assert(cur >= 0);
    ans += cur;
    dfs(v * 2, need, add + cur);
    cur = need - (a[v * 2 + 1] + add);
    ans += cur;
    dfs(v * 2 + 1, need, add + cur);
}

int main() {
#ifdef LOCAL42
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int n;
    cin >> n;
    maxv = 1;
    for (int i = 0; i < n; ++i) {
        maxv *= 2;
    }
    for (int i = 2; i < 2 * maxv; ++i) {
        scanf("%d", a + i);
        a[i] += a[i / 2];
    }
    for (int i = maxv - 1; i > 0; --i) {
        a[i] = max(a[i * 2], a[i * 2 + 1]);
    }
    ans = 0;
    dfs(1, a[1], 0);
    cout << ans << endl;
    return 0;
}